<?php

session_destroy();

$user = unserialize($_SESSION['user']);

echo "<br>";

echo session_id();
echo "<br>";
foreach ($_SESSION as $key => $value) {
    echo $key . " " . $value . "<br>";
}
echo "<br>";
foreach ($_COOKIE as $key => $value) {
    echo $key . " " . $value . "<br>";
}
echo "<br>";

echo "<a href='test2.php'>test2.php</a>";
?>

