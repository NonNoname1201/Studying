function pokaz(id) {
    var tresc = "";
    switch (id) {
        case 2:
            tresc += pokazGalerie();
            break;
        case 3:
            tresc += pokazPost();
            break;
        case 4:
            tresc += pokazKontakt();
            break;
        default:
            tresc += pokazO();
    }
    //pobierz element o wskazanym id i ustaw jego nową zawartość:
    document.getElementById('blok').innerHTML = tresc;
}

function pokazO() {
    var tresc = '<h2><br />Pierwsze kroki</h2> ';
    //operator += uzupełnia łańcuch kolejną porcją znaków:
    tresc += '<p> W aplikacjach typu SPA ......</p>' +
        '<p class="srodek"><img src="images/baner.jpg" alt="Zdjęcie" /></p>' +
        '<article><h2>Wady SPA</h2><p>' +
        ' Czas wytworzenia oraz nakład pracy ... </p></article>';
    //przekaż wynik – gotową zawartość – do miejsca wywołania funkcji:
    return tresc;
}

function pokazGalerie() {
    var tresc = '<h2><br />Moja galeria</h2>';
    tresc += ' <div class="galeria">';
    //wygeneruj kod HTML z obrazami za pomocą pętli for:
    for (i = 1; i <= 10; i++) {
        //generuj kod HTML dla kolejnych obrazów:
        var nazwa = "galeria/miniaturki/obraz" + i + ".JPG";
        tresc += '<div class="slajd"> <img src = ' + nazwa + '/></div>';
    }
    return tresc + '</div>';
}

function pokazKontakt() {
    var tresc = '<h2><br />Kontakt</h2>';
    //add random contact info
    var tel = "+48 " + Math.floor(Math.random() * 1000) + "-" + Math.floor(Math.random() * 1000) + "-" + Math.floor(Math.random() * 1000);
    var email = "s" + Math.floor(Math.random() * 100000) + "@gmail.com";
    var adres = "ul. " + Math.floor(Math.random() * 100) + " 00-000 Warszawa";
    tresc += '<article class="srodek" ><p>Telefon: ' + tel + '</p>' + '<p>Email: ' + email + '</p>' + '<p>Adres: ' + adres + '</p></article>';

    return tresc;
}

function pokazPost() {
    //funkcja generuje kod formularza – dane wpisane w odpowiednie pola przez
    //użytkownika zostaną przekazane mailem na wskazany adres, ale najpierw po
    //zajściu zdarzenia submit (wyślij) – zostanie wywołana funkcja pokazDane()
    tresc = '<h2><br />Dodaj post</h2>';
    tresc += '<article class="srodek" ><form action="mailto:b.panczyk@pollub.pl" method="post" onsubmit="return pokazDane();" >' +
        'Twój email:<br /> <input type="email" name="email" id="email" required /><br />' +
        'Nazwisko i Imię: <br /><input type="text" name="name" id="name" required /><br />' +

        'Wiek: <br /><input type="radio" name="age" value="0-18" required /> Mniej niż 18' +
        '<input type="radio" name="age" value="18-30" required /> 18-30' +
        '<input type="radio" name="age" value="30-50" required /> 30-50' +
        '<input type="radio" name="age" value="50+" required /> Więcej niż 50<br />' +

        'Zainteresowania: <br /><input type="checkbox" name="hobby" value="sport" /> Sport' +
        '<input type="checkbox" name="hobby" value="muzyka" />Muzyka ' +
        '<input type="checkbox" name="hobby" value="film" />Film ' +
        '<input type="checkbox" name="hobby" value="książki" />Książki ' +
        '<input type="checkbox" name="hobby" value="sport" />Sport <br/>' +

        'Komentarz: <br /><textarea rows="3" cols="20" id="wiadomosc" name="wiadomosc" required></textarea>' +
        '<br /> <input type="submit" name="wyslij" value="Wyślij" />' +
        '</form></article>';
    return tresc;
}

function pokazDane() {
    //Funkcja zbiera dane wpisane w pola formularza i wyświetla okienko
    //typu confirm do zatwierdzenia przez użytkownika:
    var dane = "Następujące dane zostaną wysłane:\n";
    dane += "Email: " + document.getElementById('email').value + "\n";
    // uzupełnij dane ...
    dane += "Nazwisko i Imię: " + document.getElementById('name').value + "\n";
    dane += "Treść: " + document.getElementById('tresc').value + "\n";
    dane += "Komentarz: " + document.getElementById('wiadomosc').value + "\n";
    //wyświetl okienko typu confirm z danymi:
    if (window.confirm(dane)) return true;
    else return false;
}
