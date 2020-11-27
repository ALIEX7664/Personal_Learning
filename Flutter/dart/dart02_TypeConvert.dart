// final 运行时确定
// const 编译时确定
// 均为常量类型

main(List<String> args) {
  final pi = 3.14;
  const a = 2;

// 正确获取时间,运行时获得
  final time = new DateTime.now();
  print(time);


// String => int
  var one = int.parse('1');
// String => double
  var point = double.parse('3.14');

// int => String
  String str1 = 1234.toString();
// double => String
  String str2 = 123.213.toStringAsFixed(2);
  
}
