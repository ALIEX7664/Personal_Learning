// 字面量创建MAP
var args = {'first': 'aliex', 'second': 'alex', 'third': 'aruiy'};

main(List<String> args) {
  // 类构造函数创建Map
  var args1 = new Map();
  args1["first"] = 'o';
  args1["second"] = 'i';
  args1["third"] = 'u';

// 获取长度
  print(args1.length);

// 输出键值对
  print(args1["third"]);
  print(args1["forth"]);
}
