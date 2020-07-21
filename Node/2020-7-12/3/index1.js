//同步写入

let fs = require('fs'); //导入fs模块


let fd = fs.openSync('text1.html','w'); //同步、只写方式打开文件text1

console.log(fd); //文件描述符为3，在《Unix编程》中,1,2文件描述符已被系统占用，从3开始

let str  ="<h1>Aliex<h1>"

fs.writeFileSync(fd,str) //写入文件、写入字符串

fs.closeSync(fd) //关闭文件