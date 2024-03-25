/*Krotka (ang. Tuple) jest charakterystycznym typem dla języka Swift. Krotki umożliwiają
tworzenie i przekazywanie grup wartości. Ten typ można zastosować, aby zwrócić wiele wartości
z funkcji jako pojedynczą wartość złożoną. Krotka może zawierać dane różnych typów. Dane
przechowywane przez jedną krotkę nie muszą być tego samego typu.*/

let osoba = ("Ania", 16)
print("\(osoba.0) ma \(osoba.1) lat")
//Ania ma 16 lat
//drugi sposób

let osoba = (imie:"Ania", wiek: 36)
print("\(osoba.imie) ma \(osoba.wiek) lat")

let dim3 = (x: 1, y: 0, z: 8)
print("x=\(dim3.x); y=\(dim3.y); z=\(dim3.z) ")

var osoba = (imie:"Anna", wiek: 16)
print("\(osoba.imie) ma \(osoba.wiek) lat ")
osoba = ("Monika", 17)
print("\(osoba.imie) ma \(osoba.wiek) lat ")
osoba = (imiona: "Monika, wiek: 18") //błąd

var tab: [(nazwisko: String, nrKarty: Int)] = []
tab += [(nazwisko: "Kowalski", nrKarty: 123)]
tab.append((nazwisko: "Kowal", nrKarty: 531))
for i in 0..<tab.count{
print("\(tab[i].nazwisko) - nr karty: \(tab[i].nrKarty)")
}

/*Wyliczenia (ang. Enumerations) definiują typ wspólny dla grupy powiązanych wartości.
Umożliwiają pracę z tymi wartościami w sposób bezpieczny. Wyliczenia w Swift są elastyczne,
nie trzeba podawać wartości dla każdego przypadku wyliczenia. Podana wartość wyliczenia może
być ciągiem, znakiem lub wartością dowolnego typu całkowitego lub zmiennoprzecinkowego.*/

enum Waluta{
case pln
case eur
case usd
case chf
case gbp
}

enum Mebel{
case krzeslo, stol, szafa
}

var waluta = Waluta.pln
switch waluta {
case .chf:
print("Frank szwajcarski")
case .eur:
print("Euro")
case .gbp:
print("Funt brytyjski")
case .pln:
print("Polski złoty")
case .usd:
print("Dolar amerykański")
}

enum Mebel: CaseIterable{
case krzeslo, stol, szafa, kanapa
}
let liczbaMebli = Mebel.allCases.count
print("Liczba mebli: \(liczbaMebli)")
//”Liczba mebli: 4”

for mebel in Mebel.allCases {
print(mebel)
}

enum Wymiar {
case dwuwymiarowy(Double, Double)
case trojwymiarowy(Double, Double, Double)
}
var w = Wymiar.dwuwymiarowy(30.5, 12.0)
w = .trojwymiarowy(23.8, 0.0, 10.0)


//Zadanie 1
/*Polecenie 1. Napisz program konsolowy, który zdefiniuje krotkę student składającą się
z elementów takich jak: nazwisko oraz trzech ocen jako typu wyliczeniowego.
Polecenie 2. Wczytaj dane trzech studentów. Wyświetl dane studentów w kolejności malejącej
według uzyskanej średniej. Należy utworzyć typ wyliczeniowy oceny (2, 3.0, 3.5, 4.0, 4.5, 5.0)
oraz zapewnić poprawne wprowadzenie ocen.*/

enum Ocena: Double, CaseIterable {
case dwa = 2.0
case trzy = 3.0
case trzyipol = 3.5
case cztery = 4.0
case czteryipol = 4.5
case piec = 5.0
}

var studenci: [(nazwisko: String, ocena1: Ocena, ocena2: Ocena, ocena3: Ocena)] = []

