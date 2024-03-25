<?php
function dodaj($login, $pass, $country, $email, $jezyki, $paymentmethod)
{
    $file = fopen("dane.txt", "a");

    $langs = implode(", ", $jezyki);

    $line = "$login, $pass, $country, $email, $langs, $paymentmethod\n";
    fwrite($file, $line);
    fclose($file);
}

function pokaz()
{
    $file = fopen("dane.txt", "r");
    while (!feof($file)) {
        $line = fgets($file);
        echo $line . "<br>";
    }
    fclose($file);
}

function pokaz_zamowienie($lang)
{
    $file = fopen("dane.txt", "r");
    while (!feof($file)) {
        $line = fgets($file);
        $langs = explode(", ", $line);
        if (in_array($lang, $langs)) {
            echo $line . "<br>";
        }
    }
    fclose($file);
}

function statystyki(){
    $file = fopen("dane.txt", "r");
    $count = 0;
    $countLess18 = 0;
    $countMoreEqual50 = 0;
    while (!feof($file)) {
        $line = fgets($file);
        $langs = explode(", ", $line);
        $count++;
        if ($langs[1] < 18) {
            $countLess18++;
        }
        if ($langs[1] >= 50) {
            $countMoreEqual50++;
        }
    }
    fclose($file);
    echo "Liczba zamówień: $count<br>";
    echo "Liczba zamówień osób poniżej 18 roku życia: $countLess18<br>";
    echo "Liczba zamówień osób powyżej 49 roku życia: $countMoreEqual50<br>";
}