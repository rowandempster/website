import React from 'react';
import { Row, Col } from 'elemental'
import ReactPlayer from 'react-player';
import Paper from 'material-ui/Paper';
import RaisedButton from 'material-ui/RaisedButton';
import Well from 'react-bootstrap/lib/Well';
import Panel from 'react-bootstrap/lib/Panel';
import CollapsingLinkContainer from './CollapsingLinkContainer';



const LEFT_CONTAINER_COLOR ="#c2eafc";
const LEFT_INNER_COLOR ="#E1F5FE";
const RIGHT_CONTAINER_COLOR ="#E0E0E0";
const RIGHT_INNER_COLOR ="#EEEEEE";


var screenWidth = screen.width;

var rightStyle= {
  container:{
    width: screenWidth*(2/3),
    marginBottom: 40,
    paddingTop:20,
    paddingBottom:20,
    paddingRight: 50,
    paddingLeft:20,
    background: RIGHT_CONTAINER_COLOR,
    float: "right",
    position: "relative"

  },
  hidden: {
    display:"none"
  },
  headerContainer: {
    padding: 10,
    background: RIGHT_INNER_COLOR

  },
  desciptionContainer:{
    marginTop:20,
    background: RIGHT_INNER_COLOR,
    border:0
  },
  noBootStrap: {
    margin:0,
  },
  titleRow:{
    alignItems: "center",
  },
  linkButtonLabel: {
    textTransform: "none",
    fontSize: "large",
    fontWeight:"lighter"
  }
};

var leftStyle= {
  container:{
    width: screenWidth*(2/3),
    marginBottom: 40,
    paddingTop:20,
    paddingBottom:20,
    paddingRight: 20,
    paddingLeft:50,
    background: "#c2eafc",
    position: "relative",
    float:"left"
  },
  hidden: {
    display:"none"
  },
  headerContainer: {
    padding: 10,
    background: "#E1F5FE"

  },
  desciptionContainer:{
    marginTop:20,
    background: "#E1F5FE",
    border:0
  },
  noBootStrap: {
    margin:0,
  },
  titleRow:{
    alignItems: "center",
  },
  linkButtonLabel: {
    textTransform: "none",
    fontSize: "large",
    fontWeight:"lighter"
  }
};

var ProjectCell = React.createClass({
  getInitialState: function(){
    return {
      videoIsOpen:false,
      linksAreOpen:false
    }
  },
  toggleLinks: function(){
    this.setState({
      linksAreOpen: !(this.state.linksAreOpen)
    });
  },
  render: function(){
    var data = this.props.data;
    var imgSrc = data.imgSrc;
    var imgHeight = data.imgHeight;
    var imgWidth = data.imgWidth;
    var title = data.title;
    var description = data.description;
    var linkDataArray = data.linkDataArray;
    var videoUrl = data.videoUrl;
    var style;
    if(this.props.fromLeft){
      style = leftStyle;
    }
    else{
      style= rightStyle;
    }

    return(
      <Paper zDepth={5} rounded={false} style={style.container}>
        <Paper zDepth={1} rounded={true} style={style.headerContainer}>
          <Row style={style.titleRow}>
            <div>
              <img src={imgSrc} width={imgWidth} height={imgHeight}/>
            </div>
            <div style={style.col}>
              <h1 style={style.noBootStrap}>{title}</h1>
            </div>
          </Row>
        </Paper>
        <Well style={style.desciptionContainer}>
          <p style={style.noBootStrap}>{description}</p>
        </Well>
        <CollapsingLinkContainer linkDataArray={linkDataArray} videoUrl={videoUrl} fromLeft={this.props.fromLeft}/>
        <br/>
      </Paper>);
    }
  });

  export default ProjectCell;
