import React from 'react';
import ProjectPage from '../BaseComponents/ProjectPage'
var myModule = require('/Users/rowandempster/Documents/website-react/react/data/Projects/WorkData.js');
var data = myModule.data;

var Work = React.createClass({
  render: function(){
    return(<ProjectPage data={data} key={1}/>);
  }
});

export default Work;
