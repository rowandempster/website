import React from 'react';
import { Row, Col } from 'elemental'
import ReactPlayer from 'react-player';
import Paper from 'material-ui/Paper';
import RaisedButton from 'material-ui/RaisedButton';
import Well from 'react-bootstrap/lib/Well';
import Panel from 'react-bootstrap/lib/Panel';
import CollapsingLinkContainer from './CollapsingLinkContainer';




var linkDataArray = [{
href:"http://google.com",
imageSrc: "https://4.bp.blogspot.com/-DV3oSkBGKVw/VWdWwTZ0DSI/AAAAAAAABrs/KizNkOcUhGw/s1600/Google%2BPlay%2Blogo.png",
width: 150,
height: 150
},
{
  href:"http://google.com",
  imageSrc: "https://4.bp.blogspot.com/-DV3oSkBGKVw/VWdWwTZ0DSI/AAAAAAAABrs/KizNkOcUhGw/s1600/Google%2BPlay%2Blogo.png",
  width: 150,
  height: 150
}];


var screenWidth = screen.width;
var style= {
  container:{
    width: screenWidth*(2/3),
    marginTop: 100,
    paddingTop:20,
    paddingBottom:20,
    paddingRight: 20,
    paddingLeft:50,
    background: "#c2eafc"
  },
  image: {
    width:"100%",
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
}

var FromLeftProjectCell = React.createClass({
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
    var videoStyle;
    if(this.state.videoIsOpen){
      videoStyle=null;
    }
    else{
      videoStyle = style.hidden;
    }
    var linkButtonText;
    if(this.state.linksAreOpen){
      linkButtonText = "Close Links";
    }
    else{
      linkButtonText = "Open Links";
    }
    return(
      <Paper zDepth={5} rounded={false} style={style.container}>
        <Paper zDepth={1} rounded={true} style={style.headerContainer}>
          <Row style={style.titleRow}>
            <Col sm="1/3">
              <img style={style.image} src="http://vignette3.wikia.nocookie.net/logopedia/images/0/08/ABC_News_2013b.png/revision/latest?cb=20130728134540"/>
            </Col>
            <Col sm="2/3" style={style.col}>
              <h1 style={style.noBootStrap}>Test Title</h1>
            </Col>
          </Row>
        </Paper>
        <Well style={style.desciptionContainer}>
          <p>Test Description: Lorem ipsum dolor sit amet, justo elementum morbi vitae blanditiis a, quis laoreet amet, consequat amet enim diam, sapien lorem faucibus. Pellentesque torquent in, sit praesent nullam magnis dui, duis metus aute. Et justo velit sed risus fringilla, viverra erat felis interdum, vel senectus, ultricies non lobortis senectus voluptatibus orci fusce, placerat donec nec autem vivamus. Est ligula blandit odio lacus. In proin vitae maecenas viverra, amet eu. Enim ante magna aliquam dolor, fusce rutrum quam aptent ut platea ac, ac quis vitae, convallis non nonummy. Mauris porttitor mus interdum, quam in eleifend penatibus. Porttitor justo suspendisse. Vitae tellus adipiscing egestas volutpat, lacus placerat non urna tristique</p>
        </Well>
        <CollapsingLinkContainer linkDataArray={linkDataArray}/>
        <br/>
      </Paper>);
    }
  });

  export default FromLeftProjectCell;
