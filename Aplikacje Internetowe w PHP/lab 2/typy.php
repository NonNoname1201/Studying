<?php

$n = 1234;
$x = 567.789;
$y = 1;
$z = 0;
$bool = true;
$str = "0";
$str2 = "Typy w PHP";
$arr = [1, 2, 3, 4];
$arr2 = [];
$arr3 = ["zielony", "czerwony", "niebieski"];
$arr4 = ["Agata", "Agatowska", 4.67, true];
$date = new DateTime();

print("<h1 align='center'>Typy</h1>");

//a
print("Zmienna n: " . $n . "<br>");
print("Zmienna x: " . $x . "<br>");
print("Zmienna y: " . $y . "<br>");
print("Zmienna z: " . $z . "<br>");
print("Zmienna bool: " . $bool . "<br>");
print("Zmienna str: " . $str . "<br>");
print("Zmienna str2: " . $str2 . "<br>");
print("Zmienna arr: " . $arr . "<br>");
print("Zmienna arr2: " . $arr2 . "<br>");
print("Zmienna arr3: " . $arr3 . "<br>");
print("Zmienna arr4: " . $arr4 . "<br>");
print("Zmienna date: ");
print_r($date);
print("<br>");


print("<br><br>");

//b
//add all above variables to array
$all = [$n, $x, $y, $z, $bool, $str, $str2, $arr, $arr2, $arr3, $arr4, $date];
//using foreach loop check type of each variable using is_* functions

foreach ($all as $value) {
    print("Zmienna " . $value . " jest typu: ");
    if (is_int($value)) {
        print("int");
    } else if (is_float($value)) {
        print("float");
    } else if (is_bool($value)) {
        print("bool");
    } else if (is_string($value)) {
        print("string");
    } else if (is_array($value)) {
        print("array");
    } else if (is_object($value)) {
        print("object");
    } else if (is_null($value)) {
        print("null");
    } else {
        print("unknown");
    }
    print("<br>");
}



print("<br><br>");

//d
print("var_dump() dla zmiennej arr: ");
var_dump($arr);
print("<br>");
print("var_dump() dla zmiennej arr2: ");
var_dump($arr2);
print("<br>");
print("var_dump() dla zmiennej arr3: ");
var_dump($arr3);
print("<br>");
print("var_dump() dla zmiennej arr4: ");
var_dump($arr4);
print("<br>");
print("var_dump() dla zmiennej date: ");
var_dump($date);
print("<br>");

print("<a href='index.php'>Home</a><br><br>");


