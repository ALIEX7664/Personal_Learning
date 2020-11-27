<?php
    // 严格模式,要求传入参数类型要与函数一致，否则出错
    // 不指定时php会产尝试自动转换类型
    declare(strict_types = 1);
    function test(int $a,int $b, string $c){
        echo ($a + $b);
        echo "the string is $c";
    }

    // test(3.8,3,"hello");
    test(3,3,"hello");
?>