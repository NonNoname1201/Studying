/*Zadanie 9.1
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę liczbaZespolona składającą się
z części rzeczywistej i urojonej liczby.
Polecenie 2. Wczytaj dwie liczby zespolone.
Polecenie 3. Zaimplementuj dodawanie dwóch liczb zespolonych.
Polecenie 4. Zaimplementuj odejmowanie dwóch liczb zespolonych.
Polecenie 5. Zaimplementuj mnożenie dwóch liczb zespolonych.
Polecenie 6. Opracuj menu dla zaimplementowanych funkcjonalności.*/

struct liczbaZespolona {
    var rzeczywista: Double
    var urojona: Double
}

func dodawanie(liczba1: liczbaZespolona, liczba2: liczbaZespolona) -> liczbaZespolona {
    return liczbaZespolona(rzeczywista: liczba1.rzeczywista + liczba2.rzeczywista, urojona: liczba1.urojona + liczba2.urojona)
}

func odejmowanie(liczba1: liczbaZespolona, liczba2: liczbaZespolona) -> liczbaZespolona {
    return liczbaZespolona(rzeczywista: liczba1.rzeczywista - liczba2.rzeczywista, urojona: liczba1.urojona - liczba2.urojona)
}

func mnozenie(liczba1: liczbaZespolona, liczba2: liczbaZespolona) -> liczbaZespolona {
    var re = (liczba1.rzeczywista * liczba2.rzeczywista) - (liczba1.urojona * liczba2.urojona)
    var im = (liczba1.rzeczywista * liczba2.urojona) + (liczba1.urojona * liczba2.rzeczywista)
    return liczbaZespolona(rzeczywista: re, urojona: im)
}

print ("Podaj czesc rzeczywista pierwszej liczby zespolonej")
var rzeczywista1 = Double(readLine()!)!
print ("Podaj czesc urojona pierwszej liczby zespolonej")
var urojona1 = Double(readLine()!)!

print ("Podaj czesc rzeczywista drugiej liczby zespolonej")
var rzeczywista2 = Double(readLine()!)!
print ("Podaj czesc urojona drugiej liczby zespolonej")
var urojona2 = Double(readLine()!)!

var liczba1 = liczbaZespolona(rzeczywista: rzeczywista1, urojona: urojona1)
var liczba2 = liczbaZespolona(rzeczywista: rzeczywista2, urojona: urojona2)

print ("Wybierz dzialanie: 1 - dodawanie, 2 - odejmowanie, 3 - mnozenie", terminator: "\n>> ")
var wybor = readLine()!
switch wybor {
case "1":
    print ("Wynik dodawania: \(dodawanie(liczba1: liczba1, liczba2: liczba2))")
case "2":
    print ("Wynik odejmowania: \(odejmowanie(liczba1: liczba1, liczba2: liczba2))")
case "3":
    print ("Wynik mnozenia: \(mnozenie(liczba1: liczba1, liczba2: liczba2))")
default:
    print ("Nie ma takiej opcji")
}

/*Zadanie 9.2
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę rzutOszczepem składającą się
z identyfikatora osoby oraz trzech prób rzutów.
Polecenie 2. Wczytaj dane dla czterech zawodników.
Polecenie 3. Wyświetl zawodnika, który uzyskał największą średnią swoich rzutów.
Polecenie 4. Usuń zawodnika, który uzyskał najmniejszą średnią swoich rzutów.*/

struct rzutOszczepem {
    var id: Int
    var proba1: Double
    var proba2: Double
    var proba3: Double
}

var zawodnicy = [rzutOszczepem]()
var srednie = [Double]()

for i in 1...4 {
    print ("Podaj id zawodnika nr \(i)")
    var id = Int(readLine()!)!
    print ("Podaj wynik pierwszej probie zawodnika nr \(i)")
    var proba1 = Double(readLine()!)!
    print ("Podaj wynik drugiej probie zawodnika nr \(i)")
    var proba2 = Double(readLine()!)!
    print ("Podaj wynik trzeciej probie zawodnika nr \(i)")
    var proba3 = Double(readLine()!)!
    zawodnicy.append(rzutOszczepem(id: id, proba1: proba1, proba2: proba2, proba3: proba3))
    srednie.append((proba1 + proba2 + proba3) / 3)
}

