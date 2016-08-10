import React from 'react';
var Radium = require('radium');

var HeaderNavDropDownButton = React.createClass({
	getInitialState: function(){
		return {
			showingItems: false,
			style: styles.dropDownContainerGone
		}
	},

	toggleShowItems: function(){
		if(!(this.state.showingItems)){
			this.setState({
				showingItems: true,
				style: styles.dropDownContainerShow
			});
		}
		else {
			this.setState({
				showingItems: false,
				style: styles.dropDownContainerGone
			});
		}
	},

	render: function(){
		return (
			<div style={styles.dropDownButton} onClick={this.toggleShowItems}>
				{this.props.data.buttonTitle}
				<HeaderNavDropDownContianer style={this.state.style} data={this.props.data.dropDownItems}/>
			</div>
		);
	}
});

var HeaderNavDropDownContianer = React.createClass({


	render: function(){
		var menuArray = this.props.data;
		console.log("settings conainer style to: " + this.props.style);

		return (
			  <div style={this.props.style}>
			    <DropDownItem item={menuArray[0].item} link={menuArray[0].link}/>
			    <DropDownItem item={menuArray[1].item} link={menuArray[1].link}/>
			  </div>
			);
	}
});

var DropDownItem = React.createClass({
	render: function(){
		var item = this.props.item;
		var link = this.props.link;

		return(
				<a style={styles.dropDownItem} href={link}>{item}</a>
			);
	}
})

var styles = {
	dropDownContainerGone: {
	    display: "none",
	},

	dropDownItem: {
	    color: "black",
	    padding: "12px 16px",
	    textDecoration: "none",
	    display: "block",
	    ":hover": {
	    	backgroundColor: "#f1f1f1"
	    }
	},

	dropDownContainerShow: {
		display:"block",
		position: "absolute",
	    backgroundColor: "#f9f9f9",
	    minWidth: "160px",
	    boxShadow: "0px 8px 16px 0px rgba(0,0,0,0.2)",
	    marginTop:"14px"
	},
	dropDownButton: {
		display:"block",
		color: "white",
		textAlign:"center",
		padding: '14px 16px',
		textDecoration:"none",
    ':hover': {
      backgroundColor: '#111'
    },
    userSelect: "none"
}
}

HeaderNavDropDownButton = Radium(HeaderNavDropDownButton);

export default HeaderNavDropDownButton;