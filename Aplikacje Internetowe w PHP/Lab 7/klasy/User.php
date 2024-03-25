<?php

namespace klasy;

use DateTime;

/*Zmodyfikuj aplikację utworzoną na laboratorium 5 – zamiast rejestrować użytkowników
z zapisem ich danych do pliku, dane rejestracyjne będziemy przechowywać w bazie danych
klienci w tabeli users. Korzystając z klas User, RegistrationForm i skryptu z formularzem
rejestracyjnym, do tabeli users dodamy kilku użytkowników.
W tym celu:
a) do klasy User dodaj dwie dodatkowe metody z parametrem $db (uchwyt do bazy
danych): saveDB($db) (zapis do tabeli users) i getAllUsersFromDB($db) (metoda
statyczna - pobiera i wyświetla dane wszystkich użytkowników z tabeli users). Do
operacji na bazie danych skorzystaj z klasy Baza z Lab. 6. Sama klasa Baza nie
wymaga już żadnych modyfikacji, należy tylko podać właściwe parametry połączenia
tworząc nowy obiekt klasy Baza oraz operować właściwymi parametrami metod
select() czy insert() klasy Baza. Zauważ ponadto, że parametrem metod insert(), czy
delete() w tej klasie jest tylko odpowiednio sformułowany łańcuch zapytania SQL
odpowiednio typu INSERT lub DELETE. Klasa Baza jest w pełni uniwersalna i nie
zależy od konkretnej nazwy bazy danych czy tabeli.
b) schemat skryptu index.php z formularzem rejestracyjnym pozostaje analogiczny jak
w zadaniu z laboratorium 5, tylko pamiętaj o dołączeniu klasy Baza oraz zmień
metodę zapisu nowego użytkownika i odczytu danych – zapis zrealizuj teraz do bazy
danych (metodą saveDB()) i odczyt z bazy danych (metodą getAllUsersFromDB()).
Sprawdź działanie skryptu index.php*/

class User
{
    static $STATUS_USER = 1;
    static $STATUS_ADMIN = 2;

    public $usrname;
    public $passwd;
    public $fullName;
    public $email;
    public $date;
    public $status;

    public function __construct($userName, $fullName, $email, $passwd)
    {
        $this->userName = $userName;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
        $this->date = new DateTime();
        $this->status = User::$STATUS_USER;
    }


    public function show()
    {
        echo "Nazwa użytkownika: " . $this->userName . "<br>";
        echo "Imię i nazwisko: " . $this->fullName . "<br>";
        echo "Adres e-mail: " . $this->email . "<br>";
        echo "Data utworzenia konta: " . $this->date->format('Y-m-d') . "<br>";
        echo "Status użytkownika: " . $this->status . "<br>";
    }

    static function getAllUsers($plik)
    {
        $tab = json_decode(file_get_contents($plik));
        foreach ($tab as $val) {
            $date = DateTime::createFromFormat('Y-m-d', $val->date);
            echo "<p>" . $val->userName . " " . $val->fullName . " " . $date->format('Y-m-d') . "</p>";
        }
    }

    public function toArray()
    {
        return [
            'userName' => $this->userName,
            'fullName' => $this->fullName,
            'email' => $this->email,
            'date' => $this->date->format('Y-m-d'),
            'status' => $this->status
        ];
    }

    public function save($plik)
    {
        $tab = json_decode(file_get_contents($plik));
        $tab[] = $this->toArray();
        file_put_contents($plik, json_encode($tab));
    }


    public function saveDB($db)
    {
        $sql = "INSERT INTO users (userName, fullName, email, passwd, date, status) VALUES ('" . $this->userName . "', '" . $this->fullName . "', '" . $this->email . "', '" . $this->passwd . "', '" . $this->date->format('Y-m-d') . "', '" . $this->status . "')";
        $db->insert($sql);
    }

    static function getAllUsersFromDB($db)
    {
        $sql = "SELECT * FROM users";
        $pola = ['userName', 'fullName', 'email', 'date'];
        echo $db->select($sql, $pola);
    }

    public function delete($db)
    {
        $sql = "DELETE FROM users WHERE userName='" . $this->userName . "'";
        $db->delete($sql);
    }

    public function update($db)
    {
        $sql = "UPDATE users SET fullName='" . $this->fullName . "', email='" . $this->email . "', passwd='" . $this->passwd . "', date='" . $this->date->format('Y-m-d') . "', status='" . $this->status . "' WHERE userName='" . $this->userName . "'";
        $db->update($sql);
    }





    public function setUserName($userName)
    {
        $this->userName = $userName;
    }

    public function getUserName()
    {
        return $this->userName;
    }

    public function getPasswd()
    {
        return $this->passwd;
    }

    public function setPasswd($passwd)
    {
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
    }

    public function getFullName()
    {
        return $this->fullName;
    }

    public function setFullName($fullName)
    {
        $this->fullName = $fullName;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function setEmail($email)
    {
        $this->email = $email;
    }

    public function getDate()
    {
        return $this->date->format('Y-m-d');
    }

    public function setDate($date)
    {
        $this->date = $date;
    }

    public function getStatus()
    {
        return $this->status;
    }

    public function setStatus($status)
    {
        $this->status = $status;
    }
}