var max = srednie.max()
var min = srednie.min()

for i in 0...3 {
    if srednie[i] == max {
        print ("Zawodnik o najwiekszej sredniej: \(zawodnicy[i])")
    }
    if srednie[i] == min {
        print ("Zawodnik o najmniejszej sredniej: \(zawodnicy[i])")
    }
}

/*Zadanie 9.3
Polecenie 1. Napisz program konsolowy, który zdefiniuje zbiór samochody składający się z modeli
samochodów.
Polecenie 2. Wprowadź nazwy dla 6 samochodów.
Polecenie 3. Wyświetl wszystkie elementy zbioru.
Polecenie 4. Wczytaj model samochodu od użytkownika i usuń go ze zbioru. Należy sprawdzić,
czy element taki istnieje w zbiorze.*/

var samochody = Set<String>()

for i in 1...6 {
    print ("Podaj nazwe samochodu nr \(i)")
    var nazwa = readLine()!
    samochody.insert(nazwa)
}

for i in samochody {
    print (i)
}

print ("Podaj nazwe samochodu do usuniecia")
var nazwa = readLine()!
if samochody.contains(nazwa) {
    samochody.remove(nazwa)
    print ("Samochod usuniety")
    print ("Aktualny stan zbioru:", terminator: " ")
    for i in samochody {
        print (i, terminator: " ")
    }
    print ("")
} else {
    print ("Nie ma takiego samochodu")
}

/*Zadanie 9.4.
Polecenie 1. Napisz program konsolowy, który zdefiniuje słownik student, który zawiera nazwisko
i identyfikator studenta.
Polecenie 2. Dodaj 5 studentów na podstawie wczytanych danych od użytkownika.
Polecenie 3. Wyświetl wszystkie dane.
Polecenie 4. Wczytaj dane studenta i wyszukaj go. Jeśli istnieje należy wyświetlić dane.
W przeciwnym wypadku wyświetl odpowiednią informację.
Polecenie 5. Wczytaj dane studenta i jeśli istnieje, należy go usunąć.*/

var studenci = [Int : String]()

for i in 1...5 {
    print ("Podaj id studenta nr \(i)")
    var id = Int(readLine()!)!
    print ("Podaj nazwisko studenta nr \(i)")
    var nazwisko = readLine()!
    studenci[id] = nazwisko
}

for (id, nazwisko) in studenci {
    print ("Id: \(id), nazwisko: \(nazwisko)")
}

print ("Podaj id studenta do wyszukania")
var id = Int(readLine()!)!
if studenci[id] != nil {
    print ("Student o id \(id) to \(studenci[id]!)")
} else {
    print ("Nie ma takiego studenta")
}

print ("Podaj nazwisko studenta do wyszukania")
var nazwisko = readLine()!
var znaleziono = false
for (id, nazwisko) in studenci {
    if nazwisko == nazwisko {
        print ("Student o nazwisku \(nazwisko) to \(id)")
        znaleziono = true
    }
}
if znaleziono == false {
    print ("Nie ma takiego studenta")
}

print ("Podaj id studenta do usuniecia")
var id = Int(readLine()!)!
if studenci[id] != nil {
    studenci.removeValue(forKey: id)
    print ("Student usuniety")
    print ("Aktualny stan zbioru:", terminator: " ")
    for (id, nazwisko) in studenci {
        print ("Id: \(id), nazwisko: \(nazwisko)", terminator: " ")
    }
    print ("")
} else {
    print ("Nie ma takiego studenta")
}

