let user=document.querySelector("#user");
let login=false;
let body=document.querySelector("body");
user.addEventListener("keyup",userf);
function userf(e){
    if(!(e.keyCode===13)){
        return 0;
    }else{
        this.setAttribute("disabled","disabled");
        if(this.value==="root"){
            let pwd=createPwdorUser("password");
            pwd.addEventListener("keyup",pwdf);
            pwd.style.opacity="0";
        }else{
            let output=createOutput();
            output.value="user not found!!!";
            output.disabled=true;
            let user=createPwdorUser("user");
            user.addEventListener("keyup",userf);
        }
    }
}
function pwdf(e) {
    if(!(e.keyCode===13)){
        return 0;
    }else{
        this.setAttribute("disabled","disabled");
        if(this.value==="123456"){
            login=true;
            let cmd=createCmd("root");
            cmd.addEventListener("keyup",getInstruction);
        }else{
            let output=createOutput();
            output.value="password is wrong!!!";
            output.disabled=true;
            let pwd=createPwdorUser("password");
            pwd.addEventListener("keyup",pwdf);
            pwd.style.opacity="0";
        }
    }
}
function createPwdorUser(name) {
    let div=document.createElement("div");
    let label=document.createElement("label");
    let input=document.createElement("input");
    body.appendChild(div);
    div.appendChild(label);
    div.appendChild(input);
    label.setAttribute("for",name);
    label.innerText=name+" : ";
    input.setAttribute("id",name);
    input.focus();
    return input;
}
function createCmd(path) {
    let div=document.createElement("div");
    let label=document.createElement("label");
    let input=document.createElement("input");
    body.appendChild(div);
    div.appendChild(label);
    div.appendChild(input);
    label.setAttribute("for","cmd");
    label.innerText="[root@root "+path+"] $ ";
    input.setAttribute("id","cmd");
    input.focus();
    return input;
}
function createOutput() {
    let textarea=document.createElement("textarea");
    body.appendChild(textarea);
    return textarea;
}