#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H
#include <cmath>
#include <vector>
#include "iterator.h"
#include "shape_iterator.h"
#include "two_dimensional_coordinate.h"
#include "visitor.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "compound_shape.h"

class AreaVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        _area = M_PI*ellipse->getsemiMajorAxes()*ellipse->getsemiMinorAxes();
    }

    void visit(Triangle* triangle) {
        _coordinates = triangle->get_TwoDimension();
        x1 = _coordinates[0]->getX();
        y1 = _coordinates[0]->getY();
        x2 = _coordinates[1]->getX();
        y2 = _coordinates[1]->getY();
        x3 = _coordinates[2]->getX();
        y3 = _coordinates[2]->getY();
        _area = abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2.0;
    }

    void visit(Rectangle* rectangle) {
        _area = rectangle->getlength()*rectangle->getwidth();
    }

    void visit(CompoundShape* compoundShape) {
      _area = 0;
      Iterator * it = compoundShape->createIterator();
      AreaVisitor * areavisitor = new AreaVisitor();
      for(it->first();!it->isDone();it->next()){
        if(!it->currentItem()->createIterator()->isDone()){
          Iterator * it1 = it->currentItem()->createIterator();
          for(it1->first(); !it1->isDone(); it1->next()){
              it1->currentItem()->accept(areavisitor);
              _area += areavisitor->area();
           }
        }
        else{
          it->currentItem()->accept(areavisitor);
          _area += areavisitor->area();
        }
      }
    }

    // void visit(CompoundShape* compoundShape) {
    //
    //   Iterator * it = compoundShape->createIterator();
    //   for(it->first(); !it->isDone(); it->next()){
    //     cout<<it->currentItem()->area()<<endl;
    //     _area += it->currentItem()->area();
    //   }
    // }
    double area() const {
        return _area;
    }

private:
      std::vector<TwoDimensionalCoordinate *> _coordinates;
      double _area = 0.0;
      double x1,x2,x3,y1,y2,y3;
};
#endif
