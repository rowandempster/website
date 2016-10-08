import React from 'react';
import { Row, Col } from 'elemental'
import PageHeader from 'react-bootstrap/lib/PageHeader';

var style = {
  container :{
    display: "flex",
    flexDirection: "column",
    paddingLeft:20,
    backgroundColor:"#90A4AE",
    marginBottom:30
  }
};
var HeaderWithIconAndDivider = React.createClass({
  render: function(){
    return (
<PageHeader style={style.container}>{this.props.largeText} <small>{this.props.smallText}</small></PageHeader>
    );
  }
});

export default HeaderWithIconAndDivider;
