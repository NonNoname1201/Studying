const getDate = require('./getDate.js');

const middlewareMethod = (req, res, next) => {
    // Get the current date and time
    const currentDateTime = getDate();

    // Prepare the log string
    const logString = `[${currentDateTime}] Method: ${req.method}, URL: ${req.url}, Body: ${JSON.stringify(req.body)}`;

    // Log the data
    console.log(logString);

    // Call the next middleware function
    next();
}

module.exports = middlewareMethod;