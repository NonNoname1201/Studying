class punkt {
    var x: Int
    var y: Int
    init(x: Int, y: Int) {
        self.x = x
        self.y = y
    }
}

struct punkt2 {
    var x: Int
    var y: Int
    init(x: Int, y: Int) {
        self.x = x
        self.y = y
    }

    func add(p: punkt2) -> punkt2 {
        return punkt2(x: self.x + p.x, y: self.y + p.y)
    }
}

var p1 = punkt(x: 1, y: 2)
var p2 = punkt2(x: 3, y: 4)

p2 = p1
p2.x = 5

print(p1.x)
print(p2.x)

var p3 = punkt(x: 1, y: 2)
var p4 = punkt2(x: 3, y: 4)

p4 = p3
p4.x = 5

print(p3.x)
print(p4.x)

p3 = p3.add(p: p4)

var punkty = Set<punkt>()
punkty.insert(p1)
punkty.remove(p1)
if punkty.contains(p1) {
    print("Zawiera")
} else {
    print("Nie zawiera")
}

if punkty.isEmpty {
    print("Pusty")
} else {
    print("Nie pusty")
}

for p in punkty {
    print(p)
}

var s1: Set = [1, 2, 3]
var s2: Set = [3, 4, 5]

print(s1.union(s2))
print(s1.intersection(s2))
print(s1.subtracting(s2))
print(s1.symmetricDifference(s2))

var sl : [String: Int] = [:]
if sl.isEmpty {
    print("Pusty")
} else {
    print("Nie pusty")
}

sl["a"] = 1
sl["b"] = 2

var ls : [Int: String] = [:]
ls[1] = "a"
ls[2] = "b"

if let napis = ls.updateValue("c", forKey: 2) {
    print(napis)
}

ls.removeValue(forKey: 1)
for p in ls.values {
    print(p)
}
for p in ls.keys {
    print(p)
}
for (k, v) in ls {
    print(k, v)
}
