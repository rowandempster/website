import React from 'react';
import { Row, Col } from 'elemental'
import Paper from 'material-ui/Paper';
import Well from 'react-bootstrap/lib/Well';


var style = {
  image: {
    width: "100%"
  },
  imagePage: {
    marginTop: 0,
    marginLeft:1,
    display:"inline-block"
  },
  paragraphContainer:{
    alignItems: "center",
    justifyContent: "center",
    display: "flex"
  },
  row:{
    "flex-wrap": "nowrap",
  },
  textContainer: {
    fontSize:25,
    background: "#F7F7F7",
  },
  column: {
    "alignSelf":"center",
    "align-text": "center"
  },
  outerWell:{
    background: "#FBFBFB",
    position: "relative"
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
          <img height={this.props.data.imageHeight} width={this.props.data.imageWidth}  src={this.props.data.imageSrc} alt={this.props.data.imageAlt}/>
        </Paper></Col>
      <Col xs="2/3" sm="2/3" lg="2/3" style={style.paragraphContainer}>
        <Well style={style.textContainer}>
          {this.props.data.content}
        </Well>
      </Col>
    </Row>
    </Well>
      );
  }
});

export default OneImageOneTextRow;
