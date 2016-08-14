import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './HeaderNav';
var Radium = require('radium');

var App = React.createClass({
	clearNav: function(){
		console.log("content clicked");
		this.forceUpdate();
	},
	keyDown: function(){
		console.log("detected key down");
	},
	render: function(){
		return (
			<div>
				<HeaderNav/>
				<div style={styles.home} onClick={this.clearNav}>
					<HomePager/>
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
