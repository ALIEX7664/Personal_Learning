<?php
// String
    echo "String:<br>";
    // 双引号
    $str1 = 'Hello World';
    // 单引号
    $str2 = "Hello jianpang";
    // Heredoc -- <<<开始，通过一个符号包裹要输出的多行语句
    $str3 = <<<EOF

    url:
    http://aliexzyp.com
EOF;
// 输出语句
    echo $str1."<br>".$str2."<br>".$str3."<hr>";



// Interger
    echo "Interger:<br>";
    $x = 123;
    // 抛出类型和数值
    var_dump($x);
    echo "<br>";
    $x = -123;
    var_dump($x);
    echo $x."<br>";
    $x = 0x8A;
    var_dump($x);
    echo "<br>";
    $x = 047;
    var_dump($x);
    echo "<br>";

    // PHP7中16进制字符串不会自动转换为数字
    var_dump("0x123" == "291");
    echo "<br/>";
    var_dump(is_numeric("0x123"));
    echo "<br/>";
    // 16进制拼接在PHP7中报错:
    // A non well formed numeric value encountered
    var_dump("0xD" + "0x1");
    echo "<hr>";

// Float

    echo "Float:<br>";
    // 1.8E-308 到 1.8E+308 之间
    $num1 = 12.123;
    $num2 = 2.4e3;
    $num3 = 8E-5;
    var_dump($num1,$num2,$num3);
    echo "<hr>";

//Boolean

    echo "Boolean:<br>";
    // 不区分大小写
    $x = True;
    $y = FaLsE;
    var_dump($x,$y);
    echo "<hr>";

// Array

    echo "Array:<br>";
    // index
    $arr = array('wesite','url');
    var_dump($arr);
    echo "<br>";
    // key
    $arr = array('wesite'=>'Aliex','url'=>'aliexzyp.com');
    var_dump($arr);

    echo "<br>"."key:url -- ".$arr["url"];
    echo "<hr>";

// Object
    
    echo "Object:<br>";
    class Car{
        var $color;
        var $lol;

        // 构造函数，函数名不区分大小写
        function car($color="black",$lol){
            $this->color = $color;
            $this->lol = $lol;
        }

        function getColor(){
            return $this->color;
        }

        function getLol(){
            return $this->lol;
        }
    }

    // 创建时调用构造函数
    $car = new Car("red","aliex");
    // 显式调用构造函数
    $car -> car("yellow","ARUIY");
    echo "Color:<br>".$car->getColor()."<br>".$car->getLol();
    echo "<hr>";

// NULL

    echo "NULL:<br>";
    $str = 'ALIEX';
    $str = NULL;
    var_dump($str);
    echo "<hr>";

// Resource

    echo "Resource:<br>";
    header("content-type:text/html;charset=utf-8");//设置编码，解决中文乱码
    $file = fopen("test.txt", "rw");//打开test.txt文件
    var_dump($file);
    
?>