for i in 0..<3 {
    print("Podaj nazwisko studenta nr \(i+1): ")
    var nazwisko: String? = nil
    while nazwisko == nil {
        guard let input = readLine() else {
            print("Podaj nazwisko studenta nr \(i+1): ")
            continue
        }
        nazwisko = input
    }
    
    print("Podaj ocenę 1 studenta nr \(i+1): ")
    var ocena1: Ocena? = nil
    while ocena1 == nil {
        guard let input = readLine(), let inputValue = Double(input), Ocena.allCases.contains(Ocena(rawValue: inputValue)!) else {
            print("Podaj ocenę 1 studenta nr \(i+1): ")
            continue
        }
        ocena1 = Ocena(rawValue: inputValue)!
    }
    
    print("Podaj ocenę 2 studenta nr \(i+1): ")
    var ocena2: Ocena? = nil
    while ocena2 == nil {
        guard let input = readLine(), let inputValue = Double(input), Ocena.allCases.contains(Ocena(rawValue: inputValue)!) else {
            print("Podaj ocenę 2 studenta nr \(i+1): ")
            continue
        }
        ocena2 = Ocena(rawValue: inputValue)!
    }
    
    print("Podaj ocenę 3 studenta nr \(i+1): ")
    var ocena3: Ocena? = nil
    while ocena3 == nil {
        guard let input = readLine(), let inputValue = Double(input), Ocena.allCases.contains(Ocena(rawValue: inputValue)!) else {
            print("Podaj ocenę 3 studenta nr \(i+1): ")
            continue
        }
        ocena3 = Ocena(rawValue: inputValue)!
    }
    
    studenci.append((nazwisko: nazwisko!, ocena1: ocena1!, ocena2: ocena2!, ocena3: ocena3!))
}

foreach student in studenci {
    print("\(student.nazwisko) - średnia: \((student.ocena1.rawValue + student.ocena2.rawValue + student.ocena3.rawValue) / 3)")
}


//Zadanie 2
/*Polecenie 1. Zdefiniuj typ wyliczeniowy Miesiac, który zawiera 12 miesięcy.
Polecenie 2. Dopasuj porę roku dla danego miesiąca za pomocą instrukcji switch. Załóż, że dany
miesiąc jest przyporządkowany do jednej pory roku.*/

enum Miesiac: Int, CaseIterable {
case styczen = 1
case luty = 2
case marzec = 3
case kwiecien = 4
case maj = 5
case czerwiec = 6
case lipiec = 7
case sierpien = 8
case wrzesien = 9
case pazdziernik = 10
case listopad = 11
case grudzien = 12
}

print("Podaj numer miesiąca: ")
var miesiac: Miesiac? = nil
while miesiac == nil {
    guard let input = readLine(), let inputValue = Int(input), Miesiac.allCases.contains(Miesiac(rawValue: inputValue)!) else {
        print("Podaj numer miesiąca: ")
        continue
    }
    miesiac = Miesiac(rawValue: inputValue)!
}

switch miesiac! {
case .styczen, .luty, .grudzien:
    print("Zima")
case .marzec, .kwiecien, .maj:
    print("Wiosna")
case .czerwiec, .lipiec, .sierpien:
    print("Lato")
case .wrzesien, .pazdziernik, .listopad:
    print("Jesień")
}

/*Structura (ang. Structure) to bloki kodu programu, które zawierają właściwości oraz metody.
Definiują nowy typ.*/

struct Prostopadloscian {
var a: Double
var b: Double
var h:Double
}
struct Osoba {
var imie: String
var wiek: Int
}

let pp = Prostopadloscian(a: 12.0, b: 20, h: 100)
let os = Osoba(imie: "Janek", wiek: 21)

var pp = Prostopadloscian(a: 12.0, b: 20, h: 100)
pp.a = 10
pp.b = 25
pp.h = 70

struct Osoba {
var imie: String
var wiek: Int

init(imie: String, wiek: Int) {
self.imie = imie
self.wiek = wiek
}
}
var o = Osoba(imie: "Andrzej", wiek:35)
print(o)

/*Zbiór (ang. Sets) to zestaw, który przechowuje różne wartości tego samego typu w kolekcji bez
zdefiniowanej kolejności, w przeciwieństwie do tablicy. Jeśli kolejność elementów nie jest istotna,
zamiast tablicy, można użyć zbioru. W zbiorze element o danej wartości może wystąpić tylko raz.*/
 

 var znaki = Set<Character>()
