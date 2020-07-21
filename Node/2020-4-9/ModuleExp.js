var hello = require('./printHellow')    //调用js文件

hello.print();//使用提供的外部结构名称访问函数


var hello = require('./Hellow');    //调用js的外部接口，外部接口绑定了Hellow（）函数（类似Java里的类）

var say = new hello();  //调用方法

say.setName('Aliex');
say.sayHello();

console.log('End')