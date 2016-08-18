import React from 'react';
var Radium = require('radium');
import HeaderNavDropDownButton from "./HeaderNavDropDown";
var myModule = require('../data/headerData');
var headerArray = myModule.headerArray;
import Navbar from 'react-bootstrap/lib/Navbar';
import Nav from 'react-bootstrap/lib/Nav';
import NavItem from 'react-bootstrap/lib/NavItem';
import NavDropdown from 'react-bootstrap/lib/NavDropdown';
import MenuItem from 'react-bootstrap/lib/MenuItem';
var ReactRouter = require('react-router');
var Link = ReactRouter.Link;

var HeaderNav = React.createClass({
	getInitialState: function(){
		return {
			showingDropDownId:-1
		}
	},
	componentWillReceiveProps: function(nextProps) {
		this.setState({
			showingDropDownId:-1
		});
	},
	showAndCloseOthers: function(idToShow){
		if(idToShow == this.state.showingDropDownId){
			this.setState({
				showingDropDownId: -1
			});
		}
		else{
			this.setState({
				showingDropDownId: idToShow
			});
		}
	},

	render:function(){
		var headerViewArray = [];
		for(var i=0; i<headerArray.length; i++){
			var viewToPush = (<li style={styles.listItem}
				onClick={this.showAndCloseOthers.bind(this, (headerArray[i]).id)}
				key={(headerArray[i]).id}>
				<HeaderNavDropDownButton data={(headerArray[i])} key={(headerArray[i]).id} idToShow={this.state.showingDropDownId}/>
				</li>);
				headerViewArray.push(viewToPush);
			}
			return (
				<div style={styles.headerContainer}>
				<ul style={styles.list}>
				{headerViewArray}
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
