const crypto = require('crypto')

const hash = crypto.createHash('md5')

hash.update('crypto')
hash.update('Hello')

//加密后查看加密结果,内容不变结果相同
console.log(hash.digest('hex'))