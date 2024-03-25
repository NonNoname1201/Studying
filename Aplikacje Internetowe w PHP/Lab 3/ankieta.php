<?php
/*Utwórz nową stronę ankieta.php (PHP Web Page), w której należy umieścić formularz
ankiety jak na rysunku 4.6. Przyciski typu checkbox wygeneruj za pomocą skryptu PHP,
korzystając z tablicy:
$tech = ["C", "CPP", "Java", "C#", "Html", "CSS", "XML", "PHP", "JavaScript"];
Wyniki ankiety zapisuj w pliku ankieta.txt wierszami jak na Rys. 4.7. Po zapisie pokaż stronę
z wynikami. Pojedyncze głosowanie powinno sprawdzać, na które technologie oddano głos
i inkrementować w pliku odpowiednie liczniki. Możesz wykorzystać przykład ankiety
z wykładu. Strona z wynikami powinna pokazać liczby głosów oddanych na każdy z języków
po wielokrotnym głosowaniu*/

function addToAnkieta($langs)
{
    $file = fopen("ankieta.txt", "r");
    $lines = [];
    while (!feof($file)) {
        $line = fgets($file);
        $lines[] = $line;
    }
    fclose($file);

    $file = fopen("ankieta.txt", "w");
    foreach ($lines as $line) {
        $langsInLine = explode(": ", $line);
        $lang = $langsInLine[0];
        $count = $langsInLine[1];
        if (in_array($lang, $_POST['jezyki'])) {
            $count++;
        } else {
            $count = $count+0;
        }
        $line = $lang . ": " . $count . "\n";
        if ($lang != "") {
            fwrite($file, $line);
        }

    }
    fclose($file);

    $file = fopen("ankieta.txt", "r");
    while (!feof($file)) {
        $line = fgets($file);
        echo $line . "<br>";
    }
    fclose($file);
}

$langs = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
echo "<form action='ankieta.php' method='post'>";
foreach ($langs as $lang) {
    echo "<input type='checkbox' name='jezyki[]' value='$lang'>$lang<br>";
}
echo "<input type='submit' name='zapisz' value='Zapisz'>";
echo "</form>";

//    $file = fopen("ankieta.txt", "w");
//    foreach ($langs as $lang) {
//        $line = $lang . ": 0\n";
//        fwrite($file, $line);
//    }
//    fclose($file);

if (isset($_POST['zapisz']) && $_POST['zapisz'] == 'Zapisz') {
    if (isset($_POST['jezyki'])) {
        addToAnkieta($langs);
    }
}