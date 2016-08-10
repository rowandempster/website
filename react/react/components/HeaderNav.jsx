import React from 'react';
var Radium = require('radium');
import HeaderNavDropDownButton from "./HeaderNavDropDown";

var projectsData = {
		buttonTitle: "My Work", 
		dropDownItems: [
			{
				item:"Side Projects",
				link:"www.google.com"
			},
			{
				item:"Work Projects",
				link:"www.github.com"

			}

	]
};

var HeaderNav = React.createClass({

	render:function(){

		return (
			<div style={styles.headerContainer}>
				<ul style={styles.list}>
  					{/*<li style={styles.listItem}><a key={1} style={styles.link}>Home</a></li>*/}
  					{/* <li style={styles.listItem}><a  href="http://www.github.com/rowandempster" key={2}style={styles.link}>GitHub</a></li>*/}
  					<li style={styles.listItem}><HeaderNavDropDownButton data={projectsData} key={3}/></li>
  					{/* <li style={styles.listItem}><a key={4}style={styles.link}>Side Projects</a></li>*/}
  					{/* <li style={styles.listItem}><a key={5}style={styles.link}>School Work</a></li>*/}
  					 {/* <li style={styles.listItem}><a key={6}style={styles.link}>Hackathons</a></li>*/}
  					 {/* <li style={styles.listItem}><a key={7}style={styles.link}>Tech Blog</a></li>*/}


				</ul>
			</div>
				
			);
	}
});



var styles = {
  list: {
  	listStyleType: 'none',
    margin: 0,
    overflow: 'hidden',
    backgroundColor: '#333',
    width:"100%",
    },
	listItem: {
		float: 'left',
	},
	link: {
		display:"block",
		color: "white",
		textAlign:"center",
		padding: '14px 16px',
		textDecoration:"none",
    ':hover': {
      backgroundColor: '#111'
    }
	},
	headerContainer: {
 position:'fixed',
 top:'0px',
 zIndex:1000,
 left:0,
 width:"100%"
	}

};

HeaderNav = Radium(HeaderNav);

export default HeaderNav;

