const express = require('express');
const hbs = require('hbs');
const path = require("path");
const bodyParser = require('body-parser');

const app = express();

app.set('view engine', 'hbs')
app.set('views', path.join(__dirname, 'views'))

app.use(bodyParser.urlencoded({extended: false}));

app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.render('color', {bgColor: '#aaaaaa'}); // Default to gray
});

app.post('/', (req, res) => {
    const color = req.body.color;
    const regex = /^#[0-9A-F]{6}$/i;
    const regexWithoutHash = /^[0-9A-F]{6}$/i;
    let newColor = color;
    if (regex.test(color)) {
        newColor = color;
    } else if (regexWithoutHash.test(color)) {
        newColor = '#' + color;
    } else {
        newColor = '#aaaaaa'; // Default to white
    }
    res.render('color.hbs', {bgColor: newColor});
});

app.listen(3000, () => {
    console.log('Server started on port 3000');
});