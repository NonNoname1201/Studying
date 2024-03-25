const calc = (a, b, p) => {
    if (!(a || b || p)) {
        return "Podaj wszystkie argumenty!"
    }
    switch (p) {
        case '+': {
            return a + b
        }
        case '-': {
            return a - b
        }
        case '*': {
            return a * b
        }
        case '/': {
            return a / b
        }
        default: {
            return
        }
    }
}
exports.calc = calc;