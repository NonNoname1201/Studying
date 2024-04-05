/*Na początku tego pliku należy dołączyć szkielet express oraz moduł users. Dodatkowo
należy użyć klasy express.Router, aby utworzyć modułowe, montowalne manipulatory
tras. Instancja Routera jest kompletnym systemem middleware i routingu.
const router = express.Router()*/
const express = require('express');
const path = require('path');
const router = express.Router();

router.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form.html"))
})

router.get("/form2", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form2.html"))
})

router.post("/result", (req, res) => {
    let username = req.body.username
    let password = req.body.password
    if (!username || !password) {
        res.send("Uzupełnij wszystkie pola!")
    } else {
        res.send("Użytkownik: " + username + "<br>Hasło: " + password)
    }
})

router.post("/result2", (req, res) => {
    console.log(req.body)
    let fullname = req.body.fullname
    let langs = req.body.language
    if (!fullname || !langs) {
        res.send("Uzupełnij wszystkie pola!")
    } else {
        res.send("Imię i nazwisko: " + fullname
            + "<br>Języki: "
            + langs.join(", "))
    }
})