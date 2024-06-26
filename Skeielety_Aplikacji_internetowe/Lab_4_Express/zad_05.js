const express = require('express')
const path = require('path')
const app = express()
const PORT = 3000
const {check, validationResult} = require('express-validator');

const users = require('./users')
const fs = require('fs');

fs.writeFile('./data/users.json', JSON.stringify(users), (err) => {
    if (err) throw err;
    console.log('Data written to file');
});

app.use(express.urlencoded({extended: true}))

let metoda = (req, res, next) => {
    let info = "Metoda: " + req.method + "\n";
    let sciezka = "Ścieżka: "+ req.protocol + "://" + req.get('host') + req.originalUrl;
    info += sciezka;
    res.send(info);
}

app.use(metoda)

app.get('/api/users/:id', (req, res) => {
    const found = users.some(user => user.id === parseInt(req.params.id))
    if (found) {
        res.json(users.filter(user => user.id === parseInt(req.params.id)))
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie został odnaleziony`})
    }
})

app.post('/api/users', (req, res) => {
    const newUser = {
        id: users.length + 1,
        name: req.body.name,
        email: req.body.email,
        status: "aktywny"
    }
    if (!newUser.name || !newUser.email) {
        return res.status(400).json({msg: 'Wprowadź poprawne imię i nazwisko oraz email!'})
    }
    users.push(newUser)
    res.json(users)
})

app.patch('/api/users/:id', (req, res) => {
    const found = users.some(user => user.id === parseInt(req.params.id))
    if (found) {
        const updUser = req.body
        users.forEach(user => {
            if (user.id === parseInt(req.params.id)) {
                user.name = updUser.name ? updUser.name : user.name
                user.email = updUser.email ? updUser.email : user.email
                res.json({msg: 'Dane użytkownika zaktualizowane', user})
            }
        })
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie istnieje!`})
    }
})

app.delete('/api/users/:id', (req, res) => {
    const found = users.some(user => user.id === parseInt(req.params.id))
    if (found) {
        res.json({msg: 'Użytkownik usunięty', users: users.filter(user => user.id !== parseInt(req.params.id))})
        delete users[parseInt(req.params.id) - 1]
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie istnieje!`})
    }
})

app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))