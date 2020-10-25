const util = require('util');

async function fn() {   //async异步函数
    return 'Hello World';
}
//将 async 异步函数（或者一个返回值为 Promise 的函数）转换成遵循异常优先的回调风格的函数
const callbackFunction = util.callbackify(fn);
//回调函数是异步执行的，并且有异常堆栈错误追踪。 如果回调函数抛出一个异常，进程会触发一个 'uncaughtException' 异常，如果没有被捕获，进程将会退出。
callbackFunction((err,ret) =>{
        if(err) throw err;
        console.log(ret)
});

// function fn() {
//     return Promise.reject(null);
// }
// const callbackFunction = util.callbackify(fn);
//
// callbackFunction((err, ret) => {
//     // 当 Promise 被以 `null` 拒绝时，它被包装为 Error 并且原始值存储在 `reason` 中。
//     err && err.hasOwnProperty('reason') && err.reason === null;  // true
// });