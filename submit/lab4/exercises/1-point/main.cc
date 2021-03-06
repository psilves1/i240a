#include "point.hh"

#include <iostream>
#include <cmath>

//declare an array of points
static const Point points[] = {
			       Point(0, 0), Point(3, 4), Point(1, 1), Point(4, 5), Point(6,7)
};
//use standard idiom to figure out number of elements in array
static constexpr auto nPoints = sizeof(points)/sizeof(points[0]);

static void
outSizes(std::ostream& out) {
  out << "sizeof(double) = " << sizeof(double) << std::endl;
  out << "sizeof(Point) = " << sizeof(Point) << std::endl;
}

class Line{
 public:
  Point *p1;
  Point *p2;

  Line(Point pa, Point pb){

    p1 = &pa;
    p2 = &pb;
  }
  
  double distance(){
    const auto dx = p1->x - p2->x;
    const auto dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
  }

  std::string toString(){

    std::string str = "(" + std::to_string(p1->x) + ", " + std::to_string(p1->y) + ") -- ("
                          + std::to_string(p2->x) + ", " + std::to_string(p2->y) + ")  length : "
                          + std::to_string(distance());

    return str;
  }
  
};

/** output pair-wise distance between all points in points[] to out. */
static void
outDistances(std::ostream& out)
{
  for (auto i = 0u; i < nPoints - 1; i++) {
    Point pi = points[i];
    for (auto j = i + 1; j < nPoints; j++) {
      Point pj = points[j];
      out << "distance from " << pi.toString()
	  << " to " << pj.toString()
	  << " is " << pi.distance(pj)
	  << std::endl;
    }
  }
}

int main() {

  //instead of hardcoding std::cout in functions, we pass it as a param.
  //so if we wanted to output to a file, the code for the functions
  //would not need to change (the code in this function would change).
  std::ostream& out = std::cout;

  //  outDistances(out); out << std::endl;

  //  outSizes(out);
  
  Line l(points[0], points[1]);

  for(int i = 0; i+1 < (int)nPoints; i += 2){

    l = Line(points[i] , points[i + 1]);
    
    std::cout << l.toString() << std::endl;
  }
}
