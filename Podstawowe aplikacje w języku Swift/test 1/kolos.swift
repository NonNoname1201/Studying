//Zadanie 1
/*
a = 1, n = 1
a = -2, n = 2
an-1 = an-2, n = 2k, k > 1
an-1 = an-2 + 2, n = 2k+1, k > 1
*/

func calculateA(n: Int) -> Int {
    if n == 1 {
        return 1
    } else if n == 2 {
        return -2
    } else if n % 2 == 0 {
        return calculateA(n: n - 1) + calculateA(n: n - 2)
    } else {
        return calculateA(n: n - 1) + 2
    }
}

print("Podaj n: ")
let n = Int(readLine()!)!
let a = calculateA(n: n)
print("a = \(a)")

//Zadanie 2
/*
year1 = 20_20
year2 = 18_18

yearResult = x_x, 18<x<20
*/

print("Podaj pierwszy rok: ")
var year1: Int? = nil
while year1 == nil {
    guard let input = readline(), let inputValue = Int(input), inputvalue % 100 == inputvalue / 100 else {
        print("Podaj pierwszy rok: ")
        continue
    }
    year1 = inputValue
}

print("Podaj drugi rok: ")
var year2: Int? = nil
while year2 == nil {
    guard let input = readline(), let inputValue = Int(input), inputvalue % 100 == inputvalue / 100 else {
        print("Podaj drugi rok: ")
        continue
    }
    year2 = inputValue
}

var yearNum = 0
if(abs(year1! / 100 - year2! / 100) <= 1) {
    yearNum = 0;
} else {
    yearNum = abs(year1! / 100 - year2! / 100) - 1
}

if(yearNum == 0) {
    print("Nie ma lat przestępnych pomiędzy \(year1!) a \(year2!)")
} else {
    print("Ilość lat spęłniających właściwości pomiędzy \(year1!) a \(year2!): \(yearNum)")
}

//Zadanie 3
/*
a > 0, a : int
b > 0, b : int
c = NWD(a, b)
*/

print("Podaj a: ")
var a: Int? = nil
while a == nil {
    guard let input = readLine(), let inputValue = Int(input), inputValue > 0 else {
        print("Podaj a: ")
        continue
    }
    a = inputValue
}

print("Podaj b: ")
var b: Int? = nil
while b == nil {
    guard let input = readLine(), let inputValue = Int(input), inputValue > 0 else {
        print("Podaj b: ")
        continue
    }
    b = inputValue
}

var c = 0
var a1 = a!
var b1 = b!

while b1 != 0 {
    let temp = b1
    b1 = a1 % b1
    a1 = temp
}

let c = a1
print("Największy wspólny dzielnik: \(c)")

let lcm = (a! * b!) / c
print("Najmniejsza wspólna wielokrotność: \(lcm)")

//Zadanie 4
/*
p : double
n : int, n > 3
arr[n] : double

result = arr[?] closest to p
resultaddr = ?
*/

print("Podaj p: ")
var p: Double? = nil
while p == nil {
    guard let input = readLine(), let inputValue = Double(input) else {
        print("Podaj p: ")
        continue
    }
    p = inputValue
}

print("Podaj rozmiar tablicy: ")
var n: Int? = nil
while n == nil {
    guard let input = readLine(), let inputValue = Int(input), inputValue > 3 else {
        print("Podaj rozmiar tablicy: ")
        continue
    }
    n = inputValue
}

var arr = [Double]()

for i in 0..<n! {
    print("Podaj \(i+1) element tablicy: ")
    var element: Double? = nil
    while element == nil {
        guard let input = readLine(), let inputValue = Double(input) else {
            print("Podaj \(i+1) element tablicy: ")
            continue
        }
        element = inputValue
    }
    arr.append(element!)
}

var result = arr[0]
var resultaddr = 0
for i in 1..<n! {
    if(abs(arr[i] - p!) < abs(result - p!)) {
        result = arr[i]
        resultaddr = i
    }
}

print("Wynik: \(result)")
print("Adres: \(resultaddr)")

//Zadanie 5
/*
k is random from 20-200
print(all prime numbers from 2 to k)
*/

func isPrime(n: Int) -> Bool {
    if n == 2 {
        return true
    } else if n % 2 == 0 {
        return false
    } else {
        for i in 3..<n {
            if n % i == 0 {
                return false
            }
        }
        return true
    }
}

var k = Int.random(in: 20...200)
print("k = \(k)")

var prime = [Bool]()

for _ in 0...k {
    prime.append(isPrime(n: k))
}

