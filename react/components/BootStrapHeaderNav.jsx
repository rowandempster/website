import React from 'react';
var Radium = require('radium');
import Navbar from 'react-bootstrap/lib/Navbar';
import NavItem from 'react-bootstrap/lib/NavItem';
import NavDropdown from 'react-bootstrap/lib/NavDropdown';
import MenuItem from 'react-bootstrap/lib/MenuItem';
import Nav from 'react-bootstrap/lib/Nav';
var ReactRouter = require('react-router');
var Link = ReactRouter.Link;
var myModule = require('../data/headerData');
var headerData = myModule.HeaderData;


var ReactDOM = require('react-dom');
var styles = {
  dropDownItem: {
    color: "#333333",
    padding: "5px 20px",
    textDecoration: "none",
    display: "block",
    whiteSpace: "nowrap"
  },
  rightSideItem: {
    color: "#777777",
    display: "block",
    whiteSpace: "nowrap",
    ":hover": {
      backgroundColor: "red"
    }
  },
  dropDownLinkContainer: {
    ":hover": {
      backgroundColor: "#DEDEDE"
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
          <Link style={this.props.style} to={link}>{item}</Link>
      );
    }
    else{
      return(
          <a style={this.props.style} href={link}>{item}</a>
      );
    }
  }
});


var HeaderNav = React.createClass({
  render:function(){
    var dropDownDataArray = headerData.array;
    var dropDownViewArray = [];
    for(var i = 0; i<dropDownDataArray.length; i++){
      var itemDataArray = dropDownDataArray[i].dropDownItems;
      var itemViewArray = [];
      for(var j = 0; j<itemDataArray.length; j++){
        var itemViewToPush =
        <div style={styles.dropDownLinkContainer} key={itemDataArray[j].id}>
          <DropDownItem style={styles.dropDownItem} item={itemDataArray[j].item} link={itemDataArray[j].link}
            route={itemDataArray[j].route} key={itemDataArray[j].id}/>
        </div>;
        // var itemViewToPush = <p>hello</p>;
        itemViewArray.push(itemViewToPush);
      }
      var dropDownViewToPush = <NavDropdown eventKey={dropDownDataArray[i].id}
        key={dropDownDataArray[i].id} title={dropDownDataArray[i].buttonTitle}>
        {itemViewArray}
      </NavDropdown>
      dropDownViewArray.push(dropDownViewToPush);
    }

    return (<Navbar fixedTop={true} fluid={true}>
      <Navbar.Brand>
        <Link to={'/'}>{headerData.brand}</Link>
      </Navbar.Brand>
      <Navbar.Collapse>
        <Nav>
          {dropDownViewArray}
        </Nav>
        <Nav pullRight>
          <NavItem>
            <DropDownItem style={styles.rightSideItem} route={true} item={"Contact Me"} link={"http://google.com"}/>
          </NavItem>
          <NavItem>
            <DropDownItem style={styles.rightSideItem} route={true} item={"Resume"} link={"http://google.com"}/>
          </NavItem>
        </Nav>
      </Navbar.Collapse>
    </Navbar>);
    }
  });



  HeaderNav = Radium(HeaderNav);

  export default HeaderNav;
