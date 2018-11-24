const pending = 0;
const fulfilled = 1;
const rejected = 2;

function MyPromise(executor) {
    const self = this;
    self.value = undefined;
    self.reason = undefined;
    self.status = pending;
    self.onFulfilledCallbacks = [];
    self.onRejectedCallbacks = [];

    function resolve(value) {
        if (value instanceof MyPromise) {
            return value.then(resolve, reject);
        }
        if (self.status === pending) {
            setTimeout(function () {
                self.status = fulfilled;
                self.value = value;
                for(let i=0;i<self.onFulfilledCallbacks.length;i++){
                    (function (callback) {
                        callback(self.value);
                    })();
                }
            }, 0)
        }
    }

    function reject(reason) {
        if (self.status === pending) {
            setTimeout(function () {
                self.status = rejected;
                self.reason = reason;
                self.onRejectedCallbacks.forEach((callback) => callback(self.reason));
                for(let i=0;i<self.onRejectedCallbacks.length;i++){
                    (function (callback) {
                        callback(self.value);
                    })();
                }
            }, 0)
        }
    }

    try {
        executor(resolve, reject);//执行执行器
    } catch (e) {
        reject(e);
    }
}

function resolvePromise(nextPromise, x, resolve, reject) {
    if (nextPromise === x) {
        return reject(new TypeError("循环引用"))
    }
    let hasCalled = false;
    if (x instanceof MyPromise) {
        if (x.status === pending) {
            x.then(function (y) {
                resolvePromise(nextPromise, y, resolve, reject);
            }, function (reason) {
                reject(reason);
            })
        } else {
            x.then(resolve, reject);
        }
    } else if (x != null && ((typeof x === 'object') || (typeof x === 'function'))) {
        try {
            let then = x.then;
            if (typeof then === "function") {
                then.call(x, function (y) {
                    if (hasCalled) {
                        return;
                    }
                    hasCalled = true;
                    resolvePromise(nextPromise, y, resolve, reject);
                }, function (reason) {
                    if (hasCalled) {
                        return;
                    }
                    hasCalled = true;
                    reject(reason);
                })
            } else {
                resolve(x);
            }
        } catch (e) {
            if (hasCalled) {
                return;
            }
            hasCalled = true;
            reject(e);
        }
    }else{
        resolve(x);
    }
}

MyPromise.prototype.then = function (onFulfilled, onRejected) {
    const self = this;
    let nextPromise;
    onFulfilled = typeof onFulfilled === "function" ? onFulfilled : function (value) {};
    onRejected = typeof onRejected === "function" ? onRejected : function (error) {};
    if (self.status === fulfilled) {
        return nextPromise = new MyPromise(function (resolve, reject) {
            setTimeout(function () {
                try {
                    let x = onFulfilled(self.value);
                    resolvePromise(nextPromise, x, resolve, reject);
                } catch (e) {
                    reject(e);
                }
            }, 0)
        })
    }
    if (self.status === rejected) {
        return nextPromise = new MyPromise(function (resolve, reject) {
            setTimeout(function () {
                try {
                    let x = onRejected(self.reason);
                    resolvePromise(nextPromise, x, resolve, reject);
                } catch (e) {
                    reject(e);
                }
            }, 0)
        })
    }
    if (self.status === pending) {
        return nextPromise = new MyPromise(function (resolve, reject) {
            self.onFulfilledCallbacks.push(function (value) {
                try {
                    let x = onFulfilled(value);
                    resolvePromise(nextPromise, x, resolve, reject);
                } catch (e) {
                    reject(e);
                }
            });
            self.onRejectedCallbacks.push(function (reason) {
                try {
                    let x = onRejected(reason);
                    resolvePromise(nextPromise, x, resolve, reject);
                } catch (e) {
                    reject(e);
                }
            })
        })
    }
};
MyPromise.prototype.catch = function (onRejected) {
    return this.then(null, onRejected);
};
MyPromise.resolve = function(value) {
    let promise = new MyPromise(function(resolve, reject) {
        resolvePromise(promise, value, resolve, reject)
    });
    return promise
};
MyPromise.reject = function(reason) {
    return new MyPromise(function(resolve, reject) {
        reject(reason)
    })
};
