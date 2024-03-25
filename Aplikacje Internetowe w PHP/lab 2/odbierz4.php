<?php

//resolve array of languages
if (isset($_REQUEST['jezyki']) && ($_REQUEST['jezyki'] != "")) {
    $jezyki = $_REQUEST['jezyki'];
    echo "Wybrane jezyki: <br />";
    foreach ($jezyki as $jezyk) {
        echo "$jezyk <br />";
    }
    echo "Wybrane jezyki (join): <br />";
    echo join(", ", $jezyki);
    echo "Wybrane jezyki (implode): <br />";
    echo implode(", ", $jezyki);
    echo "<br />";
} else echo "Nie wybrano jezykow <br />";
if (isset($_REQUEST['paymentmethod']) && ($_REQUEST['paymentmethod'] != "")) {
    $paymentmethod = htmlspecialchars(trim($_REQUEST['paymentmethod']));
    echo "Sposób zapłaty: $paymentmethod <br />";
} else echo "Nie wybrano sposobu zaplaty <br />";
echo "<br />";

echo "<a href='klient.php?nazwisko=$nazwisko&wiek=$wiek&kraj=$kraj&email=$email'>Dane zamawiającego</a>";
echo "<br />";
echo "<a href='index.php'>Powrót do strony głównej</a>";
echo "<br />";
echo "<a href='formularz.php'>Powrót do formularza</a>";
echo "<br />";

