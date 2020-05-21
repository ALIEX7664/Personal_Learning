/*Node.js 单线程类似进入一个while(true)的事件循环，直到没有事件观察者退出
，每个异步事件都生成一个事件观察者，如果有事件发生就调用该回调函数.*/

var events = require('events');

var eventEmitter = new events.EventEmitter();

var connectHandler = function connected() {
    console.log('连接成功');
    eventEmitter.emit('data_received');
}

eventEmitter.on('connection',connectHandler);   //假若connection事件被触发，那么connectHandler绑定的函数被调用

eventEmitter.on('data_received',function () { //假若事件data_received被触发，那么监听函数就被调用，显示数据成功接收
    console.log('数据接收成功');
});

eventEmitter.emit('connection');//出发了connection函数，所以调用了connectHandler，所以又触发了data_received，调用了接收成功语句
console.log('程序结束')
