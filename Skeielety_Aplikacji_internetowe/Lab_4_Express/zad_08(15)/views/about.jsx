const React = require('react')
const HelloMessage = (props) => {
    return <div>Nazwisko: {props.nazwisko} <br/>
    Email: {props.email} <br/>
    Wiek: {props.age} </div>
}
module.exports = HelloMessage