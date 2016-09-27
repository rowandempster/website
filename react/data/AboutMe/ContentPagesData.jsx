import React from 'react';

//PAGE ONE

//---ROWS

//---------ROW ONE
var pageOneRowOneContent =
<div>
  <p>
    I finished my first two terms of school and first co-op term at the University of Waterloo.
  </p>
  <p>
    I am in the CS class of 2020
  </p>
</div>

var pageOneRowOne = {
    imageSrc: "https://www.student.cs.uwaterloo.ca/~cs200/csbanner.png",
    imageAlt: "Waterloo",
    content: pageOneRowOneContent,
    key:1
  };

//---------ROW TWO

 //---ROW ARRAY

var pageOneRowArray = [pageOneRowOne];

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
