import Foundation


print("Podaj imie")
let imie = readLine()!


// random number generator
let licz1 = Int.random(in: 1...250)


// list input
func wczytajTablice(n:Int) -> [Int]{
    var tab:[Int] = []
    for _ in 0..<n {
        tab.append(Int(readLine()!)!)
    }
    return tab
}
wczytajTablice(n: 5)


// wymuszenie podania liczby
var num: Int = 0
var czyDalej = false
repeat {
    print("Podaj liczbę")
    if let tmp = Int(readLine()!){
        num = tmp
        czyDalej = true
    } else {
        print("wprowadzona liczba nie jest ")
    }
} while !czyDalej


// three ways to unwrap optional
// 1. force unwrap
var optionalString: String? = "Hello"
print(optionalString!)


// 2. optional binding
if let tmp = readLine() {
    print(tmp)
}


// 3. guard
guard let tmp = optionalString else {
    print("optionalString is nil")
    return
}
print(tmp)


// tips for string
var str = "Hello, playground"
print(str.count) // 17
print(str.isEmpty) // false
print(str.lowercased()) // hello, playground
print(str.uppercased()) // HELLO, PLAYGROUND
print(str.prefix(5)) // Hello
print(str.suffix(8)) // playground
print(str.contains("play")) // true
print(str.dropLast()) // Hello, playgroun
print(str.dropFirst()) // ello, playground
print(str.replacingOccurrences(of: "play", with: "work")) // Hello, workground
print(str.sorted()) // [" ", " ", "H", "a", "d", "e", "g", "l", "l", "n", "o", "o", "p", "r", "u", "y"]
print(str.split(separator: ",")) // ["Hello", " playground"]
// hasPrefix, hasSuffix


// tips for array
var arr = [1, 2, 3, 4, 5]
print(arr.first) // 1
print(arr.last) // 5
print(arr.contains(3)) // true
print(arr.sorted()) // [1, 2, 3, 4, 5]
print(arr.sorted(by: >)) // [5, 4, 3, 2, 1]
print(arr.reversed()) // [5, 4, 3, 2, 1]
print(arr.prefix(2)) // [1, 2]
print(arr.suffix(2)) // [4, 5]
print(arr.map { $0 * 2 }) // [2, 4, 6, 8, 10]
print(arr.filter { $0 % 2 == 0 }) // [2, 4]
print(arr.reduce(0, +)) // 15 (sum) or you can use * to get product
print(arr.reduce("", { $0 + String($1) })) // 12345


// tips for dictionary
var dict = ["a": 1, "b": 2, "c": 3]
print(dict["a"]) // 1
print(dict.keys) // ["a", "b", "c"]
print(dict.values) // [1, 2, 3]
print(dict.sorted(by: { $0.key < $1.key })) // [("a", 1), ("b", 2), ("c", 3)]
print(dict.sorted(by: { $0.value < $1.value })) // [("a", 1), ("b", 2), ("c", 3)]
print(dict.mapValues { $0 * 2 }) // ["a": 2, "b": 4, "c": 6]
print(dict.filter { $0.value % 2 == 0 }) // ["b": 2]


// tips for enum
enum Direction {
    case north
    case south
    case east
    case west
}
var dir = Direction.north
dir = .south
switch dir {
case .north:
    print("north")
case .south:
    print("south")
case .east:
    print("east")
case .west:
    print("west")
}


// for with terminator
for i in 1...5 {
    print(i, terminator: " ")
}
// 1 2 3 4 5


// 1...10 -> 1, 2, ..., 10
// 1..<10 -> 1, ..., 9


// function to create 2d array
let rows = 3
let cols = 4
func create2dArray(rows: Int, cols: Int) -> [[Int]] {
    var arr = [[Int]]()
    for _ in 0..<rows {
        var tmp = [Int]()
        for _ in 0..<cols {
            tmp.append(Int.random(in: 1...10))
        }
        arr.append(tmp)
    }
    return arr
}


// functon returns several values
func getMinMax(arr: [Int]) -> (min: Int, max: Int) {
    var min = arr[0]
    var max = arr[0]
    for i in 1..<arr.count {
        if arr[i] < min {
            min = arr[i]
        }
        if arr[i] > max {
            max = arr[i]
        }
    }
    return (min, max)
}
let arr = [1, 2, 3, 4, 5]
let (min, max) = getMinMax(arr: arr)


// how to use inout
func swap(a: inout Int, b: inout Int) {
    let tmp = a
    a = b
    b = tmp
}
var a = 1
var b = 2
swap(&a, &b)
print(a, b) // 2 1


