import React from 'react';
var Radium = require('radium');
var ReactRouter = require('react-router');
var Link = ReactRouter.Link;

var HeaderNavDropDownButton = React.createClass({
	getInitialState: function(){
		return {
				showingItems: false
			}
	},
	componentWillReceiveProps: function(nextProps) {
	  this.setState({
	    showingItems: (nextProps.idToShow == nextProps.data.id)
	  });
	},

	render: function(){
		if(this.state.showingItems){
			return (
				<div style={styles.dropDownButton} onClick={this.toggleShowItems}>
					{this.props.data.buttonTitle}
					<HeaderNavDropDownContianer style={styles.dropDownContainerShow} data={this.props.data.dropDownItems}/>
				</div>
			);
		}
		else {
			return (
				<div style={styles.dropDownButton} onClick={this.toggleShowItems}>
					{this.props.data.buttonTitle}
					<HeaderNavDropDownContianer style={styles.dropDownContainerGone} data={this.props.data.dropDownItems}/>
				</div>
			);
		}

	}
});

var HeaderNavDropDownContianer = React.createClass({


	render: function(){
		var menuArray = this.props.data;
		var dropDownItemArray = [];
		for(var i=0; i<menuArray.length; i++){
			dropDownItemArray.push(<DropDownItem item={menuArray[i].item} link={menuArray[i].link} 
													key={menuArray[i].id} route={menuArray[i].route}/>);
		}

		return (
			  <div style={this.props.style}>
					{dropDownItemArray}
			  </div>
			);
	}
});

var DropDownItem = React.createClass({
	render: function(){
		var item = this.props.item;
		var link = this.props.link;
		var route = this.props.route;
		if(route){
			return(
					<Link style={styles.dropDownItem} to={link}>{item}</Link>
				);
		}
		else{
			return(
				<a style={styles.dropDownItem} href={link}>{item}</a>
			);
		}
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