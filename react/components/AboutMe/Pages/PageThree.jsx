import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');

var PageThree = React.createClass({
  render: function(){
    var style = {
      marginBottom:0,
      paddingLeft:50,
      height: this.props.height,
      overflowY:"scroll",
    };
    return (
      <Jumbotron style={style}>
        <h1>
          TribalScale
        </h1>
        <p>
          First my first co-op I worked at TribalScale in downtown Toronto.
        </p>
        <p>
          At TribalScale I worked as an Android developer, developing mobile apps for ABC News and Helpful Inc.
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
        <p>
          This is the About Me section of my website, use the NavBar at the top to explore the other sections
        </p>
      </Jumbotron>
    );
  }
});

export default PageThree;
