<?php

if (isset($_GET['nazwisko']) && isset($_GET['wiek']) && isset($_GET['kraj']) && isset($_GET['email'])) {
    $nazwisko = htmlspecialchars(trim($_GET['nazwisko']));
    $wiek = htmlspecialchars(trim($_GET['wiek']));
    $kraj = htmlspecialchars(trim($_GET['kraj']));
    $email = htmlspecialchars(trim($_GET['email']));
} else {
    echo "No data received.";
}

echo "<br />";
echo "Nazwisko: $nazwisko <br />";
echo "Wiek: $wiek <br />";
echo "Kraj: $kraj <br />";
echo "Email: $email <br />";
echo "<br />";
