#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H
#include <string>
#include <vector>
#include "visitor.h"
using namespace std;
class InfoVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
      double _semiMajorAxes=ellipse->getsemiMajorAxes();
      double _semiMinorAxes=ellipse->getsemiMinorAxes();
      string strsemiMajorAxes = std::to_string(_semiMajorAxes);
      string strsemiMinorAxes = std::to_string(_semiMinorAxes);
      _info="Ellipse ("+strsemiMajorAxes.erase(strsemiMajorAxes.length()-3,strsemiMajorAxes.length()-1)+", "+strsemiMinorAxes.erase(strsemiMinorAxes.length()-3,strsemiMinorAxes.length()-1)+")";
    }

    void visit(Triangle* triangle) {
      _coordinates = triangle->get_TwoDimension();
      x1=_coordinates[0]->getX();
      x2=_coordinates[1]->getX();
      x3=_coordinates[2]->getX();
      y1=_coordinates[0]->getY();
      y2=_coordinates[1]->getY();
      y3=_coordinates[2]->getY();
      _info="Triangle (";
      for(int i=0;i<3;i++){
        string tempx=to_string(_coordinates[i]->getX());
        string tempy=to_string(_coordinates[i]->getY());
        _info+="["+tempx.erase(tempx.length()-3,tempx.length()-1) +", "+tempy.erase(tempy.length()-3,tempy.length()-1)+"]";
        if(i!=2)
          _info+=", ";
      }
      _info+=")";
    }

    void visit(Rectangle* rectangle) {
      string strlength = std::to_string(rectangle->getlength());
      string strwidth = std::to_string(rectangle->getwidth());
      _info="Rectangle ("+strlength.erase(strlength.length()-3,strlength.length()-2) +", "+strwidth.erase(strwidth.length()-3,strwidth.length()-2) +")";
    }

    // void visit(CompoundShape* compoundShape) {
    //   _info ="Compound Shape {";
    //   int it_size = 0;
    //   int info_size = 0;
    //   Iterator * it = compoundShape->createIterator();
    //   InfoVisitor * infovisit = new InfoVisitor();
    //   for(it->first(); !it->isDone(); it->next()) {
    //     it_size ++;
    //   }
    //   for(it->first();!it->isDone();it->next()){
    //     info_size++;
    //     it->currentItem()->accept(infovisit);
    //     _info += infovisit->info() ;
    //     if(!(info_size==it_size)){
    //       _info += ", ";
    //     }
    //     if(info_size==it_size){
    //       _info +=  "}";
    //     }
    //   }
    // }
    void visit(CompoundShape* compoundShape) {
        _info ="Compound Shape {";
        Iterator * it = compoundShape->createIterator();
        InfoVisitor * infovisit = new InfoVisitor();
        for(it->first(); !it->isDone(); it->next()) {
          it_size ++;
        }
        for(it->first(); !it->isDone(); it->next()){
          info_size++;
          if(!it->currentItem()->createIterator()->isDone()){
            _info +="Compound Shape {";
            Iterator * it1 = it->currentItem()->createIterator();
            for(it1->first(); !it1->isDone(); it1->next()) {
              it1_size ++;
            }
            for(it1->first(); !it1->isDone(); it1->next()){
              info1_size++;
              if(!(info1_size==it1_size)){
              it1->currentItem()->accept(infovisit);
              _info += infovisit->info() ;
                _info += ", ";
              }
              if(info1_size==it1_size){
                it1->currentItem()->accept(infovisit);
                _info += infovisit->info() ;
                _info +=  "}";
              }
            }
            _info +="}";
          }
          else{
            it->currentItem()->accept(infovisit);
            _info += infovisit->info() ;
            if(!(info_size==it_size)){
              _info += ", ";
            }
            if(info_size==it_size){
              _info +=  "}";
            }
          }
        }
    }
    std::string info() const {
        return _info;
    }
private:
    std::vector<TwoDimensionalCoordinate *> _coordinates;
    std::string _info;
    double x1,x2,x3,y1,y2,y3;
    int it_size = 0,it1_size = 0,info_size = 0,info1_size = 0;
};

#endif
