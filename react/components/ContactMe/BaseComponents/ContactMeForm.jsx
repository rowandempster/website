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
  }
};


var ContactMeForm = React.createClass({
  getInitialState: function(){
    return {
      snackbarOpen: false,
      emailStatus: "",
      inputName: "",
      inputEmail:"",
      inputSubject: "",
      inputMessage: ""
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
    console.log("showSnackbar with message = " + message);

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
      this.showSnackbar("Message Failed To Send");

    }
  });
},
render: function(){
  return(
    <div style={style.container}>
    <TextField hintText="Your Name" value={this.state.inputName} onChange={this.handleNameInput}/>
    <br/>
    <TextField hintText="Your Email" value={this.state.inputEmail} onChange={this.handleEmailInput}/>
    <br/>
    <TextField hintText="Subject" value={this.state.inputSubject} onChange={this.handleSubjectInput}/>
    <br/>
    <TextField hintText="Message" multiLine={true}
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
