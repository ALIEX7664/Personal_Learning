var  util = require('util');

function Base() {
    this.name ='Aliex';
    this.base = '1991';
    this.sayHello = function () {
        console.log('Hello' + this.name);
    }
}

Base.prototype.showName = function () {
    console.log(this.name);
}

function Sub() {
    this.name = 'sub';
}
//inherits(继承，被继承)，只继承被声明为原型的函数prototype.functionName
util.inherits(Sub,Base);
var obj = new Base();
obj.showName();
obj.sayHello();
console.log(obj);
var objs = new Sub();
objs.showName();
// objs.sayHello();
console.log(objs);
