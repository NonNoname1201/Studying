<?php

/*Opracuj nowy skrypt odbierz3.php, który wyświetli dane o wybranych przyciskach
        (tutorialach) z nowego formularza za pomocą:
        a) pętli foreach (dla tablicy wartości $_REQUEST['jezyki']),
        b) funkcję join() lub implode() (np. join(",",$_REQUEST['jezyki'])).
        Sprawdź ponownie działanie funkcji var_dump() dla tablicy $_REQUEST i zwróć uwagę, że
        wartości dla niektórych kluczy (np. 'jezyki') są tablicą wartości typu String. W skrypcie
        odbierz3.php dodaj kolejną pętlę foreach, która wyświetli wszystkie parametry tablicy
        $_REQUEST (nazwy i ich wartości), pamiętając, że niektóre wartości są tablicami
        (wykorzystaj funkcję is_array()).
        Warto też sprawdzić w manualu przykłady zastosowania funkcji join()/implode() oraz pętli
        foreach.*/

        if (isset($_REQUEST['login']) && ($_REQUEST['login'] != "")) {
            $nazwisko = htmlspecialchars(trim($_REQUEST['login']));
            echo "Nazwisko: $nazwisko <br />";
        } else echo "Nie wpisano nazwiska <br />";
        if (isset($_REQUEST['pass']) && ($_REQUEST['pass'] != "")) {
            $wiek = htmlspecialchars(trim($_REQUEST['pass']));
            echo "Wiek: $wiek <br />";
        } else echo "Nie wpisano wieku <br />";
        //country is select, so we need to check if it is set and not empty
        
        if (isset($_REQUEST['country']) && ($_REQUEST['country'] != "")) {
            $kraj = htmlspecialchars(trim($_REQUEST['country']));
            echo "Kraj: $kraj <br />";
        } else echo "Nie wybrano kraju <br />";
        
        if (isset($_REQUEST['email']) && ($_REQUEST['email'] != "")) {
            $email = htmlspecialchars(trim($_REQUEST['email']));
            echo "Email: $email <br />";
        } else echo "Nie wpisano emaila <br />";

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

        var_dump($_REQUEST);
        echo "<br />";