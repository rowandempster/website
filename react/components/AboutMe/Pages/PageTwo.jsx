import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
import PageHeader from 'react-bootstrap/lib/PageHeader';
import Well from 'react-bootstrap/lib/Well';
import { Row, Col, Grid } from 'elemental'
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');
import Paper from 'material-ui/Paper';
import Divider from 'material-ui/Divider';
import OneImageOneTextRow from './ReusableComponents/OneImageOneTextRow'
var module = require('/Users/rowandempster/Documents/website-react/react/data/AboutMe/PageTwoData');
var pageData = module.PageTwoData;

var PageTwo = React.createClass({
  render: function(){
    var style = {
      container: {
        marginBottom:0,
        paddingTop:20,
        marginLeft:20,
        height: this.props.height,
        overflowY:"scroll",
        overflowX:"hidden"
      },
      uwaterlooImage: {
        width: "100%",
      },
      uwaterlooImagePage: {
        marginTop: 20,
        marginLeft:1
      },
      divider: {
        marginTop:20,
        marginBottom:20,
        background: "#FFFFFF"
      },
      paragraphContainer:{
        display: "flex",
        alignItems: "center",
        justifyContent: "center"
      },
      rowOne:{
        marginBottom:-20,
        marginLeft:0
      },
      rowOneTextContainer: {
        fontSize:25
      }
    };
    console.log(pageData);
    return (
      <div style={style.container}>
        <Row style={style.rowOne}>
          <h1>Education</h1>
        </Row>
        <Divider style={style.divider}/>
        <OneImageOneTextRow data={pageData.rows[0]}/>
        <Divider style={style.divider}/>
        <OneImageOneTextRow data={pageData.rows[1]}/>
        <Divider style={style.divider}/>
      </div>
      );
    }
  });

  export default PageTwo;
