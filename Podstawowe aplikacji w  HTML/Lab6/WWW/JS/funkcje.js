function raty() {
    var kwota = document.getElementById("kwota").value;
    var procenty = document.getElementById("procenty").value;
    var n = document.getElementById("n").value;
    var rata = document.getElementById("rata");
    var kwota_z_procentami = document.getElementById("kwota_z_procentami");
    var procenty_m = procenty / 12;
    var wyliczonaRata = (kwota * procenty_m) / (1 - (1 / Math.pow(1 + procenty_m, n)));
    if (isNaN(wyliczonaRata) || !isFinite(wyliczonaRata)) {
        rata.value = "0";
        kwota_z_procentami.value = "0";
    } else {
        rata.value = Math.round(wyliczonaRata * 100) / 100;
        kwota_z_procentami.value = Math.round((wyliczonaRata * n) * 100) / 100;
    }
}

function oblicz() {
    var tab = document.getElementsByName("operator");
    var op; //operacja arytmetyczna do wykonania
    for (let i = 0; i < tab.length; i++) {
        if (tab[i].checked) op = tab[i].value;
    }
    //pobierz x
    var x = document.getElementById("x").value;
    //pobierz y
    var y = document.getElementById("y").value;
    //oblicz i pokaż wynik w zależności od operatora (zastosuj switch)
    var obliczenie = document.getElementById("wynik");
    switch (op) {
        case "+":
            obliczenie.value = parseInt(x) + parseInt(y);
            break;
        case "-":
            obliczenie.value = parseInt(x) - parseInt(y);
            break;
        case "*":
            obliczenie.value = parseInt(x) * parseInt(y);
            break;
        case "/":
            obliczenie.value = parseInt(x) / parseInt(y);
            break;
        default:
            alert("Nie wybrano operatora")
            break;
    }
}