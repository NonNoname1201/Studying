const isAuthorized = (req, res, next) => {
    const password
        = req.query.password
    if (password === "secretpaswd") {
        next()
    }
    else {
        res.status(401).send("Dostęp zabroniony")
    }
}