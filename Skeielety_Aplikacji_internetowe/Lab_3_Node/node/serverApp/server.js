const http = require('http')
const fs = require('fs')
const port = 3000

function serveStaticFile(res, path, contentType, responseCode = 200) {
    fs.readFile(__dirname + path, (err, data) => {
        if (err) {
            res.writeHead(500, {'Content-Type': 'text/plain'})
            return res.end('500 - Blad wewnetrzny')
        }
        res.writeHead(responseCode, {'Content-Type': contentType})
        res.end(data)
    })
}

const server = http.createServer((req, res) => {
    switch (req.url) {
        case '/':
            serveStaticFile(res, '/public/home.html', 'text/html')
            break
        case '/about':
        case '/about.html':
            serveStaticFile(res, '/public/about.html', 'text/html')
            break
        case '/img/6.1.png':
            serveStaticFile(res, '/img/6.1.png', 'image/png')
            break
        default:
            serveStaticFile(res, '/public/404.html', 'text/html')
            break
    }
})
server.listen(port, () => console.log(`Server działa na porcie ${port}; ` + 'naciśnij Ctrl+C, aby zakończyć'))