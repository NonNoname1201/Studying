const express = require('express')
const path = require('path')
const app = express()
const PORT = 3000
const {check, validationResult} = require('express-validator');

app.use(express.urlencoded({extended: true}))

app.get("/form3", (req, res) => {
    res.sendFile(path.join(__dirname, "HTML/form3.html"))
})

app.post("/result3", [
    /*
    Listing 1.14 Fragment kodu z własną walidacją polegającą na generowaniu wyjątku
    check('email').custom(email => {
    if(alreadyHaveEmail(email)){
    throw new Error('Email już istnieje!')
    }
    }),
   Listing 1.15 Fragment kodu z własną walidacją polegającą na odrzuceniu obietnicy
    check('email').custom(email => {
    if(alreadyHaveEmail(email)){
    return Promise.reject('Email już istnieje!')
    }
    }),
    Listing 1.16 Fragment kodu, w którym zastosowano oczyszczanie danych
    check('message')
    .isLength({ min: 1 })
    .withMessage('Message is required')
    .trim()
    */

    check('name')
        .isLength({
            min: 2,
            max: 25
        }).withMessage("Imię musi mieć co najmniej 2 znaki i być krótsze niż 25 znaków").bail()
        .isAlpha().withMessage("Imię musi składać się tylko z liter").bail()
        .trim().stripLow().customSanitizer(value => {
        return value.charAt(0).toUpperCase()
    }),
    check('surname')
        .isLength({
            min: 2,
            max: 25
        }).withMessage("Nazwisko musi mieć co najmniej 2 znaki i być krótsze niż 25 znaków").bail()
        .isAlpha().withMessage("Nazwisko musi składać się tylko z liter").bail()
        .trim().stripLow().customSanitizer(value => {
        return value.charAt(0).toUpperCase()
    }),
    check('email')
        .isEmail().withMessage("Niepoprawny adres email").bail()
        .normalizeEmail(),
    check('phone')
        .isMobilePhone().withMessage("Niepoprawny numer telefonu").bail()
        .stripLow(),
    check('age')
        .isInt({min: 1, max: 110}).withMessage("Wiek musi być liczbą całkowitą z zakresu 1-110").bail()
], (req, res) => {
    //name, surname, email, phone, age
    let name = req.body.name
    let surname = req.body.surname
    let email = req.body.email
    let phone = req.body.phone
    let age = req.body.age

    const errors = validationResult(req)

    if (!errors.isEmpty()) {
        return res.status(400).json({errors: errors.array()})
    }
    res.send("Imię: " + name + "<br>Nazwisko: " + surname
        + "<br>Email: " + email + "<br>Telefon: " + phone
        + "<br>Wiek: " + age)
})

app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))