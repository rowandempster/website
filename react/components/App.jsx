import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var Radium = require('radium');
import AboutMePageManager from './AboutMe/AboutMePageManager'
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';

var App = React.createClass({
	getInitialState: function(){
		return {pageShouldAnimate: true};
	},
	clearNav: function(){
		console.log("content clicked");

	},
	componentDidMount(){
		document.body.style.overflow = 'hidden';
		document.body.style.overflowX = 'hidden';
	},
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

App = Radium(App);



export default App;
