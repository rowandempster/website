import React from 'react';
var Radium = require('radium');
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
import PageHeader from 'react-bootstrap/lib/PageHeader';
import Well from 'react-bootstrap/lib/Well';
import { Row, Col, Spinner } from 'elemental'
var ReactDOM = require('react-dom');
var Scroll  = require('react-scroll');
var scroll  = Scroll.animateScroll;
var $ = require('jquery');
import Paper from 'material-ui/Paper';
import Divider from 'material-ui/Divider';

var style = {
  image: {
    width: "100%"
  },
  imagePage: {
    marginTop: 0,
    marginLeft:1,
  },
  paragraphContainer:{
    alignItems: "center",
    justifyContent: "center"
  },
  row:{
    "flex-wrap": "nowrap",
    marginTop:0,
    marginBottom: -20,
  },
  textContainer: {
    fontSize:25,
    background: "#F7F7F7"
  },
  column: {
    "alignSelf":"center",
  },
  outerWell:{
    background: "#FBFBFB"
  }
};
var OneImageOneTextRow = React.createClass({
  render: function(){
    // var paragraphArrayData = this.props.data.paragraphArray;
    // var paragraphViewArray = [];
    // for(var i = 0; i<paragraphArrayData.length; i++){
    //   var paragraphToPush = <p style={style.paragraph}>{paragraphArrayData[i]}</p>;
    //   paragraphViewArray.push(paragraphToPush);
    // }
    return (<Well style={style.outerWell}><Row style={style.row}>

      <Col style={style.column} sm="1/3" xs="1/3" lg="1/3">
        <Paper style={style.imagePage} zDepth={1}>
          <img style={style.image} src={this.props.data.imageSrc} alt={this.props.data.imageAlt}/>
        </Paper></Col>
      <Col xs="2/3" sm="2/3" lg="2/3" style={style.paragraphContainer}>
        <Well zDepth={1} style={style.textContainer}>
          {this.props.data.content}
        </Well>
      </Col>
    </Row>
    </Well>
      );
  }
});

export default OneImageOneTextRow;
