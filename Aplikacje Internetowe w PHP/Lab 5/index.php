<?php

use klasy\RegistrationForm;
use klasy\User;

include_once('klasy/User.php');
include_once('klasy/RegistrationForm.php');

$user = new User('user1', 'Jan Kowalski', 'temp@temp.com', '1234');
$user->show();
echo '<br>';

$rf = new RegistrationForm(); //wyświetla formularz rejestracji
if (filter_input(INPUT_POST, 'submit',
    FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
    $user = $rf->checkUser(); //sprawdza poprawność danych
    if ($user === NULL)
        echo "<p>Niepoprawne dane rejestracji.</p>";
    else {
        echo "<p>Poprawne dane rejestracji:</p>";
        $user->show();
    }
}

$user->save('users.json');
User::getAllUsers('users.json');
?>