var osoby = Set<String>()
znaki.insert("z") //z
znaki.insert(";") //z, ;
print(znaki)
znaki = [] //pusty zbiór
osoby.insert("Monika")
osoby.insert("Janek")

var kwiaty: Set<String> = ["róża", "żonkil", "frezja"]
var kwiaty: Set = ["róża", "żonkil", "frezja"]

if kwiaty.isEmpty {
print("Zbiór jest pusty")
}
else {
print(kwiaty)
}

kwiaty.insert("fiołek")
print(kwiaty)
//["żonkil", "frezja", "fiołek", "róża"]
kwiaty.remove("róża")
print(kwiaty)
//["żonkil", "frezja", "fiołek"]

if let kwiatDoUsuniecia = kwiaty.remove("fiołek") {
print("Można usunąć \(kwiatDoUsuniecia)")
}
else {
print("Element do usunięcia nie istnieje")
}

var kwiaty: Set = ["róża", "żonkil", "frezja", "fiołek"]
for i in kwiaty {
print(i)
}
for i in kwiaty.sorted() {
print(i)
}
/*
Na zbiorach można wydajnie wykonywać podstawowe jego operacje za pomocą metod:
• union() – suma dwóch zbiorów;
• intersection() – część wspólna dwóch zbiorów;
• symmetricDifference() – metoda tworzenia nowego zestawu z wartościami w jednym
zestawie, ale nie w obu;
• subtracting() – odejmowanie zbiorów.
*/

var s1: Set = [1, 5, 3, 27,80]
var s2: Set = [2, 4, 27, 80]
var s = s1.intersection(s2).sorted()
print(s) //[27, 80]
s = s1.union(s2).sorted()
print(s) //[1, 2, 3, 4, 5, 27, 80]
s = s1.subtracting(s2).sorted()
print(s) //[1, 3, 5]
s = s1.symmetricDifference(s2).sorted()
print(s) //[1, 2, 3, 4, 5]
/*Na zbiorach można wykonywać także następujące operacje:
• == – sprawdza, czy dwa zbiory są sobie równe;
• isSubset(of:) – sprawdza, czy wszystkie wartości zestawu są zawarte w określonym
zestawie;
• isSuperset(of:) – sprawdza, czy zestaw zawiera wszystkie wartości z określonego zestawu;
• isStrictSubset(z:) lub isStrictSuperset(z:) – sprawdza, czy zestaw jest podzbiorem, czy
nadzbiorem, ale nie jest równy określonemu zestawowi;
• isDisjoint(with:) – sprawdza, czy dwa zestawy nie mają wspólnych wartości.
Operacje zostały przedstawione na Listingu 9.11.
*/
if s1.isSubset(of: s2) {
print("s1 jest podzbiorem s2")
}else {
print("s1 nie jest podzbiorem s2")
}
if s1.isDisjoint(with: s2) {
print("s1 i s2 nie maja wspólnych wartości")
} else {
print("s1 i s2 mają wspólne wartości")
}

/*Słownik (ang. Dictionary) przechowuje skojarzenia między kluczami tego samego typu
i wartościami tego samego typu w kolekcji, bez zdefiniowanej kolejności. Każda wartość jest
powiązana z unikalnym kluczem, który działa jako identyfikator tej wartości w słowniku. Elementy
w słowniku nie mają określonej kolejności. Słownik stosuje się w celu wyszukania wartości na
podstawie ich identyfikatora*/

var sl: [Int: String] = [:] // pusty słownik
print(sl)
sl[1] = "jeden"
sl[21] = "dwadzieścia jeden"
print(sl) //[21: "dwadzieścia jeden", 1: "jeden"]

var kraje: [String: String] = ["PL": "Polska", "D": "Niemcy",
 "A": "Austria", "Hr":"Chorwacja"]
print("Zdefiniowano \(kraje.count) elementów")

if kraje.isEmpty {
print("Słownik jest pusty")
} else {
print("Słownik zawiera \(kraje.count) elementów")
}