// tips for class
class Person {
    var name: String
    var age: Int
    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }
}
var p = Person(name: "John", age: 20)
print(p.name, p.age) // John 20
// function inside class
class Person {
    var name: String
    var age: Int
    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }
    func sayHello() {
        print("Hello, my name is \(name)")
    }
}
var p = Person(name: "John", age: 20)
p.sayHello() // Hello, my name is John
// child class
class Student: Person {
    var school: String
    init(name: String, age: Int, school: String) {
        self.school = school
        super.init(name: name, age: age)
    }
    override func sayHello() {
        print("Hello, my name is \(name), I am a student")
    }
}   
var s = Student(name: "John", age: 20, school: "MIT")
s.sayHello() // Hello, my name is John, I am a student
// static property, i other words, how to count the number of instances
class Person {
    static var count = 0
    var name: String
    var age: Int
    init(name: String, age: Int) {
        Person.count += 1
        self.name = name
        self.age = age
    }
}
var p1 = Person(name: "John", age: 20)
var p2 = Person(name: "Mary", age: 21)
print(Person.count) // 2
// static function
class Person {
    static var count = 0
    static func getCount() -> Int {
        return count
    }
    var name: String
    var age: Int
    init(name: String, age: Int) {
        Person.count += 1
        self.name = name
        self.age = age
    }
}
var p1 = Person(name: "John", age: 20)
var p2 = Person(name: "Mary", age: 21)
print(Person.getCount()) // 2


// tips for struct
struct Person {
    var name: String
    var age: Int
}
var p = Person(name: "John", age: 20)
print(p.name, p.age) // John 20
// function inside struct
struct Person {
    var name: String
    var age: Int
    func sayHello() {
        print("Hello, my name is \(name)")
    }
}
var p = Person(name: "John", age: 20)
p.sayHello() // Hello, my name is John
// static property
struct Person {
    static var count = 0
    var name: String
    var age: Int
    init(name: String, age: Int) {
        Person.count += 1
        self.name = name
        self.age = age
    }
}
var p1 = Person(name: "John", age: 20)
var p2 = Person(name: "Mary", age: 21)
print(Person.count) // 2
// static function
struct Person {
    static var count = 0
    static func getCount() -> Int {
        return count
    }
    var name: String
    var age: Int
    init(name: String, age: Int) {
        Person.count += 1
        self.name = name
        self.age = age
    }
}
var p1 = Person(name: "John", age: 20)
var p2 = Person(name: "Mary", age: 21)
print(Person.getCount()) // 2
// class with show function
class Person {
    var name: String
    var age: Int
    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }
    func show() {
        print("name: \(name), age: \(age)")
    }
}


// tips for enum
// enum is a type, like class and struct
enum Direction {
    case north
    case south
    case east
    case west
}
// you can use dot syntax to access enum
var dir = Direction.north
dir = .south
// make enum iterateable
enum Direction: CaseIterable {
    case north
    case south
    case east
    case west
}
for dir in Direction.allCases {
    print(dir)
}
// enum with raw value
enum Direction: Int {
    case north = 1
    case south = 2
    case east = 3
    case west = 4
}
var dir = Direction.north
print(dir.rawValue) // 1
// enum with associated value
enum Direction {
    case north(Int)
    case south(Int)
    case east(Int)
    case west(Int)
}
var dir = Direction.north(10)
switch dir {
case .north(let distance):
    print("north \(distance)")
case .south(let distance):
    print("south \(distance)")
case .east(let distance):
    print("east \(distance)")
case .west(let distance):
    print("west \(distance)")
}


// tips for object
// object is an instance of class
// object is a reference type
class Person {
    var name: String
    var age: Int
    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }
}
var p1 = Person(name: "John", age: 20)
var p2 = p1
p2.name = "Mary"
print(p1.name) // Mary
// object is a reference type
// struct is a value type
struct Person {
    var name: String
    var age: Int
}
var p1 = Person(name: "John", age: 20)
var p2 = p1
p2.name = "Mary"
print(p1.name) // John


// tips for tuples
// tuple is a group of values
var person = ("John", 20)
print(person.0, person.1) // John 20
// tuple with name
var person = (name: "John", age: 20)
print(person.name, person.age) // John 20
// tuple with type
var person: (String, Int) = ("John", 20)
print(person.0, person.1) // John 20
// tuple with type and name
var person: (name: String, age: Int) = ("John", 20)
print(person.name, person.age) // John 20


