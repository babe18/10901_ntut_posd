#pragma once

#include "shape.h"
#include "find_first_visitor.h"

typedef bool (*FilterFunction)(Shape *);

class AreaFilter
{
public:
    AreaFilter(FilterFunction f) {
        _sv = new FindFirstVisitor(f);
    }
    void setNext(AreaFilter * af) {
        _next = af;
    }
    Shape * push(Shape * shape) {
        shape->accept(*_sv);
        Shape * s = _sv->getResult();
        if(!s) {
            return s;
        }
        if(_next) {
            return _next->push(s);
        }
        return s;
        // if(_f(shape)) {
        //     if(_next) {
        //         return _next->push(shape);
        //     }
        //     return shape;
        // }
        // return nullptr;
    }
private:
    AreaFilter * _next;
    FindFirstVisitor * _sv;
}; 