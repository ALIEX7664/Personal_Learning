//目录读取
let fs = require('fs')

//读取后目录名称被存入files中
fs.readdir('./', (err, files) => {
    if (!err) {
        console.log(files)
    }else{
        console.log('err',err)
    }
})