<?php
// 可变变量
// 取值方式类似于指针
// 根据$的个数获取对应的值

// 变量
// 1.先赋值
    $var1 = "Hello var1";
    $hello = "var1";   
    echo $$hello."<hr>";

// 2.后赋值
    $var2 = "msg";  
    $$var2  = "Send msg";
    echo $msg."<hr>";

// 3.多重
    $var3 = "Aliex";
    $username = "var3";
    $user = "username";
    echo $$$user."<br>".$$user."<br>".$$username."<hr>";

// 数组
// 1.数组=(变量...)
    $arr1 = array('test','web');
    $test = "First";
    $web = "Second";
    echo ${$arr1[0]}."<br>".${$arr1[1]}."<hr>";
// 2.$数组 = 数组
    $arr2 = array('Third',"Forth");
    $string = "arr2";
    echo ${$string}[0]."<br>".${$string}[1]."<hr>";



?>