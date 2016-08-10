import React from 'react';
var Radium = require('radium');

var Content = React.createClass({
	render:function(){
		return (
			<div style={[styles.home]}>
				<h1 style={styles.h1}>Welcome to my website!</h1>


				<hr></hr>


				<p2>About Me!</p2>
				<p>My name is Rowan, and I program </p>

				<a href="google.com" key={1} style={styles.link}>Home</a>

				<hr></hr>

				<footer>
				<p  style={styles.footer}>Contact: rowan.dempster@gmail.com</p>
				</footer>

			</div>

			);
	}
});

var styles = {
  	home: {
		textAlign: "center",
		  		position:"absolute",
  		top:0,
  		left:0,
  		width:"100%",
  		backgroundImage: "url(pictures/animated_background.gif)",
		backgroundSize: "cover",
		height:2000,
		paddingTop:20
	},
	footer: {
	    color:"#FFFFFF",
	    padding: "0px",
    	fontSize:"50px"
	},
	h1 : {
		color:"#660033",
		fontSize:"50px",
		    ':hover': {
      backgroundColor: 'red'
    },

    ':focus': {
      backgroundColor: 'green'
    },

    ':active': {
      backgroundColor: 'yellow'
    }
	}

  
};

Content = Radium(Content);

export default Content;