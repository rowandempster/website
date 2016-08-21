import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var Radium = require('radium');
import FromLeftProjectCell from './Projects/FromLeftProjectCell'
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';

var Projects = React.createClass({
	render: function(){
		return (
        <div>
          <HeaderNav/>
          <MuiThemeProvider>
            <FromLeftProjectCell/>
          </MuiThemeProvider>
        </div>
        );
	}
});
export default Projects;

/* <HeaderNav/>
  <MuiThemeProvider>
  <FromLeftProjectCell/>
</MuiThemeProvider> */
