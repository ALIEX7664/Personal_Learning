main(List<String> args) {
  // bool
  bool boolean; 
  print(boolean); //默认值为null

  bool boolean1 = true;
  print(boolean1);

  // list 
  var list = [1,2,3];
  list.add(4);
  print(list);

  //将list定义为不可修改对象
  var list1 = const [1,2];
}