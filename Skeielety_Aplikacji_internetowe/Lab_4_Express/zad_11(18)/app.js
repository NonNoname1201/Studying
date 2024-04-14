const express = require('express');
const path = require('path');

const app = express();

app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
    const value = parseFloat(req.query.value);
    const toRad = req.query.toRad;

    if (isNaN(value)) {
        res.send('Invalid value');
        return;
    }

    if (toRad === 'true' || toRad === '1') {
        res.send(value.toString() + " deg  =  " + (value * Math.PI / 180).toString() + " rad");
    }
    else if (toRad === 'false' || toRad === '0') {
        res.send(value.toString() + " rad  =  " + (value * 180 / Math.PI).toString() + " deg");
    }
    else {
        res.send('Invalid conversion type');
    }
})

app.listen(3000, () => {
    console.log('Server started on port 3000');
})