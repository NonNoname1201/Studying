<?php

namespace klasy;

/*W foderze klasy zdefiniuj kolejną klasę RegistrationForm (plik
RegistrationForm.php – Listing 5.3):
a) z polem chronionym $user klasy User,
b) z konstruktorem bezparametrowym, który wyświetla formularz zawierający
wszystkie niezbędne pola do rejestracji nowego użytkownika (Rys. 5.3).
c) z metodą checkUser(), która sprawdza, czy wszystkie niezbędne pola zostały
podane prawidłowo, a jeśli tak, to tworzy nowy obiekt $user, wypełniony
wartościami pobranymi z wypełnionego formularza. W tym celu zastosuj
funkcję walidacji i filtry podobnie jak w zadaniach z laboratorium 4. Jeśli dane
nie są prawidłowe, metoda ustawia $this->user=NULL. Jako wynik działania
metoda zwraca obiekt $this->user.

W pliku index.php (Listing 5.4) wyświetl formularz rejestracji a następnie zastosuj
metodę checkUser. Metoda zwróci utworzony na podstawie danych obiekt $user, gdy
wszystkie dane są poprawne lub NULL w przeciwnym razie.
3. W przypadku kiedy rejestracja będzie poprawna - poniżej formularza (Rys. 5.3)
wyświetl (za pomocą metody show()) dane nowego użytkownika. W przeciwnym
razie wyświetl komunikat: „Niepoprawne dane rejestracji”.*/

class RegistrationForm
{
    protected $user;

    function __construct()
    { ?>
        <h3>Formularz rejestracji</h3><p>
        <form action="index.php" method="post">
            Nazwa użytkownika: <br/><input name="userName"/><br/>
            //dodaj pozostałe pola formularza
        </form></p>
        <?php
    }

    function checkUser()
    {
        $args = [
            'userName' => ['filter' => FILTER_VALIDATE_REGEXP,
                'options' => ['regexp' => '/^[0-9A-Za-ząęłńśćźżó_-]{2,25}$/']],
        ];
        $dane = filter_input_array(INPUT_POST, $args);
        $errors = "";
        foreach ($dane as $key => $value) {
            if ($value === false or $value === NULL) {
                $errors .= $key . " ";
            }
        }

        if ($errors === "") {
            $this->user = new User($dane['userName'], $dane['fullName'], $dane['email'], $dane['passwd']);
        } else {
            echo "<p>Błędne dane:$errors</p>";
            $this->user = NULL;
        }
        return $this->user;
    }

    function getUser(){
        if ($this->user === NULL)
            echo "<p>Niepoprawne dane rejestracji.</p>";
        else {
            echo "<p>Poprawne dane rejestracji:</p>";
            $this->user->show();
        }
    }
}

