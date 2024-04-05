const express = require('express');
const path = require('path');
const router = require('./api/routes');
const auth = require('./middleware/autoryzacja');
const app = express();
const PORT = 3000;
app.use(express.urlencoded({extended: true}));

/*Zaimplementuj funkcję pośredniczącą isAuthorized, która sprawdza czy użytkownik jest
zalogowany i ma dostęp do zasobów. Jeżeli ustawionym hasłem jest secretpaswd -
użytkownik uzyska dostęp do danych, w przeciwnym wypadku wyświetli się informacja
Dostęp zabroniony oraz zostanie zwrócony status odpowiedzi 401. Przetestuj utworzoną
funkcję za pomocą narzędzia Insomnia.
b) Utwórz katalog api i w nim plik routes.js oraz przenieś do niego wszystkie metody
definiujące trasy.
Na początku tego pliku należy dołączyć szkielet express oraz moduł users. Dodatkowo
należy użyć klasy express.Router, aby utworzyć modułowe, montowalne manipulatory
tras. Instancja Routera jest kompletnym systemem middleware i routingu.
const router = express.Router()
W pliku, w którym znajduje się część główna aplikacji, powinien odbyć się import
zawartości pliku routes.js, a następnie dołącznie routera jako oprogramowania
pośredniczącego.
W wywołaniach metod obsługujących żądania obiekty app należy zastąpić obiektem
router. Ponadto na końcu tego modułu powinien zostać zainicjowany export obiektu
router.
Kolejną czynnością będzie modyfikacja tras w pliku routes.js we wszystkich
zaimplementowanych tam metodach odpowiedzialnych za routing, np:
router.get('/', (req, res) => {…}
router.get('/:id', (req, res) => {…}
c) Na koniec należy utworzyć katalog middleware, umieścić w nim pliki metoda.js
i autoryzacja.js oraz przenieś do nich kod metod pośredniczących o nazwie metoda.
*/

app.use(auth.isAuthorized);
app.use('/', router);



app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))