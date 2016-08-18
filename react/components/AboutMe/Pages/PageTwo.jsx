import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');

var PageTwo = React.createClass({
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
          Universtiy of Waterloo
        </h1>
        <p>
          I finished my first two terms of school and first co-op term at the University of Waterloo.
        </p>
        <p>
          I am in the CS class of 2020.
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

export default PageTwo;
