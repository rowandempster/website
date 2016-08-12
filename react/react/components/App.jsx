import React from 'react';
import Content from './Content';
import HeaderNav from './HeaderNav';
var Radium = require('radium');

var App = React.createClass({
	clearNav: function(){
		console.log("content clicked");
		this.forceUpdate();
		},
	render: function(){
		return (
			<div>
				<HeaderNav/>
				<div onClick={this.clearNav}>
					<Content/>
				</div>
			</div>
			);
	}
});

App = Radium(App);



export default App;