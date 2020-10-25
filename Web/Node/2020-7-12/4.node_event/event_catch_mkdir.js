//目录创建(事件触发)
let fs = require('fs')
let events = require('events')

//创建事件对象
var eventlog = new events.EventEmitter()

//监听事件
eventlog.on('MKDIR', (msg) => {

    console.log(msg)
    
    fs.rmdir('./dir', (err) => {
        if (!err) {
            console.log('rmdir succeed')
        } else {
            console.log('err', err)
        }
    })
})

//目录创建
fs.mkdir('./dir', (err) => {
    if (!err) {
        //触发事件,表示执行成功
        eventlog.emit('MKDIR', "SUCCEED")
    } else {
        console.log('err', err)
    }
})
