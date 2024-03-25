function saveProduct() {
    var product = document.getElementById("product").value;
    var price = document.getElementById("price").value;
    var color = document.getElementById("color").value;
    var quantity = document.getElementById("quantity").value;
    var productObject = {
        product: product,
        price: price,
        color: color,
        quantity: quantity
    };

    organizer = JSON.parse(localStorage.getItem("organizer"));
    if (organizer == null) {
        organizer = [];
        organizer.push(productObject);
    }else{
        organizer.push(productObject);
    }
    localStorage.setItem("organizer", JSON.stringify(organizer));
}

function displayBasket() {
    var table = document.getElementById("basketTable");

    table.innerHTML = "<tr><th style=\"width: 20%\">Nazwa produktu</th>" +
        "<th style=\"width: 20%\">Cena\t</th>" +
        "<th style=\"width: 20%\">Kolor</th>" +
        "<th style=\"width: 20%\">Liczba sztuk</th>" +
        "<th style=\"width: 20%\">Usuń produkt</th></tr>";

    var productsTemp = JSON.parse(localStorage.getItem("organizer"));

    for (var i = 0; i < productsTemp.length; i++) {
        table.innerHTML += "<tr><td>" + productsTemp[i].product + "</td>" +
            "<td>" + productsTemp[i].price + "</td>" +
            "<td>" + productsTemp[i].color + "</td>" +
            "<td>" + productsTemp[i].quantity + "</td>" +
            "<td><button onclick=\"deleteProduct(" + i + ")\">Usuń</button></td></tr>";
    }
}

function deleteAll() {
    localStorage.setItem("organizer", JSON.stringify([]));
    localStorage.clear();
    displayBasket();
}

function deleteProduct(product) {
    var productsTemp = JSON.parse(localStorage.getItem("organizer"));
    var index = productsTemp.indexOf(product);
    productsTemp.splice(index, 1);
    localStorage.setItem("organizer", JSON.stringify(productsTemp));
    displayBasket();
}

function searchProduct(){
    var search = document.getElementById("search").value;
    var productsTemp = JSON.parse(localStorage.getItem("organizer"));
    var table = document.getElementById("lookupTable");
    table.innerHTML = "<tr><th style=\"width: 20%\">Nazwa produktu</th>" +
        "<th style=\"width: 20%\">Cena\t</th>" +
        "<th style=\"width: 20%\">Kolor</th>" +
        "<th style=\"width: 20%\">Liczba sztuk</th>" +
        "<th style=\"width: 20%\">Usuń produkt</th></tr>";
    for (var i = 0; i < productsTemp.length; i++) {
        if (productsTemp[i].product.includes(search)) {
            table.innerHTML += "<tr><td>" + productsTemp[i].product + "</td>" +
                "<td>" + productsTemp[i].price + "</td>" +
                "<td>" + productsTemp[i].color + "</td>" +
                "<td>" + productsTemp[i].quantity + "</td>" +
                "<td><button onclick=\"deleteProduct(" + i + ")\">Usuń</button></td></tr>";
        }
    }
}