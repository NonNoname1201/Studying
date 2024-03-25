<?php

namespace klasy;

use DateTime;

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