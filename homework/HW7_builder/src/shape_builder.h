#ifndef SHAPE_BUILDER_H
#define SHAPE_BUILDER_H
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "compound_shape.h"
#include "triangle.h"
#include "two_dimensional_coordinate.h"
#include <math.h>
#include <stack>
#include <vector>
#include <sstream>      
#include <string>

class ShapeBuilder {
public:
    ShapeBuilder() {}

    void buildRectangle(double length, double width) {
        _id +=1;
        id = std::to_string(_id);
        Shape * r = new Rectangle(id,length, width);
        _pushdown.push(r);
    }
    
    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        _id +=1;
        id = std::to_string(_id);
        Shape * e = new Ellipse(id,semiMajorAxes, semiMinorAxes);
        _pushdown.push(e);
    }
    
    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        _id +=1;
        id = std::to_string(_id);
        TwoDimensionalCoordinate t1(x1, y1);
        TwoDimensionalCoordinate t2(x2, y2);
        TwoDimensionalCoordinate t3(x3, y3);
        std::vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(&t1);
        triangleVector.push_back(&t2);
        triangleVector.push_back(&t3);
        Shape * t =new Triangle(id,triangleVector);
        _pushdown.push(t);
    }
    
    void buildCompoundShapeBegin() {
        b+=1;
        _id +=1;
        id = std::to_string(_id);
        cs_id.push(id); 
        std::list<Shape*> shapeVec;
        Shape * ms = new CompoundShape(id, shapeVec);
        _pushdown.push(ms); 
    }
    
    void buildCompoundShapeEnd() {
        std::vector<Shape *> v;
        while((_pushdown.top())->id() != cs_id.top()){
            v.push_back(_pushdown.top());
            _pushdown.pop();
        }
        for(auto it=v.rbegin(); it!=v.rend(); it++){           
            _pushdown.top()->addShape(*it);
        }
        cs_id.pop();
    }
    
    std::deque<Shape*> getResult() {
        std::deque<Shape *> result;
        while(!_pushdown.empty()){
            result.push_back(_pushdown.top());
            _pushdown.pop();
        }
        return std::deque<Shape*>(result.rbegin(),result.rend());
    }

private:
    std::stack<Shape *> _pushdown;
    std::stack<string> cs_id;
    string id;
    int _id = 0;
    int a = 0;
    int b = 0;

};

#endif

