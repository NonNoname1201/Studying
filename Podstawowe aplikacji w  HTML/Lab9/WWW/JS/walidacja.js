// Zrealizuj walidację formularza z pliku formularze.html. Do walidacji wykorzystaj funkcje
// pomocnicze umieszczone w zewnętrznym pliku walidacja.js.
//     W pliku powinny się znaleźć funkcje odpowiadające za:
//      sprawdzanie poprawności danych wpisanych do pola tekstowego m.in. z wykorzystaniem
// wyrażeń regularnych,
//  sprawdzenie czy i który przycisk typu radio został zaznaczony,
//  sprawdzenie czy i które przyciski typu checkbox zostały wybrane.
//     Formularz z pliku formularze.html uzupełnij o pola, w których zostaną umieszczone
// ewentualne komunikaty o błędach.

// Path: JS\walidacja.js

function sprawdzImie(imie) {
    var reg = /^[A-Za-z ,.'-]+$/i;
    if (reg.test(imie)) {
        document.getElementById("nazw_error").innerHTML = "";
        return true;
    } else {
        document.getElementById("nazw_error").innerHTML = "Błędne nazwisko";
        return false;
    }
}

function sprawdzWiek(wiek) {
    var reg = /^[1-9][0-9]?$/;
    if (reg.test(wiek)) {
        document.getElementById("wiek_error").innerHTML = "";
        return true;
    } else {
        document.getElementById("wiek_error").innerHTML = "Błędny wiek";
        return false;
    }
}

function sprawdzEmail(email) {
    var reg = /^[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$/;
    if (reg.test(email)) {
        document.getElementById("email_error").innerHTML = "";
        return true;
    } else {
        document.getElementById("email_error").innerHTML = "Błędny email";
        return false;
    }
}

function sprawdzBox(Box_name) {
    var box = document.getElementById(Box_name)
    if (box !== null) {
        return box.checked;
    }
    return false;
}

function sprawdzRadio(radio_name) {
    var radio = document.getElementsByName(radio_name);
    if (radio !== undefined) {
        for (let i = 0; i < radio.length; i++) {
            if (radio[i].checked) {
                document.getElementById("zaplata_error").innerHTML = "";
                return true;
            }
        }
    }
    document.getElementById("zaplata_error").innerHTML = "Wybierz sposób zapłaty";
    return false;
}

function checkedRadio(radio_name) {
    var radio = document.getElementsByName(radio_name);
    if (radio !== undefined) {
        for (let i = 0; i < radio.length; i++) {
            if (radio[i].checked) {
                return radio[i].value;
            }
        }
    }
    return "";
}

function sprawdz() {
    document.getElementById('formularz').addEventListener("submit", function (event) {
        var isBoxChecked = false;
        if (sprawdzBox("PHP")
            || sprawdzBox("Java")
            || sprawdzBox("C/C++")) {
            document.getElementById("produkt_error").innerHTML = "";
            isBoxChecked = true;
        } else {
            document.getElementById("produkt_error").innerHTML = "Wybierz język programowania";
        }
        if (sprawdzImie(document.getElementById("name").value)
            & sprawdzWiek(document.getElementById("age").value)
            & sprawdzEmail(document.getElementById("email").value)
            & sprawdzRadio("paymentmethod")
            && isBoxChecked) {
            confirm("Imie i Nazwisko: " + document.getElementById("name").value
                + "\nWiek: " + document.getElementById("age").value
                + "\nEmail: " + document.getElementById("email").value
                + "\nZapłata: " + checkedRadio("paymentmethod")
                + "\nProdukt: " + document.getElementById("PHP").value
                + document.getElementById("Java").value
                + document.getElementById("C/C++").value);
            return true;
        } else {
            return false;
        }
    });
}



