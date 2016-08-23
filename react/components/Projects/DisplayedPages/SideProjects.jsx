import React from 'react';
import ProjectPage from '../BaseComponents/ProjectPage'
var myModule = require('/Users/rowandempster/Documents/website-react/react/data/Projects/SideProjectsData.js');
var data = myModule.data;

var SideProjects = React.createClass({
  render: function(){
    return(<ProjectPage data={data} key={1}/>);
  }
});

export default SideProjects;
