// 1.带数据类型
String greet(String name) {
  return "hello,$name";
}

// 2.不带数据类型，默认dynamic
greet1(String name) {
  return "hello world,$name";
}

// 3.调用时传参需使用“参数名：值”形式传递
add({int a, int b = 0}) {
  print(a + b);
}

// 4.可选参数形式
// []内的参数可传可不传
add_3(int x, [int y, int z]) {
  int result = x;
  if (y != null) {
    result += y;
  }
  if (z != null){
    result += z;
  }
 print(result);
}

main(List<String> args) {
  add(a: 10);
  add(a: 12, b: 3);

  add_3(3);
  add_3(3,4);
  add_3(3,4,5);
}
