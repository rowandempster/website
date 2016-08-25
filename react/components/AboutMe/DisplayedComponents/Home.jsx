import React from 'react';
import HeaderNav from '/Users/rowandempster/Documents/website-react/react/components/BootStrapHeaderNav.jsx';
var Radium = require('radium');
import AboutMePageManager from '/Users/rowandempster/Documents/website-react/react/components/AboutMe/DisplayedComponents/AboutMePageManager.jsx'
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';

var Home = React.createClass({
	render: function(){
		return (
			<div>
				<HeaderNav/>
				<MuiThemeProvider>
					<AboutMePageManager/>
				</MuiThemeProvider>
			</div>
		);
	}
});


export default Home;
