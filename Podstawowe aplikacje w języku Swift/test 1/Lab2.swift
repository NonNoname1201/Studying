import Foundation
//2.2
print("Podaj rozmaiar sciany A: ")
let a = readLine()

print("Podaj rozmaiar sciany B: ")
let b = readLine()

print("Podaj rozmaiar drzwi: ")
let c = readLine()

print("Podaj rozmaiar sciany Z: ")
let z = readLine()

let perimeter1 = 2 * (Int(a!)! + Int(b!)!) - Int(c!)!
let perimeter2 = perimeter1 + Int(z!)! + Int(b!)! - Int(c!)!

print(perimeter2)

//2.1
print("Podaj bok sześcianu: ")
let a = Double(readLine()!)!

let surfaceArea = 6 * pow(a, 2)
let volume = pow(a, 3)

print("Pole całkowite: \(String(format: "%.2f", surfaceArea))")
print("Objętość: \(String(format: "%.2f", volume))")

//2.3
let a = Int.random(in: 1...9)
let b = Int.random(in: 1...9)
let c = Int.random(in: 1...9)

let average = Double(a + b + c) / 3

print("Wylosowane liczby: \(a), \(b), \(c)")
print("Średnia arytmetyczna: \(String(format: "%.2f", average))")

//2.4
print("Podaj ocenę 1: ")
let a = Int(readLine()!)!
print("Podaj wagę oceny 1: ")
let w1 = Int(readLine()!)!

print("Podaj ocenę 2: ")
let b = Int(readLine()!)!
print("Podaj wagę oceny 2: ")
let w2 = Int(readLine()!)!

print("Podaj ocenę 3: ")
let c = Int(readLine()!)!
print("Podaj wagę oceny 3: ")
let w3 = Int(readLine()!)!

let average = Double(a * w1 + b * w2 + c * w3) / Double(w1 + w2 + w3)
print(average)

//2.5
let str = "Napis jednoliniowy"
let mstr = """
Pierwsza linia
Druga linia
Trzecia linia
"""

print (str)
print (mstr)

//2.6
var str = "Nauka kodowania to nie tylko nauka języka technologii. To odkrywanie nowych sposobów myślenia i urzeczywistnianie rozmaitych koncepcji."

str.insert(contentsOf: "\n\t", at: str.startIndex)

let lines = str.split(separator: ". ")
str = lines.joined(separator: ".\n\t")

let lines2 = str.split(separator: " i")
str = lines2.joined(separator: "\n\ti")

print(str)

//2.7

let currentYear = 2023

print("Podaj imię: ")
let firstName = readLine()!

print("Podaj drugie imię: ")
let middleName = readLine()!

print("Podaj nazwisko: ")
let lastName = readLine()!

print("Podaj rok urodzenia: ")
let birthYear = Int(readLine()!)!

var namingStr = "Imię: \(firstName), drugie imię: \(middleName), nazwisko: \(lastName), rok urodzenia: \(birthYear)"
print(namingStr)

var i : Int = 0
for k in 0..<namingStr.count {
    if(namingStr[namingStr.index(namingStr.startIndex, offsetBy: k)] == ",") {
        i = k
        break
    }
}

var j : Int = 0
for k in (i+1)..<namingStr.count {
    if(namingStr[namingStr.index(namingStr.startIndex, offsetBy: k)] == ",") {
        j = k
        break
    }
}

var range = namingStr.index(namingStr.startIndex, offsetBy: i)..<namingStr.index(namingStr.startIndex, offsetBy: j)
namingStr.removeSubrange(range)
print(namingStr)

let age = currentYear - birthYear

for k in (0..<namingStr.count).reversed() {
    if(namingStr[namingStr.index(namingStr.startIndex, offsetBy: k)] == ",") {
        i = k
        break
    }
}

range = namingStr.index(namingStr.startIndex, offsetBy: i)..< namingStr.endIndex
namingStr.removeSubrange(range)
namingStr.append(" wiek: \(age)")

print(namingStr)

if(namingStr.hasPrefix("D")) {
    print("Imię zaczyna się na D")
}
