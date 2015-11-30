#include <stdio.h>
#include <math.h>

typedef struct circle{
  double x;
  double y;
  double r;
  int collisions;
} circle;

double getDistance(circle*, circle*);

void main(){
  circle circles[50];
  int i = 0;
  while (i < 50){
    circles[i++].collisions = 0;
  }
  int input;
  i = 0;
  do { //input phase
    printf("Circle %d:\n", i + 1);
    printf("X: ");
    scanf("%lf", &(circles[i].x));
    printf("Y: ");
    scanf("%lf", &(circles[i].y));
    printf("Radius: ");
    scanf("%lf", &(circles[i].r));
    printf("Enter one more circle? Type 0 for no.");
    scanf("%d", &input);
    i++;
  } while (input != 0 && i < 50);
  int j;
  int highest = 0;
  int highestc;
  for (i = 0; i < 49; i++){ //compare all pairs with each other
    for (j = i + 1; j < 50; j++){
      double dist = getDistance(circles + i, circles + j);
      if (dist <= circles[i].r + circles[j].r && dist >= abs(circles[i].r - circles[j].r)){
        circles[i].collisions++;
        circles[j].collisions++;
      }
    }
    //update highest collisions
    if (circles[i].collisions >= highest) {
      highestc = i;
      highest = circles[i].collisions;
    }
  }
  printf("The circle with the highest intesections is circle %d (x: %f, y: %f, r: %f) with %d collisions.",
  highestc + 1, circles[highestc].x, circles[highestc].y, circles[highestc].r, highest);
}

//uses the distance formula to determine the distance
double getDistance(circle* p1, circle* p2){
  double dist;
  double x1,x2,y1,y2;
  x1 = p1 -> x;
  x2 = p2 -> x;
  y1 = p1 -> y;
  y2 = p2 -> y;
  dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  return dist;
}
