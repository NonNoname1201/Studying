/*
Zadanie 2.1. Aplikacja kolorowe kwadraty
Napisać aplikację, która wyświetli 6 kwadratów o wymiarze 200 na 200, każdy w innym
kolorze

Wskazówki:
    1. Należy zdefiniować tablicę tablica_kolorow zawierającą 6 kolorów.
    2. W pętli ForEach po liczbie kolorów narysować kwadrat używając Rectangle() i ustawić dla każdego następujące właściwości:
        .fill(tablica_kolorow[$0])
        .frame(width: 200, height: 200)
        .offset(x: CGFloat($0) * 10.0,y: CGFloat($0) * 10.0)
*/

import SwiftUI

let tablica_kolorow: [Color] = [.red, .green, .blue, .yellow, .orange, .purple]

struct ContentView: View {
    var body: some View {
        ZStack {
            ForEach(0..<6) { index in
                Rectangle()
                    .fill(tablica_kolorow[index])
                    .frame(width: CGFloat(200 - index * 20), height: CGFloat(200 - index * 20))
                    .offset(x: CGFloat(index) * 10.0, y: CGFloat(index) * 10.0)
            }
        }
    }
}

///////////////////////////////////////////////
/*
Zadanie 2.2. Aplikacja z rysunkiem
Napisać aplikację, która wyświetli zdjęcie i na dole tego zdjęcia wypisze jego tytuł oraz autora
zdjęcia. Napisy powinny być wyrównane do lewego brzegu pudełka.

Wskazówki:
    1. Przeźroczystość uzyskuje się stosując kolor .primary.
    2. Należy zastosować układ postaci:
        a. ZStack zawierający obrazek oraz HStack;
        b. HStack zawierający dwa napisy zgrupowane w VStack oraz wypełnienie przestrzeni Spacer(). 
*/

import SwiftUI

struct ContentView: View {
    var body: some View {
        ZStack {
            Image("zdjecie")
                .resizable()
                .scaledToFit()
            HStack {
                VStack(alignment: .leading) {
                    Text("Tytuł zdjęcia")
                        .font(.title)
                        .foregroundColor(.primary)
                    Text("Autor zdjęcia")
                        .font(.subheadline)
                        .foregroundColor(.primary)
                }
                Spacer()
            }
            .padding()
        }
    }
}

///////////////////////////////////////////////

/*
Zadanie 2.3. Aplikacja trójkąt
Napisać aplikację, w której użytkownik podaje długości trzech boków trójkąta i po wciśnięciu
przycisku „Trojkat” pojawia się komunikat o tym, czy z tych boków da się zbudować trójkąt
czy nie. Dodatkowo zostają wyświetlone wartości podanych
długości boków. Zastosować różne kolory czcionek i kształtów do poszczególnych elementów
interfejsu.
Wskazówki:
    1. Pobranie wartości realizuje się poprzez instrukcję Binding.
    Jeżeli podana wartość nie jest liczbą całkowitą, wtedy wartość zmiennej b1 zostaje
    ustawiona na 0.
    HStack {
        Text("Podaj bok 1:")
        TextField("Podaj długość boku 1", text: Binding()
            get: { String(b1) }
            set: { b1 = Int($0) ?? 0 })
    }
    2. Warunek budowy trójkąta jest następujący: długości boków muszą być dodatnie i suma
    każdych dwóch boków musi być dłuższa od trzeciego boku.
*/

import SwiftUI

struct ContentView: View {
    @State private var b1 = 0
    @State private var b2 = 0
    @State private var b3 = 0
    @State private var komunikat = ""
    var body: some View {
        VStack {
            HStack {
                Text("Podaj bok 1:")
                TextField("Podaj długość boku 1", text: Binding(
                    get: { String(b1) },
                    set: { b1 = Int($0) ?? 0 })
                )
            }
            HStack {
                Text("Podaj bok 2:")
                TextField("Podaj długość boku 2", text: Binding(
                    get: { String(b2) },
                    set: { b2 = Int($0) ?? 0 })
                )
            }
            HStack {
                Text("Podaj bok 3:")
                TextField("Podaj długość boku 3", text: Binding(
                    get: { String(b3) },
                    set: { b3 = Int($0) ?? 0 })
                )
            }
            Button(action: {
                if b1 > 0 && b2 > 0 && b3 > 0 {
                    if b1 + b2 > b3 && b1 + b3 > b2 && b2 + b3 > b1 {
                        komunikat = "Można zbudować trójkąt"
                    } else {
                        komunikat = "Nie można zbudować trójkąta"
                    }
                } else {
                    komunikat = "Podane długości boków muszą być dodatnie"
                }
            }) {
                Text("Trójkąt")
                    .font(.title)
                    .foregroundColor(.white)
                    .padding()
                    .background(Color.blue)
                    .cornerRadius(40)
            }
            Text(komunikat)
                .font(.title)
                .foregroundColor(.red)
        }
    }
}

///////////////////////////////////////////////
/*
Zadanie 2.4. Aplikacja cztery działania
Napisać aplikację, w której użytkownik podaje:
• dwie liczby całkowite i
• wybiera jeden z czterech przycisków oznaczających odpowiednio cztery działania
arytmetyczne: +, –, *, /.
Po wciśnięciu przycisku pojawia się wynik wybranego działania. Zabezpieczyć przed
wykonaniem dzielenia przez zero.
*/

import SwiftUI

struct ContentView: View {
    @State private var liczba1 = 0
    @State private var liczba2 = 0
    @State private var wynik = 0
    var body: some View {
        VStack {
            HStack {
                Text("Podaj liczbę 1:")
                TextField("Podaj liczbę 1", text: Binding(
                    get: { String(liczba1) },
                    set: { liczba1 = Int($0) ?? 0 })
                )
            }
            HStack {
                Text("Podaj liczbę 2:")
                TextField("Podaj liczbę 2", text: Binding(
                    get: { String(liczba2) },
                    set: { liczba2 = Int($0) ?? 0 })
                )
            }
            HStack {
                Button(action: {
                    wynik = liczba1 + liczba2
                }) {
                    Text("+")
                        .font(.title)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .cornerRadius(40)
                }
                Button(action: {
                    wynik = liczba1 - liczba2
                }) {
                    Text("-")
                        .font(.title)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .cornerRadius(40)
                }
                Button(action: {
                    wynik = liczba1 * liczba2
                }) {
                    Text("*")
                        .font(.title)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .cornerRadius(40)
                }
                Button(action: {
                    if liczba2 != 0 {
                        wynik = liczba1 / liczba2
                    } else {
                        wynik = 0
                    }
                }) {
                    Text("/")
                        .font(.title)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .cornerRadius(40)
                }
            }
            Text("Wynik: \(wynik)")
                .font(.title)
                .foregroundColor(.red)
        }
    }
}
