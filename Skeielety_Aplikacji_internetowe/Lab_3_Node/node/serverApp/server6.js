const http = require("http")
const hostname = "localhost"
const port = 3000
const server = http.createServer((req, res) => {
    res.statusCode = 200
    res.setHeader("Content-Type", "text/html; charset=utf-8")
    let responseText;
    switch (req.url) {
        case "/home":
            responseText = "<h1>Strona główna</h1>"
            break
        case "/about":
            responseText = "<h1>Strona o mnie</h1>"
            break
        default:
            responseText = "<h1>Strona nie istnieje</h1>"
            break
    }
    res.end(responseText)
})
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`)
})