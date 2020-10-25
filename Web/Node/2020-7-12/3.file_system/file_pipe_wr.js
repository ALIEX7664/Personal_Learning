let fs = require('fs')

let rs = fs.createReadStream('Aliex.jpg')
let ws = fs.createWriteStream('ooO.jpg')

//创建管道，将读取流通过管道流过并写入
rs.pipe(ws)