<?php
/*Zadanie 7.3. Mechanizm działania sesji
Zmienne sesyjne w języku PHP są umieszczane w specjalnej tablicy asocjacyjnej
$_SESSION i są dostępne dla wszystkich stron należących do danej domeny. Możemy z nich
korzystać np. w celu przekazywania informacji pomiędzy stronami czy w celu
uwierzytelnienia użytkownika.
a) Przetestuj mechanizm działania sesji wykonując następujący skrypt umieszczony na
stronie test1.php:
session_start();
$_SESSION['username'] = 'kubus';
$_SESSION['fullname'] = 'Kubus Puchatek';
$_SESSION['email'] = 'kubus@stumilowylas.pl';
$_SESSION['status'] = 'ADMIN';
b) Następnie na stronie test1.php (Rys.7.1):
 wyświetl id sesji,
 wyświetl wszystkie zmienne sesji (skorzystaj z pętli foreach i tablicy
$_SESSION),
 wyświetl ciasteczka skojarzone z domeną localhost (zastosuj pętlę foreach dla
tablicy $_COOKIE),
 umieść link do kolejnej strony test2.php.
c) Korzystając z narzędzi deweloperskich dostępnych w przeglądarce - przejrzyj, jakie
ciasteczka (pasek narzędzi deweloperskich i zakładka Application) zostały utworzone
po uruchomieniu skryptu test1.php (Rys. 7.1).
d) Przejrzyj zawartość folderu xampp/tmp (w przypadku XAMPP lub odpowiednio
inny) i znajdź plik przechowujący zmienne utworzonej sesji (nazwa pliku zawiera id
sesji, np. w niniejszym przykładzie nazwa pliku to:
sess_50he1lkqhhc34onugi1mg9l89o). Przejrzyj jego zawartość.
e) Na stronie test2.php (Rys. 7.2):
 wyświetl id sesji i wszystkie zmienne sesji,
 wykonaj usunięcie sesji (funkcja session_destroy()),
 umieść link powrotny do strony test1.php.
 sprawdź czy id sesji jest taki sam jak na stronie test1.php i czy istnieje ciasteczko
sesyjne z tym samym id (dostępne ze strony test2).
f) Skorzystaj z linku powrotnego do strony test1.php i sprawdź, czy został zmieniony id
sesji po wykonaniu funkcji session_destroy() na stronie test2. Co należy zrobić, aby
„zabić” sesję (sprawdź w materiałach wykładowych)*/

/*Zadanie 7.4. Przechowywanie obiektu w zmiennej sesji
Zmodyfikuj działanie skryptów ze stron test1 i test2. Zamiast tworzyć 4 zmienne sesji, jak
w punkcie 7.3a) - utwórz obiekt user klasy User i zapamiętaj go w zmiennej sesji pod
kluczem "user" (zobacz przykład z wykładu).
Wyświetl właściwości obiektu user zapamiętanego w sesji na stronie test2.php. Pamiętaj
o konieczności skorzystania z funkcji serialize i unserialize. Efekt działania powinien być
analogiczny do tego z rys. 7.1 i 7.2.*/

use klasy\RegistrationForm;

session_start();
//$_SESSION['username'] = 'kubus';
//$_SESSION['fullname'] = 'Kubus Puchatek';
//$_SESSION['email'] = 'kubus@stumilowylas.pl';
//$_SESSION['status'] = 'ADMIN';

require_once("klasy/User.php");
require_once("klasy/RegistrationForm.php");

$rf = new RegistrationForm();
if (filter_input(INPUT_POST, 'submit',
    FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
    $user = $rf->checkUser();
    if ($user === NULL)
        echo "<p>Niepoprawne dane rejestracji.</p>";
    else {
        echo "<p>Poprawne dane rejestracji:</p>";
        $user->show();
    }
}

$_SESSION['user'] = serialize($user);

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