kraje["Sk"] = "Słowacja" //dodanie elementu
print(kraje)
//["D": "Niemcy", "PL": "Polska", "A": "Austria", "Hr": "Chorwacja", "Sk": "Słowacja"]
kraje["Cz"] = "Czech"
print(kraje)
//["D": "Niemcy", "Hr": "Chorwacja", "Cz": "Czech", "Sk": "Słowacja", "PL": "Polska", "A": "Austria"]

 kraje["Cz"] = "Czechy"
print(kraje)
//["D": "Niemcy", "A": "Austria", "Sk": "Słowacja", "PL": "Polska", "Hr": "Chorwacja", "Cz": "Czechy"]
//albo
if let kr = kraje.updateValue("Czechy", forKey: "Cz") {
print("Zmodyfikowano \(kr)")
} else {
print("Brakuje szukanego elementu")
}
print(kraje)
//["Sk": "Słowacja", "PL": "Polska", "A": "Austria", "D": "Niemcy", "Hr": "Chorwacja", "Cz": "Czechy"]

kraje["Cz"] = nil
print(kraje)
//["PL": "Polska", "A": "Austria", "D": "Niemcy", "Sk": "Słowacja", "Hr": "Chorwacja"]
//albo
if let usunietyElem = kraje.removeValue(forKey: "Cz") {
print("Usunięto \(usunietyElem)")
} else {
print("Brakuje elementu do usunicia")
}

for (symbol, panstwo) in kraje {
print("\(symbol) - \(panstwo)")
}
for panstwo in kraje.keys {
print("\(panstwo)")
}
for symbol in kraje.values {
print(symbol)
}

let symbole = [String] (kraje.keys)
print(symbole)
let panstwa = [String] (kraje.values)
print(panstwa)

/*Funkcja (ang. Function) to fragmenty kodu, które wykonują określone zadanie. Funkcja jest
scharakteryzowana nazwą, która jest stosowana do wywołania funkcji w celu jej wykonania.
Funkcja może być bezparametrowa lub posiadać parametry. Każda funkcja w języku Swift ma typ,
składający się z typów parametrów funkcji i typu zwracanego przez funkcję. Można używać tego
typu jak każdego innego typu w Swift, co ułatwia przekazywanie funkcji jako parametrów do
innych funkcji i zwracanie funkcji z funkcji. */

func losujLiczbe() -> Int {
return Int.random(in: 0..<101)
}
print("Wygenerowana liczba to \(losujLiczbe())")

func witaj(imie: String, nazwisko: String) -> String {
let str = imie + " " + nazwisko + "- witaj na zajęciach z
programowania Swift!"
return str
}
//wczytanie danych
print(witaj(imie: im!, nazwisko: nazw!))

func pole(bok: Int) -> Int {
return bok * bok
}
let p = pole(bok: b!)
print("Pole kwadratu o boku \(b!) wynosi \(p)")

func wyswietl(tab: [Int]) {

print("Elementy tablicy:")
for i in tab {
print(i)
}
}
wyswietl(tab: num)

