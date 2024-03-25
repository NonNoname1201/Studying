function OnClickInteractiveArticles(id) {
    document.getElementById('main_content').innerHTML = `<p><button onclick="OnClickInteractiveArticlesBack()" class="container">Do artykulów</button></p>`;

    // Load the article
    fetch('data/articles.json')
        .then(response => response.json())
        .then(data => {
            // Parse the file and store the articles
            const articles = data.articles;
            const article = articles[id];
            const name = article.title;
            const content = article.content;
            // Use the article as needed
            document.getElementById('main_content').innerHTML += `<div class="article container"><h3>` + name + `</h3><p>` + content + `</p></div>`;
        })
        .catch(error => {
            console.error('Error loading articles:', error);
        });

    // Load the controls
    document.getElementById('alt_nav').innerHTML += `<button onclick="OnClickInteractiveArticlesBack()">Back</button>`;
}

function OnClickInteractiveArticlesBack() {
    document.getElementById('main_content').innerHTML = `<h3>Dostępne artykuły:</h3>`;
    fetchArticles();
}