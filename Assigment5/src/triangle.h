#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>
#include "shape.h"
#include <vector>
#include <string>
#include "two_dimensional_coordinate.h"
#include <iostream>
using namespace std;


class Triangle: public Shape{
public:
    Triangle(std::string id,std::vector<TwoDimensionalCoordinate*> vectors): Shape(id) {
        _vectors = vectors;
        if(_vectors.size()!=3){
          run=false;
          throw string ("This is not a triangle!");
      }
        x1 = _vectors[0]->getX();
        y1 = _vectors[0]->getY();
        x2 = _vectors[1]->getX();
        y2 = _vectors[1]->getY();
        x3 = _vectors[2]->getX();
        y3 = _vectors[2]->getY();
        double L1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
        double L2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
        double L3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
        if(!(L1+L2>L3&&L1+L3>L2&&L3+L2>L1)){
          run=false;
          throw string ("This is not a triangle!");
      }
        pmeter = L1 + L2 + L3;
        // handle the exception by throwing string "This is not a triangle!"
    }
    Triangle(std::string id,std::vector<TwoDimensionalCoordinate*> vectors,std::string color): Shape(id,color) {
        _vectors = vectors;
        if(_vectors.size()!=3){
          run=false;
          throw string ("This is not a triangle!");
      }
        x1 = _vectors[0]->getX();
        y1 = _vectors[0]->getY();
        x2 = _vectors[1]->getX();
        y2 = _vectors[1]->getY();
        x3 = _vectors[2]->getX();
        y3 = _vectors[2]->getY();
        double L1=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
        double L2=sqrt(pow((x3-x2),2)+pow((y3-y2),2));
        double L3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
        if(!(L1+L2>L3&&L1+L3>L2&&L3+L2>L1)){
          run=false;
          throw string ("This is not a triangle!");
      }
        pmeter = L1 + L2 + L3;
        // handle the exception by throwing string "This is not a triangle!"
    }


    double area() const {
       if(run) return abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2.0;
       else return -1;// return the area of the Triangle.
    }

    double perimeter() const {
      string p = to_string(pmeter);
      p = p.erase(p.length()-3,p.length()-1);
      if(run) return stod(p);
      else return -1;
        // return the perimeter of the Triangle.
    }

    std::string info() const {
      std::string an;
      an = "Triangle (";
      for(int i=0;i<3;i++){
        std::string a = std::to_string(_vectors[i]->getX());
        std::string b = std::to_string(_vectors[i]->getY());
        an += "["+a.erase(a.length()-3,a.length()-1) + ", "+b.erase(b.length()-3,b.length()-1)+"]";
        if(i!=2)
          an += ", ";
      }
      an += ")";

      return an;
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
    }
    std::string type() const {
      std::string type_name = "Triangle";
      return type_name;
    }

private:
    std::vector<TwoDimensionalCoordinate*> _vectors;
    double x1,x2,x3,y1,y2,y3;
    double pmeter;
    double L1=0,L2=0,L3=0;
    bool run=true;
};
#endif