func suma(tab: [Int]) -> (Int, Int) {
var sump = 0
var sumnp = 0

for i in tab {
if i % 2 == 0 {
sump += i
} else {
sumnp += i
}
}
return (sump, sumnp)
}
let num = [1, 6, 8, 9, 33, 11, 70]
var sum: (Int, Int) = suma(tab: num)
print("Suma elementów parzystych: \(sum.0), suma elementów
nieparzystych: \(sum.1)")

func srednia(tab: [Int]) -> (srdod: Double, srujem:Double)? {
if tab.isEmpty {
return nil
}
var sumd = 0, sumu = 0, ld = 0, lu = 0
for i in tab {
if i > 0 {
sumd += i
ld += 1

} else {
sumu += i
lu += 1
}
}
if (ld != 0){
if (lu != 0){
return (Double(sumd/ld), Double(sumu/lu))
}else {
return(nil)
}
} else {
return (nil)
}
}
let num = [0, 0, 0, 0]
if let sr = srednia(tab: num) {
print("Średnia elementów dodatnich: \(sr.srdod), a ujemnych:
\(sr.srujem)")
} else {
print("Nie można obliczyć obu średnich")
}

func suma(a: Int = 0, b: Int = 0) -> Int {
return a + b
}
var x: Int, y: Int
print(suma())

func zamiana(x: inout Int, y: inout Int) {
let tmp = x
x = y
y = tmp
}
var a = 18, b = 90
print("a = \(a), b = \(b)") // a = 18, b = 90
zamiana(x: &a, y: &b)
print("a = \(a), b = \(b)") // a = 90, b = 18

/*Klasy (ang. Classes) to konstrukcje, które pozwalają na definiowanie właściwości, metod, ale także
umożliwiają dziedziczenie czy rzutowanie typów. */

class Samochod {
var marka: String = ""
var model: String = ""
var rokProd: Int = 0
var przebieg: Double = 0.0
var cena: Double = 0.0
}
var s = Samochod()

s.marka = "Porsche"
s.model = "911"
s.rokProd = 2000
s.przebieg = 10000
s.cena = 120000

class Samochod {
    ...
init(marka: String, model: String, rokProd: Int, przebieg:
 Double, cena: Double) {
self.marka = marka
self.model = model
self.rokProd = rokProd
self.przebieg = przebieg
self.cena = cena
}
}
var s = Samochod(marka:"Porsche", model: "911", rokProd: 2000,
przebieg: 10000.0, cena: 12000.0)


class Samochod {
 …

func wyswietl() {
print("\(marka) \(model)")
print("Rok produkcji: \(rokProd)")
print("Przebieg: \(przebieg)")
print("Cena: \(cena)")
}
}
var s = Samochod(marka:"Porsche", model: "911", rokProd: 2000,
przebieg: 10000.0, cena: 12000.0)
s.wyswietl()

class Kwadrat {
var a: Double = 0.0
init(bok: Double) {
self.a = bok
}

func pole() -> Double {
return a * a
}
}
class Szescian : Kwadrat {
override func pole() -> Double {
return 6 * super.pole() //return 6 * a * a
}

func objetosc() -> Double {
return a * a * a
}
}
var kw = Kwadrat(bok: 2.5)
print(kw.pole())
var sz = Szescian(bok: 5.0)
print(sz.pole())
print(sz.objetosc())


/*Protokół (ang. Protocol) definiuje schemat metod, właściwości i innych wymagań, które
pasują do konkretnego zadania lub funkcji. Protokół może następnie być zastosowany przez
klasę, strukturę lub wyliczenie, aby zapewnić implementację zdefiniowanych wymagań. Każdy
typ, który spełnia wymagania protokołu, jest zgodny z tym protokołem. */

protocol PelneDane {
var nazwa: String {get}
}


class Osoba: PelneDane{
var tytul: String = ""
var imie: String = ""
var drugieImie: String = ""
var nazwisko: String = ""

var nazwa: String {
return tytul + " " + imie + " " + drugieImie + " " +
 nazwisko
}
init(tytul: String, imie: String, drugieImie: String,
 nazwisko: String) {
self.tytul = tytul
self.imie = imie
self.drugieImie = drugieImie
self.nazwisko = nazwisko
}
}
let os = Osoba(tytul: "Pan", imie: "Jan", drugieImie: "Andrzej", nazwisko: "Kowalski")
print(os.nazwa) //Pan Jan Andrzej Kowalski

protocol Dodawanie {
func dodaj() -> Double
}

class Obliczenia: Dodawanie {
var a: Double = 0.0
var b: Double = 0.0
 init(a: Double, b: Double) {
self.a = a
self.b = b
}
func dodaj() -> Double {
return a + b
}
}
let oblicz = Obliczenia(a: 12.5, b: 17.5)
print(oblicz.dodaj())


/*Obsługa błędów (ang. Error Handling) jest procesem reagowania na błędy występujące
podczas obsługi programu i obsługę ich po wystąpieniu. W języku Swift błędy są
reprezentowane przez wartości typów, które są zgodne z protokołem Error. Do modelowania
grupy błędów można zastosować wyliczenia w języku Swift. Na Listingu 12.5 przedstawiono
wyliczenie, które definiuje przypadki nieprawidłowości hasła: gdy jest za długie (powyżej 20
znaków), za krótkie (do 4 znaków) lub jeśli zawiera znak matematyczny.*/

enum WalidacjaHasla: Error {
case zaDlugie
case zaKrotkie
case symbolMatem
}

func walidujHaslo(haslo: String) throws {
guard haslo.count > 4 else {
throw WalidacjaHasla.zaKrotkie
}
guard haslo.count < 20 else {
throw WalidacjaHasla.zaDlugie
}
for znak in haslo {
guard znak.isMathSymbol else {
throw WalidacjaHasla.symbolMatem
}
}
}

let h: String = "k7kk+"
do {
try walidujHaslo(haslo: h)
print("Poprawne hasło")
} catch WalidacjaHasla.zaKrotkie {
print("Podane haslo jest za krótkie")
} catch WalidacjaHasla.zaDlugie {
print("Podane hasło jest za długie")
} catch WalidacjaHasla.symbolMatem {
print("Hasło zawiera znak matematyczny")
}


enum Obywatelstwo: String{
    case pl = "Polska"
    case sp = "Hiszpania"
    case de = "Niemcy"
}

class Osoba{
    var imie: String = ""
    var nazwisko: String = ""
    var vaga: Double = 0.0
    var wzrost: Double = 0.0
    var pesel: String = ""
    var obywatelstwo: Obywatelstwo = .pl

    init(imie: String, nazwisko: String, vaga: Double, wzrost: Double, pesel: String, obywatelstwo: Obywatelstwo){
        self.imie = imie
        self.nazwisko = nazwisko
        self.vaga = vaga
        self.wzrost = wzrost
        self.pesel = pesel
        self.obywatelstwo = obywatelstwo
    }

    func ileLat () -> DateFormatter{
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy/MM/dd"
        //convert pesel to date
        let date = formatter.date(from: pesel.substring(with: 0..<6).inserting(separator: "/", every: 2))
        var i = date!.distance(to: date!)
        return i
    }

    func show() {
        print("Imie: \(imie)")
        print("Nazwisko: \(nazwisko)")
        print("Vaga: \(vaga)")
        print("Wzrost: \(wzrost)")
        print("Pesel: \(pesel)")
        print("Obywatelstwo: \(obywatelstwo)")
        print("Wiek: \(ileLat())")
    }

}

enum TypGry: String{
    case singiel = "single"
    case debel = "double"
    case mikst = "singleAndDouble"
}
class Tenisista : Osoba{
    var ranking: Int = 0
    var typ: TypGry = .singiel
    var najwyzszyRanking: Int = 0
    var punkty: Int = 0
    var ranking: Int = 0

    //var turneje: [String: Int] = ["Australian Open": 0, "Roland Garros": 0, "Wimbledon": 0]
    //musi byc tablica krotek
    var turneje: [(String, Int)] = [("Australian Open", 0), ("Roland Garros", 0), ("Wimbledon", 0)]

    init (imie: String, nazwisko: String, vaga: Double, wzrost: Double, pesel: String, obywatelstwo: Obywatelstwo, ranking: Int, typ: TypGry, najwyzszyRanking: Int, punkty: Int, ranking: Int, turneje: [(String, Int)]){
        super.init(imie: imie, nazwisko: nazwisko, vaga: vaga, wzrost: wzrost, pesel: pesel, obywatelstwo: obywatelstwo)
        self.ranking = ranking
        self.typ = typ
        self.najwyzszyRanking = najwyzszyRanking
        self.punkty = punkty
        self.ranking = ranking
        self.turneje = turneje
    }

    func show() {
        super.show()
        print("Ranking: \(ranking)")
        print("Typ: \(typ)")
        print("Najwyzszy ranking: \(najwyzszyRanking)")
        print("Punkty: \(punkty)")
        print("Ranking: \(ranking)")
        print("Turneje: \(turneje)")
    }

    func dodajTurniej(nazwa: String, punkty: Int){
        turneje.append((nazwa, punkty))
        turneje.remove(at: 0)
        self.punkty += punkty
    }
}

var player1 = Tenisista(imie: "Jan", nazwisko: "Kowalski", vaga: 80.0, wzrost: 180.0, pesel: "12345678901", obywatelstwo: .pl, ranking: 1, typ: .singiel, najwyzszyRanking: 1, punkty: 300, ranking: 1, turneje: [("Australian Open", 0), ("Roland Garros", 0), ("Wimbledon", 0)])
player1.show()

player1.dodajTurniej(nazwa: "Australian Open", punkty: 100)
player1.show()

player1.dodajTurniej(nazwa: "Roland Garros", punkty: 20)
player1.show()

class RankingTenisistow: Tenisista{
    var ranking: [Tenisista] = []

    init(ranking: [Tenisista]){
        self.ranking = ranking
    }

    func show() {
        print("Ranking:")
        for i in ranking{
            print(i.imie + " " + i.nazwisko, terminator: " - ")
            print(i.punkty)
        }
    }

    func showDoule(){
        print("Ranking deblistow:")
        for i in ranking{
            if(i.typ == .debel){
                print(i.imie + " " + i.nazwisko, terminator: " - ")
                print(i.punkty)
            }
        }
    }

    func dodajTenisiste(tenisista: Tenisista){
        ranking.append(tenisista)
    }

    func usunTenisiste(tenisista: Tenisista){
        ranking.remove(at: ranking.firstIndex(of: tenisista)!)
    }

    func showNajwyzej(){
        var max = 0
        for i in ranking{
            if(i.punkty > max){
                max = i.punkty
            }
        }
        
        for i in ranking{
            if(i.punkty == max){
                (i.imie + " " + i.nazwisko, terminator: " - ")
                print(i.ranking)
            }
        }
    }

    func getTenisista (String: pesel) -> Tenisista{
        for i in ranking{
            if(i.pesel == pesel){
                return i
            }
        }
    }

    func updateTenisista (String: pesel, String: turnej, punkty: Int){
        for i in ranking{
            if(i.pesel == pesel){
                i.dodajTurniej(nazwa: turnej, punkty: punkty)
                
            }
        }
    }

    func updateAll (String: turnej, [(String, Int)]: (pesel, punkty)){
        for i in ranking{
            for j in turnej{
                if(i.pesel == j.pesel){
                    i.dodajTurniej(nazwa: turnej, punkty: punkty)
                }
            }
        }
    }

    func updateRanking(Tenisista t){
        switch t.punkty {
        case 1200...1500:
            t.ranking = 1
        case 900...1199:
            t.ranking = 2
        case 700...899:
            t.ranking = 3
        case 400...699:
            t.ranking = 4
        case 300...399:
            t.ranking = 5
        case 200...299:
            t.ranking = 6
        case 100...199:
            t.ranking = 7
        default:
            t.ranking = 0
        }

        if (t.ranking < t.najwyzszyRanking){
            t.najwyzszyRanking = t.ranking
        }

    }
}

var player2 = Tenisista(imie: "Janusz", nazwisko: "Kowalski", vaga: 80.0, wzrost: 180.0, pesel: "12345678902", obywatelstwo: .pl, ranking: 1, typ: .double, najwyzszyRanking: 1, punkty: 100, ranking: 1, turneje: [("Australian Open", 0), ("Roland Garros", 0), ("Wimbledon", 0)])
var player3 = Tenisista(imie: "Tomek", nazwisko: "Kowalski", vaga: 80.0, wzrost: 180.0, pesel: "12345678903", obywatelstwo: .pl, ranking: 1, typ: .singiel, najwyzszyRanking: 1, punkty: 500, ranking: 1, turneje: [("Australian Open", 0), ("Roland Garros", 0), ("Wimbledon", 0)])
var ranking = RankingTenisistow(ranking: [player1, player2, player3])
ranking.show()

ranking.showDoule()

ranking.updateAll("Australian Open", [("12345678901", 20), ("12345678902", 200), ("12345678903", 300)])
ranking.show()


