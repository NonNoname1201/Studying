const http = require("http")
const hostname = "localhost"
const port = 3000
const server = http.createServer((req, res) => {
    res.statusCode = 200
    res.setHeader("Content-Type", "text/html; charset=utf-8")
    res.end(
        "<h1>Aplikacja w Node</h1>" +
        "<h2>To jest odpowiedź HTML</h2>" +
        "<ul>" +
        "<li>1.</li>" +
        "<li>2.</li>" +
        "<li>3.</li>" +
        "</ul>"
    )
})
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`)
})