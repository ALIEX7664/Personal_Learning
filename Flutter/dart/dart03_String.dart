main(List<String> args) {
  // 字符串可以使用Python多行字符串的输出格式
  // 可以是单引号和双引号
  // 可直接使用 == 比较
  String str1 = """
  Hello World
  Aliex
  """;

  String str2 = '''
  Hello 
  Aliex
  ''';

  print(str1);
  print(str2);

  // 可以使用模板语言${},单个变量时可以省略{}

  String a = "Aliex";
  String str3 = "This is ${a} , $a";
  print(str3);

  // 不止输出变量时{}必须被加上
  String str4 = "${a.toUpperCase()}";
  print(str4);


  // 与Python类似,可在字符串前加上'r',来创建字符串,使字符串特殊字符无需转义
  String dir1 = 'E:\/Person'; 
  String dir2 = r'E:/Person'; //加'r'后无需转义
  print(dir1);
  print(dir2);
}