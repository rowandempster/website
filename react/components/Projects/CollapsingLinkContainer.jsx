import React from 'react';
import { Row, Col } from 'elemental'
import ReactPlayer from 'react-player';
import Paper from 'material-ui/Paper';
import RaisedButton from 'material-ui/RaisedButton';
import Well from 'react-bootstrap/lib/Well';
import Panel from 'react-bootstrap/lib/Panel';

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
  link: {
    height: 75,
    width: 75,
  },
  linkPanel : {
    border:"none",
    display: "inline-block"
  },
  linkContainer: {
  },
  contentContainer: {
    marginTop: 3,
    textAlign:"center"
  }

}

var LinkContainer = React.createClass({
  getInitialState: function(){
    return {
      linksAreOpen:false,
      videoIsOpen: false
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

    var linkDataArray = this.props.linkDataArray;
    var linkViewArray = [];
    for(var i = 0; i<linkDataArray.length; i++){
      var linkStyle = {
        height: linkDataArray[i].height,
        width: linkDataArray[i].width,
      };
      var viewToPush =
      <RaisedButton
        href={linkDataArray[i].href}
        icon={<img style={linkStyle} src={linkDataArray[i].imageSrc}/>}
        style={linkStyle}
      />;
      linkViewArray.push(viewToPush);
    }
    var linkButtonText;
    if(this.state.linksAreOpen){
      linkButtonText = "Close Links";
    }
    else{
      linkButtonText = "Open Links";
    }
    return(
      <div style={style.linkContainer}>
        <Row>
          <Col xs="1/2">
            <RaisedButton
              labelStyle={style.linkButtonLabel}
              label={linkButtonText}
              backgroundColor="#E1F5FE"
              style={style.linksButton}
              onClick={this.toggleLinks}/>
          </Col>
          <Col xs="1/2">
            <RaisedButton
              labelStyle={style.linkButtonLabel}
              label={"Show Video"}
              backgroundColor="#E1F5FE"
              style={style.linksButton}
              onClick={this.toggleVideo}/>
          </Col>
        </Row>
        <div style={style.contentContainer}>
          <Panel style={style.linkPanel} collapsible expanded={this.state.linksAreOpen}>
            {linkViewArray}
          </Panel>
          <Panel style={style.linkPanel} collapsible expanded={this.state.videoIsOpen}>
            <ReactPlayer url='https://www.youtube.com/watch?v=_KpsVLeLsJM' />
          </Panel>
        </div>
      </div>)
    }
  });

  export default LinkContainer;
