import React from 'react';
import { Row, Col } from 'elemental'
import Paper from 'material-ui/Paper';
import Divider from 'material-ui/Divider';


var style = {
  divider: {
    marginTop:20,
    marginBottom:20,
  },
  row:{
    marginBottom:-20,
    marginTop: 20
  },
  image: {
    width: "100%"
  },
  text: {
    margin:0,
    color:"black"
  },
  col: {
    alignSelf: "center"
  }
};
var HeaderWithIconAndDivider = React.createClass({
  render: function(){
    return (
      <div>
        <Row style={style.row}>
          <Col style={style.col} sm="1/15">
            <img style={style.image} src={this.props.imageSrc}/>
          </Col>
          <Col sm="14/15" style={style.col}>
            <h1 style={style.text}>{this.props.text}</h1>
          </Col>
        </Row>
        <Divider style={style.divider}/>
      </div>
    );
  }
});

export default HeaderWithIconAndDivider;
