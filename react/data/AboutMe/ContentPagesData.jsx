import React from 'react';

//*******************PAGE ONE*************************

//---ROWS

//---------ROW ONE
var pageOneRowOneContent =
<div>
  <p>
    I finished my first two years of school and am searching for my third co-op placement at the University of Waterloo.
  </p>
  <p>
    I am in the Computer Science class of 2020.
  </p>
</div>

var pageOneRowOne = {
  imageHeight: "100px",
  imageWidth: "300px",
  image: true,
  imageSrc: "https://www.student.cs.uwaterloo.ca/~cs200/csbanner.png",
  imageAlt: "Waterloo",
  content: pageOneRowOneContent,
  key:1
};

//---------ROW TWO
var pageOneRowTwoContent =
<div>
  <p>
    At Waterloo I like to play sports (intramurals like Soccer, Volleyball, Basketball, etc...), attend hackathons (see next page), and yes, do course work (mostly in the depressing DC cubicles).
  </p>
</div>

var pageOneRowTwo = {
  image: false,
  content: pageOneRowTwoContent,
  key:2
};
//---ROW ARRAY

var pageOneRowArray = [pageOneRowOne, pageOneRowTwo];

//---HEADER
var pageOneHeader = {
  imageSrc: "https://image.freepik.com/free-icon/graduation-cap-variant_318-47155.png",
  text: "Education"
}

//*********************PAGE 2*********************

//---ROWS

//---------ROW ONE
var pageTwoRowOneContent =
<div>
  <p>
    I like to attend Hackathons, checkout my projects from:
    <ul>
      <li><a href="https://github.com/rowandempster/colour-my-world">AngelHack</a></li>
      <li><a href="https://github.com/rowandempster/MotivateMe">EngHack</a></li>
      <li><a href="https://github.com/rowandempster/NeighborCater">Hack the North</a></li>
      <li><a href="https://github.com/rowandempster/ada_fb_bot">HeForShe Equithon</a></li>
    </ul>
  </p>
</div>

var pageTwoRowOne = {
  imageHeight: "100px",
  imageWidth: "400px",
  image: true,
  imageSrc: "https://preview.ibb.co/e61Hqv/Be_Funky_Collage.jpg",
  imageAlt: "Hackathons",
  content: pageTwoRowOneContent,
  key:1
};

//---------ROW TWO
var pageTwoRowTwoContent =
<div>
  <p>
    Hackathons are a great way for me to start work on a new side project. <br></br>
    When I have a cool project idea, distractions usually hold me back from putting my head down and doing the overhead work necessary to get the project started. <br></br>
    At a hackathon, those distractions don't exist, so I can concentrate on quickly getting the project setup. <br></br>
    Once the setup (and usually the first iteration) of the project is done during the hackathon, I am much more likely to continue working on the project during my free time.
  </p>
</div>

var pageTwoRowTwo = {
  image: false,
  content: pageTwoRowTwoContent,
  key:2
};
//---ROW ARRAY

var pageTwoRowArray = [pageTwoRowOne, pageTwoRowTwo];

//---HEADER
var pageTwoHeader = {
  imageSrc: "https://d30y9cdsu7xlg0.cloudfront.net/png/72566-200.png",
  text: "Hackathons"
}

//*********************PAGE 3*********************

//---ROWS

//---------ROW ONE
var pageThreeRowOneContent =
<div>
  <p>
    <b>Sailing</b><br></br>
    I am from Boston, and learned to sail on the Charles River when I was growing up. <br></br>
    After a few years of learning, I got a job at a local pond teaching sailing to people ages 15-65.<br></br>
    As you can probably guess, there was a large range of skill levels, which made teaching difficult. <br></br>
    Fortunately I like to teach as well as sail, and have a good amount of patience, so it was a fun job none the less!
  </p>
</div>

var pageThreeRowOne = {
  imageHeight: "200px",
  imageWidth: "200px",
  image: true,
  imageSrc: "https://media.licdn.com/mpr/mpr/shrinknp_400_400/AAEAAQAAAAAAAAavAAAAJGM5YzI0NWJlLTg1ZTMtNDkzMS05OGE2LWQ4NGRiM2FkNDIyZA.jpg",
  imageAlt: "Hackathons",
  content: pageThreeRowOneContent,
  key:1
};

//---------ROW TWO
var pageThreeRowTwoContentOne =
<div>
  <p>
    <b>Music</b><br></br>
    Music is...good. Here's some music that I like: <br></br>
  </p>
</div>

var pageThreeRowTwoContentTwo =
<div>
  <p>
    <iframe src="https://open.spotify.com/embed/user/1224437001/playlist/6PCMVJX8d7ou7v1ke81MIz" width="640" height="720" frameborder="0" allowtransparency="true"></iframe>
  </p>
</div>

var pageThreeRowTwo = {
  image: false,
  twoRows: true,
  contentOne: pageThreeRowTwoContentOne,
  contentTwo: pageThreeRowTwoContentTwo,
  key:2
};
//---ROW ARRAY

var pageThreeRowArray = [pageThreeRowOne, pageThreeRowTwo];

//---HEADER
var pageThreeHeader = {
  imageSrc: "https://d30y9cdsu7xlg0.cloudfront.net/png/10148-200.png",
  text: "Activities and Interests"
}


//*********************DISPLAY CONFIG**********************

//---PAGE
var PageOneData = {
  header: pageOneHeader,
  rows: pageOneRowArray,
  key:1
};
var PageTwoData = {
  header: pageTwoHeader,
  rows: pageTwoRowArray,
  key:2
};
var PageThreeData = {
  header: pageThreeHeader,
  rows: pageThreeRowArray,
  key:3
};

var PageArray = [PageOneData, PageTwoData, PageThreeData]

exports.PageArray = PageArray;
