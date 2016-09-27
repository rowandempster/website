var React = require('react');

//PROJECT ONE

//---LINKS
var projectOneLinkArray = [{
  href:"http://52.207.75.185",
  imageSrc: "react/images/gotowebapp.png",
  width: 150,
  height: 150,
  key:1
},
{
  href:"https://github.com/rowandempster/colour-my-world",
  imageSrc: "https://cdn4.iconfinder.com/data/icons/iconsimple-logotypes/512/github-512.png",
  width: 150,
  height: 150,
  key: 2
},
{
  href:"react/images/colormyworldcollage.png",
  imageSrc: "react/images/gotocollage.png",
  width: 150,
  height: 150,
  key: 3
}];

var projectOne = {
  imgSrc: "react/images/colormyworld.svg",
  imgHeight: 50,
  imgWidth: 200,
  title: "Colour My World",
  date: "Summer 2016",
  description: <div> <p>Colour My World uses an open source deep learning framework called <a href="http://caffe.berkeleyvision.org/" target="_blank">Caffe</a> to color black and white sketches or images. You can either draw your own sketch or upload a preexisting one.</p> <p> This Web App is CPU intensive and hosted on Amazon Web Services (meaning it costs me money to run it). To checkout this project please go to the Contact Me page and send me a message. I will arrange a time that works for you to start the Amazon Web Services Instance that the App is running on.</p></div>,
  linkDataArray: projectOneLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 1
};

var projectTwo = {
  imgSrc: "https://4.bp.blogspot.com/-DV3oSkBGKVw/VWdWwTZ0DSI/AAAAAAAABrs/KizNkOcUhGw/s1600/Google%2BPlay%2Blogo.png",
  imgHeight: 150,
  imgWidth: 150,
  title: "test title",
  date: "Fall 2016",
  description: "sadogifhasiodfhaihasdiofhsidofhisfdh",
  linkDataArray: projectOneLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 2
};

var projectThree = {
  imgSrc: "https://4.bp.blogspot.com/-DV3oSkBGKVw/VWdWwTZ0DSI/AAAAAAAABrs/KizNkOcUhGw/s1600/Google%2BPlay%2Blogo.png",
  imgHeight: 150,
  imgWidth: 150,
  title: "test title",
  date: "Fall 2016",
  description: "sadogifhasiodfhaihasdiofhsidofhisfdh",
  linkDataArray: projectOneLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 3
};


var ProjectsData= {
  headerTextArray: ["My Work","Side Projects"],
  headerImageSrc: "http://icons.iconarchive.com/icons/paomedia/small-n-flat/1024/sign-check-icon.png",
  projectsDataArray: [projectOne]
};

exports.data = ProjectsData;
