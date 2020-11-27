<?php
    // 可变函数
    // 随值的变化调用不同的函数，与可变变量相似
    function a(){
        echo 'a<br>';
    }
    function b($string = 'default'){
        echo "$string <br>";
    }


    $func = 'a';
    $func();

    $func = 'b';
    $func();
    $func('b');

?>