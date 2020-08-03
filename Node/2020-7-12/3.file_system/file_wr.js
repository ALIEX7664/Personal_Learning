//文件读取
let fs = require('fs')

//读取图片数据，该数据在data中
fs.readFile('Aliex.jpg', (err, data) => {
    if (!err) {
        console.log(data)
        //将数据写入到新文件
        fs.writeFile('Aruiy.png', data, (err) => {
            if (!err) {
                console.log('wirte succeed')
            }else{
                //输出错误信息
                console('err',err)
            }
        })
    } else {
        console.log('err', err)
    }
})

console.log('read data')