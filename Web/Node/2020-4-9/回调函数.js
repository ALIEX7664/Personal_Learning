//
// /* 阻塞调用 */
// var fs = require('fs');
//
// var data = fs.readFileSync('input.txt');
//
// console.log(data.toString());
// console.log('输出结束')
//
//
// /* 非阻塞调用 */
// fs.readFile('input.txt',function (err,data2) {
//     if(err) console.error(err);
//     console.log(data2.toString());
// });
//
// console.log('输出结束')