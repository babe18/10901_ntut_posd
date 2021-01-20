#pragma once
#include <string>
#include <vector>
#include "shape_builder.h"
#include "shape.h"
#include "scanner.h"


class Parser{
public:
    Parser(std::string input):_input(input){
        _builder = ShapeBuilder::instance();
        _scanner = new Scanner(_input);
    }

    void parse(){
        while(!_scanner->isDone()){
            std::string token = _scanner->next();
            if(token == "rect") {
                _builder->buildRect(_scanner->nextDouble(), _scanner->nextDouble());
            }
            else if(token == "tri") {
                _builder->buildTri(_scanner->nextDouble(), _scanner->nextDouble(), _scanner->nextDouble());
            }
            else if(token == "mixed") {
                if(_scanner->next() == "{") {
                    _builder->buildMixedBegin();
                }                
            }
            else if(token == "}") {
                _builder->buildMixedEnd();
            }
        }
        _result = _builder->getResult();
    }

    std::vector<Shape*> getResult(){
        return _result;
    }
private:
    std::string _input;
    std::vector<Shape*> _result;
    ShapeBuilder * _builder;
    Scanner * _scanner;

};