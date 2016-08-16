import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');

var PageOne = React.createClass({
  render: function(){
    var style = {
      height: this.props.height,
      marginBottom:0
    };
    return (
      <Jumbotron style={style}>
        <h1>
          Hi, my name is Rowan.
        </h1>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          Tap enter to continue, or the up arrow to return to the top
        </p>
      </Jumbotron>
    );
  }
});

export default PageOne;
