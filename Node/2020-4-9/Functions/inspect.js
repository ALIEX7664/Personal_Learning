/*
util.inspect(object,[showHidden],[depth],[colors]) 是一个将任意对象转换 为字符串的方法，通常用于调试和错误输出。
它至少接受一个参数 object，即要转换的对象。
showHidden 是一个可选参数，如果值为 true，将会输出更多隐藏信息。
depth 表示最大递归的层数，如果对象很复杂，你可以指定层数以控制输出信息的多 少。
如果不指定depth，默认会递归 2 层，指定为 null 表示将不限递归层数完整遍历对象。
 如果 colors 值为 true，输出格式将会以 ANSI 颜色编码，通常用于在终端显示更漂亮 的效果。
特别要指出的是，util.inspect 并不会简单地直接把对象转换为字符串，即使该对象定义了toString 方法也不会调用。
 */

var util = require('util');

function Person() {
    this.name ='Aliex';
    this.toString = function () {//输出内容信息，而不是去调用
        console.log(this.name);
    }
}

var obj = new Person();
console.log(util.inspect(obj));
console.log(util.inspect(obj,true));
console.log(util.inspect(obj,true,2,true));



