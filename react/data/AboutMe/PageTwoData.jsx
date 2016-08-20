import React from 'react';


var rowOneContent =
<div>
  <p>
    I finished my first two terms of school and first co-op term at the University of Waterloo.
  </p>
  <p>
    I am in the CS class of 2020
  </p>
  <p>
    I am in the CS class of 2020
  </p>
  <p>
    I am in the CS class of 2020
  </p>
  <p>
    I am in the CS class of 2020
  </p>
</div>

var rowOne = {
    imageSrc: "http://cemc.uwaterloo.ca/!images/donors/UniversityOfWaterloo_logo_horiz_rgb.png",
    imageAlt: "Waterloo",
    content: rowOneContent
  };

  var rowArray = [rowOne, rowOne];

var PageTwoData = {
  header: "Education",
  rows: rowArray
};

exports.PageTwoData = PageTwoData;
