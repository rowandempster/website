import React from 'react';

//PAGE ONE

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
  imageHeight: "150px",
  imageWidth: "300px",
  imageSrc: "https://www.student.cs.uwaterloo.ca/~cs200/csbanner.png",
  imageAlt: "Waterloo",
  content: pageOneRowOneContent,
  key:1
};

//---------ROW TWO
var pageOneRowTwoContent =
<div>
  <p>
    I like to attend Hackathons, checkout my projects from <a href="https://github.com/rowandempster/colour-my-world">AngelHack</a>, <a href="https://github.com/rowandempster/MotivateMe">EngHack</a>, <a href="https://github.com/rowandempster/NeighborCater">Hack the North</a>, and the <a href="https://github.com/rowandempster/ada_fb_bot">HeForShe Equithon</a>
  </p>
</div>

var pageOneRowTwo = {
  imageHeight: "350px",
  imageWidth: "200px",
  imageSrc: "https://d30y9cdsu7xlg0.cloudfront.net/png/72566-200.png",
  imageAlt: "Hacking",
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

//---PAGE
var PageOneData = {
  header: pageOneHeader,
  rows: pageOneRowArray,
  key:1
};
var PageTwoData = {
  header: pageOneHeader,
  rows: pageOneRowArray,
  key:2
};
var PageThreeData = {
  header: pageOneHeader,
  rows: pageOneRowArray,
  key:3
};


var PageArray = [PageOneData, PageTwoData]

exports.PageArray = PageArray;
