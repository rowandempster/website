import React from 'react';
import HeaderNav from '/Users/rowandempster/Documents/website-react/react/components/BootStrapHeaderNav.jsx';
var ReactDOM = require('react-dom');
var Radium = require('radium');
import ProjectCell from '/Users/rowandempster/Documents/website-react/react/components/Projects/BaseComponents/ProjectCell.jsx';
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import HeaderWithIconAndDivider from '/Users/rowandempster/Documents/website-react/react/components/AboutMe/BaseComponents/HeaderWithIconAndDivider.jsx'

var style= {
	pageHeader: {
		marginTop: 50,
		marginBottom: 0
	}
};
var Projects = React.createClass({
	render: function(){
		console.log(this.props.data);
    var projectsDataArray = this.props.data.projectsDataArray;
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
								text={this.props.data.headerText}
								imageSrc={this.props.data.headerImageSrc}/>
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
