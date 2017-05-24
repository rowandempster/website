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


var projectTwoLinkArray = [{
  href:"https://github.com/rowandempster/NeighborCater",
  imageSrc: "https://cdn4.iconfinder.com/data/icons/iconsimple-logotypes/512/github-512.png",
  width: 150,
  height: 150,
  key:1
},
{
  href:"http://devpost.com/software/neighborcater-ga8765",
  imageSrc: "http://devpost2.assetspost.com/assets/shared/devpost_social_icon_200_200-7b823e9bb545df78675e749bcb8b15ed.jpg",
  width: 150,
  height: 150,
  key: 2
}];

var projectThreeLinkArray = [{
  href:"https://github.com/rowandempster/website/tree/develop",
  imageSrc: "https://cdn4.iconfinder.com/data/icons/iconsimple-logotypes/512/github-512.png",
  width: 150,
  height: 150,
  key:1
}];

var projectFourLinkArray = [{
  href:"https://github.com/rowandempster/Poster-Reader",
  imageSrc: "https://cdn4.iconfinder.com/data/icons/iconsimple-logotypes/512/github-512.png",
  width: 150,
  height: 150,
  key:1
}];

var projectFiveLinkArray = [{
  href:"https://github.com/rowandempster/NeighborCater",
  imageSrc: "https://cdn4.iconfinder.com/data/icons/iconsimple-logotypes/512/github-512.png",
  width: 150,
  height: 150,
  key:1
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
  imgSrc: "react/images/neighborcater.png",
  imgHeight: 120,
  imgWidth: 150,
  title: "Neighbor Cater",
  date: "Fall 2016",
  description: <div><p>Designed and engineered a micro-ecommerce Android App for household kitchens that allows users to sell left over meals.</p><p>Utilized Firebase for user authorization and realtime database management. New seller posts and buyer orders are immediately pushed to all app sessions.</p><p>Gained experience with Firebase, Retrotfit HTTP client, and Google Maps API.</p></div>,
  linkDataArray: projectTwoLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 2
};

var projectThree = {
  imgSrc: "http://www.valuecoders.com/blog/wp-content/uploads/2016/08/reactjs.png",
  imgHeight: 50,
  imgWidth: 200,
  title: "Personal Website",
  date: "Summer 2016",
  description: <div><p>Designed and implemented a personal website to showcase side projects.</p><p>Implemented using MVC design pattern, allowing for content to be added/modi ed by only touching the site's data schema.</p><p>Front end written in ReactJS. Back end is an Express Node.js App. Deployed using Webpack and AWS Code Deploy.</p></div>,
  linkDataArray: projectThreeLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 3
};

var projectFour = {
  imgSrc: "http://cdn.fasstatic.com/expert-advice/5-ways-to-empower-your-business-with-optical-character-recognition-ocr/icon-expense-reporting~122252.png?w=242.55",
  imgHeight: 100,
  imgWidth: 150,
  title: "Poster Reader",
  date: "Spring 2016",
  description: <div><p>Developed an Android App which allows users to take pictures of posters and add displayed dates and descriptions to their calendars.</p><p>Integrated OCR (Tesseract and Leptonica) libraries with Google Calendar API.</p><p>Written in Java using Android Studio.</p></div>,
  linkDataArray: projectFourLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=n6pwkHjRWuM",
  key: 4
};

var ProjectsData= {
  headerTextArray: ["My Work","Side Projects"],
  headerImageSrc: "http://icons.iconarchive.com/icons/paomedia/small-n-flat/1024/sign-check-icon.png",
  projectsDataArray: [projectOne, projectTwo, projectThree, projectFour]
};

exports.data = ProjectsData;
