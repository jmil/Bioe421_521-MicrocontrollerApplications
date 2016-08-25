void simpleImage(int backgnd, int redValue, int greenValue, int blueValue) {
  //image (img01, 0, 0);

  if(backgnd == 1) {
    image (img01, 0, 0);
  }
  if(backgnd == 2) {
    image (img02, 0, 0);
  }
  if(backgnd == 3) {
    image (img03, 0, 0);
  }

  //point ( 250, 250 );
  //line ( 300, 300, 350, 350 );

  strokeWeight ( 5 );
  fill ( redValue, greenValue, blueValue );

  triangle ( 250, 250, 300, 300, 250, 300 );
  rect ( 350, 350, 50, 50 );
  ellipse ( 450, 450, 50, 50 );
}


