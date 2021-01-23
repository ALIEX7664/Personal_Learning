//特殊类型不要用类型限定,无意义
//1 . Object
//常用TS 对象声明,? - 表示属性可选
var a;
// 结构与对象需一模一样
a = { name: 'aliex', age: 13 };
// 声明属性名为string类型,其属性值为任意类型,[]可以有多个键值
var b;
b = { name: 'aliex', age: 13, gender: 'male' };
//2 . Function
//函数类型限定
var fn;
fn = function (a1, a2) {
    return a1 + a2;
};
fn = function (num1, num2) {
    return num1 + num2;
};
//3 . Array
// 数组类型限定
var arr1;
// 另一种方法，类似Java泛型限定
var arr2;
// 元组 - 固定长度的数组,效率高,长度短
var arr3;
//4. Enum
//枚举由TS自动生成相应的值或手动编写，在编写时可以采用命名来编写
var Gender;
(function (Gender) {
    Gender[Gender["Mail"] = 0] = "Mail";
    Gender[Gender["FeMail"] = 1] = "FeMail";
})(Gender || (Gender = {}));
//在编写时自动匹配
var enumobj = {
    name: 'ALiex',
    gender: Gender.FeMail
};
