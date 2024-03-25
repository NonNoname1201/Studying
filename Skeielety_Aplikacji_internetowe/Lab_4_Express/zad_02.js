const express = require('express')
const path = require('path')
const app = express()
const PORT = 3000

app.use(express.urlencoded({extended: true}))

app.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form.html"))
})

app.get("/form2", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form2.html"))
})

app.post("/result", (req, res) => {
    let username = req.body.username
    let password = req.body.password
    if (!username || !password) {
        res.send("Uzupełnij wszystkie pola!")
    } else {
        res.send("Użytkownik: " + username + "<br>Hasło: " + password)
    }
})

app.post("/result2", (req, res) => {
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

app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))