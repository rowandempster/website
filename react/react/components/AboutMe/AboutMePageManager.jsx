import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');
import AboutMeView from './AboutMeView'
import PageOne from './Pages/PageOne'
import PageTwo from './Pages/PageTwo'
import PageThree from './Pages/PageThree'


//GLOBAL VARS
var viewPortHeight = (Math.max(document.documentElement.clientHeight, window.innerHeight || 0)) - 52;
var pageIsScrolling = false;
var pageArray = [
  <PageOne height={viewPortHeight}/>,
  <PageTwo height={viewPortHeight}/>,
  <PageThree height={viewPortHeight}/>];

//COMPONENTS

var AboutMePageManager = React.createClass({
  getInitialState: function(){
    return {
      previousPage: -1,
      currentPage: 0
    }
  },
  componentDidMount: function(){
    // disableScroll();
    ReactDOM.findDOMNode(this.refs.homePager).focus();
  },
  goToNextPage: function(key){
    if(key.keyCode == 13 && !pageIsScrolling && (this.state.currentPage+1)<pageArray.length)
    {
      this.setState(
        {
          previousPage: this.state.previousPage + 1,
          currentPage: this.state.currentPage + 1
        }
      );
      pageIsScrolling = true;
      setTimeout(function(){
        pageIsScrolling = false;
      }, 3000);
    }
    else if(key.keyCode == 38 && !pageIsScrolling){
      this.setState({
        previousPage: -1,
        currentPage: 0
      });
    }
  },
  render:function(){
    console.log("rendering with reset = " + this.state.reset);
    return (
      <div tabIndex="1" onKeyDown={this.goToNextPage} ref="homePager"
        style={styles.home}>
        <AboutMeView height={viewPortHeight} previousPage={this.state.previousPage}
          currentPage={this.state.currentPage} pageArray={pageArray}/>
      </div>
    );
  }
});


//DISABLING SCROLL


var keys = {37: 1, 38: 1, 39: 1, 40: 1};

function preventDefault(e) {
  e = e || window.event;
  if (e.preventDefault)
  e.preventDefault();
  e.returnValue = false;
}

function preventDefaultForScrollKeys(e) {
  if (keys[e.keyCode]) {
    preventDefault(e);
    return false;
  }
}

function disableScroll() {
  if (window.addEventListener) // older FF
  window.addEventListener('DOMMouseScroll', preventDefault, false);
  window.onwheel = preventDefault; // modern standard
  window.onmousewheel = document.onmousewheel = preventDefault; // older browsers, IE
  window.ontouchmove  = preventDefault; // mobile
  document.onkeydown  = preventDefaultForScrollKeys;
  $('body').on({
    'mousewheel': function(e) {
      if (e.target.id == 'el') return;
      e.preventDefault();
      e.stopPropagation();
    }
  });
}

// styles

var styles = {
  home: {
    position:"absolute",
    top:32,
    left:0,
    width:"100%",
    outline:"none"
  }
};

// EXPORTS

AboutMePageManager = Radium(AboutMePageManager);

export default AboutMePageManager;
