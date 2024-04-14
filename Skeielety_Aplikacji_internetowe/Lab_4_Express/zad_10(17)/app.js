const express = require('express');
const path = require('path');

const app = express();

app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'HTML/home.html'));
})

app.get('/about', (req, res) => {
    res.sendFile(path.join(__dirname, 'HTML/about.html'));
})

app.get('/gallery', (req, res) => {
    res.sendFile(path.join(__dirname, 'HTML/gallery.html'));
})

app.get('/support', (req, res) => {
    res.sendFile(path.join(__dirname, 'HTML/support.html'));
})

app.get('/form', (req, res) => {
    res.sendFile(path.join(__dirname, 'HTML/form.html'));
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
    response += '<footer>\n' +
        '        <p>Copyright &copy; 2023</p>\n' +
        '        <a href="home.html">Home</a>\n' +
        '    </footer>'
    res.send(response);
})

app.listen(3000, () => {
    console.log('Server started on port 3000');
});