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
    At Waterloo I like to sport (intramurals like Soccer, Volleyball, Basketball, etc...), do homework in the depressing DC cubicles, and get drinks at local pubs with friends (not alone).
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
    I like to attend Hackathons, checkout my projects from <a href="https://github.com/rowandempster/colour-my-world">AngelHack</a>, <a href="https://github.com/rowandempster/MotivateMe">EngHack</a>, <a href="https://github.com/rowandempster/NeighborCater">Hack the North</a>, and the <a href="https://github.com/rowandempster/ada_fb_bot">HeForShe Equithon</a>.
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

  </p>
</div>

var pageTwoRowTwo = {
  imageHeight: "150px",
  imageWidth: "300px",
  image: true,
  imageSrc: "https://d30y9cdsu7xlg0.cloudfront.net/png/72566-200.png",
  imageAlt: "Hacking",
  content: pageOneRowTwoContent,
  key:2
};
//---ROW ARRAY

var pageTwoRowArray = [pageTwoRowOne];

//---HEADER
var pageTwoHeader = {
  imageSrc: "https://d30y9cdsu7xlg0.cloudfront.net/png/72566-200.png",
  text: "Hackathons"
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


var PageArray = [PageOneData, PageTwoData]

exports.PageArray = PageArray;
