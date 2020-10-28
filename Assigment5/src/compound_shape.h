#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H
#include <cmath>
#include "shape.h"
#include "iterator.h"
#include "shape_iterator.h"
#include <string>
#include <vector>
#include <list>

class CompoundShape : public Shape {
public:
        CompoundShape(std::string id, std::list<Shape*> shapes):Shape(id,"transparent") {

            _id = id;
            _shapes = shapes;

            if(_shapes.empty()){
              throw std::string ("This is not a compound shape!");
            }
        }

        // template<class ForwardIterator>
        Iterator* createIterator() const{
            // ShapeIterator<std::list<Shape*>::const_iterator> si(_shapes.begin(), _shapes.end());
            return new ShapeIterator<std::list<Shape*>::const_iterator>(_shapes.begin(), _shapes.end());
        }


        double area() const {
            std::list<Shape*>::const_iterator it;
            double SumOfArea = 0.0;

            for(it = _shapes.begin(); it != _shapes.end(); it++){
              SumOfArea += (*it)->area();
            }

            return SumOfArea;
        }

        double perimeter() const {
            std::list<Shape*>::const_iterator it;
            double SumOfPerimeter = 0.0;

            for(it = _shapes.begin(); it != _shapes.end(); it++){
              SumOfPerimeter += (*it)->perimeter();
            }

            return SumOfPerimeter;
        }

        std::string info() const {
            std::list<Shape*>::const_iterator it;
            std::string AllInfo = "Compound Shape {";
            for (it = _shapes.begin();it!=_shapes.end();it++) {
                if (std::distance(it,_shapes.end())==1)
                    AllInfo += (*it)->info() + "}";
                    else
                    AllInfo += (*it)->info() + ", ";
            }

            return AllInfo;
            // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
        }

        std::string type() const {
          std::string type_name = "Compound Shape";
          return type_name;
        }

        void addShape(Shape* shape) {
            _shapes.push_back(shape);

        }

        void deleteShapeById(std::string id) {
            Iterator * it = createIterator();
            bool NoMatch = 1;

            for (it->first(); !it->isDone(); it->next()) {
                    if (id == it->currentItem()->id()){
                        _shapes.remove(it->currentItem());
                        NoMatch = 0;
                        return ;
                    }
                    else if (!it->currentItem()->createIterator()->isDone()){
                      it->currentItem()->deleteShapeById(id);
                      return ;
                    }
            }
            if(NoMatch){
              throw std::string("Expected delete shape but shape not found");
            }
            // search all the containing shapes and the tree structure below,
        }


        // void deleteShapeById(std::string id) {
        //     std::list<Shape*>::const_iterator it;
        //     bool NoMatch = 1;
        //
        //     for (it = _shapes.begin(); it != _shapes.end(); it++) {
        //             if (id == (*it)->id()){
        //                 _shapes.erase(it);
        //                 NoMatch = 0;
        //                 return ;
        //             }
        //             else if ((*it)->color() == "transparent"){
        //               (*it)->deleteShapeById(id);
        //               return ;
        //             }
        //     }
        //     if(NoMatch){
        //       throw std::string("Expected delete shape but shape not found");
        //     }
        //     // search all the containing shapes and the tree structure below,
        // }

        // Shape* getShapeById(std::string id) const{
        //     std::list<Shape*>::const_iterator it;
        //     bool NoMatch = 1;
        //
        //     for (it = _shapes.begin(); it!=_shapes.end(); it++) {
        //             if (id == (*it)->id()){
        //                 NoMatch = 0;
        //                 break;
        //             }
        //             else if ((*it)->type() == "Compound Shape")
        //               return (*it)->getShapeById(id);
        //     }
        //     if(NoMatch){
        //       throw std::string("Expected get shape but shape not found");
        //     }
        //
        //     return *it;
        //
        // }

        Shape* getShapeById(std::string id) const{
            Iterator * it = createIterator();
            bool NoMatch = 1;

            for (it->first(); !it->isDone(); it->next()) {
                    if (id == it->currentItem()->id()){
                        NoMatch = 0;
                        break;
                    }
                    else if (!it->currentItem()->createIterator()->isDone())
                      return it->currentItem()->getShapeById(id);
            }
            if(NoMatch){
              throw std::string("Expected get shape but shape not found");
            }

            return it->currentItem();

        }

private:
  std::string _id;
  std::list<Shape*> _shapes;

};
#endif
