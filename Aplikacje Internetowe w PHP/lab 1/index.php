<!DOCTYPE html>
<html>
<head>
    <title>PHP Lab 2</title>
</head>
<body>
<?php

// Zadanie 1
$n = 4567;
$x = 10.123456789;

print("<h1 align='center'>Zadanie 1</h1>");

print("Domyślny format: " . $n . " " . $x . "<br>");
print("Zaokrąglenie do liczby całkowitej: " . round($x) . "<br>");
print("Zaokrąglenie do dwóch miejsc po przecinku: " . round($x, 2) . "<br>");

print("<br><br>");

// Zadanie 2
print("<a href='galeria.php'>Galeria</a><br><br>");

// Zadanie 3
print("<a href='typy.php'>Typy</a><br><br>");

?>
</body>
</html>