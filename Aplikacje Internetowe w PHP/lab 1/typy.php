<?php
//W kolejnym skrypcie (np. typy.php) utwórz zmienne o następujących wartościach:
//- 1234
//- 567.789
//- 1
//- 0
//- true
//- "0"
//- "Typy w PHP"
//- [1, 2, 3, 4]
//- []
//- ["zielony", "czerwony", "niebieski"]
//- ["Agata", "Agatowska", 4.67, true]
//- obiekt DateTime z bieżącą datą (https://www.php.net/manual/en/class.datetime.php).
//11
//Zintegrowany Program Rozwoju Politechniki Lubelskiej – część druga
//a) Wyświetl nazwy i wartości poszczególnych zmiennych (dla tablic skorzystaj z funkcji
//count() do uzyskania liczby elementów tablicy).
//b) Sprawdź na wybranych zmiennych działanie następujących funkcji: is_bool(), is_int(),
//is_numeric(), is_string(), is_array(), is_object().
//c) Porównaj zmienne o wartościach 1 i true oraz 0 i "0", za pomocą operatorów „==”
//oraz „===”. Wyświetl wynik porównania we wszystkich przypadkach.
//d) Dla tablic sprawdź jakie jest działanie pomocniczych funkcji var_dump() i print_r(),
//które wyświetlają informacje o zmiennych. Funkcje te są bardzo użyteczne na etapie
//testowania działania kodu skryptów.

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
if(is_bool($bool)){
    print("Zmienna bool jest typu bool<br>");
}
else{
    print("Zmienna bool nie jest typu bool<br>");
}

if(is_bool($z)){
    print("Zmienna z jest typu bool<br>");
}
else{
    print("Zmienna z nie jest typu bool<br>");
}

if(is_int($n)){
    print("Zmienna n jest typu int<br>");
}
else{
    print("Zmienna n nie jest typu int<br>");
}

if(is_int($str)){
    print("Zmienna str jest typu int<br>");
}
else{
    print("Zmienna str nie jest typu int<br>");
}

if(is_numeric($x)){
    print("Zmienna x jest typu numeric<br>");
}
else{
    print("Zmienna x nie jest typu numeric<br>");
}

if(is_string($str)){
    print("Zmienna str jest typu string<br>");
}
else{
    print("Zmienna str nie jest typu string<br>");
}

if(is_array($arr)){
    print("Zmienna arr jest typu array<br>");
}
else{
    print("Zmienna arr nie jest typu array<br>");
}

if(is_object($date)){
    print("Zmienna date jest typu object<br>");
}
else{
    print("Zmienna date nie jest typu object<br>");
}

print("<br><br>");

//c
if($y == $bool){
    print("Zmienna y jest równa zmiennej bool<br>");
}
else{
    print("Zmienna y nie jest równa zmiennej bool<br>");
}

if($z == $str){
    print("Zmienna z jest równa zmiennej str<br>");
}
else{
    print("Zmienna z nie jest równa zmiennej str<br>");
}

if($y === $bool){
    print("Zmienna y jest identyczna ze zmienną bool<br>");
}
else{
    print("Zmienna y nie jest identyczna ze zmienną bool<br>");
}

if($z === $str){
    print("Zmienna z jest identyczna ze zmienną str<br>");
}
else{
    print("Zmienna z nie jest identyczna ze zmienną str<br>");
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


