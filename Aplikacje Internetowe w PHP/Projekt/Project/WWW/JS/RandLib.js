function fetchRandomArticle() {
    // Load the articles
    fetch('data/articles.json')
        .then(response => response.json())
        .then(data => {
            // Parse the file and store the articles
            const articles = data.articles;

            // Generate a random index
            const randomIndex = Math.floor(Math.random() * articles.length);

            // Retrieve the random article
            const randomArticle = articles[randomIndex];
            const name = randomArticle.title;
            const content = randomArticle.content;

            // Use the random article as needed
            document.getElementById('main_content').innerHTML += `<div class="article" id="`+ randomIndex +`"><h3>` + name + `</h3><p>` + content + `</p></div>`;
        })
        .catch(error => {
            console.error('Error loading articles:', error);
        });
}
function fetchRandomFact() {
    // Load the articles
    fetch('data/facts.json')
        .then(response => response.json())
        .then(data => {
            // Parse the file and store the facts
            const facts = data.facts;

            // Generate a random index
            const randomIndex = Math.floor(Math.random() * facts.length);

            // Retrieve the random fact
            const randomFact = facts[randomIndex];

            // Use the random fact as needed
            document.getElementById('rand_fact').innerHTML += `<p><h4>Ciekawy fakt!</h4></p><div class="fact">` + randomFact.content + `</div>`;

        })
        .catch(error => {
            console.error('Error loading articles:', error);
        });
}

