#pragma once

#include "shape.h"
#include "rectangle.h"
#include "mixed_shape.h"
#include "triangle.h"
#include <stack>
#include <vector>
class ShapeBuilder {

protected:
    ShapeBuilder(){}

public:
    static ShapeBuilder * instance(){
        if(!_instance)
            _instance = new ShapeBuilder();
        return _instance;
    }

    void buildMixedBegin() {
        Shape * ms = new MixedShape();
        _pushdown.push(ms); 
    }

    void buildMixedEnd() {
        std::vector<Shape *> v;
        while(!dynamic_cast<MixedShape*>(_pushdown.top()) ||
            (dynamic_cast<MixedShape*>(_pushdown.top()) && !_pushdown.top()->createIterator()->isDone())){
            v.push_back(_pushdown.top());
            _pushdown.pop();
        }
        for(auto it=v.rbegin(); it!=v.rend(); it++){
            _pushdown.top()->add(*it);
        }
    }
    void buildRect(double w, double l) {
        Shape * r = new Rectangle(w, l);
        _pushdown.push(r);
    }

    void buildTri(double a, double b, double c) {
        Shape * t =new Triangle(a, b, c);
        _pushdown.push(t);
    }
    std::vector<Shape *> getResult() {
        std::vector<Shape *> result;
        
        while(!_pushdown.empty()){
            result.push_back(_pushdown.top());
            _pushdown.pop();
        }
        return std::vector<Shape*>(result.rbegin(),result.rend());
    }
private:
    std::stack<Shape *> _pushdown;
    static ShapeBuilder * _instance;
};

ShapeBuilder * ShapeBuilder::_instance = nullptr;