var projectsData = {
		buttonTitle: "My Work", 
		id:1,
		dropDownItems: [
			{
				item:"Side Projects",
				link:"/",
				id:1,
				route:true

			},
			{
				item:"Work Projects",
				link:"/test",
				id:2,
				route:true


			},
			{
				item:"Hackathon Projects",
				link:"/test",
				id:3,
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
				id:1,
				route:true
			},
			{
				item:"Caffe Deep Learning Framework",
				link:"http://www.google.com",
				id:2,
				route:false

			}
	]
};

var test1 = {
		buttonTitle: "test1",
		id:3, 
		dropDownItems: [
			{
				item:"test1.1",
				link:"/",
				id:1,
				route:true
			},
			{
				item:"test1.2",
				link:"http://www.google.com",
				id:2,
				route:false

			},
						{
				item:"test1.3",
				link:"http://www.google.com",
				id:3,
				route:false

			},
						{
				item:"test1.4",
				link:"http://www.google.com",
				id:4,
				route:false

			},
						{
				item:"test1.5",
				link:"http://www.google.com",
				id:5,
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
				id:1,
				route:true
			}
	]
};

var headerArray = [projectsData, blogData, test1, test2];

exports.headerArray = headerArray;