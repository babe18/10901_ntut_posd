#define _USE_MATH_DEFINES
#include <cmath>
#include "shape.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
class Ellipse: public Shape{
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes):_semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes) {
      if( _semiMajorAxes<=0 || _semiMinorAxes<=0){
          run=false;
          throw string ("This is not a ellipse!");
      }
      strsemiMajorAxes = std::to_string(semiMajorAxes);
      strsemiMinorAxes = std::to_string(semiMinorAxes);
      ellipseinfo="Ellipse ("+strsemiMajorAxes.erase(strsemiMajorAxes.length()-3,strsemiMajorAxes.length()-1)+", "+strsemiMinorAxes.erase(strsemiMinorAxes.length()-3,strsemiMinorAxes.length()-1)+")";
    }
    double area() const {
        if(run) return M_PI*_semiMajorAxes*_semiMinorAxes;
        else return -1;
    }
    double perimeter() const {
        if(run) return 2*M_PI*_semiMinorAxes+4*(_semiMajorAxes-_semiMinorAxes);
        else return -1;
    }
    std::string info() const {
        return ellipseinfo;
    }
  private:
  double  _semiMajorAxes;
  double  _semiMinorAxes;
  std::string ellipseinfo,strsemiMajorAxes,strsemiMinorAxes;
  bool run=true;
};
