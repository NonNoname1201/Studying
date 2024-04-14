const express = require('express')
const path = require('path')
const app = express()
const hbs = require('hbs')
app.set('view engine', 'hbs')
app.set('views', path.join(__dirname, 'views'))
app.get('/about', (req, res) => {
    res.render('about', {name: 'Jan'})
})
app.get('/info', (req, res) => {
    res.render('info', {name: 'Jan', email: '123123@io.oi', age: '23'})
})
app.listen(3000, () => console.log('Serwer działa!'))