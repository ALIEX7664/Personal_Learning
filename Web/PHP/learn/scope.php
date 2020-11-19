<?php
    // 局部作用域,作用域在函数中
    function toPrint(){
        $x = "Local scope";
        echo "scope".$x;
    }
    
    if($x){
        echo "get".$x;
    }

    // // 全局作用域,函数无法获取全局作用域的变量(error)
    // $x = "Global scope";
    // function toPrint_2(){
    //     if($x){
    //         echo $x;
    //     }
    // }
    // toPrint_2();
?>