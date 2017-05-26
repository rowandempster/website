var React = require('react');

//PROJECT ONE

//---LINKS
var projectOneLinkArray = [{
  href:"https://www.kik.com/",
  label:"Company Website",
  width: 150,
  height: 150,
  key:1
}];


var projectTwoLinkArray = [{
  href:"http://www.tribalscale.com/",
  label:"Company Website",
  width: 150,
  height: 150,
  key:1
}];

var projectOne = {
  imgSrc: "https://avatars1.githubusercontent.com/u/1424728?v=3&s=200",
  imgHeight: 150,
  imgWidth: 150,
  title: "Kik Interactive",
  date: "Winter 2017",
  description: <div><p>Developed the GIF favoriting feature, allowing users to send their favorite GIFs without having to search for them.
    <ul><li>Implemented using a local cache and posting to the GIF content provider's favourites API.</li>
      <li>Optimized synchronization of the local cache with the API, minimizing the number of calls made to the content provider API.</li></ul>
    Added message timestamps to conversation history which users reveal by tapping on chat bubbles.
    <ul><li>Implemented using the MVVM (Model-View-ViewModel) design pattern in conjunction with RxJava for Data Binding.</li>
      <li>Added high coverage unit tests at the ViewModel layer using the JUnit testing framework.</li></ul>
  Learned how to efficiently move a feature through multiple rounds of code review and QA. </p></div>,
  linkDataArray: projectOneLinkArray,
  videoUrl: "https://www.youtube.com/watch?v=4jq54zXk10g",
  key: 1
};

var projectTwo = {
  imgSrc: "https://s3-us-west-2.amazonaws.com/tribalscale-website-v2/metatagimage.png",
  imgHeight: 120,
  imgWidth: 150,
  title: "TribalScale",
  date: "Summer 2016",
  description: <div><p>Developed the podcast section of the ABC News Android App.
    <ul><li>Gained experience with the OkHttp Android client, SQLite Android databases, and version control best practices. </li>
      <li>Communicated daily with the client to confirm requirements. </li></ul>
    Developed and deployed the beta Helpful.com Android App to the Play Store.
    <ul><li>Integrated Auth0 allowing users to sign in with their Google accounts, and implemented a Retrofit/RxJava networking layer to optimize backend interfacing.</li>
      <li>Worked closely with design and QA staff to ship weekly builds to the client, allowing for quick iteration on features. </li></ul> </p></div>,
  linkDataArray: projectTwoLinkArray,
  videoUrl: "https://vimeo.com/188891585",
  key: 2
};

var ProjectsData= {
  headerTextArray: ["My Work","Employement"],
  headerImageSrc: "http://icons.iconarchive.com/icons/paomedia/small-n-flat/1024/sign-check-icon.png",
  projectsDataArray: [projectOne, projectTwo]
};

exports.data = ProjectsData;
