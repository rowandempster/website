import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var Radium = require('radium');
import AboutMePageManager from './AboutMe/AboutMePageManager'
var $ = require('jquery');

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
			<AboutMePageManager/>
			</div>
		);
	}
});

App = Radium(App);



export default App;
