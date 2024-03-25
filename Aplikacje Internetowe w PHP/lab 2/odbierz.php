<?php

//b) W skrypcie odbierz.php wyświetl dane przesłane z formularz.html (Rys.2.2).
//Pamiętaj o ustawieniu odpowiednich atrybutów action='odbierz.php' i method
//w znaczniku form dokumentu formularz.html (Wykład 1, część 2). Przetestuj
//działanie metody GET i POST. Zastosuj narzędzia dostępne w przeglądarce w celu
//podglądu przesyłanych żądań z danymi z formularza. Zauważ, że w tablicy
//$_REQUEST znajdują się parametry przesyłane zarówno metodą GET, jak i POST.
//Zamiast korzystać z tablicy $_REQUEST, można również sięgnąć osobno do
//parametrów przesłanych metodą GET (tablica $_GET) czy POST (tablica $_POST).
//UWAGA!
//Skrypt, który odczytuje parametry przesłane w żądaniu HTTP, na początek powinien
//sprawdzać ich istnienie. Do tego celu skorzystaj z funkcji isset(), która sprawdza, czy
//parametr istnieje w odpowiedniej tablicy i czy jego wartość jest różna od NULL. Przy
//odczytywaniu danych pobranych z pól tekstowych pamiętaj o odpowiednim wykorzystaniu
//funkcji trim() i htmlspecialchars(). Fragment kodu z Listingu 2.1 przedstawia prawidłowe
//wykorzystanie niezbędnych funkcji.
//Listing 2.1. Przykładowy kod skryptu odbierającego dane z żądania HTTP
// <div>
// <h2>Dane odebrane z formularza:</h2>
// <?php
// if (isset($_REQUEST['nazw'])&&($_REQUEST['nazw']!="")) {
// $nazwisko = htmlspecialchars(trim($_REQUEST['nazw']));
//13
//Zintegrowany Program Rozwoju Politechniki Lubelskiej – część druga
// echo "Nazwisko: $nazwisko <br />";
// }
// else echo "Nie wpisano nazwiska <br />";
// //pozostałe instrukcje pobierające dane wysłane
// //z formularza w postaci parametrów żądania
// //...
//
// </div>

//read all parameters from request
if (isset($_REQUEST['login']) && ($_REQUEST['login'] != "")) {
    $nazwisko = htmlspecialchars(trim($_REQUEST['login']));
    echo "Nazwisko: $nazwisko <br />";
} else echo "Nie wpisano nazwiska <br />";
if (isset($_REQUEST['pass']) && ($_REQUEST['pass'] != "")) {
    $wiek = htmlspecialchars(trim($_REQUEST['pass']));
    echo "Wiek: $wiek <br />";
} else echo "Nie wpisano wieku <br />";
//country is select, so we need to check if it is set and not empty

if (isset($_REQUEST['country']) && ($_REQUEST['country'] != "")) {
    $kraj = htmlspecialchars(trim($_REQUEST['country']));
    echo "Kraj: $kraj <br />";
} else echo "Nie wybrano kraju <br />";

if (isset($_REQUEST['email']) && ($_REQUEST['email'] != "")) {
    $email = htmlspecialchars(trim($_REQUEST['email']));
    echo "Email: $email <br />";
} else echo "Nie wpisano emaila <br />";

//check if checkbox is checked



?>