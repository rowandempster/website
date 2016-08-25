import React from 'react';
import HeaderNav from '/Users/rowandempster/Documents/website-react/react/components/BootStrapHeaderNav.jsx';
var ReactDOM = require('react-dom');
var Radium = require('radium');
import ProjectCell from '/Users/rowandempster/Documents/website-react/react/components/Projects/BaseComponents/ProjectCell.jsx';
var $ = require('jquery');
import MuiThemeProvider from 'material-ui/styles/MuiThemeProvider';
import HeaderWithIconAndDivider from '/Users/rowandempster/Documents/website-react/react/components/Projects/BaseComponents/ProjectPageHeader.jsx'

var style= {
	pageHeader: {
		marginTop: 50,
		marginBottom: 0
	},
	contentContainer: {
		background: "red"
	}
};
var Projects = React.createClass({
	componentDidMount: function(){
		document.body.style.backgroundColor = "#B0BEC5";
	},
	componentWillUnmount: function(){
		document.body.style.backgroundColor = "white";
	},
	render: function(){
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
					<div style={style.contentContainer}>
						<div style={style.pageHeader}>
							<MuiThemeProvider>
								<HeaderWithIconAndDivider
									largeText={this.props.data.headerTextArray[0]}
									smallText={this.props.data.headerTextArray[1]}
									imageSrc={this.props.data.headerImageSrc}/>
							</MuiThemeProvider>
						</div>
						{projectsViewArray}
					</div>
					</div>
			);
		}
	});
	export default Projects;

	/* <HeaderNav/>
	<MuiThemeProvider>
	<FromLeftProjectCell/>
	</MuiThemeProvider> */
