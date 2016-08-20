import React from 'react';
var Radium = require('radium');
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');
import PageOne from './Pages/PageOne'
import PageTwo from './Pages/PageTwo'
import PageThree from './Pages/PageThree'

const ANIMATION_TIME = 500;

var ViewToShow = React.createClass({
  getInitialState: function(){
    return {
      doneAnimating:false
    }
  },
  componentWillReceiveProps: function(nextProps) {
    this.setState({
      doneAnimating:false
    });
  },
  setAnimationStateToTrue: function(){
    this.setState({
      doneAnimating: true
    });
  },
  scrollToNextPage:function(){
    $('html, body').animate({
      scrollTop: this.props.height
    }, ANIMATION_TIME);
    if(!(this.state.doneAnimating)){
      setTimeout(this.setAnimationStateToTrue
        , ANIMATION_TIME);
      }
    },
    componentDidUpdate: function(prevProps, prevState) {
      if(this.props.previousPage>=0 && !(this.state.doneAnimating)){
        this.scrollToNextPage();
      }
    },
    render: function(){
      var pageArray = this.props.pageArray;
      if(this.props.previousPage>=0){
        var previousPage = pageArray[this.props.previousPage];
      }
      else{
        var previousPage = null;
      }
      var currentPage = pageArray[this.props.currentPage];
      if(!(this.state.doneAnimating)){
        return (<div>
          {previousPage}
          {currentPage}
          </div>);
        }
        else{
          return (<div>
            {currentPage}
            </div>);
          }
        }
      });

      export default ViewToShow;
