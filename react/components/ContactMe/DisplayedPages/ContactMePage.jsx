import React from 'react';
import TextField from 'material-ui/TextField';
import ContactMeForm from "/Users/rowandempster/Documents/website-react/react/components/ContactMe/BaseComponents/ContactMeForm.jsx";
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import HeaderNav from '/Users/rowandempster/Documents/website-react/react/components/BootStrapHeaderNav.jsx';



var style= {
  form: {
    position: "absolute",
    top:0,
    bottom: 0,
    left: 0,
    right: 0,
    margin: "auto"
  }
};

var ContactMePage = React.createClass({
  render: function(){
    return(
      <div>
        <HeaderNav/>
        <MuiThemeProvider>
          <ContactMeForm />
        </MuiThemeProvider>
      </div>
    );
  }
});

export default ContactMePage;
