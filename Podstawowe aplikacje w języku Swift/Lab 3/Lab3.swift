import Foundation

/*
Polecenie 1. Utwórz program, który wczyta od użytkownika dowolny ciąg, pojedynczy znak
oraz liczbę całkowitą. Program powinien sprawdzić, czy wczytany znak znajduje się na
początku ciągu, na końcu, czy na indeksie oddalonym o podaną liczbę całkowitą od początku
lub od końca ciągu. 
*/

print("Enter text:")
let text = readLine()!  //text

print("Enter a character:")
let char: Character = Character(readLine()!)  //char

print("Enter a number:")
let number = Int(readLine()!)!  //number

switch(number){
    case let x where text.hasPrefix(String(char)):
        print("Char is at the beginning of the text");
    case let x where text.hasSuffix(String(char)):
        print("Char is at the end of the text");
    case let x where text[text.index(text.startIndex, offsetBy: number)] == char:
        print("Char is at the index \(number) from the beginning of the text");
    case let x where text[text.index(text.endIndex, offsetBy: -number)] == char:
        print("Char is at the index \(number) from the end of the text");
    default:
        print("Char is not in the text")
}


/*
Utwórz aplikację konsolową – porównywanie ciągów
Polecenie 1. Utwórz program, który wczyta od użytkownika dwa ciągi i sprawdzi, czy oba ciągi
są identyczne.
Polecenie 2. Wczytaj prefiks od użytkownika. Należy sprawdzić, czy prefiks występuje
w podanych ciągach.
Polecenie 3. Wczytaj sufiks od użytkownika. Należy sprawdzić, czy sufiks występuje
w podanych ciągach. 
*/

print("Enter text 1:")
let text1 = readLine()! //text1

print("Enter text 2:")
let text2 = readLine()! //text2

if(text1 == text2) {
    print("Texts are the same")
} else {
    print("Texts are not the same")
}

print("Enter prefix:")
let prefix = readLine()! //prefix

if(text1.hasPrefix(prefix)){
    print("Text1 has prefix: \(prefix)")
} else {
    print("Text1 does not have the prefix")
}

if(text2.hasPrefix(prefix)){
    print("Text2 has prefix: \(prefix)")
} else {
    print("Text2 does not have the prefix")
}

print("Enter suffix:")
let suffix = readLine()! //suffix

if(text1.hasSuffix(suffix)){
    print("Text1 has suffix: \(suffix)")
} else {
    print("Text1 does not have the suffix")
}

if(text2.hasSuffix(suffix)){
    print("Text2 has suffix: \(suffix)")
} else {
    print("Text2 does not have the suffix")
}


/*
Utwórz aplikację konsolową – rok przestępny
Polecenie 1. Napisz program, który wczyta od użytkownika rok i sprawdzi, czy jest on
przestępny. Należy sprawdzić poprawność danyc
*/

print("Enter a year:")
guard let year = Int(readLine()!) else {
    fatalError("Wrong year format")
}


if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
    print("Year \(year) is a leap year")
} else {
    print("Year \(year) is not a leap year")
}


/*
Napisz program, który dla wczytanej zmiennej całkowitej z zakresu <2,3010>
oznaczającej rok, obliczy i wyświetli wiek, który reprezentuje wczytana dana.
Przykład:
rok 1000- wiek 10
rok 1903 – wiek 20
*/

print("Enter a year between 2 and 3010:")
guard var year = Int(readLine()!), year >= 2 && year <= 3010 else {
    fatalError("Invalid input. Please enter a year between 2 and 3010.")
}


let century = (year - 1) / 100 + 1
print("Year \(year) is in century #\(century).")


/*
Polecenie 1. Napisz program, który dla wczytanej średniej ze studiów, obliczy i wyświetli
stypendium naukowe według wzoru:

Należy sprawdzić poprawność wprowadzonych danych.
*/

print("Enter average grade:")
guard var avg = Double(readLine()!), avg >= 2.0 && avg <= 5.0 else {
    fatalError("Invalid input. Please enter a grade between 2.0 and 5.0.")
}

var scholarship = 0

switch(avg){
    case let x where avg >= 4.5:
        scholarship = 200
    case let x where avg >= 4.0:
        scholarship = 150
    case let x where avg >= 3.0:
        scholarship = 100
    default:
        scholarship = 0
}

print("The student will receive a scholarship of \(scholarship) PLN.")

/*
Polecenie 1. Napisz program, który wczyta dwie liczby całkowite oraz wyświetla menu
w postaci: ‘1-dodawanie, 2-odejmowanie, 3-mnożenie, 4-dzielenie’.
W zależności od wybranego elementu na ekranie powinien wyświetlić się wynik. Zabezpiecz
odpowiednio program na wypadek dzielenia przez 0. Zastosuj instrukcję switch.
*/

print("Enter first number:")
guard let firstNumber = Double(readLine()!) else {
    fatalError("Wrong number format")
}

print("Enter second number:")
guard let secondNumber = Double(readLine()!) else {
    fatalError("Wrong number format")
}

print("Choose an operation:\n1-addition\n2-subtraction\n3-multiplication\n4-division")

guard let operation = Int(readLine()!) else {
    fatalError("Wrong operation format")
}

switch(operation){
    case 1:
        print("Result: \(firstNumber + secondNumber)")
    case 2:
        print("Result: \(firstNumber - secondNumber)")
    case 3:
        print("Result: \(firstNumber * secondNumber)")
    case 4:
        if(secondNumber == 0.0){
            print("Cannot divide by 0")
        } else {
            print("Result: \(firstNumber / secondNumber)")
        }
    default:
        print("Wrong operation")
}

/*
Napisz program, który wczyta znak z klawiatury i określi, czy jest to samogłoska,
spółgłoska, cyfra, czy inny znak. Zastosuj instrukcję switch.
*/

print("Enter a character:")
let character: Character = readLine().first!

switch(character){
    case "a", "ą", "e", "ę", "i", "o", "ó", "u", "y":
        print("Character is a vowel")
    case "b", "c", "ć", "d", "f", "g", "h", "j", "k", "l", "ł", "m", "n", "ń", "p", "r", "s", "ś", "t", "w", "z", "ź", "ż":
        print("Character is a consonant")
    case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9":
        print("Character is a digit")
    default:
        print("Character is a special character")    
}