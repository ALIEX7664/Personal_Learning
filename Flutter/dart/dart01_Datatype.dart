
// 1.
// void main(){
//   print("Hello World");
// }


// 2. 省略void
// main(){
//   print("Hello World");
// }

// 3. 箭头函数
// main() => print("Hello World");

// 4. 带参传入
main(List<String> args) {
  print(args);

  var msg = 'hello';
  num number = 1;
  String str = "world";
  // 变量赋值后类型不能更改，否则出错，var也一样
  // 可以声明为dynamic/Object更改数据类型

  dynamic dyn = 'hello';  //编译阶段不检查类型
  dyn = 123;
  Object  obj = 123;   //所有类型的基类型，一切基于对象，编译阶段检查类型
  obj = '1234';
  
  
}