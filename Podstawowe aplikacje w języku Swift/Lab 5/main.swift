import Foundation

//var tab  = [] error
var tab:[Int] = []

tab.append(1)
tab.append(2)

tab.append(contentsOf: [3,4,5])

print(tab)
print(tab[0])
print(tab.count)

if tab.isEmpty {
    print("tab is empty")
}else{
    print("tab is not empty")
}

var tab2:[Int] = Array(repeating: 0, count: 10)
print(tab2)

tab += tab2
tab = [1,2,3,4,5,6,7,8,9,10]
tab.insert(0, at: 0)
tab.insert(contentsOf: [-2,-1], at: 0)
print(tab)

tab.remove(at: 0)
print(tab)

tab.removeFirst()
tab.removeFirst(2)
tab.removeLast()
tab.removeLast(2)
print(tab)

tab.removeAll()
print(tab)

tab = [1,2,3,4,5,6,7,8,9,10]
tab[0...2] = [0,0,0]
tab[0..2] = [3]
tab[9] = 0

for i in tab {
    print(i, terminator: " ")
}
print()

for(i, v) in tab.enumerated() {
    print("i = \(i), v = \(v)")
}

tab = [1,2,3,4,5,6,7,8,9,10]
tab.shuffle()
print(tab)

tab.revese()
print(tab)

tab.swapAt(0, 1)
print(tab)

if(tab.contains([5,6])){ // error
    print("tab contains 5,6")
}else{
    print("tab does not contain 5,6")
}

if(tab.contains([5])){ //or tab.contains(5)
    print("tab contains 5")
}else{
    print("tab does not contain 5")
}


///////////////////////////////////////////////////////////////

/*Zadanie 6.1.
Polecenie 1. Przeanalizuj kod z Listingu 6.19, znajdź błąd i go popraw.
Listing 6.19. Kod do analizy
var tab: [Int] = Array(repeating: 1.0, count: 12)
for i in tab {
print(i)
}
*/

var tab: [Int] = Array(repeating: 1, count: 12) //double to int
for i in tab {
    print(i)
}

/*Zadanie 6.2.
Polecenie 1. Napisz program konsolowy, który wygeneruje tablicę elementów całkowitych
o wartościach domyślnych z zakresu 1-100. Rozmiar tej tablicy należy ustawić na 10.
Polecenie 2. Dodaj wczytaną liczbę całkowitą na zerowy element tablicy.
Polecenie 3. Dodaj wczytaną liczbę całkowitą na indeksie tabeli, który zostanie wygenerowany
losowo.
Polecenie 4. Wyświetl elementy otrzymanych tablic. 
*/

var tab2:[Int] = []
for i in 0...9 {
    tab2.append(Int.random(in: 1...100))
}

print("Podaj liczbe calkowita")
var liczba = Int(readLine()!)!
tab2.insert(liczba, at: 0)

var index = Int.random(in: 0...tab2.count)
tab2.insert(liczba, at: index)

for i in tab2 {
    print(i, terminator: " ")
}

/*Zadanie 6.3.
Polecenie 1. Napisz program konsolowy, który wczyta od użytkownika liczbę elementów tablicy
oraz jej elementy całkowite, a następnie sprawdzi i wyświetli, czy wczytana liczba całkowita:
jest pierwszym elementem tablicy, ostatnim elementem tablicy lub żadnym z powyższych.
Należy sprawdzić, czy wczytane dane są liczbami całkowitymi oraz czy wczytana liczba
elementów tablicy jest dodatnia.
*/

print("Podaj liczbe elementow tablicy")

var liczbaElementow = Int(readLine()!)!
var tab3:[Int] = []

for i in 0..<liczbaElementow {
    print("Podaj liczbe calkowita nr \(i+1)")
    var liczba = Int(readLine()!)!
    tab3.append(liczba)
}

print("Podaj liczbe calkowita do sprawdzenia")
var liczba = Int(readLine()!)!

if tab3.count == 1 && tab3[0] == liczba {
    print("Liczba jest pierwszym i ostatnim elementem tablicy")
} else if tab3[0] == liczba {
    print("Liczba jest pierwszym elementem tablicy")
} else if tab3[tab3.count - 1] == liczba {
    print("Liczba jest ostatnim elementem tablicy")
} else {
    print("Liczba nie jest pierwszym albo ostatnim elementem tablicy")
}

/*Zadanie 6.4.
Polecenie 1. Napisz program konsolowy, który wygeneruje liczbę elementów tablicy z zakresu
3…100 oraz jej elementy całkowite z zakresu od 3…100, a następnie obliczy i wyświetli:
• średnią arytmetyczną wszystkich elementów tego ciągu;
• średnią geometryczną elementów parzystych ciągu;
• średnią harmoniczną wszystkich elementów tego ciągu.
*/

var tab4:[Int] = Array(repeating: 0, count: Int.random(in: 3...100))
for i in 0..<tab4.count {
    tab4[i] = Int.random(in: 3...100)
}

var suma = 0
for i in tab4 {
    suma += i
}
var sredniaArytmetyczna = suma / tab4.count

var iloczyn = 1
for i in tab4 {
    if i % 2 == 0 {
        iloczyn *= i
    }
}
var sredniaGeometryczna = pow(Double(iloczyn), 1.0 / Double(tab4.count))

var suma2 = 0.0
for i in tab4 {
    suma2 += 1.0 / Double(i)
}
var sredniaHarmoniczna = Double(tab4.count) / suma2

