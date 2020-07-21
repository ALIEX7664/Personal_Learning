function Hello() {
    var str;

    this.setName = function (name) { //this让方法被自身调用
        str = name;
    }

    this.sayHello = function () {
        console.log('Hello' + str);
    }
}
module.exports = Hello;