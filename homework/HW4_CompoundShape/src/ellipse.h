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
      // if(color == "blue"){
      //   cout<<color<<endl;
      // }
      strsemiMajorAxes = std::to_string(semiMajorAxes);
      strsemiMinorAxes = std::to_string(semiMinorAxes);
      ellipseinfo="Ellipse ("+strsemiMajorAxes.erase(strsemiMajorAxes.length()-3,strsemiMajorAxes.length()-1)+", "+strsemiMinorAxes.erase(strsemiMinorAxes.length()-3,strsemiMinorAxes.length()-1)+")";
    }
    double area() const {

        if(run) return M_PI*_semiMajorAxes*_semiMinorAxes;
        else return 0;
    }
    double perimeter() const {
        if(run) return 2*M_PI*_semiMinorAxes+4*(_semiMajorAxes-_semiMinorAxes);
        else return 0;
    }
    std::string info() const {
    return ellipseinfo;
    }

    // std::string id() const {
    //   return _id;
    // }
    // std::string color() const {
    //   return _color;
    // }
    // void addShape(Shape *shape){
    //     throw std::string ("Only compound shape can add shape!");
    // }
    // void deleteShapeById(std::string id){
    //   throw std::string ("Only compound shape can delete shape!");
    // }
  private:
  double  _semiMajorAxes;
  double  _semiMinorAxes;
  std::string ellipseinfo,strsemiMajorAxes,strsemiMinorAxes,_id,_color;
  bool run=true;
};

#endif