print("Srednia arytmetyczna: \(sredniaArytmetyczna)")
print("Srednia geometryczna: \(sredniaGeometryczna)")
print("Srednia harmoniczna: \(sredniaHarmoniczna)")

/*Zadanie 6.5.
Polecenie 1. Napisz program konsolowy, który wczyta od użytkownika liczbę elementów tablicy
oraz wygeneruje elementy całkowite do dwóch tablic z zakresu 1-20. Program powinien sprawdzić,
czy zawierają one identyczne elementy, nie koniecznie na odpowiadających pozycjach. Należy
wyświetlić odpowiedni komunikat.
Należy sprawdzić, czy wczytana liczba elementów tablicy jest dodatnia
*/

print("Podaj liczbe elementow tablicy")
var liczbaElementow = Int(readLine()!)!
if liczbaElementow <= 0 {
    print("Liczba elementow tablicy musi byc dodatnia")
    exit(0)
}

var tab5:[Int] = []
for i in 0..<liczbaElementow {
    tab5.append(Int.random(in: 1...20))
}
var tab6:[Int] = []
for i in 0..<liczbaElementow {
    tab6.append(Int.random(in: 1...20))
}

var czyZawierajaIdentyczneElementy = false

for i in tab5 {
    for j in tab6 {
        if i == j {
            czyZawierajaIdentyczneElementy = true
            break
        }
    }
    if czyZawierajaIdentyczneElementy {
        break
    }
}

if czyZawierajaIdentyczneElementy {
    print("Tablice zawieraja identyczne elementy")
} else {
    print("Tablice nie zawieraja identycznych elementow")
}

/*Zadanie 6.6.
Polecenie 1. Napisz program konsolowy, który zdefiniuje tablicę dwuwymiarową, przypisze jej
wartości, a następnie wyświetli ją w postaci macierzy. Przykład kodu został przedstawiony na
Listingu 6.20.
*/

let mac: [[Int]] = [[10, 20, 30], [40, 50, 60]]
for i in 0 ..< mac.count {
    for j in 0 ..< mac[i].count{
        print("\(mac[i][j])", terminator:" ")
    }
    print()
}

/*Zadanie 6.7.
Polecenie 1. Napisz program konsolowy, który wczyta od użytkownika liczbę wierszy i kolumn
macierzy, a następnie wygeneruje jej elementy zmiennoprzecinkowe z zakresu -100-100. Program
ma znaleźć największą i najmniejszą liczbę w macierzy, a także indeks, na którym występuje.
Należy wyświetlić wygenerowaną macierz (Listing 6.20).
*/

print ("Podaj liczbe wierszy macierzy")
var liczbaWierszy = Int(readLine()!)!
print ("Podaj liczbe kolumn macierzy")
var liczbaKolumn = Int(readLine()!)!

var mac2:[[Int]] = Array(repeating: Array(repeating: 0, count: liczbaKolumn), count: liczbaWierszy)
for i in 0 ..< LiczbaWierszy {
    for j in 0 ..< LiczbaWierszy{
        mac2[i][j] = Int.random(in: -100...100)
    }
}

var najmniejszaLiczba = mac2[0][0]
var najwiekszaLiczba = mac2[0][0]
var indeksNajmniejszejLiczby = (0,0)
var indeksNajwiekszejLiczby = (0,0)

for i in 0 ..< mac2.count {
    for j in 0 ..< mac2[i].count{
        if mac2[i][j] < najmniejszaLiczba {
            najmniejszaLiczba = mac2[i][j]
            indeksNajmniejszejLiczby = (i,j)
        }
        if mac2[i][j] > najwiekszaLiczba {
            najwiekszaLiczba = mac2[i][j]
            indeksNajwiekszejLiczby = (i,j)
        }
    }
}

print("Najmniejsza liczba: \(najmniejszaLiczba), indeks: \(indeksNajmniejszejLiczby)")
print("Najwieksza liczba: \(najwiekszaLiczba), indeks: \(indeksNajwiekszejLiczby)")

for i in 0 ..< mac2.count {
    for j in 0 ..< mac2[i].count{
        print("\(mac2[i][j])", terminator:" ")
    }
    print()
}

/*Zadanie 6.8.
Polecenie 1. Napisz program konsolowy, który wczyta od użytkownika liczbę elementów tablicy
i jej elementy całkowite, a następnie wyświetli najdłuższy podciąg rosnący. Należy także podać
indeks, od którego ten podciąg się rozpoczyna i liczbę jego elementów. Jeśli taki podciąg nie
istnieje, należy wyświetlić odpowiednią informację.
*/

print("Podaj liczbe elementow tablicy")
var liczbaElementow = Int(readLine()!)!
var tab7:[Int] = []

for i in 0..<liczbaElementow {
    print("Podaj liczbe calkowita nr \(i+1)")
    var liczba = Int(readLine()!)!
    tab7.append(liczba)
}

var najdluzszyPodciag = 1
var IndexBegin = 0
var IndexEnd = 0
var indexBeginOld = 0
var indexEndOld = 0

for i in 1..<tab7.count {
    if tab7[i] >= tab7[i-1] {
        indexEndOld = i
    } else {
        indexBeginOld = i
    }
    if indexEndOld - indexBeginOld > IndexEnd - IndexBegin {
        IndexBegin = indexBeginOld
        IndexEnd = indexEndOld
    }
}

if IndexBegin == IndexEnd {
    print("Nie istnieje taki podciag")
} else {
    print("Najdluzszy podciag rosnacy: ", terminator: "")
    for i in IndexBegin...IndexEnd {
        print("\(tab7[i])", terminator: " ")
    }
    print()
}

