import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var Radium = require('radium');
import AboutMePageManager from './AboutMe/AboutMePageManager'

var App = React.createClass({
	getInitialState: function(){
		return {pageShouldAnimate: true};
	},
	clearNav: function(){
		console.log("content clicked");

	},
	render: function(){
		return (
			<div>
				<HeaderNav/>
				<div style={styles.home} onClick={this.clearNav}>
					<AboutMePageManager/>
				</div>
			</div>
		);
	}
});

var styles = {
	home: {
		position:"absolute",
		top:0,
		left:0,
		width:"100%",
		marginTop:20
	}
}

App = Radium(App);



export default App;
