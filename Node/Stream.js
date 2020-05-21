/*
* data - 当有数据可读时触发。

* end - 没有更多的数据可读时触发。

* error - 在接收和写入过程中发生错误时触发。

* finish - 所有数据已被写入到底层系统时触发。
* */

// /* 输出流 */
// var fs = require('fs');
// data ='';
//
// var readStream = fs.createReadStream('input.txt');
//
// readStream.setEncoding('UTF-8');
//
// readStream.on('data',function (chunk) {
//     data+=chunk;
// });
//
// readStream.on('end',function () {
//  console.log(data);
// })
//
// readStream.on('err',function () {
//     console.log(err.stack);
// });
//
//
// console.log("程序执行完毕");

// /* 写入流 非阻塞*/
// var fs = require('fs');
// data = 'HelloWorld';
//
// var write = fs.createWriteStream('input.txt');
//
// write.write(data,'UTF-8');
//
// write.end();//标记文件末尾
//
// write.on('finish',function () {
//     console.log('写入完毕');
// })
//
// write.on('error',function () {
//     console.log(err.stack);
// })
//
// console.log('执行完毕');


// /* 管道流 */
// var fs = require('fs');
//
// var read = fs.createReadStream('input.txt');
//
// var write = fs.createWriteStream('output.txt');
//
// read.pipe(write); //read ——管道——>  write，所读内容流到（写到）write对应的文件中
//
// console.log('读写完毕');



