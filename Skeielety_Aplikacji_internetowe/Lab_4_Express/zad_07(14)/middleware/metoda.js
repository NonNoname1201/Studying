let metoda = (req, res, next) => {
    let info = "Metoda: " + req.method + "\n";
    let sciezka = "Ścieżka: "+ req.protocol + "://" + req.get('host') + req.originalUrl;
    info += sciezka;
    res.send(info);
}
let metodaMiddleware = (req, res, next) => {
    console.log("Metoda: ",req.method)
    let sciezka = "Ścieżka: "+ req.protocol + "://" + req.get('host') + req.originalUrl
    res.write(metodaInfo + "\n" + sciezkaInfo + "\n");
    next()
}

module.exports = {metoda, metodaMiddleware}