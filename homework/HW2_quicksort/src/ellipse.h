#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <cmath>
#include "shape.h"
using namespace std;

class Ellipse: public Shape{
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes):_semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes) {
      if( _semiMajorAxes<=0 || _semiMinorAxes<=0 || _semiMajorAxes < _semiMinorAxes){
          run=false;
          throw string ("This is not an ellipse!");
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

#endif
