#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <cmath>
#include "shape.h"

using namespace std;

class Ellipse: public Shape{
public:
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes):Shape(id) {
      _id=id;
      _semiMajorAxes=semiMajorAxes;
      _semiMinorAxes=semiMinorAxes;
      if( _semiMajorAxes<=0 || _semiMinorAxes<=0 || _semiMajorAxes < _semiMinorAxes){
          run=false;
          throw string ("This is not an ellipse!");
      }
      strsemiMajorAxes = std::to_string(semiMajorAxes);
      strsemiMinorAxes = std::to_string(semiMinorAxes);
      ellipseinfo="Ellipse ("+strsemiMajorAxes.erase(strsemiMajorAxes.length()-3,strsemiMajorAxes.length()-1)+", "+strsemiMinorAxes.erase(strsemiMinorAxes.length()-3,strsemiMinorAxes.length()-1)+")";
      _type="Ellipse";
    }
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color):Shape(id,color) {
      _id=id;
      _semiMajorAxes=semiMajorAxes;
      _semiMinorAxes=semiMinorAxes;
      _color=color;
      if( _semiMajorAxes<=0 || _semiMinorAxes<=0 || _semiMajorAxes < _semiMinorAxes){
          run=false;
          throw string ("This is not an ellipse!");
      }
      strsemiMajorAxes = std::to_string(semiMajorAxes);
      strsemiMinorAxes = std::to_string(semiMinorAxes);
      ellipseinfo="Ellipse ("+strsemiMajorAxes.erase(strsemiMajorAxes.length()-3,strsemiMajorAxes.length()-1)+", "+strsemiMinorAxes.erase(strsemiMinorAxes.length()-3,strsemiMinorAxes.length()-1)+")";
      _type="Ellipse";
    }
    double area() const {

        if(run) return M_PI*_semiMajorAxes*_semiMinorAxes;
        else return 0;
    }
    double perimeter() const {
        if(run) return 2*M_PI*_semiMinorAxes+4*(_semiMajorAxes-_semiMinorAxes);
        else return 0;
    }
    double getsemiMajorAxes() {
      return _semiMajorAxes;
    }
    double getsemiMinorAxes() {
      return _semiMinorAxes;
    }
    std::string info() const {
    return ellipseinfo;
    }

    std::string type() const {
      return _type;
    }
    void accept(Visitor * visitor) {
      visitor->visit(this);
    }

  private:
  double  _semiMajorAxes;
  double  _semiMinorAxes;
  std::string ellipseinfo,strsemiMajorAxes,strsemiMinorAxes,_id,_color,_type;
  bool run=true;
};

#endif
