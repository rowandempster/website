var projectsData = {
		buttonTitle: "My Work",
		id:1,
		dropDownItems: [
			{
				item:"Side Projects",
				link:"side_projects",
				id:1.1,
				route:true

			}
	]
};

var blogData = {
		buttonTitle: "Tech Blog",
		id:2,
		dropDownItems: [
			{
				item:"Caffe Deep Learning Framework",
				link:"https://rowanstechblog.wordpress.com/2016/10/07/configuring-an-aws-web-app-with-caffe/",
				id:2.1,
				route:false
			}
	]
};

var usefulLinks = {
		buttonTitle: "Useful Links",
		id:3,
		dropDownItems: [
			{
				item:"My Github",
				link:"http://www.github.com/rowandempster",
				id:3.1,
				route:false
			}
	]
};

var headerArray = [projectsData, blogData, usefulLinks];

var HeaderData = {
	brand: "Rowan Dempster",
	resume: "/Users/rowandempster/Documents/website-react/react/data/static/Resume.pdf",
	contact: "contact_me",
	array: headerArray
}

exports.HeaderData = HeaderData;
