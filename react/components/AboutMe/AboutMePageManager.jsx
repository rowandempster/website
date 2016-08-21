import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
import Button from 'react-bootstrap/lib/Button';
import ButtonGroup from 'react-bootstrap/lib/ButtonGroup';
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');
import AboutMeView from './AboutMeView'
import PageOne from './Pages/PageOne'
import ContentPage from './Pages/ReusableComponents/ContentPage'
var data = require('/Users/rowandempster/Documents/website-react/react/data/AboutMe/PageTwoData');

//GLOBAL VARS
var viewPortHeight = (Math.max(document.documentElement.clientHeight, window.innerHeight || 0)) - 65;
var pageIsScrolling = false;
var pageDataArray = data.PageArray;
var pageViewArray = [];
var pageOne = <PageOne height={viewPortHeight}/>;
pageViewArray.push(pageOne);
console.log(pageDataArray);
for (var i = 0; i<pageDataArray.length; i++){
  var viewToPush =
  <ContentPage
    height={viewPortHeight}
    data={pageDataArray[i]}
    key={pageDataArray[i].key}/>
  // var viewToPush = <h1>Hello</h1>

  pageViewArray.push(viewToPush);
}
const ANIMATION_TIME = 500;

//COMPONENTS

var AboutMePageManager = React.createClass({
  getInitialState: function(){
    return {
      previousPage: -1,
      currentPage: 0
    }
  },
  updateDimensions: function(){
    location.reload();
  },
  componentDidUpdate: function(){
    ReactDOM.findDOMNode(this.refs.homePager).focus();
  },
  componentDidMount: function(){
    ReactDOM.findDOMNode(this.refs.homePager).focus();
    window.addEventListener("resize", this.updateDimensions);
  },
  componentWillUnmount:function(){
    window.removeEventListener("resize", this.updateDimensions);
  },
  goToTop: function(){
    if(!pageIsScrolling){
      this.setState({
        previousPage: -1,
        currentPage: 0
      });
    }
  },
  goToNextPage: function(){
    if(!pageIsScrolling && (this.state.currentPage+1)<pageViewArray.length)
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
      }, ANIMATION_TIME);
    }
  },
  handleKeyDown: function(key){
    if(key.keyCode == 13)
    {
      this.goToNextPage();
    }
    else if(key.keyCode == 38){
      this.goToTop();
    }
  },
  render:function(){
    var nextPageButton;
    if(this.state.currentPage == pageViewArray.length-1){
      nextPageButton = <Button onClick={this.goToNextPage} disabled bsStyle="primary" style={styles.bottomButton}>
      Go To Next Page
      </Button>;
    }
    else{
      nextPageButton =
      <Button onClick={this.goToNextPage} bsStyle="primary" style={styles.bottomButton}>
      Go To Next Page
      </Button>;
    }
    var returnToTopButton;
    if(this.state.previousPage == -1){
      returnToTopButton =
      <Button onClick={this.goToTop} disabled bsStyle="primary" style={styles.bottomButton}>
      Return To Top
      </Button>;
    }
    else{
      returnToTopButton =
      <Button onClick={this.goToTop} bsStyle="primary" style={styles.bottomButton}>
      Return To Top
      </Button>;
    }
    return (
      <div tabIndex="1" onKeyDown={this.handleKeyDown} ref="homePager"
      style={styles.home}>
      <AboutMeView height={viewPortHeight} previousPage={this.state.previousPage}
      currentPage={this.state.currentPage} pageArray={pageViewArray}/>
      <ButtonGroup style={styles.bottomButtonContainter}>
      {nextPageButton}
      {returnToTopButton}
      </ButtonGroup>
      </div>
    );
  }
});

// STYLES

var styles = {
  home: {
    position:"absolute",
    top:32,
    left:0,
    width:"100%",
    outline:"none"
  },
  bottomButtonContainter:{
    width:"100%"
  },
  bottomButton: {
    display: "inline",
    width:"50%",
    margin:0,
    paddingTop:5
  }
};

// EXPORTS

AboutMePageManager = Radium(AboutMePageManager);

export default AboutMePageManager;
