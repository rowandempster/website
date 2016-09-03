import React from 'react';
import TextField from 'material-ui/TextField';
var $ = require('jquery');
import RaisedButton from 'material-ui/RaisedButton';
import Snackbar from 'material-ui/Snackbar';



var style= {
  container: {
    textAlign: "center",
    marginTop: "15%"
  },
  message: {
    width:1000
  },
  submitButtom:{
    marginTop: 30,
    width:150
  },
  hidden:{
    display: "none",
    color: "transparent",
    backgroundColor: "transparent"
  },
};


var ContactMeForm = React.createClass({
  getInitialState: function(){
    return {
      snackbarOpen: false,
      emailStatus: "",
      inputName: "",
      inputEmail:"",
      inputSubject: "",
      inputMessage: "",
      nameStyle: style.hidden,
      emailStyle: style.hidden,
      messageStyle: style.hidden
    };
  },
  handleNameInput: function(event){
    this.setState({
      inputName: event.target.value
    });
  },
  handleEmailInput: function(event){
    this.setState({
      inputEmail: event.target.value
    });
  },
  handleSubjectInput: function(event){
    this.setState({
      inputSubject: event.target.value
    });
  },
  handleMessageInput: function(event){
    this.setState({
      inputMessage: event.target.value
    });
  },
  showSnackbar: function(message){
    this.setState({
      snackbarOpen: true,
      emailStatus: message
    });
  },
  hideSnackbar: function(){
    this.setState({
      snackbarOpen: false,
    });
  },
  testEmail: function(){
    if(this.checkValidInput()){
      this.clearFields();
      var self = this;
      var subject = this.state.inputSubject;
      var body ="<div><p>From Email: " + this.state.inputEmail + "</p><p>From Name: " + this.state.inputName + "</p><p>Message: " + this.state.inputMessage + "</p></div>";
      $.ajax({
        type: 'POST',
        url: 'http://52.205.175.117:3000/sayHello',
        data : { 'subject': subject,
        'body' : body
      },
      success: function(data) {
        self.showSnackbar("Message Sent");
      }, error: function (XMLHttpRequest, textStatus, errorThrown) {
        self.showSnackbar("Message Failed To Send");
      }
    });
  }
  else{
    this.showSnackbar("Please Complete Required Fields");
  }
},
checkValidInput: function(){
  var isNameGood = (this.state.inputName).length > 0;
  var isEmailGood = (this.state.inputEmail).length > 0;
  var isMessageGood = (this.state.inputMessage).length > 0;

  this.setState({
    nameStyle: isNameGood ? style.hidden: "",
    emailStyle: isEmailGood ? style.hidden: "",
    messageStyle: isMessageGood ? style.hidden: ""
  });
  return isNameGood && isEmailGood && isMessageGood;
},
clearFields: function(){
  this.setState({
    snackbarOpen: false,
    emailStatus: "",
    inputName: "",
    inputEmail:"",
    inputSubject: "",
    inputMessage: "",
    nameStyle: style.hidden,
    emailStyle: style.hidden,
    messageStyle: style.hidden
  });
},
render: function(){
  return(
    <div style={style.container}>
    <TextField hintText="Your Name"
    errorText="Your name is required!"
    errorStyle={this.state.nameStyle}
    value={this.state.inputName} onChange={this.handleNameInput}/>
    <br/>
    <TextField hintText="Your Email"
    errorText="Your email is required!"
    errorStyle={this.state.emailStyle}
    value={this.state.inputEmail} onChange={this.handleEmailInput}/>
    <br/>
    <TextField hintText="Subject" value={this.state.inputSubject} onChange={this.handleSubjectInput}/>
    <br/>
    <TextField hintText="Message"
    errorText="A message is required!"
    errorStyle={this.state.messageStyle}
    multiLine={true}
    style={style.message} value={this.state.inputMessage} onChange={this.handleMessageInput}/>
    <br/>
    <RaisedButton label="Send" primary={true} style={style.submitButtom}
    onTouchTap={this.testEmail}/>
    <Snackbar
    open={this.state.snackbarOpen}
    message={this.state.emailStatus}
    autoHideDuration={4000}
    onRequestClose={this.hideSnackbar}
    />
    </div>
  );
}
});

export default ContactMeForm;
