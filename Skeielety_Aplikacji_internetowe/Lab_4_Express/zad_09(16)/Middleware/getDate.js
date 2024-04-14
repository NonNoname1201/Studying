function getCurrentDateTime() {
    // Get current date and time
    const currentDateTime = new Date();

    // Return the current date and time as a string
    return currentDateTime.toString();
}

module.exports = getCurrentDateTime;