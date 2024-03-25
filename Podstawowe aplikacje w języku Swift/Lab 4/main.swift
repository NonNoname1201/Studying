/*Polecenie 1. Napisz program, który wczyta pewną liczbę do zmiennej licz oraz wyliczy i wyświetli
kolejne elementy ciągu Fibonacciego, które nie przekraczają wartości wczytanej zmiennej. W
przypadku, gdy kolejny wyliczony element jest większy od zmiennej licz, program powinien
zaprzestać wyświetlania. Zastosuj instrukcję while.
*/

import Foundation

print ("Podaj liczbę: ")
guard let input = readLine(), let liczba = Int(input) else {
    print("Błędne dane!")
    exit(1)
}
var n = 0
var n_1 = 0
var n_2 = 1

while n <= liczba {
    print(n)
    n = n_1 + n_2
    n_2 = n_1
    n_1 = n
}


/*Zadanie 5.2. Utwórz aplikację konsolową – liczba pierwsza
Polecenie 1. Napisz program, który wczyta pewną liczbę, a następnie sprawdzi, czy jest to liczba
pierwsza.*/

print ("Podaj liczbę: ")
guard let input = readLine(), let liczba = Int(input) else {
    print("Błędne dane!")
    exit(1)
}

var i = 2
var jestPierwsza = true

repeat {
    if liczba % i == 0 {
        jestPierwsza = false
    }
    i += 1
} while (i < Int(sqrt(Double(liczba)))) || (jestPierwsza == false)

if jestPierwsza {
    print("Liczba jest pierwsza")
} else {
    print("Liczba nie jest pierwsza")
}


/*Napisz program, który wczyta liczbę i obliczy średnią geometryczną cyfr. Należy
wymusić poprawność wczytanej liczby, aby była ona co najmniej trzycyfrowa. Należy upewnić
się, że wczytany ciąg znaków jest liczbą.*/

print ("Podaj liczbę: ")
guard let input = readLine(), let liczba = Int(input) else {
    print("Błędne dane!")
    exit(1)
}
+
if(liczba < 100) {
    print("Liczba musi być co najmniej trzycyfrowa!")
    exit(1)
}

var suma = 1
var ilosc = 0
var liczba2 = liczba

while liczba2 > 0 {
    suma *= liczba2 % 10
    ilosc += 1
    liczba2 /= 10
}

print("Średnia geometryczna cyfr liczby \(liczba) wynosi \(pow(Double(suma), 1.0/Double(ilosc)))")


/*Polecenie 1. Napisz program, który sprawdzi, czy wczytany ciąg znaków jest palindromem
(czytany od prawej lub lewej strony daje taki sam łańcuch). Należy zastosować pętlę!
*/

print ("Podaj ciąg znaków: ")
guard ciag = readLine() else {
    print("Błędne dane!")
    exit(1)
}

var jestPalindromem = true

for i in 0...ciag.count/2 {
    if ciag[ciag.index(ciag.startIndex, offsetBy: i)] != ciag[ciag.index(ciag.endIndex, offsetBy: -i-1)] {
        jestPalindromem = false
    }
}

if jestPalindromem {
    print("Ciąg znaków jest palindromem")
} else {
    print("Ciąg znaków nie jest palindromem")
}


/*Napisz program, który wczyta ciąg liczb całkowitych {ai}, i=1, 2, …, n. Należy
zapewnić, że 𝑎𝑖 ≠ 𝑎𝑖+1podczas wczytywania danych. Należy znaleźć i wyświetlić liczbę minimów
i maksimów lokalnych w tym ciągu, przesuwając się z krokiem 1.
Przykład:
a= {1, 2, 0, 3, 8, 7}
1. (1, 2, 0) → max = 1, min = 0
2. (2, 0, 3) → max = 1, min = 1
3. (0, 3, 8) → max = 1, min = 1, bo ciąg rosnący
4. (3, 8, 7) → max = 2, min = 1*/

print ("Podaj ciąg liczb całkowitych: ")

guard let ciag = readLine() else {
    print("Błędne dane!")
    exit(1)
}

var ciag2 = ciag.split(separator: " ").map { Int($0)! }

var i = 0
var min = 0
var max = 0

if(ciag2.count < 3) {
    print("Ciąg musi mieć co najmniej 3 elementy!")
    exit(1)
}

while(i < ciag2.count - 2) {
    if(ciag2[i] < ciag2[i+1] && ciag2[i+1] > ciag2[i+2]) {
        max += 1
    }
    if(ciag2[i] > ciag2[i+1] && ciag2[i+1] < ciag2[i+2]) {
        min += 1
    }
    i += 1
}

print("Liczba minimów lokalnych: \(min)")
print("Liczba maksimów lokalnych: \(max)")