print ("Podaj nazwisko studenta do usuniecia")
var nazwisko = readLine()!
var znaleziono = false
for (id, nazwisko) in studenci {
    if nazwisko == nazwisko {
        studenci.removeValue(forKey: id)
        print ("Student usuniety")
        print ("Aktualny stan zbioru:", terminator: " ")
        for (id, nazwisko) in studenci {
            print ("Id: \(id), nazwisko: \(nazwisko)", terminator: " ")
        }
        print ("")
        znaleziono = true
    }
}
if znaleziono == false {
    print ("Nie ma takiego studenta")
}

/*Zadanie 9.5.
Polecenie 1. Napisz program konsolowy, który zdefiniuje strukturę loty składającą z miejsca
wylotu (jako słownik: numer lotniska i jego nazwa), miejsca docelowego (jako słownik: numer
lotniska i jego nazwa) oraz czas podróży w minutach.
Polecenie 2. Wczytaj dane dla n lotów do tablicy (n – podaje użytkownik). Należy sprawdzić
poprawność danych.
Polecenie 3. Wyświetl dane wszystkich lotów.
Polecenie 4. Wyświetl dane wszystkich lotów, które trwają dłużej niż średnia wszystkich.
Polecenie 5. Usuń dane wszystkich lotów, które trwają krócej niż średnia wszystkich lotów.
Polecenie 6. Wyświetl dane lotów.*/

struct loty {
    var miejsceWylotu: [Int : String]
    var miejsceDocelowe: [Int : String]
    var czasPodrozy: Int
}

var loty_set = [loty]()
var sredniaCzasu = 0

print ("Podaj ilosc lotow")
var ilosc = Int(readLine()!)!
for i in 0..<ilosc {
    print ("Podaj miejsce wylotu lotu nr \(i+1)")
    var miejsceWylotu = [Int : String]()
    print ("Podaj numer lotniska")
    var numerLotniska = Int(readLine()!)!
    print ("Podaj nazwe lotniska")
    var nazwaLotniska = readLine()!
    miejsceWylotu[numerLotniska] = nazwaLotniska
    print ("Podaj miejsce docelowe lotu nr \(i+1)")
    var miejsceDocelowe = [Int : String]()
    print ("Podaj numer lotniska")
    numerLotniska = Int(readLine()!)!
    print ("Podaj nazwe lotniska")
    nazwaLotniska = readLine()!
    miejsceDocelowe[numerLotniska] = nazwaLotniska
    print ("Podaj czas podrozy lotu nr \(i+1)")
    var czasPodrozy = Int(readLine()!)!
    loty_set.append(loty(miejsceWylotu: miejsceWylotu, miejsceDocelowe: miejsceDocelowe, czasPodrozy: czasPodrozy))
    sredniaCzasu += czasPodrozy
}

sredniaCzasu /= ilosc

for i in 0..<ilosc {
    print ("Lot nr \(i+1):")
    print ("Miejsce wylotu: \(loty_set[i].miejsceWylotu)")
    print ("Miejsce docelowe: \(loty_set[i].miejsceDocelowe)")
    print ("Czas podrozy: \(loty_set[i].czasPodrozy)")
}

print ("Loty trwajace dluzej niz srednia:")
for i in 0..<ilosc {
    if loty_set[i].czasPodrozy > sredniaCzasu {
    print ("Lot nr \(i+1):")
    print ("Miejsce wylotu: \(loty_set[i].miejsceWylotu)")
    print ("Miejsce docelowe: \(loty_set[i].miejsceDocelowe)")
    print ("Czas podrozy: \(loty_set[i].czasPodrozy)")
    }
}

for i in 0..<ilosc {
    if loty_set[i].czasPodrozy < sredniaCzasu {
        loty_set.remove(at: i)
    }
}

print ("Aktualny stan lotow:")
for i in 0..<ilosc {
    print ("Lot nr \(i+1):")
    print ("Miejsce wylotu: \(loty_set[i].miejsceWylotu)")
    print ("Miejsce docelowe: \(loty_set[i].miejsceDocelowe)")
    print ("Czas podrozy: \(loty_set[i].czasPodrozy)")
}