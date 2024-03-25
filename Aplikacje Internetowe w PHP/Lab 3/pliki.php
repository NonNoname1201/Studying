<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="utf-8"/>
    <meta content="width=device-width, initial-scale=1.0" name="viewport"/>
    <title>Szybki kurs HTML</title>
    <link href="CSS/style.css" rel="stylesheet" type="text/css"/>
    <link href="CSS/formularze.css" rel="stylesheet" type="text/css"/>
</head>

<body>
<div id="baner">
    <h2>Szybki kurs HTML</h2>
</div>
<div id="menu">
    <ul id="nav">
        <li><a href="index.php">Podstawy</a></li>
        <li><a href="typy.php">Typy</a></li>
        <li><a href="galeria.php">Galeria</a></li>
    </ul>
</div>
</div>

<div>
    <h3><b>Przykladowy formularz HTML</b></h3>
    <form action="pliki.php" method="post">
        <table>
            <tr>
                <td>Nazwisko:</td>
                <td><input name="login" type="text"/></td>
            </tr>
            <tr>
                <td>Wiek:</td>
                <td><input name="pass" type="number"/></td>
            </tr>
            <tr>
                <td>Panstwo:</td>
                <td>
                    <select name="country" size="1">
                        <option value="Polska">Polska</option>
                        <option value="Niemcy">Niemcy</option>
                        <option value="Czechy">Czechy</option>
                        <option value="Szwecja">Szwecja</option>
                        <option value="Wielka Brytania">Wielka Brytania</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>Adres e-mail:</td>
                <td><input name="email" type="email"/></td>
            </tr>
        </table>
        <br/>
        <b>Zamawiam tutorial z języka:</b><br/><br/>
        <?php

        $langs = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];

        foreach ($langs as $lang) {
            echo "<input type='checkbox' name='jezyki[]' value='$lang'>$lang<br>";
        }

        ?>
        <b>Sposób zapłaty:</b><br/><br/>
        <input name="paymentmethod" type="radio" value="eurocard"/>eurocard
        <input name="paymentmethod" type="radio" value="visa"/>visa
        <input name="paymentmethod" type="radio" value="przelew bankowy"/>przelew bankowy<br/>
        <?php
        /*b) Po wyborze przycisku Zapisz - za pomocą funkcji dodaj(), dane z formularza należy
dopisać do pliku tekstowego dane.txt w lokalizacji domyślnej (na razie bez walidacji
danych po stronie serwera). Sprawdź, gdzie zapisał się plik dane.txt i przejrzyj jego
zawartość w dowolnym edytorze tekstowym. Najwygodniej jest dopisywać dane
z każdego żądania w postaci kolejnego wiersza (Rys. 3.2). Taki format zapisu umożliwia
łatwy dostęp do poszczególnych informacji. Zauważ, że poszczególne informacje
rozdzielone są znakiem spacji, natomiast dane o zamawianych tutorialach scalane są
w jeden łańcuch z separatorem przecinka (co będzie szczególnie ważne w przypadku
zapisu danych do bazy danych).
c) Po wyborze przycisku Pokaż - za pomocą funkcji pokaz() wyświetl wszystkie wiersze
z pliku dane.txt (Rys.3.3).
d) Po wyborze przycisków Java, PHP, CPP - za pomocą pomocniczej funkcji
pokaz_zamowienie - wyświetl tylko zamówienia na wskazane parametrem tutoriale.
*/

        include_once "funkcje.php";

        if (isset($_POST['submit'])) {
            if ($_POST['submit'] == "Wyślij") {
                dodaj($_POST['login'], $_POST['pass'], $_POST['country'], $_POST['email'], $_POST['jezyki'], $_POST['paymentmethod']);
            } else if ($_POST['submit'] == "Pokaż") {
                pokaz();
            } else if ($_POST['submit'] == "Statystyki") {
                statystyki();
            } else {
                pokaz_zamowienie($_POST['submit']);
            }
        }


        echo '<input type="submit" name="submit" value="Wyślij"/>';
        echo '<input type="reset" value="Anuluj"/>';
        echo '<input type="submit" name="submit" value="Pokaż"/>';
        foreach ($langs as $lang) {
            echo '<input type="submit" name="submit" value="' . $lang . '"/>';
        }

        /*W celach statystycznych do formularza dodaj kolejny przycisk ’Statystyki’, po wyborze
którego na dole formularza należy wyświetlić informację o liczbie wszystkich zamówień
w pliku oraz o liczbie zamówień pochodzących odpowiednio od osób poniżej 18 i powyżej
49 roku życia.*/
        echo '<input type="submit" name="submit" value="Statystyki"/>';


        ?>
    </form>
</div>
</div>
</body>

</html>



