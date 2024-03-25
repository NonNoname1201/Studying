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

<div>
    <h3><b>Przykladowy formularz HTML</b></h3>
    <form action="odbierz4.php" method="post">
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

        /*Przygotuj kolejny skrypt formularz.php, który buduje taki sam formularz HTML jak
        w zadaniu 2.1, tyle, że z dodatkowymi przyciskami do wyboru kursów (Rys. 2.3).
        W tym celu fragment z przyciskami typu checkbox wygeneruj za pomocą pętli w skrypcie
        PHP, stosując dla każdego przycisku taką samą wartość atrybutu name="jezyki[]", ale inną
        wartość atrybutu value pobieraną z tablicy:
        $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
        
        */

        $langs = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];

        foreach ($langs as $lang) {
            echo "<input type='checkbox' name='jezyki[]' value='$lang'>$lang<br>";
        }

        ?>
        <b>Sposób zapłaty:</b><br/><br/>
        <input name="paymentmethod" type="radio" value="eurocard"/>eurocard
        <input name="paymentmethod" type="radio" value="visa"/>visa
        <input name="paymentmethod" type="radio" value="przelew bankowy"/>przelew bankowy<br/>
        <input type="submit" value="Wyślij"/>
        <input type="reset" value="Anuluj"/>
    </form>
</div>
</div>
</body>

</html>



