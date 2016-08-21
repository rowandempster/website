var projectsData = {
		buttonTitle: "My Work",
		id:1,
		dropDownItems: [
			{
				item:"Side Projects",
				link:"/projects",
				id:1.1,
				route:true

			},
			{
				item:"Work Projects",
				link:"/projects",
				id:1.2,
				route:true


			},
			{
				item:"Hackathon Projects",
				link:"/projects",
				id:1.3,
				route:true


			}
	]
};

var blogData = {
		buttonTitle: "Tech Blog",
		id:2,
		dropDownItems: [
			{
				item:"AWS Code Deploy",
				link:"/",
				id:2.1,
				route:true
			},
			{
				item:"Caffe Deep Learning Framework",
				link:"http://www.google.com",
				id:2.2,
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
			},
			{
				item:"test1.2",
				link:"http://www.google.com",
				id:3.2,
				route:false

			},
						{
				item:"test1.3",
				link:"http://www.google.com",
				id:3.3,
				route:false

			},
						{
				item:"test1.4",
				link:"http://www.google.com",
				id:3.4,
				route:true

			},
						{
				item:"test1.5",
				link:"http://www.google.com",
				id:3.5,
				route:false

			}
	]
};

var test2 = {
		buttonTitle: "test2",
		id:4,
		dropDownItems: [
			{
				item:"test2.1",
				link:"/",
				id:4.1,
				route:true
			}
	]
};

var headerArray = [projectsData, blogData, usefulLinks];

var HeaderData = {
	brand: "Rowan Dempster",
	array: headerArray
}

exports.HeaderData = HeaderData;
