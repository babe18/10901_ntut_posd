#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cmath>
#include "shape.h"

using namespace std;
class Rectangle: public Shape{
public:
  Rectangle(std::string id, double length, double width):Shape(id) {
    _id=id;
    _length=length;
    _width=width;
    if(_length<=0 || _width<=0){
        run=false;
        throw string ("This is not a rectangle!");
    }
    strlength = std::to_string(_length);
    strwidth = std::to_string(_width);
    recinfo="Rectangle ("+strlength.erase(strlength.length()-3,strlength.length()-2) +", "+strwidth.erase(strwidth.length()-3,strwidth.length()-2) +")";
  }
  Rectangle(std::string id, double length, double width, std::string color):Shape(id,color) {
    _id=id;
    _length=length;
    _width=width;
    _color=color;
    if(_length<=0 || _width<=0){
        run=false;
        throw string ("This is not a rectangle!");
    }
    strlength = std::to_string(_length);
    strwidth = std::to_string(_width);
    recinfo="Rectangle ("+strlength.erase(strlength.length()-3,strlength.length()-2) +", "+strwidth.erase(strwidth.length()-3,strwidth.length()-2) +")";
  }


  double area() const {
    if(run) return _length * _width;
    else return 0;
  }

  double perimeter() const {
    if(run) return (2.0*(_length + _width));
    else return 0;
    }
  std::string info() const {
    return recinfo;
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
  double _length, _width;
  std::string recinfo,strlength,strwidth,_id,_color;
  bool run=true;
};

#endif
