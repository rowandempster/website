import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');

var viewPortHeight = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
var pageIsScrolling = false;

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
}

var styles = {
	home: {
		position:"absolute",
		top:0,
		left:0,
		width:"100%",
		outline:"none"
	},
	header: {
		height: viewPortHeight,
		paddingLeft: 50,
		paddingBottom: 0,
		marginBottom:0
	}
};

var HomePager = React.createClass({
	getInitialState: function(){
		return {
			currentPage: 1
		}
	},
	componentDidMount: function(){
		ReactDOM.findDOMNode(this.refs.homePager).focus();
		$('body').on({
			'mousewheel': function(e) {
				if (e.target.id == 'el') return;
				e.preventDefault();
				e.stopPropagation();
			}
		});
		disableScroll();
		console.log("scrollingToTop");
		$('html, body').animate({
			scrollTop: 0
		}, 1);
	},
	goToNextPage: function(key){
		if((key.keyCode == 13 || key.keyCode == 38) && !pageIsScrolling)
		{
			if(key.keyCode == 13) {
				console.log("moving down");
				$('html, body').animate({
					scrollTop: '+=' + viewPortHeight
				}, 1000);
			}
			else{
				console.log("moving up");
				$('html, body').animate({
					scrollTop: 0
				}, 1000);
			}
			pageIsScrolling = true;
			setTimeout(function(){
				pageIsScrolling = false;
			}, 1000);
		}
	},
	render:function(){
		return (
			<div tabIndex="1" onKeyDown={this.goToNextPage} ref="homePager"
				style={styles.home}>

			</div>
		);
	}
});



HomePager = Radium(HomePager);

export default HomePager;
