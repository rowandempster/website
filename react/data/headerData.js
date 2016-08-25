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
	// 	dropDownItems: [
	// 		{
	// 			item:"AWS Code Deploy",
	// 			link:"/",
	// 			id:2.1,
	// 			route:true
	// 		},
	// 		{
	// 			item:"Caffe Deep Learning Framework",
	// 			link:"http://www.google.com",
	// 			id:2.2,
	// 			route:false
	//
	// 		}
	// ]
	dropDownItems: null
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
	contact: "",
	array: headerArray
}

exports.HeaderData = HeaderData;
