//文件读取

let fs = require('fs')

//异步读取，高效使用Node
fs.readFile('text3.html',(err,data)=>{
    if(!err)
    {
        console.log(data.toString())
    }else{
        console.log('err',err)
    }
})

console.log('read data')

