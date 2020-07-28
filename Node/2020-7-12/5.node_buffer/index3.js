const { Console } = require("console")

//创建缓冲区 - 不初始化,不安全，数据泄露
let bf = Buffer.allocUnsafe(10)
console.log(bf)

bf[0] = '1'

console.log(bf)
console.log(bf.toString())
console.log(bf[0].toString())
