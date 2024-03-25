function validateForm(event) {
    // Prevent form submission
    event.preventDefault();

    // Get form values
    const name = document.getElementById("name").value;
    const surname = document.getElementById("surname").value;
    const email = document.getElementById("email").value;
    const phone = document.getElementById("phone").value;
    const birthdate = document.getElementById("birthdate").value;
    const problemType = document.getElementById("problem-type").value;
    const gender = document.querySelector('input[name="gender"]:checked');
    const tag = document.querySelectorAll('input[name="tag"]:checked');
    const about = document.getElementById("about").value;

    // Perform additional validation if needed
    const today = new Date();
    const selectedDate = new Date(birthdate);
    if (selectedDate > today) {
        alert("Data urodzenia nie może być w przyszłości!");
        return;
    }

    if (tag.length === 0) {
        alert("Wybierz przynajmniej jeden tag!");
        return;
    }

    // Save the form data to local storage
    saveData(name, surname, email, phone, birthdate, problemType, gender, tag, about);

    // Reset the form
    event.target.reset();
    displayData();
}