import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
import Well from 'react-bootstrap/lib/Well';
const {Grid, Row, Col} = require('react-flexbox-grid');
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');

var PageTwo = React.createClass({
  render: function(){
    var style = {
      marginBottom:0,
      marginTop:0,
      paddingTop:20,
      height: this.props.height,
      overflowY:"scroll",
    };
    return (
      <div style={style}>
        <Row>
          <Col xs>
            <Row center="xs">
              <img height={150} width={600} src="http://cemc.uwaterloo.ca/!images/donors/UniversityOfWaterloo_logo_horiz_rgb.png" alt="Waterloo"/>
            </Row>
          </Col>
          <Col xs>
            <Row middle="xs" style={{height:"150"}}>
              <p>
                I finished my first two terms of school and first co-op term at the University of Waterloo.
              </p>
              <p>
                I am in the CS class of 2020.
              </p>
            </Row>
          </Col>
        </Row>
      </div>
    );
  }
});

export default PageTwo;
