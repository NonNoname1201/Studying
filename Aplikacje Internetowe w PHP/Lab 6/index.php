<?php
include_once("funkcje.php");
include_once "Baza.php";
include_once "BazaPDO.php";

//tworzymy uchwyt do bazy danych:
$bd = new Baza("localhost", "root", "", "klienci");
if (filter_input(INPUT_POST, "submit")) {
    $akcja = filter_input(INPUT_POST, "submit");
    switch ($akcja) {
        case "Dodaj" :
            dodajdoBD($bd);
            break;
        case "Pokaż" :
            echo $bd->select("select Nazwisko,Zamowienie
from klienci", ["Nazwisko", "Zamowienie"]);
            break;
    }
}

function dodajdoBD($bd)
{
    //pobierz dane z formularza, dokonaj ich walidacji
    //jeśli dane są poprawne - sformułuj zapytanie $sql typu insert np.:
    // INSERT INTO klienci VALUES (NULL, 'Babacka', '22', 'Niemcy',
    // 'bbbp@ollub.pl', 'Java,CPP', 'Przelew');
    //i wywołaj metodę:
    //$bd->insert($sql);
}


$login = 'ola';
$pass = 'ola123';

$stmt = $bd->prepare("INSERT INTO USERS (login, pass) VALUES (?, ?)");
$stmt->bindParam(1, $login);
$stmt->bindParam(2, $pass);
// dodanie jednego wiersza:
$login = 'ola';
$pass = 'ola123';
$stmt->execute();
// dodanie kolejnego wiersza z innymi wartościami:
$login = 'jasio';
$pass = 'jasio123';
$stmt->execute();

?>