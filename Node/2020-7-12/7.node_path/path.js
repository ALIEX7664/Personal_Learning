//当前正在执行脚本的文件名称
console.log(__filename)

//当前正在执行脚本目录名称
console.log(__dirname)

//路径模块
let path = require('path')

//路径'\'会被认定为是要转义的
let strPath = 'E:/LearningDemo/Node/2020-7-12/7.node_path/index.js'

//得到后缀扩展名
console.log(path.extname(strPath))
console.log(path.extname(__filename))

//获取文件名
console.log(path.basename(strPath))
console.log(path.basename(__filename))

//获取目录名
console.log(path.dirname(strPath))
console.log(path.dirname(__filename))

//根据操作系统进行路径解析-规范化
console.log(path.normalize(strPath))

//路径合并
console.log(path.join(__dirname+'/aliex.png'))

//路径合并
console.log(path.resolve(__dirname+'/aliex.png'))