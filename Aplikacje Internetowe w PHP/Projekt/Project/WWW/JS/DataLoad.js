function fetchArticles() {
    // Load the articles
    fetch('data/articles.json')
        .then(response => response.json())
        .then(data => {
            // Parse the file and store the articles
            const articles = data.articles;

            for (let i = 0; i < articles.length; i++) {
                // Retrieve the article
                const article = articles[i];
                const preview = article.content.slice(0, 70) + '...';
                const name = article.title.split(':')[0];
                // Use the article as needed
                document.getElementById('main_content').innerHTML += `
                    <button class="container" onclick="OnClickInteractiveArticles(` + i + `)" ><h3>` + name + `</h3> <p>` + preview + `</p></button>
                `;
            }
        })
        .catch(error => {
            console.error('Error loading articles:', error);
        });
}

function saveData(name, surname, email, phone, birthdate, problemType, gender, tag, about) {
    // Get the existing form data from local storage
    const existingFormData = JSON.parse(localStorage.getItem("formData"));

    // Create an array with the new form data
    const newFormData = [{
        name,
        surname,
        email,
        phone,
        birthdate,
        problemType,
        gender: gender ? gender.value : null,
        tag: Array.from(tag).map(input => input.value),
        about
    }];

    // If existingFormData is an array, append the new form data to it
    if (Array.isArray(existingFormData)) {
        existingFormData.push(...newFormData);
    } else {
        // If existingFormData is not an array, create a new array with the new form data
        localStorage.setItem("formData", JSON.stringify(newFormData));
        return;
    }

    // Save the updated form data to local storage
    localStorage.setItem("formData", JSON.stringify(existingFormData));
}

function displayData() {
    // Get the form data from local storage
    const formData = JSON.parse(localStorage.getItem("formData"));

    // Check if there is any form data
    if (!formData || formData.length === 0) {
        document.getElementById("data-box").textContent = "No data available.";
        return;
    }

    // Clear the previous content of the data box
    document.getElementById("data-box").innerHTML = "";

    // Create a container element for each form entry
    formData.forEach((entry, index) => {
        const container = document.createElement("div");
        container.classList.add("entry-container");

        // Create a heading with the entry number
        const heading = document.createElement("h3");
        heading.textContent = `Entry ${index + 1}`;
        container.appendChild(heading);

        // Create a paragraph for each form field and its value
        for (const field in entry) {
            const paragraph = document.createElement("p");
            paragraph.innerHTML = `<strong>${field}:</strong> ${entry[field]}`;
            container.appendChild(paragraph);
        }

        // Create edit and delete buttons
        const editButton = document.createElement("button");
        editButton.textContent = "Edit";
        editButton.addEventListener("click", () => {
            editEntry(index);
        });
        container.appendChild(editButton);

        const deleteButton = document.createElement("button");
        deleteButton.textContent = "Delete";
        deleteButton.addEventListener("click", () => {
            deleteEntry(index);
        });
        container.appendChild(deleteButton);

        // Add the container to the data box
        document.getElementById("data-box").appendChild(container);
    });
}

function editEntry(index) {
    // Get the form data from local storage
    const formData = JSON.parse(localStorage.getItem("formData"));

    // Check if there is any form data
    if (!formData || formData.length === 0) {
        return;
    }

    // Retrieve the selected entry for editing
    const selectedEntry = formData[index];

    // Populate the form fields with the existing values
    document.getElementById("name").value = selectedEntry.name;
    document.getElementById("surname").value = selectedEntry.surname;
    document.getElementById("email").value = selectedEntry.email;
    document.getElementById("phone").value = selectedEntry.phone;
    document.getElementById("birthdate").value = selectedEntry.birthdate;
    document.getElementById("field-of-study").value = selectedEntry.fieldOfStudy;
    const genderInputs = document.querySelectorAll('input[name="gender"]');
    genderInputs.forEach((input) => {
        if (input.value === selectedEntry.gender) {
            input.checked = true;
        }
    });
    const memeTypeInputs = document.querySelectorAll('input[name="memeType"]');
    memeTypeInputs.forEach((input) => {
        if (selectedEntry.memeTypes.includes(input.value)) {
            input.checked = true;
        }
    });
    document.getElementById("about").value = selectedEntry.about;

    // Remove the selected entry from the form data array
    formData.splice(index, 1);

    // Save the updated form data to local storage
    localStorage.setItem("formData", JSON.stringify(formData));

    // Optionally, you can scroll to the top of the form for better visibility
    document.documentElement.scrollTop = 0;

    displayData();
}


function deleteEntry(index) {
    // Get the form data from local storage
    const formData = JSON.parse(localStorage.getItem("formData"));

    // Check if there is any form data
    if (!formData || formData.length === 0) {
        return;
    }

    // Remove the entry from the form data array
    formData.splice(index, 1);

    // Save the updated form data to local storage
    localStorage.setItem("formData", JSON.stringify(formData));

    // Refresh the displayed data
    displayData();
}

function deleteAllData() {
    localStorage.removeItem("formData");
    document.getElementById("data-box").innerHTML = "All data has been deleted.";
}