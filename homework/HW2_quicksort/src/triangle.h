#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include "two_dimensional_coordinate.h"
using namespace std;

class Triangle: public Shape{
public:
    Triangle(std::vector<TwoDimensionalCoordinate*> vectors):_vectors(vectors) {
      if(_vectors.size()!=3){
          run=false;
          throw string ("This is not a triangle!");
      }
      double _x1=_vectors[0]->getX();
      double _x2=_vectors[1]->getX();
      double _x3=_vectors[2]->getX();
      double _y1=_vectors[0]->getY();
      double _y2=_vectors[1]->getY();
      double _y3=_vectors[2]->getY();
      _l1=sqrt(pow((_x2-_x1),2)+pow((_y2-_y1),2));
      _l2=sqrt(pow((_x3-_x2),2)+pow((_y3-_y2),2));
      _l3=sqrt(pow((_x3-_x1),2)+pow((_y3-_y1),2));
      if(!((_l1+_l2)>_l3 && (_l1+_l3)>_l2 && (_l3+_l2)>_l1)){
          run=false;
          throw string ("This is not a triangle!");
      }
      triperimeter=_l1+_l2+_l3;
      triarea=abs(_x1*_y2+_x2*_y3+_x3*_y1-_y1*_x2-_y2*_x3-_y3*_x1)/2.0;
    }
    double perimeter() const {
      if(run) return triperimeter;
      else return -1;
    }
    double area() const {
      if(run) return triarea;
      else return -1;
    }
    std::string info() const {
        string an="Triangle (";
        string temp="";
        for(int i=0;i<3;i++){
          string tempx=to_string(_vectors[i]->getX());
          string tempy=to_string(_vectors[i]->getY());
          temp+="["+tempx.erase(tempx.length()-3,tempx.length()-1) +", "+tempy.erase(tempy.length()-3,tempy.length()-1)+"]";
          if(i!=2)
            temp+=", ";
        }
        an+=temp+")";
        return an;
    }
  private:
    std::vector<TwoDimensionalCoordinate*> _vectors;
    double _x1,_x2,_x3,_y1,_y2,_y3;
    double _l1=0,_l2=0,_l3=0;
    double triperimeter ,triarea;
    bool run=true;
};
#endif
