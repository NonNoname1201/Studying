<?php
/*Na stronie testLogin.php (pamiętaj o pobraniu plików z definicją odpowiednich klas) na
początku należy sprawdzić, czy rzeczywiście w tabeli logged_in_users istnieje wpis z id
bieżącej sesji.
Jeśli taki wpis istnieje:
 dodaj link do wylogowania (processLogin.php?akcja=wyloguj);
 wyświetl na stronie dane użytkownika z tabeli users o identyfikatorze
pobranym z tabeli logged_in_users dla bieżącej sesji (Rys. 8.3).
Jeśli taki wpis nie istnieje – przekieruj użytkownika ponownie do strony z formularzem
logowania (processLogin.php).*/

include_once 'klasy/Baza.php';
include_once 'klasy/User.php';
include_once 'klasy/UserManager.php';

echo '<a href="processLogin.php?akcja=wyloguj">Wyloguj</a><br>';

$db = new mysqli('localhost', 'root', '', 'users');
$um = new UserManager();

$sessionId = session_id();
$userId = $um->getLoggedInUser($db, $sessionId);

if ($userId > 0) {
    $sql = "SELECT * FROM users WHERE user_id='$userId'";
    echo $db->select($sql, ['userName', 'fullName', 'email', 'date', 'status']);
} else {
    header("Location: processLogin.php");
}

if (filter_input(INPUT_GET, "akcja") == "wyloguj") {
    $um->logout($db);
    header("Location: processLogin.php");
}

?>