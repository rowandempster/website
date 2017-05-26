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
    display:"inline-block",
    paddingLeft: "10px",
    paddingRight: "10px"
  },
  paragraphContainer:{
    alignItems: "center",
  },
  row:{
    "flex-wrap": "nowrap",
  },
  textContainer: {
    fontSize:25,
    background: "#F7F7F7",
    width:"100%",
    marginBottom:0
  },
  column: {
    "alignSelf":"center",
    "text-align": "center"
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

      <Col xs="1/2" sm="1/2" lg="1/2" style={style.paragraphContainer}>
        <Well style={style.textContainer}>
          {this.props.data.contentOne}
        </Well>
      </Col>
      <Col xs="1/2" sm="1/2" lg="1/2" style={style.paragraphContainer}>
        <Well style={style.textContainer}>
          {this.props.data.contentTwo}
        </Well>
      </Col>
    </Row>
    </Well>
      );
  }
});

export default OneImageOneTextRow;
