const express = require('express');
const path = require('path');
const router = require('./api/routes');
const auth = require('./middleware/autoryzacja');
const {metoda, metodaMiddleware} = require("./middleware/metoda");
const app = express();
const PORT = 3000;
app.use(express.urlencoded({extended: true}));

app.use(metoda);
app.use(metodaMiddleware);

app.use(auth.isAuthorized);
app.use('/', router);


app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))