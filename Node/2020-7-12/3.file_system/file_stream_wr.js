let fs = require('fs')

let rs = fs.createReadStream('Aliex.jpg')
let ws = fs.createWriteStream('zzZ.jpg')

//监听读取流是否开启
rs.once('open',()=>{
    console.log('Read stream open')
})

//监听读取流是否关闭
rs.once('close',()=>{
    console.log('Read stream close')
})

ws.once('open',()=>{
    console.log('Write stream open')
})

ws.once('close',()=>{
    console.log('Write stream close')
})

//监听是否读到数据
rs.on('data',(data)=>{
    ws.write(data) //完成写入
}) 