#include "sketch.h"
#include "pebcessing/def_for_sketch.h"

void setup() {
  background(color(255, 255, 255));
  noLoop();
}

void draw() {
  int h = hour() % 12;
  int m = minute();
  int s = second();

  translate(sketchWidth / 2, sketchHeight / 2);

  strokeWeight(7);

  pushMatrix();
  rotate((h + (float)m / 60) * TWO_PI / 12);
  stroke(color(255, 0, 85));
  line(0, 0, 0, -sketchWidth * 0.3f);
  popMatrix();

  pushMatrix();
  rotate((m + (float)s / 60) * TWO_PI / 60);
  stroke(color(0, 85, 255));
  line(0, 0, 0, -sketchWidth * 0.4f);
  popMatrix();

  strokeWeight(3);

  pushMatrix();
  rotate(s * TWO_PI / 60);
  stroke(color(255, 255, 0));
  line(0, 0, 0, -sketchWidth * 0.4f);
  popMatrix();

  noStroke();
  fill(color(85, 85, 85));
  for(int i = 0; i < 12; i++){
    ellipse(0, -sketchWidth * 0.45f, 8, 8);
    rotate(TWO_PI / 12);
  }
}

void secondEvent() {
  redraw();  
}
