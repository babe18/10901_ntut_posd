#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "shape.h"
class CompoundShape : public Shape{
public:
        CompoundShape(std::string id, std::vector<Shape*>* shapes):Shape(id,"transparent"){
           _id=id;
           _shapes=shapes;
            // The default color of compound shape should be "Transparent".
            // When there's no shape contain in the compound shape,
            // should throw std::string "This is not a compound shape!"
            if(_shapes->empty()){
              throw std::string ("This is not a compound shape!");
            }
        }

        double area() const {
            // return sum of all containing shapes area.
            double totalarea = 0.0;
            for (std::vector<Shape*>::iterator it = _shapes->begin() ; it != _shapes->end(); it++){
              totalarea += (*it)->area();
            }
            return totalarea;
        }
        double perimeter() const {
            // return sum of all containing shapes perimeter.
            double totalperimeter = 0.0;
            for (std::vector<Shape*>::iterator it = _shapes->begin() ; it != _shapes->end(); it++){
              totalperimeter += (*it)->perimeter();
            }
            return totalperimeter;
        }
        std::string info() const {
            // return list of all containing shapes info with wrapped of "CompoundShape {}".
            std::string totalinfo ="Compound Shape {";
            for (std::vector<Shape*>::iterator it = _shapes->begin() ; it != _shapes->end(); it++){
              totalinfo += (*it)->info();
              if(*it != *(_shapes->end()-1)){
                  totalinfo += ", ";
              }
            }
            totalinfo += "}";
            return totalinfo;
        }
        void addShape(Shape* shape) {
           //add shape into compound shape.
           _shapes->push_back(shape);
        }
        void deleteShapeById(std::string id) {
            // search and delete a shape through id,
            // search all the containing shapes and the tree structure bellow,
            // if no match of id, throw std::string "Expected delete shape but shape not found"
            for (std::vector<Shape*>::iterator it = _shapes->begin() ; it != _shapes->end(); it++){
              if(id == (*it)->id()){
                  _shapes->erase(it);
                  _MATCH = true;
                  break;
              }
              else if((*it)->color()=="transparent"){
                return (*it)->deleteShapeById(id);
              }
            }
             if(_MATCH == false){
                 throw std::string ("Expected delete shape but shape not found");
             }
          }
        Shape* getShapeById(std::string id) {
            // search and return a shape through id,
            // search all the containing shapes and the tree structure bellow,
            // if no match of id, throw std::string "Expected get shape but shape not found"
            std::vector<Shape*>::iterator it;
            for (it = _shapes->begin() ; it != _shapes->end(); it++){
                if(id == (*it)->id()){
                  _MATCH = true;
                  break;
                }
                else if((*it)->color()=="transparent"){
                  return (*it)->getShapeById(id);
                }
             }

             if(_MATCH == false){
                 throw std::string ("Expected get shape but shape not found");
            }
            return (*it);
        }


  private :
  bool _MATCH=false;
  std::vector<Shape *>* _shapes;
  std::string _id,_color,an,totalinfo;
  double totalperimeter,totalarea;
};

#endif
