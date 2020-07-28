let fs = require('fs')
let events = require('events')

//创建事件对象
var eventlog =new events.EventEmitter()

//监听事件(事件名字由自己定义)
eventlog.on('MKDIR',(msg)=>{
    console.log('catch MKDIR event1',msg)
})

eventlog.on('MKDIR',(msg)=>{
    console.log('catch MKDIR event2',msg)
})

eventlog.on('MKDIR',(msg)=>{
    console.log('catch MKDIR event3',msg)
})

//触发事件(名字与监听)
eventlog.emit('MKDIR',"SUCCEED")

console.log('execute over')