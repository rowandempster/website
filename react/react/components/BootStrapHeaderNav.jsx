import React from 'react';
var Radium = require('radium');
import Navbar from 'react-bootstrap/lib/Navbar';
import NavItem from 'react-bootstrap/lib/NavItem';
import NavDropdown from 'react-bootstrap/lib/NavDropdown';
import MenuItem from 'react-bootstrap/lib/MenuItem';
import Nav from 'react-bootstrap/lib/Nav';
var ReactRouter = require('react-router');
var Link = ReactRouter.Link;


var ReactDOM = require('react-dom');
var styles = {
  dropDownItem: {
    color: "black",
    padding: "12px 16px",
    textDecoration: "none",
    display: "block"
  },
  dropDownLinkContainer: {
    ":hover": {
      backgroundColor: "#000000"
    },
    "focus":{
      backgroundColor: "#000000"
    }
  }
}

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


var HeaderNav = React.createClass({
  render:function(){
    return (<Navbar>
      <Navbar.Header>
        <Navbar.Brand>
          <p> Rowan Dempster </p>
        </Navbar.Brand>
      </Navbar.Header>
      <Nav>
        <NavDropdown eventKey={3} title="My Work" id="basic-nav-dropdown">
          <div style={styles.dropDownLinkContainer}>
            <DropDownItem  item={"Google"} link={"http://www.google.com"} route={false}/>
          </div>
          <MenuItem eventKey={3.2}>Another action</MenuItem>
          <MenuItem eventKey={3.3}>Something else here</MenuItem>
          <MenuItem divider />
          <MenuItem eventKey={3.3}>Separated link</MenuItem>
        </NavDropdown>
        <NavDropdown eventKey={3} title="Dropdown">
      <MenuItem eventKey={3.1}>Action</MenuItem>
      <MenuItem eventKey={3.2}>Another action</MenuItem>
      <MenuItem eventKey={3.3}>Something else here</MenuItem>
      <MenuItem divider />
      <MenuItem eventKey={3.3}>Separated link</MenuItem>
      </NavDropdown>
      <NavDropdown eventKey={3} title="Dropdown" id="basic-nav-dropdown">
      <MenuItem eventKey={3.1}>Action</MenuItem>
      <MenuItem eventKey={3.2}>Another action</MenuItem>
      <MenuItem eventKey={3.3}>Something else here</MenuItem>
      <MenuItem divider />
      <MenuItem eventKey={3.3}>Separated link</MenuItem>
      </NavDropdown>
      </Nav>
      </Navbar>);
    }
  });



  HeaderNav = Radium(HeaderNav);

  export default HeaderNav;
