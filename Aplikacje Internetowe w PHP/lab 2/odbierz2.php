<?php

/*Przygotuj i przetestuj kolejny skrypt odbierz2.php, który pokaże nazwy i wartości
wszystkich parametrów z globalnych tablic asocjacyjnych: $_GET, $_POST
i $_REQUEST. W tym celu wykorzystaj pętlę foreach postaci np.:
foreach($_REQUEST as $key=>$value) {
 echo "$key = $value <br />";
}*/

//read all parameters from request
for ($i = 0; $i < count($_REQUEST); $i++) {
    $key = array_keys($_REQUEST)[$i];
    $value = array_values($_REQUEST)[$i];
    echo "$key = $value <br />";
}

for ($i = 0; $i < count($_GET); $i++) {
    $key = array_keys($_GET)[$i];
    $value = array_values($_GET)[$i];
    echo "$key = $value <br />";
}

for ($i = 0; $i < count($_POST); $i++) {
    $key = array_keys($_POST)[$i];
    $value = array_values($_POST)[$i];
    echo "$key = $value <br />";
}
?>
