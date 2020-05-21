// //1
// const buffer = Buffer.from('runnoob','ascii');
//
// console.log(buffer.toString('hex'));
// console.log(buffer.toString('base64'));
// console.log(buffer.toString('ascii'));
// console.log(buffer.toString('UTF-8'));
// console.log(buffer.toString('binary'));

// /*2
// *  Buffer.alloc(size[, fill[, encoding]])： 返回一个指定大小的 Buffer 实例，如果没有设置 fill，则默认填满 0
// *  Buffer.allocUnsafe(size)： 返回一个指定大小的 Buffer 实例，但是它不会被初始化，所以它可能包含敏感的数据
// *  Buffer.allocUnsafeSlow(size)
// *  Buffer.from(array)： 返回一个被 array 的值初始化的新的 Buffer 实例（传入的 array 的元素只能是数字，不然就会自动被 0 覆盖）
// *  Buffer.from(arrayBuffer[, byteOffset[, length]])： 返回一个新建的与给定的 ArrayBuffer 共享同一内存的 Buffer。
// *  Buffer.from(buffer)： 复制传入的 Buffer 实例的数据，并返回一个新的 Buffer 实例
// *  dBuffer.from(string[, encoding])： 返回一个被 string 的值初始化的新的 Buffer 实例*/
// const  buf1 = Buffer.alloc(10);
// const  buf6 = Buffer.alloc(10,1);
// console.log(buf1);
// console.log(buf6);
//
// const  buf2 = Buffer.allocUnsafe(20);
// console.log(buf2);
//
// const  buf3 = Buffer.allocUnsafeSlow(10);
// console.log(buf3);
//
// const  buf4 = Buffer.from([1,2,3]);
// console.log(buf4);
//
// const  buf5 = Buffer.from('test');
// console.log(buf5);
//
// const  buf7 = Buffer.from('test','latin1');//latin1专门将Buffer编码成一字节编码的字符串的方式
// console.log(buf7);


// /*3
// * buf.write(string[, offset[, length]][, encoding])
// * string - 写入缓冲区的字符串。
// * offset - 缓冲区开始写入的索引值，默认为 0 。
// * length - 写入的字节数，默认为 buffer.length
// * encoding - 使用的编码。默认为 'utf8' 。
// *
// *  如果 buf 没有足够的空间保存整个字符串，则只会写入 string 的一部分。 只部分解码的字符不会被写入。
// *  返回实际写入的大小。如果 buffer 空间不足， 则只会写入部分字符串。
// *
// * */
// const buf1 = Buffer.alloc(10);
// buf1.write('Hello');
// buf1.write('World',5,4,'ascii');
// console.log(buf1);


// /*4
// * buf.toString([encoding[, start[, end]]])
// * encoding - 使用的编码。默认为 'utf8' 。
// * start - 指定开始读取的索引位置，默认为 0。
// * end - 结束位置，默认为缓冲区的末尾。
// * 解码缓冲区数据并使用指定的编码返回字符串。
// *
// * */
//
// buf = Buffer.alloc(30);
// for (var i = 0 ; i < 26 ; i++) {
//     buf[i] = i + 97;
// }
// console.log(buf);
// console.log( buf.toString('ascii'));       // 输出: abcdefghijklmnopqrstuvwxyz
// console.log( buf.toString('ascii',0,5));   //使用 'ascii' 编码, 并输出: abcde
// console.log( buf.toString('utf8',0,5));    // 使用 'utf8' 编码, 并输出: abcde
// console.log( buf.toString(undefined,0,5)); // 使用默认的 'utf8' 编码, 并输出: abcde




