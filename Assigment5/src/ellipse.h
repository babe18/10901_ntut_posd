#ifndef ELLIPSE_H
#define ELLIPSE_H
#include<cmath>
#include"shape.h"
#include<string>


class Ellipse: public Shape{
public:
    Ellipse(std::string id,double semiMajorAxes, double semiMinorAxes): Shape(id){
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
        strmaj = std::to_string(semiMajorAxes);
        strmin = std::to_string(semiMinorAxes);
        str_an ="Ellipse ("+strmaj.erase(strmaj.length()-3,strmaj.length()-1)+", "+strmin.erase(strmin.length()-3,strmin.length()-1)+")";
        if(semiMajorAxes<=0||semiMinorAxes<=0||semiMajorAxes < semiMinorAxes)
          throw std::string("This is not an ellipse!");
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
    }

    Ellipse(std::string id,double semiMajorAxes, double semiMinorAxes,std::string color): Shape(id,color) {
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
        strmaj = std::to_string(semiMajorAxes);
        strmin = std::to_string(semiMinorAxes);
        str_an ="Ellipse ("+strmaj.erase(strmaj.length()-3,strmaj.length()-1)+", "+strmin.erase(strmin.length()-3,strmin.length()-1)+")";
        if(semiMajorAxes<=0||semiMinorAxes<=0||semiMajorAxes < semiMinorAxes)
          throw std::string("This is not an ellipse!");
    }
    double area() const {
      return M_PI*_semiMajorAxes*_semiMinorAxes;
    }

    double perimeter() const {
      return 2*M_PI*_semiMinorAxes+4*(_semiMajorAxes-_semiMinorAxes);
    }

    std::string info() const {
      return str_an;
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
    }
    std::string type() const {
      std::string type_name = "Ellipse";
      return type_name;
    }
private:
  double _semiMajorAxes,_semiMinorAxes;
  std::string str_an,strmaj,strmin;
};
#endif
