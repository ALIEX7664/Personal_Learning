<?php
    // foreach循环
    // 仅适用于数组和对象

    // 1. 值
    $arr = ['a','b','c'];

    foreach($arr as $val){
        echo $val."<br>";
    }

    echo "<hr>";

    // 2. 键值 => 值
    foreach ($arr as $key => $val){
        echo $key.":".$val."<br>";
    }

    echo "<hr>";

    // 3.PHP5和PHP7区别
    // PHP5内部指针会向后移动一个单元
    // PHP7内部指针不移动
    $arr = [0, 1, 2];
    foreach ($arr as $val){
    var_dump(current($arr));
    }
    echo "<br>";
    // PHP7中是对数组的复制操作
    // PHP5对数组修改会产生影响
    foreach ($arr as $val) {
        var_dump($val);
        // 销毁变量
        unset($arr[1]);
    }
    echo "<br>";
    // PHP7中增值操作会产生影响
    // PHP5则不变
    $arr = [0];
    foreach ($arr as &$val) {
        var_dump($val);
        $arr[1] = 1;
        $arr[2] = 2;
        $arr[3] = 3;
    }



    

    

?>