//1.声明变量与变量类型let x: type
var a;
//只能是Number值
a = 10;
// a="hello"; //报错
//2.类型声明并赋值
var b = "hello";
//3.不声明使用其他类型也会报错
var c = false;
// c = 1; //报错
//4.函数提前类型声明
function sum(a, b) {
    return a + b;
}
sum(1, 2);
var add = sum(3, 4); //add为number类型
//JS不报错且正常执行
// sum(1,"2"); //报错
// sum(a,b); //报错
// sum(1,2,3) //报错
// sum(1,) //报错
