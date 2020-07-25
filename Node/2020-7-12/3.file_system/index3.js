//文件流写入

let fs =  require('fs')

//创建写入流 (路径)
let ws = fs.createWriteStream('text3.html') 

ws.once('open',()=>{
    console.log("open")
    //写入
    ws.write('1')
    ws.write('2')
    ws.write('3')
    ws.write('4')
    //写入结束
    ws.end()
})

//关闭写入流
ws.once('close',()=>{
    console.log('close')
})
