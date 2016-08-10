import React from 'react';
import Content from './Content';
import HeaderNav from './HeaderNav';
var Radium = require('radium');

var App = React.createClass({
	render: function(){
		return (
			<div>
			<div>
			<HeaderNav/>
			</div>
			<br/>


			<Content/>
			</div>
			);
	}
});

App = Radium(App);



export default App;