import React from 'react';
var ReactDOM = require('react-dom');
import OneImageOneTextRow from './OneImageOneTextRow'
import HeaderWithIconAndDivider from './HeaderWithIconAndDivider'

var ContentPage = React.createClass({
  render: function(){
    var style = {
      container: {
        marginBottom:0,
        paddingTop:20,
        marginLeft:20,
        height: this.props.height,
        overflowY:"scroll",
        overflowX:"hidden"
      },
    };
      var rowDataArray = this.props.data.rows;
      var rowViewArray = [];
      for(var i =0; i<rowDataArray.length; i++){
        var viewToPush = <OneImageOneTextRow data={rowDataArray[i]} key={rowDataArray[i].key}/>;
        rowViewArray.push(viewToPush);
      }
      return (
        <div style={style.container}>
          <HeaderWithIconAndDivider
            imageSrc={this.props.data.header.imageSrc}
            text={this.props.data.header.text}/>
          {rowViewArray}
        </div>
      );
  }
});

export default ContentPage;
