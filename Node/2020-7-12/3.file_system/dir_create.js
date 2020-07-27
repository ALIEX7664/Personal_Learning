let fs = require('fs')

// 创建文件夹
fs.mkdir('./dir', (err) => {
    if (!err) {
        console.log('create dir')
    }else{
        console.log('err',err)
    }
})

//删除文件夹
fs.rmdir('dir',(err)=>{
    if(!err)
    {
        console.log('delete succeed')
    }else{
        console.log('err',err)
    }
})