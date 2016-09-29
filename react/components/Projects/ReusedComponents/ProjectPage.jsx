import React from 'react';
import HomePager from './HomePager';
import HeaderNav from './BootStrapHeaderNav';
var ReactDOM = require('react-dom');
import ProjectCell from './Projects/ProjectCell'
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
var myModule = require('../data/ProjectsData');
import HeaderWithIconAndDivider from './AboutMe/Pages/ReusableComponents/HeaderWithIconAndDivider'

var style= {
	pageHeader: {
		marginTop: 50,
		marginBottom: 0
	}
};
var Projects = React.createClass({
	render: function(){
    var projectsDataArray = this.props.data;
		var projectsViewArray = [];
		for (var i = 0; i<projectsDataArray.length; i++){
			var projectData = projectsDataArray[i];
			var viewToPush;
			if(i%2 == 0){
				viewToPush = (<MuiThemeProvider key={projectData.key}>
					<ProjectCell data={projectData} key={projectData.key} fromLeft={true}/>
				</MuiThemeProvider>
				);
			}
			else{
				viewToPush = (<MuiThemeProvider key={projectData.key}>
					<ProjectCell data={projectData} key={projectData.key} fromLeft={false}/>
				</MuiThemeProvider>);
				}
				projectsViewArray.push(viewToPush);
			}
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
