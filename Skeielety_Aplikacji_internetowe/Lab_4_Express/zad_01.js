const express = require('express');
const app = express();
const PORT = 3000;

app.get('/', (req, res) => {
  res.send('Prosty serwer oparty na szkielecie programistycznym Express!');
});

app.get('/about', (req, res) => {
  res.send('Autor strony: Volodymyr Dobrohorskyi');
});

app.listen(PORT, () => {
  console.log('App is listening on port ' + PORT);
});