print("Liczby pierwsze: ")
for i in 0...k {
    if prime[i] {
        print("\(i) ")
    }
}

//Zadanie 6
/*
m : int > 0
p : int > 0
arr(m, p) : int = random from 800 to 2600

n = smallest number from arr without using min()
*/

print("Podaj liczbę oddziałów: ")

var m: Int? = nil
while m == nil {
    guard let input = readLine(), let inputValue = Int(input), inputValue > 0 else {
        print("Podaj liczbę oddziałów: ")
        continue
    }
    m = inputValue
}

print("Podaj liczbę pracowników: ")

var p: Int? = nil
while p == nil {
    guard let input = readLine(), let inputValue = Int(input), inputValue > 0 else {
        print("Podaj liczbę pracowników: ")
        continue
    }
    p = inputValue
}

var arr = [[Int]]()

for i in 0..<m! {
    arr.append([Int]())
    for j in 0..<p! {
        arr[i].append(Int.random(in: 800...2600))
    }
}

var resultTemp = [Int]()
var n = arr[0][0]

for i in 0..<m! {
    for j in 0..<p! {
        if arr[i][j] < n {
            n = arr[i][j]
        }
    }
    resultTemp.append(n)
}

var n = resultTemp[0]
for i in 1..<m! {
    if resultTemp[i] > n {
        n = resultTemp[i]
    }
}

print("Najmniejsza pensja dla wszystkich oddziałów: \(n)")


//Zadanie 7
/*
3 arrays R G B
R = random from 0 to 255
G = random from 0 to 255
B = random from 0 to 255

to 1 array HSV
H = 0.0 to 360.0
S = 0.0 to 1.0
V = 0.0 to 1.0
*/

var R = [[Int]]()
var G = [[Int]]()
var B = [[Int]]()

for i in 0..<3 {
    R.append([Int]())
    G.append([Int]())
    B.append([Int]())
    for j in 0..<3 {
        R[i].append(Int.random(in: 0...255))
        G[i].append(Int.random(in: 0...255))
        B[i].append(Int.random(in: 0...255))
    }
}

var H = [[Double]]()
var S = [[Double]]()
var V = [[Double]]()

for i in 0..<3 {
    H.append([Double]())
    S.append([Double]())
    V.append([Double]())
    for j in 0..<3 {
        let r = Double(R[i][j]) / 255.0
        let g = Double(G[i][j]) / 255.0
        let b = Double(B[i][j]) / 255.0
        let cmax = max(r, g, b)
        let cmin = min(r, g, b)
        let delta = cmax - cmin
        var h = 0.0
        var s = 0.0
        var v = 0.0
        if delta == 0 {
            h = 0
        } else if cmax == r {
            h = 60 * (((g - b) / delta).truncatingRemainder(dividingBy: 6))
            if h < 0 {
                h += 360
            }
        } else if cmax == g {
            h = 60 * (((b - r) / delta) + 2)
        } else if cmax == b {
            h = 60 * (((r - g) / delta) + 4)
        }
        if cmax == 0 {
            s = 0
        } else {
            s = delta / cmax
        }
        v = cmax - cmin
        H[i].append(h)
        S[i].append(s)
        V[i].append(v)
    }
}

print("RGB: ")
for i in 0..<3 {
    for j in 0..<3 {
        print("(\(R[i][j]), \(G[i][j]), \(B[i][j])) ", terminator: "")
    }
    print()
}

print("HSV: ")
for i in 0..<3 {
    for j in 0..<3 {
        print("(\(H[i][j]), \(S[i][j] * 100)%, \(V[i][j] * 100)%) " , terminator: "")
    }
    print()
}

//Zadanie 8
/*
get card number
check if it's valid
16 digits if less add 0 at the beginning
multiply digits on even positions by 2
last digit = 0 then correct
*/

print("Podaj numer karty: ")
var card: String? = nil
while card == nil {
    guard let input = readLine() else {
        print("Podaj numer karty: ")
        continue
    }
    card = input
}

var cardNum = card!.count
if cardNum < 16 {
    for _ in 0..<(16 - cardNum) {
        card = "0" + card!
    }
}

var sum = 0

for i in 0..<16 {
    if i % 2 == 0 {
        sum += Int(String(card![card!.index(card!.startIndex, offsetBy: i)]))!
    } else {
        sum += Int(String(card![card!.index(card!.startIndex, offsetBy: i)]))! * 2
    }
}

if sum % 10 == 0 {
    print("Numer karty jest poprawny")
} else {
    print("Numer karty jest niepoprawny")
}

