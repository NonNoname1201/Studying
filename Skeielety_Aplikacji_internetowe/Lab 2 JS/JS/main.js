function sumAll(...args) {
    let sum = 0;
    let resultText = "Sum of: ";
    for (let arg of args) {
        if (typeof arg === 'number') {
            sum += arg;
        } else {
            resultText = "Error: wrong input";
            document.getElementById('result1').innerHTML = resultText;
            return;
        }
    }
    for (let i = 0; i < args.length; i++) {
        if (i === args.length - 1) {
            resultText += args[i];
        } else {
            resultText += args[i] + ", ";
        }
    }
    resultText += " is: " + sum;
    document.getElementById('result1').innerHTML = resultText;
}

//
const listaZadan = [
    {
        id: 1,
        tekst: "Zrobienie zakupów",
        zrealizowano: true
    },
    {
        id: 2,
        tekst: "Przegląd techniczny samochodu",
        zrealizowano: false
    },
    {
        id: 3,
        tekst: "Wizyta u dentysty",
        zrealizowano: false
    },
]

/*
    a) Używając metody forEach() wyświetl wszystkie właściwości tekst z obiektów będących
elementami tablicy.
    b) Wykorzystując metodę map() utwórz nowa tablicę składającą się z tekstów będących
elementami obiektów tablicy listaZadan.
    c) Za pomocą metody filter() utwórz tablicę zawierającą teksty pochodzące z obiektów
składających się na tablicę listaZadan, wyłącznie dla zadań zrealizowanych.
*/

function showList() {
    let resultTextA = "";
    let zadanie2a = "";
    listaZadan.forEach((element) => {
        zadanie2a += element.tekst + ", ";
    });
    resultTextA = zadanie2a;

    let resultTextB = "";
    let zadanie2b = listaZadan.map((element) => {
        return element.tekst;
    });
    zadanie2b.forEach((element) => {
        resultTextB += element + ", "
    });

    let resultTextC = "";
    let zadanie2c = listaZadan.filter((element) => {
        return element.zrealizowano === true;
    });
    zadanie2c.forEach((element) => {
        resultTextC += element.tekst + ", ";
    });

    document.getElementById('result2').innerHTML = resultTextA + "<br><br>" + resultTextB + "<br><br>" + resultTextC;
}

//
const poniedzialek = [
    {
        'nazwa': 'Przygotowania do zajęć z AI',
        'czas': 180
    },
    {
        'nazwa': 'Realizacja projektu z AI',
        'czas': 120
    }
]

const wtorek = [
    {
        'nazwa': 'Rozbudowa swojego bloga',
        'czas': 240
    },
    {
        'nazwa': 'Administrowanie serwisem szkoly',
        'czas': 180
    },
    {
        'nazwa': 'Sluchanie koncertu online',
        'czas': 240
    }
]

/*
Mocną cechą metod map(), filter() i reduce() jest możliwość ich łączenia w łańcuch.
Używając właściwości łączenia metod w łańcuch należy wykonać kolejno następujące
czynności:
1. umieścić zadania z dwóch dni w jednej tablicy (reduce),
2. pobrać czasy trwania zadania i przekonwertować je z minut na godziny (map),
3. odfiltrować czasy, które są większe niż 2 godziny (filter),
4. pomnożyć czasy przez stawkę godzinową wynoszącą 35 zł (map),
5. zsumować wszystkie kwoty (reduce),
6. sformatować kwotę poprzez dodanie 2 miejsc dziesiętnych oraz symbolu waluty PLN
(map),
7. wyjąć wartość z tablicy (reduce).
W punkcie 5 używając metody reduce() wartości parametrów funkcji anonimowej należy ująć
w nawiasy zwykłe i poprzedzić znakiem +, aby wymusić konwersję na liczbę:
reduce(function (acc, curr) {
 return [(+acc) + (+curr)];
})
 */

