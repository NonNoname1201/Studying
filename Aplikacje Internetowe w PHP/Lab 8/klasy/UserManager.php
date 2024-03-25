<?php

class UserManager
{
    /*/*twórz pomocniczą klasę do zarządzania logowaniem UserManager, która
zawiera metodę loginForm() do wyświetlenia formularza logowania oraz
metody login($db), logout($db) i getLoggedInUser($db, $id) (Listing 8.2):
 metoda login($db) najpierw filtruje dane przesłane z formularza logowania,
a następnie sprawdza, czy dany użytkownik znajduje się w tabeli users
w bazie, do której uchwyt jest podany za pomocą parametru $db. Jeżeli
dane logowania są poprawne - metoda rozpoczyna sesję, czyści wszystkie
wpisy historyczne logowania w tabeli logged_in_users dla danego
użytkownika oraz zapisuje aktualne dane logowania do tabeli
logged_in_users . Metoda zwraca w wyniku id zalogowanego użytkownika
lub -1.
 metoda logout($db) usuwa z tabeli logged_in_users rekord z id bieżącej
sesji oraz likwiduje sesję.
 metoda getLoggedInUser($db, $sessionId) sprawdza, czy użytkownik się
zalogował - jako parametr przyjmuje id sesji i sprawdza czy dla tego id
istnieje wpis w tabeli logged_in_users. Zwraca id zalogowanego
użytkownika lub -1. * /
//    public function loginForm()
//    {
//        echo '<form action="index.php" method="post">
//        <fieldset>
//        <legend>Logowanie</legend>
//        <label for="login">Login:</label>
//        <input type="text" name="login" id="login" required><br>
//        <label for="passwd">Hasło:</label>
//        <input type="password" name="passwd" id="passwd" required><br>
//        <input type="submit" name="submit" value="Zaloguj">
//        </fieldset>
//        </form>';
//    }
//    public function login($db)
//    {
//        $login = filter_input(INPUT_POST, 'login', FILTER_SANITIZE_FULL_SPECIAL_CHARS);
//        $passwd = filter_input(INPUT_POST, 'passwd', FILTER_SANITIZE_FULL_SPECIAL_CHARS);
//        $sql = "SELECT * FROM users WHERE login='$login' AND passwd='$passwd'";
//        if ($result = $db->query($sql)) {
//            $row = $result->fetch_object();
//            $result->close();
//            return $row->id;
//        } else return -1;
//    }
//    public function logout($db)
//    {
//        $sessionId = session_id();
//        $sql = "DELETE FROM logged_in_users WHERE session_id='$sessionId'";
//        $db->query($sql);
//        session_destroy();
//    }
//    public function getLoggedInUser($db, $sessionId)
//    {
//        $sql = "SELECT * FROM logged_in_users WHERE session_id='$sessionId'";
//        if ($result = $db->query($sql)) {
//            $row = $result->fetch_object();
//            $result->close();
//            return $row->user_id;
//        } else return -1;
//    }
*/
    function loginForm()
    {
        echo '
        <h3>Formularz logowania</h3><p>
        <form action="processLogin.php" method="post">
            <label for="login">Login:</label>
            <input type="text" name="login" id="login" required/><br/>
            <label for="passwd">Hasło:</label>
            <input type="password" name="passwd" id="passwd" required/><br/>
            <input type="submit" value="Zaloguj" name="zaloguj"/>
        </form></p>';
    }

    function login($db)
    {
        $args = [
            'login' => FILTER_SANITIZE_MAGIC_QUOTES,
            'passwd' => FILTER_SANITIZE_MAGIC_QUOTES
        ];
        $dane = filter_input_array(INPUT_POST, $args);

        $login = $dane["login"];
        $passwd = $dane["passwd"];
        $userId = $db->selectUser($login, $passwd, "users");
        if ($userId >= 0) {
            session_start();
            $sessionId = session_id();
            $sql = "DELETE FROM logged_in_users WHERE user_id='$userId'";
            $db->delete($sql);
            $date = date("Y-m-d H:i:s");
            $sql = "INSERT INTO logged_in_users VALUES ('$sessionId', '$userId', '$date')";
            $db->insert($sql);
        }
        return $userId;
    }

    function logout($db)
    {
        //pobierz id bieżącej sesji (pamiętaj o session_start()
        //usuń sesję (łącznie z ciasteczkiem sesyjnym)
        //usuń wpis z id bieżącej sesji z tabeli logged_in_users

        session_start();
        $sessionId = session_id();
        session_destroy();
        $sql = "DELETE FROM logged_in_users WHERE session_id='$sessionId'";
        $db->delete($sql);

    }

    function getLoggedInUser($db, $sessionId)
    {
        //wynik $userId - znaleziono wpis z id sesji w tabeli logged_in_users
        //wynik -1 - nie ma wpisu dla tego id sesji w tabeli logged_in_users
        $userId = -1;
        $sql = "SELECT * FROM logged_in_users WHERE session_id='$sessionId'";
        if ($result = $db->query($sql)) {
            $row = $result->fetch_object();
            $result->close();
            $userId = $row->user_id;
        }
        return $userId;
    }
}