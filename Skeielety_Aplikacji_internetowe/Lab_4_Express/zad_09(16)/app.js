const express = require('express')
const path = require('path')
const middlewareMethod = require('./Middleware/middleware.js')
const app = express()
const PORT = 3000

app.use(express.urlencoded({extended: true}))

app.use(middlewareMethod)

app.use(express.static(path.join(__dirname)));
app.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form.html"))
})

app.post("/result", (req, res) => {
    let username = req.body.username
    let password = req.body.password
    let response = '';
    if (!username || !password) {
        response = "Uzupełnij wszystkie pola!";
    } else {
        response = "Użytkownik: " + username + "<br>Hasło: " + password;
    }
    response += '<br><a href="/form"><button type="button">Return</button></a>';
    res.send(response);
})
app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))