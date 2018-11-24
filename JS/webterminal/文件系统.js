let root = JSON.parse(localStorage.root);
let instruction = /^((ls)|(mkdir)|(touch)|(cat)|(ln)|(echo)|(rm)|(cp)|(cd)|(clean)|(pwd))/;
let currentPath = "root";
let currentFullPath = "/root";
/*root={
 *   type:"directory",
 *   date:new Date(+new Date() + 8 * 3600 * 1000).toISOString().replace(/T/g, ' ').replace(/\.[\d]{3}Z/, ''),
 *   path:"",
**};
**localStorage.setItem("root",JSON.stringify(root));
*/
function seekSoft(obj) {
    for (let key in obj) {
        if (obj[key] instanceof Object) {
            if (obj[key].hasOwnProperty("path") && obj[key].path.substr(0, 4) === "soft") {
                let match = /^soft (\S*)/;
                let array = pathAnalyze(match.exec(obj[key].path)[1]);
                array.shift();
                let target = findObj(array);
                target = target[array[array.length - 1]];
                obj[key] = target;
            }
            seekSoft(obj[key]);
        }
    }
}

seekSoft(root);

function seekHard(obj) {
    for (let key in obj) {
        if (obj[key] instanceof Object) {
            if (obj[key].hasOwnProperty("path") && obj[key].path.substr(0, 4) === "hard") {
                let match = /^hard (\S*)/;
                let tPath = obj[key].path;
                let array = pathAnalyze(match.exec(obj[key].path)[1]);
                array.shift();
                let target = findObj(array);
                if (target[array[array.length - 1]] === undefined) {
                    obj[key].path = "";
                } else {
                    target = target[array[array.length - 1]];
                    obj[key] = JSON.parse(JSON.stringify(target));
                    obj[key].path = tPath;
                }
            }
            seekHard(obj[key]);
        }
    }
}

function getInstruction(e) {
    let self = this;
    if (!(e.keyCode === 13)) {
        return 0;
    }
    self.setAttribute("disabled", "disabled");
    if (instruction.test(self.value) === false) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        let cmd = createCmd(currentPath);
        cmd.addEventListener("keyup", getInstruction);
    } else {
        let instructionArray;
        instructionArray = instruction.exec(self.value);
        switch (instructionArray[0]) {
            case "ls":
                lsFunction(self.value);
                break;
            case "mkdir":
                mkdirFunction(self.value);
                break;
            case "touch":
                touchFunction(self.value);
                break;
            case "cat":
                catFunction(self.value);
                break;
            case "ln":
                lnFunction(self.value);
                break;
            case "echo":
                echoFunction(self.value);
                break;
            case "rm":
                rmFunction(self.value);
                break;
            case "cp":
                cpFunction(self.value);
                break;
            case "cd":
                cdFunction(self.value);
                break;
            case "clean":
                cleanFunction();
                break;
            case "pwd":
                pwdFunction(self.value);
                break;
        }
        seekHard(root);
        localStorage.setItem("root", JSON.stringify(root));
        let cmd = createCmd(currentPath);
        cmd.addEventListener("keyup", getInstruction);
    }
}

function Directory() {
    return {
        date: new Date(+new Date() + 8 * 3600 * 1000).toISOString().replace(/T/g, ' ').replace(/\.[\d]{3}Z/, ''),
        type: "directory",
        path: "",
    };
}

function File() {
    return {
        content: "",
        date: new Date(+new Date() + 8 * 3600 * 1000).toISOString().replace(/T/g, ' ').replace(/\.[\d]{3}Z/, ''),
        type: "file",
        path: "",
    }
}

function pathAnalyze(pathStr) {
    let pathArray = pathStr.split("/");
    if (pathArray[0] === "") {
        pathArray.shift();
    }
    return pathArray;
}

