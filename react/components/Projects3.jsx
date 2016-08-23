import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var Radium = require('radium');
import FromLeftProjectCell from './Projects/FromLeftProjectCell'
import FromRightProjectCell from './Projects/FromRightProjectCell'
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
var myModule = require('../data/ProjectsData');
var projectsData = myModule.ProjectsData;
var projectsDataArray = projectsData.projectsDataArray;
import HeaderWithIconAndDivider from './AboutMe/Pages/ReusableComponents/HeaderWithIconAndDivider'

var style= {
	pageHeader: {
		marginTop: 50,
		marginBottom: 0
	}
};
var Projects = React.createClass({
	componentWillReceiveProps: function(){
		this.forceUpdate();
	},
	render: function(){
		var projectsViewArray = [];
		for (var i = 0; i<projectsDataArray.length; i++){
			var projectData = projectsDataArray[i];
			var viewToPush;
			if(i%2 == 0){
				viewToPush = (<MuiThemeProvider key={projectData.key}>
					<FromLeftProjectCell data={projectData} key={projectData.key}/>
					</MuiThemeProvider>
				);
			}
			else{
				viewToPush = (<MuiThemeProvider key={projectData.key}>
					<FromRightProjectCell data={projectData} key={projectData.key}/>
					</MuiThemeProvider>);
				}
				projectsViewArray.push(viewToPush);
			}
			console.log(projectsViewArray);
			return (
				<div>
					<HeaderNav/>
					<div style={style.pageHeader}>
						<MuiThemeProvider>
							<HeaderWithIconAndDivider
								text={projectsData.headerText}
								imageSrc={projectsData.headerImageSrc}/>
						</MuiThemeProvider>
					</div>
					{projectsViewArray}
				</div>
			);
		}
	});
	export default Projects;

	/* <HeaderNav/>
	<MuiThemeProvider>
	<FromLeftProjectCell/>
	</MuiThemeProvider> */
