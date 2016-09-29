import React from 'react';
import Jumbotron from 'react-bootstrap/lib/Jumbotron';
var ReactDOM = require('react-dom');

var PageOne = React.createClass({
  render: function(){
    var styles = {
      jumbotron: {
        marginBottom:0,
        paddingLeft:50,
        height: this.props.height,
        overflowY:"scroll",
        right:0,
        marginRight:0,
        paddingRight:0,
        overflowX: "hidden"
      }
    };
    return (
        <Jumbotron style={styles.jumbotron}>
          <h1>
            Hi, my name is Rowan.
          </h1>
          <br/>
          <p>
            This is the homepage of my website. Use the navigation bar at the top to explore the other sections.
          </p>
          <p>
            Tap <img height={30} width={70} src="react/images/enter_key.png" alt="Enter Key"/> to continue. Hit <img height={40} width={40} src="react/images/up_key.png" alt="Up Arrow"/> at any time to return to the top
          </p>

        </Jumbotron>
    );
  }
});

export default PageOne;