function mkdirFunction(value) {
    let i = 0;
    let currentObj = root;
    //let pathMatch = /^mkdir (((\.)?\/[\w]+)+)|([\w]+)/;
    let pathMatch = /^mkdir (\S*)/;
    let fullPath = pathAnalyze(currentFullPath);
    if (!(pathMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let pathStr = pathMatch.exec(value)[1];
    let pathArray = pathAnalyze(pathStr);


    if (pathArray.length === 1 && pathArray[0] !== "." && pathArray[0] !== "..") {
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        if (currentObj.hasOwnProperty(pathArray[0])) {
            let output = createOutput();
            output.value = "directory " + pathArray[0] + " is existed!!!";
            output.disabled = true;
            return 0;
        } else {
            currentObj[pathArray[0]] = Directory();
            let output = createOutput();
            output.value = "directory " + pathArray[0] + " is created!!!";
            output.disabled = true;
            localStorage.setItem("root", JSON.stringify(root));
        }
    } else if (pathArray.length === 1 && (pathArray[0] === "." || pathArray[0] === "..")) {
        let output = createOutput();
        output.value = "instruction is wrong!!!";
        output.disabled = true;
    } else if (pathArray[0] === ".") {
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = "directory " + pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = Directory();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                currentObj[pathArray[i]] = Directory();
                currentObj = currentObj[pathArray[i]];
            }
            else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "directory " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    } else if (pathArray[0] === "..") {
        for (i = 1; i < fullPath.length - 1; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = "directory " + pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = Directory();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                currentObj[pathArray[i]] = Directory();
                currentObj = currentObj[pathArray[i]];
            }
            else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "directory " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    } else {
        for (i = 0; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = "directory " + pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = Directory();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                currentObj[pathArray[i]] = Directory();
                currentObj = currentObj[pathArray[i]];
            }
            else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "directory " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function touchFunction(value) {
    let i = 0;
    let currentObj = root;
    let pathMatch = /^touch (\S*)/;
    let fullPath = pathAnalyze(currentFullPath);
    if (!(pathMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let pathStr = pathMatch.exec(value)[1];
    let pathArray = pathAnalyze(pathStr);

    if (pathArray.length === 1 && (pathArray[0] === "." || pathArray[0] === "..")) {
        let output = createOutput();
        output.value = "instruction is wrong!!!";
        output.disabled = true;
    } else if (pathArray.length === 1 && pathArray[0] !== "." && pathArray[0] !== "..") {
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        if (currentObj.hasOwnProperty(pathArray[0])) {
            let output = createOutput();
            output.value = pathArray[0] + " is existed!!!";
            output.disabled = true;
            return 0;
        } else {
            currentObj[pathArray[0]] = File();
            let output = createOutput();
            output.value = "file " + pathArray[0] + " is created!!!";
            output.disabled = true;
            localStorage.setItem("root", JSON.stringify(root));
        }
    } else if (pathArray[0] === ".") {
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = File();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!!";
                output.disabled = true;
                return 0;
            } else if (currentObj[pathArray[i]].type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "file " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    } else if (pathArray[0] === "..") {
        for (i = 1; i < fullPath.length - 1; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = File();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!!";
                output.disabled = true;
                return 0;
            } else if (currentObj[pathArray[i]].type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "file " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    } else {
        for (i = 0; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj.hasOwnProperty(pathArray[i])) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is existed!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj[pathArray[i]] = File();
                }
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!";
                output.disabled = true;
                return 0;
            } else if ((currentObj[pathArray[i]]).type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
        let output = createOutput();
        output.value = "file " + pathArray[i - 1] + " is created!!!";
        output.disabled = true;
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function cdFunction(value) {
    let i = 0;
    let currentObj = root;
    let pathMatch = /^cd (\S*)/;
    let fullPath = pathAnalyze(currentFullPath);
    if (!(pathMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let pathStr = pathMatch.exec(value)[1];
    let pathArray = pathAnalyze(pathStr);

    if (pathArray.length === 1 && pathArray[0] === ".") {                     //cd .
        let output = createOutput();
        output.value = "instruction is wrong!!!";
        output.disabled = true;
    } else if (pathArray.length === 1 && pathArray[0] === "..") {              //cd ..
        if (fullPath.length === 1) {
            let output = createOutput();
            output.value = "No parent directory";
            output.disabled = true;
        } else {
            fullPath.pop();
            currentPath = fullPath[fullPath.length - 1];
            currentFullPath = "/" + fullPath.join("/");
        }
    } else if (pathArray.length === 1) {                                 //cd xxx
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        if (pathArray[0] === "root" || pathArray[0] === "~") {
            currentPath = "root";
            currentFullPath = "/root";
        } else if (currentObj[pathArray[0]] === undefined) {
            let output = createOutput();
            output.value = pathArray[0] + " is not existed!!";
            output.disabled = true;
            return 0;
        } else if (currentObj[pathArray[0]].type !== "directory") {
            let output = createOutput();
            output.value = pathArray[0] + " is not a directory!!!";
            output.disabled = true;
            return 0;
        } else {
            currentPath = pathArray[0];
            currentFullPath = currentFullPath + "/" + pathArray[0];
        }
    } else if (pathArray[0] === ".." && fullPath.length === 1) {             //当处于主目录时
        let output = createOutput();
        output.value = "No parent directory";
        output.disabled = true;
    } else {                   //要判断cd的路径中是否有非文件夹，回来记得写！！！！！
        if (pathArray[0] === ".") {                                                         //cd ./xxx
            for (i = 1; i < fullPath.length; i++) {
                currentObj = currentObj[fullPath[i]];
            }
            for (i = 1; i < pathArray.length; i++) {
                if (currentObj[pathArray[i]] === undefined) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not existed!!";
                    output.disabled = true;
                    return 0;
                } else if (currentObj[pathArray[i]].type !== "directory") {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not a directory!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj = currentObj[pathArray[i]];
                }
            }
            pathArray.shift();
            currentPath = pathArray[pathArray.length - 1];
            currentFullPath = currentFullPath + "/" + pathArray.join("/");
        } else if (pathArray[0] === "..") {                                                   //  cd ../xxx
            for (i = 1; i < fullPath.length - 1; i++) {
                currentObj = currentObj[fullPath[i]];
            }
            for (i = 1; i < pathArray.length; i++) {
                if (currentObj[pathArray[i]] === undefined) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not existed!!";
                    output.disabled = true;
                    return 0;
                } else if (currentObj[pathArray[i]].type !== "directory") {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not a directory!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj = currentObj[pathArray[i]];
                }
            }
            pathArray.shift();
            fullPath.pop();
            currentPath = pathArray[pathArray.length - 1];
            currentFullPath = "/" + fullPath.join("/") + "/" + pathArray.join("/");
        } else {
            for (i = 0; i < pathArray.length; i++) {
                if (currentObj[pathArray[i]] === undefined) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not existed!!";
                    output.disabled = true;
                    return 0;
                } else if (currentObj[pathArray[i]].type !== "directory") {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not a directory!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj = currentObj[pathArray[i]];
                }
            }
            currentPath = pathArray[pathArray.length - 1];
            currentFullPath = "/root/" + pathArray.join("/");
        }
    }
}

function lsFunction(value) {
    let instructionMatch = /^ls(( -la)?|( -al)?|( -a)?|( -l))?/;
    if (!instructionMatch.test(value))
        return;
    let i = 0;
    let currentObj = root;
    let fullPath = pathAnalyze(currentFullPath);
    for (i = 1; i < fullPath.length; i++)
        currentObj = currentObj[fullPath[i]];
    let objArray = Object.getOwnPropertyNames(currentObj);
    let method = instructionMatch.exec(value)[1];
    switch (method) {
        case " -a":
            lsa(currentObj, objArray, value);
            break;
        case " -l":
            lsl(currentObj, objArray, value);
            break;
        case " -al":
        case " -la":
            lsal(currentObj, objArray, value);
            break;
        default:
            ls(currentObj, objArray, value);
            break;
    }
}

function ls(currentObj, objArray, value) {
    let i;
    let text = "";
    if (objArray.length === 3) {
        let output = createOutput();
        output.value = "Empty!!";
        output.disabled = true;
        return;
    }
    for (i = 0; i < objArray.length; i++) {
        if (objArray[i] === "date" || objArray[i] === "type" || objArray[i].charAt(0) === "." || objArray[i] === "path") {
            continue;
        } else {
            text = text + length(objArray[i]);
        }
    }
    let match = />> (\S*)/;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function lsa(currentObj, objArray, value) {
    let i;
    let text = "";
    if (objArray.length === 3) {
        let output = createOutput();
        output.value = "Empty!!";
        output.disabled = true;
        return;
    }
    for (i = 0; i < objArray.length; i++) {
        if (objArray[i] === "date" || objArray[i] === "type" || objArray[i] === "path") {
            continue;
        } else {
            text = text + length(objArray[i]);
        }
    }
    let match = />> (\S*)/;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function lsl(currentObj, objArray, value) {
    let i;
    let text = "";
    if (objArray.length === 3) {
        let output = createOutput();
        output.value = "Empty!!";
        output.disabled = true;
        return;
    }
    for (i = 0; i < objArray.length; i++) {
        if (objArray[i] === "date" || objArray[i] === "type" || objArray[i].charAt(0) === "." || objArray[i] === "path") {
            continue;
        } else {
            text = text + "root\t" + length(currentObj[objArray[i]].type) + currentObj[objArray[i]].date + "  " + objArray[i] + "\n";
        }
    }
    let match = />> (\S*)/;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function lsal(currentObj, objArray, value) {
    let i;
    let text = "";
    if (objArray.length === 3) {
        let output = createOutput();
        output.value = "Empty!!";
        output.disabled = true;
        return;
    }
    for (i = 0; i < objArray.length; i++) {
        if (objArray[i] === "date" || objArray[i] === "type" || objArray[i] === "path") {
            continue;
        } else {
            text = text + "root\t" + length(currentObj[objArray[i]].type) + currentObj[objArray[i]].date + "  " + objArray[i] + "\n";
        }
    }
    let match = />> (\S*)/;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function length(str) {
    if (str === "file")
        str += "\t   ";
    else if (str === "directory")
        str += "  ";
    else {
        let j = 15 - str.length;
        for (let i = 0; i < j; i++)
            str += " ";
    }
    return str;
}

function cleanFunction() {
    let win = document.querySelector("body");
    win.innerHTML = "";
}

function catFunction(value) {
    let i = 0;
    let currentObj = root;
    let pathMatch = /^cat (\S*)/;
    let fullPath = pathAnalyze(currentFullPath);
    let text;
    if (!(pathMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let pathStr = pathMatch.exec(value)[1];
    let pathArray = pathAnalyze(pathStr);


    if (pathArray.length === 1 && (pathArray[0] === "." || pathArray[0] === "..")) {
        let output = createOutput();
        output.value = "instruction is wrong!!!";
        output.disabled = true;
    } else if (pathArray.length === 1) {
        for (i = 1; i < fullPath.length; i++)
            currentObj = currentObj[fullPath[i]];
        if (currentObj[pathArray[0]] === undefined) {
            let output = createOutput();
            output.value = pathArray[0] + " is not existed!!";
            output.disabled = true;
            return 0;
        } else if (currentObj[pathArray[0]].type === "directory") {
            let output = createOutput();
            output.value = pathArray[0] + " is not a file!!!";
            output.disabled = true;
            return 0;
        } else {
            text = currentObj[pathArray[0]].content;
        }
    } else {
        if (pathArray[0] === "..") {
            for (i = 1; i < fullPath.length - 1; i++)
                currentObj = currentObj[fullPath[i]];
            pathArray.shift();
        } else if (pathArray[0] === ".") {
            for (i = 0; i < fullPath.length; i++)
                currentObj = currentObj[fullPath[i]];
            pathArray.shift();
        }
        for (i = 0; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                if (currentObj[pathArray[i]] === undefined) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not existed!!";
                    output.disabled = true;
                    return 0;
                } else if (currentObj[pathArray[i]].type === "directory") {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not a file!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    text = currentObj[pathArray[i]].content;
                }
            } else {
                if (currentObj[pathArray[i]] === undefined) {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not existed!!";
                    output.disabled = true;
                    return 0;
                } else if (currentObj[pathArray[i]].type !== "directory") {
                    let output = createOutput();
                    output.value = pathArray[i] + " is not a directory!!!";
                    output.disabled = true;
                    return 0;
                } else {
                    currentObj = currentObj[pathArray[i]];
                }
            }
        }
    }
    let match = />> (\S*)/;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function echoFunction(value) {
    let instructionMatch = /^echo ("(\S*)"( (>>) (\S*))?)|((<<) (\S*))/;
    if (!(instructionMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let matchArray = instructionMatch.exec(value);
    if (matchArray[4] === undefined && matchArray[7] === undefined) {
        let output = createOutput();
        output.value = matchArray[2];
        output.disabled = true;
    } else if (matchArray[4] === ">>") {
        toFile(matchArray[2], matchArray[5]);
        localStorage.setItem("root", JSON.stringify(root));
    } else if (matchArray[7] === "<<") {
        toScreen(matchArray[8]);
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function rmFunction(value) {
    let instructionMatch = /^rm( -r)? (\S*)/;
    if (!(instructionMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let pathStr = instructionMatch.exec(value)[2];
    let pathArray = pathAnalyze(pathStr);
    if (instructionMatch.exec(value)[1] === " -r") {
        rmr(pathArray);
    } else {
        rm(pathArray);
    }
}

function rmr(pathArray) {
    let obj = findObj(pathArray);
    if (obj[pathArray[pathArray.length - 1]] !== undefined) {
        delete obj[pathArray[pathArray.length - 1]];
        localStorage.setItem("root", JSON.stringify(root));
    } else {
        let output = createOutput();
        output.value = pathArray[pathArray.length - 1] + " is not found";
        output.disabled = true;
        return 0;
    }
}

function rm(pathArray) {
    let obj = findObj(pathArray);
    if (obj[pathArray[pathArray.length - 1]] === undefined) {
        let output = createOutput();
        output.value = pathArray[pathArray.length - 1] + " is not found";
        output.disabled = true;
        return 0;
    } else if (obj[pathArray[pathArray.length - 1]].type === "file") {
        delete obj[pathArray[pathArray.length - 1]];
        localStorage.setItem("root", JSON.stringify(root));
    } else {
        if (obj[pathArray[pathArray.length - 1]].length <= 3) {
            let output = createOutput();
            output.value = "directory " + pathArray[pathArray.length - 1] + " is not empty";
            output.disabled = true;
            return 0;
        } else {
            delete obj[pathArray[pathArray.length - 1]];
            localStorage.setItem("root", JSON.stringify(root));
        }
    }
}

function findObj(pathArray) {
    let i = 0;
    let currentObj = root;
    let fullPath = pathAnalyze(currentFullPath);
    if (pathArray.length === 1 && (pathArray[0] === "." || pathArray[0] === "..")) {
        let output = createOutput();
        output.value = "instruction is wrong!!!";
        output.disabled = true;
        return 0;
    } else if (pathArray.length === 1) {
        return currentObj;
    } else if (pathArray[0] === ".") {
        for (i = 1; i < fullPath.length; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                return currentObj;
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!!";
                output.disabled = true;
                return 0;
            } else if (currentObj[pathArray[i]].type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
    } else if (pathArray[0] === "..") {
        for (i = 1; i < fullPath.length - 1; i++) {
            currentObj = currentObj[fullPath[i]];
        }
        for (i = 1; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                return currentObj;
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!!";
                output.disabled = true;
                return 0;
            } else if (currentObj[pathArray[i]].type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
    } else {
        for (i = 0; i < pathArray.length; i++) {
            if (i === pathArray.length - 1) {
                return currentObj;
            } else if ((currentObj[pathArray[i]]) === undefined) {
                let output = createOutput();
                output.value = pathArray[i] + " is not existed!!";
                output.disabled = true;
                return 0;
            } else if ((currentObj[pathArray[i]]).type !== "directory") {
                let output = createOutput();
                output.value = pathArray[i] + " is not a directory!!!";
                output.disabled = true;
                return 0;
            } else {
                currentObj = currentObj[pathArray[i]];
            }
        }
    }
}

function cpFunction(value) {
    let i = 0;
    let currentObj = root;
    let pathMatch = /^cp (\S*) (\S*)/;
    let fullPath = pathAnalyze(currentFullPath);
    if (!(pathMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let nowPath = pathMatch.exec(value)[1];
    let targetPath = pathMatch.exec(value)[2];
    let nowPathArray = pathAnalyze(nowPath);
    let targetPathArray = pathAnalyze(targetPath);
    let nowObj = findObj(nowPathArray);
    let targetObj = findObj(targetPathArray);
    if (typeof nowObj[nowPathArray[nowPathArray.length - 1]] !== "object" || typeof targetObj !== "object") {
        return 0;
    } else if (targetObj.hasOwnProperty(targetPathArray[targetPathArray.length - 1])) {
        let output = createOutput();
        output.value = targetPathArray[targetPathArray.length - 1] + "is existed!!!";
        output.disabled = true;
        return 0;
    } else {
        targetObj[targetPathArray[targetPathArray.length - 1]] = JSON.parse(JSON.stringify(nowObj[nowPathArray[nowPathArray.length - 1]]));
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function pwdFunction(value) {
    let match = />> (\S*)/;
    let text=currentFullPath;
    if (match.test(value)) {
        let pathStr=match.exec(value)[1];
        toFile(text,pathStr);
    } else {
        let output = createOutput();
        output.value = text;
        output.style.height = output.scrollHeight + "px";
        output.disabled = true;
    }
}

function lnFunction(value) {
    let instructionMatch = /^ln( -s)? (\S*) (\S*)/;
    if (!(instructionMatch.test(value))) {
        let output = createOutput();
        output.value = "instruction not found!!!";
        output.disabled = true;
        return 0;
    }
    let array = instructionMatch.exec(value);
    let source = pathAnalyze(array[2]);
    let target = pathAnalyze(array[3]);
    if (array[1] === " -s") {
        softLink(source, target);
    } else {
        hardLink(source, target);
    }
}

function softLink(source, target) {
    let sourceObj = findObj(source);
    let targetObj = findObj(target);
    if (typeof sourceObj !== "object" || typeof targetObj !== "object") {
        let output = createOutput();
        output.value = "error!!!";
        output.disabled = true;
        return 0;
    } else if (sourceObj[source[source.length - 1]] === undefined) {
        let output = createOutput();
        output.value = source[source.length - 1] + " not found!!!";
        output.disabled = true;
        return 0;
    } else if (targetObj[target[target.length - 1]] !== undefined) {
        let output = createOutput();
        output.value = target[target.length - 1] + " is existed!!!";
        output.disabled = true;
        return 0;
    } else {
        targetObj[target[target.length - 1]] = sourceObj[source[source.length - 1]];
        targetObj[target[target.length - 1]].path = "soft " + fullSourcePath(source);
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function hardLink(source, target) {
    let sourceObj = findObj(source);
    let targetObj = findObj(target);
    if (typeof sourceObj !== "object" || typeof targetObj !== "object") {
        let output = createOutput();
        output.value = "error!!!";
        output.disabled = true;
        return 0;
    } else if (sourceObj[source[source.length - 1]] === undefined) {
        let output = createOutput();
        output.value = source[source.length - 1] + "not found!!!";
        output.disabled = true;
        return 0;
    } else if (sourceObj[source[source.length - 1]].type === "directory") {
        let output = createOutput();
        output.value = source[source.length - 1] + " is a directory!!!";
        output.disabled = true;
        return 0;
    } else if (targetObj[target[target.length - 1]] !== undefined) {
        let output = createOutput();
        output.value = target[target.length - 1] + " is existed!!!";
        output.disabled = true;
        return 0;
    } else {
        targetObj[target[target.length - 1]] = JSON.parse(JSON.stringify(sourceObj[source[source.length - 1]]));
        targetObj[target[target.length - 1]].path = "hard " + fullSourcePath(source);
        localStorage.setItem("root", JSON.stringify(root));
    }
}

function fullSourcePath(pathArray) {
    let fullPath = pathAnalyze(currentFullPath);
    let string;
    if (pathArray.length === 1) {
        string = currentFullPath + "/" + pathArray[0];
    } else {
        if (pathArray[0] === ".") {
            pathArray.shift();
            string = currentFullPath + "/" + pathArray.join("/");
        } else if (pathArray[0] === "..") {
            pathArray.shift();
            fullPath.pop();
            string = "/" + fullPath.join("/") + "/" + pathArray.join("/");
        } else {
            string = "/root/" + pathArray.join("/");
        }
    }
    return string;
}

function toFile(str, pathStr) {
    let pathArray = pathAnalyze(pathStr);
    let obj = findObj(pathArray);
    if (obj instanceof Object) {
        if (obj[pathArray[pathArray.length - 1]].type !== "file") {
            let output = createOutput();
            output.value = pathArray[pathArray.length - 1] + " is not a file!!!";
            output.disabled = true;
        } else {
            console.log(obj[pathArray[pathArray.length - 1]]);
            obj[pathArray[pathArray.length - 1]].content += str;
        }
    } else {
        let output = createOutput();
        output.value = "error";
        output.disabled = true;
    }
}

function toScreen(pathStr) {
    let pathArray = pathAnalyze(pathStr);
    let obj = findObj(pathArray);
    if (obj instanceof Object) {
        if (obj[pathArray[pathArray.length - 1]].type !== "file") {
            let output = createOutput();
            output.value = pathArray[pathArray.length - 1] + " is not a file!!!";
            output.disabled = true;
        } else {
            let output = createOutput();
            output.value = obj[pathArray[pathArray.length - 1]].content;
            output.disabled = true;
        }
    } else {
        let output = createOutput();
        output.value = "error";
        output.disabled = true;
    }
}