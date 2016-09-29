import React from 'react';
import { Row, Col } from 'elemental'
import ReactPlayer from 'react-player';
import RaisedButton from 'material-ui/RaisedButton';
import Panel from 'react-bootstrap/lib/Panel';

import Collapse from 'react-bootstrap/lib/Collapse';
var injectTapEventPlugin = require("react-tap-event-plugin");
import Expandable from 'react-simple-collapse';
import Collapsible from 'react-collapsible';
var $ = require('jquery');

injectTapEventPlugin();

const ANIMATION_TIME = 500;
const LEFT_CONTAINER_COLOR ="#c2eafc";
const LEFT_INNER_COLOR ="#E1F5FE";
const RIGHT_CONTAINER_COLOR ="#E0E0E0";
const RIGHT_INNER_COLOR ="#EEEEEE";

var style= {
  linksButton:{
    width:"100%",
    display:"inline-block"
  },
  linkButtonLabel: {
    textTransform: "none",
    fontSize: "large",
    fontWeight:"lighter"
  },
  noMarginOrPadding:{
    margin:0,
    padding:0,
    border: "none",
    display:"inline-block"
  },
  link: {
    height: 75,
    width: 75,
  },
  linkPanel : {
    background: "transparent",
    color: "transparent",
    border:"none",
    display: "inline-block",

  },
  linkContainer: {
  },
  contentContainer: {
    marginTop: 3,
    textAlign:
    "-webkit-center"  },
    linkButtonRow:{
      "flex-wrap": "nowrap",
    }
  }

  var CollapsingLinkContainer = React.createClass({
    getInitialState: function(){
      return {
        linksAreOpen:false,
        videoIsOpen: false
      }
    },
    isExpandedFullyVisible: function () {
      var el = this.refs.contentContainer;
      var elemTop = el.getBoundingClientRect().top;
      var elemBottom = el.getBoundingClientRect().bottom;

      var isVisible = (elemTop >= 0) && (elemBottom <= window.innerHeight);
      return isVisible;
    },
    checkContentVisibilityAndScrollIfNeeded: function(){
      if(!(this.isExpandedFullyVisible())){
        (this.refs.contentContainer).scrollIntoView(false);
      }
    },
    componentDidUpdate: function(newProps, newState){
      if(this.state.videoIsOpen || this.state.linksAreOpen){
      setTimeout(this.checkContentVisibilityAndScrollIfNeeded, ANIMATION_TIME);
    }
    },
    toggleLinks: function(){
      this.setState({
        linksAreOpen: !(this.state.linksAreOpen),
        videoIsOpen: false
      });
    },
    toggleVideo: function(){
      this.setState({
        videoIsOpen: !(this.state.videoIsOpen),
        linksAreOpen: false
      });

    },
    render: function(){
      var themeContainerColor;
      var themeInnerColor;
      if(this.props.fromLeft){
        themeContainerColor = LEFT_CONTAINER_COLOR;
        themeInnerColor = LEFT_INNER_COLOR;
      }
      else{
        themeContainerColor = RIGHT_CONTAINER_COLOR;
        themeInnerColor = RIGHT_INNER_COLOR;
      }
      var linkDataArray = this.props.linkDataArray;
      var linkViewArray = [];
      for(var i = 0; i<linkDataArray.length; i++){
        var linkStyle = {
          height: linkDataArray[i].height,
          width: linkDataArray[i].width,
        };
        var viewToPush =
        <RaisedButton
          target="_blank"
          key={linkDataArray[i].key}
          href={linkDataArray[i].href}
          icon={<img style={linkStyle}
            src={linkDataArray[i].imageSrc}/>}
          style={linkStyle}
        />;
        linkViewArray.push(viewToPush);
      }
      var linkButtonText;
      if(this.state.linksAreOpen){
        linkButtonText = "Close Links";
      }
      else{
        linkButtonText = "Show Links";
      }
      var videoButtonText;
      if(this.state.videoIsOpen){
        videoButtonText = "Close Video";
      }
      else{
        videoButtonText = "Open Video";
      }
      var videoUrl = this.props.videoUrl;
      return(
        <div style={style.linkContainer}>
          <Row style={style.linkButtonRow}>
            <Col xs="1/2">
              <RaisedButton
                disabled={false}
                onTouchTap={this.toggleLinks}
                labelStyle={style.linkButtonLabel}
                label={linkButtonText}
                backgroundColor={themeInnerColor}
                style={style.linksButton}
              />
            </Col>
            <Col xs="1/2">
              <RaisedButton
                labelStyle={style.linkButtonLabel}
                label={videoButtonText}
                disabled={videoUrl == null}
                backgroundColor={themeInnerColor}
                style={style.linksButton}
                onTouchTap={this.toggleVideo}/>
            </Col>
          </Row>
          <div style={style.contentContainer} ref="contentContainer" id="contentContainer">
            <Collapsible style={style.linkPanel}
              open={this.state.linksAreOpen}
              transitionTime={ANIMATION_TIME}
              easing="linear">
              <div style={style.noMarginOrPadding}>
                <Panel style={style.noMarginOrPadding}>
                  {linkViewArray}
                </Panel>
              </div>
            </Collapsible>
            <Collapsible style={style.linkPanel}
              open={this.state.videoIsOpen}
              transitionTime={ANIMATION_TIME}
              easing="linear">
              <ReactPlayer url={videoUrl} />
        </Collapsible>
        </div>
        </div>)
      }
    });

    export default CollapsingLinkContainer;