function showActivities() {
    let resultText = "";
    let zadanie3_1 = poniedzialek.reduce((acc, curr) => {
        return acc.concat(curr);
    }, wtorek);
    let zadanie3_2 = zadanie3_1.map((element) => {
        return {
            'czas': element.czas / 60
        }
    });
    let zadanie3_3 = zadanie3_2.filter((element) => {
        return element.czas > 2;  //Zostawia tylko te zadania, ktore trwają dluzej niż 2 godziny czy musi zostawic te, ktore mniej?
    });
    let zadanie3_4 = zadanie3_3.map((element) => {
        return {
            'koszt': element.czas * 35
        }
    });
    let zadanie3_5 = zadanie3_4.reduce((acc, curr) => {
        return [(+acc) + (+curr.koszt)];
    }, 0);
    let zadanie3_6 = zadanie3_5.map((element) => {
        return element.toFixed(2) + " PLN";
    });
    let zadanie3_7 = zadanie3_6.reduce((acc, curr) => {
        return curr;
    });
    document.getElementById('result3').innerHTML = zadanie3_1 + "<br><br>" + zadanie3_2 + "<br><br>" + zadanie3_3 + "<br><br>" + zadanie3_4 + "<br><br>" + zadanie3_5 + "<br><br>" + zadanie3_6 + "<br><br>" + zadanie3_7;
}

//
const firmy = [
    {nazwa: "Abasco", kategoria: "IT", poczatek: 1999, koniec: 2010},
    {nazwa: "Redis", kategoria: "IT", poczatek: 1993, koniec: 1998},
    {nazwa: "Komp", kategoria: "IT", poczatek: 2003, koniec: 2018},
    {nazwa: "Bosco", kategoria: "Technologie", poczatek: 2011, koniec: 2014},
    {nazwa: "CCA", kategoria: "IT", poczatek: 1991, koniec: 1995},
    {nazwa: "Autosan", kategoria: "Auto", poczatek: 2009, koniec: 2018},
    {nazwa: "Broke", kategoria: "Finanse", poczatek: 1990, koniec: 1992},
    {nazwa: "Funds", kategoria: "Finanse", poczatek: 2000, koniec: 2021}
]

/*
a) Napisz program z użyciem metody filter(), który spowoduje wyświetlenie firm z branży
IT.
b) Używając metody filter() oraz funkcji strzałkowej, wyświetl firmy, które powstały
i zakończyły swoją działalność w latach dziewięćdziesiątych.
c) Wyświetl firmy, które funkcjonowały na rynku dłużej niż 10 lat
 */

function showCompanies() {
    let resultTextA = "";
    let zadanie4a = firmy.filter((element) => {
        return element.kategoria === "IT";
    });
    zadanie4a.forEach((element) => {
        resultTextA += element.nazwa + ", ";
    });

    let resultTextB = "";
    let zadanie4b = firmy.filter((element) => {
        return element.poczatek >= 1990 && element.koniec <= 1999;
    });
    zadanie4b.forEach((element) => {
        resultTextB += element.nazwa + ", ";
    });

    let resultTextC = "";
    let zadanie4c = firmy.filter((element) => {
        return element.koniec - element.poczatek > 10;
    });
    zadanie4c.forEach((element) => {
        resultTextC += element.nazwa + ", ";
    });

    document.getElementById('result4').innerHTML = resultTextA + "<br><br>" + resultTextB + "<br><br>" + resultTextC;
}

//
/*
a) Utwórz nowy plik main.js i używając funkcji require zaimportuj w nim moduł z listingu
1.5 oraz wywołaj funkcję calc.
b) Dokonaj modyfikacji pliku main.js zastępując funkcję require słowem kluczowym import
i zaimportuj możliwość nazwaną calc.
c) Dokonaj ponownej modyfikacji pliku main.js i używając słowa import zaimportuj
domyślną możliwość nazwaną calc.
*/

// a)
const calc = require('./cofile');
document.getElementById('result5').innerHTML += calc.calc(2, 3, '+') + '<br>';
document.getElementById('result5').innerHTML += calc.calc(2, 3, '-') + '<br>';
document.getElementById('result5').innerHTML += calc.calc(2, 3, '*') + '<br>';
document.getElementById('result5').innerHTML += calc.calc(2, 3, '/') + '<br>';
document.getElementById('result5').innerHTML += calc.calc(2, 3) + '<br>';

// b)
import {calc} from './cofile';
document.getElementById('result5').innerHTML += calc(2, 3, '+') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '-') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '*') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '/') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3) + '<br>';

// c)
import calc from './cofile';
document.getElementById('result5').innerHTML += calc(2, 3, '+') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '-') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '*') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3, '/') + '<br>';
document.getElementById('result5').innerHTML += calc(2, 3) + '<br>';
