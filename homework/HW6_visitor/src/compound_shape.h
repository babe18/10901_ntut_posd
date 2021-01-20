#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H
#include <cmath>
#include "shape.h"
#include "iterator.h"
#include "shape_iterator.h"
#include <string>
#include <vector>
#include <list>

class CompoundShape : public Shape{
public:
        CompoundShape(std::string id, std::list<Shape*> shapes):Shape(id,"transparent"){
           _id=id;
           _shapes=shapes;
            if(_shapes.empty()){
              throw std::string ("This is not a compound shape!");
            }
        }
        double area() const {
            // return sum of all containing shapes area.
            double totalarea = 0.0;
            for (std::list<Shape*>::const_iterator it = _shapes.begin() ; it != _shapes.end(); it++){
              totalarea += (*it)->area();
            }
            return totalarea;
        }

        double perimeter() const {
            // return sum of all containing shapes perimeter.
            double totalperimeter = 0.0;
            for (std::list<Shape*>::const_iterator it = _shapes.begin();it!=_shapes.end();it++){
              totalperimeter += (*it)->perimeter();
            }
            return totalperimeter;
        }
        std::string info() const{
            std::string totalinfo ="Compound Shape {";
            for(std::list<Shape*>::const_iterator it=_shapes.begin();it!=_shapes.end();it++){
              totalinfo += (*it)->info();
              if((*it)!= *(_shapes.rbegin())){
                  totalinfo += ", ";
              }
            }
            totalinfo += "}";
            return totalinfo;
        }
    		// double area() const {
    		// 	// return sum of all containing shapes area.
    		// 	double totalarea = 0.0;
    		// 	for (auto shape : _shapes) {
    		// 		totalarea += shape->area();
    		// 	}
    		// 	return totalarea;
    		// }
    		// double perimeter() const {
    		// 	// return sum of all containing shapes perimeter.
    		// 	double totalperimeter = 0.0;
    		// 	for (auto shape : _shapes) {
    		// 		totalperimeter += shape->perimeter();
    		// 	}
    		// 	return totalperimeter;
    		// }
    		// std::string info() const {
    		// 	// return list of all containing shapes info with wrapped of "CompoundShape {}".
    		// 	std::string totalinfo = "Compound Shape {";
    		// 	for (auto shape : _shapes) {
    		// 		totalinfo += shape->info();
    		// 		if (shape != *(_shapes.rbegin())) {
    		// 			totalinfo += ", ";
    		// 		}
    		// 	}
    		// 	totalinfo += "}";
    		// 	return totalinfo;
    		// }
        std::string type() const {
          std::string _type="Compound Shape";
          return _type;
        }
        void accept(Visitor* visitor) {
          visitor->visit(this);
        }
        Iterator * createIterator()  const {
          return new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
        }

        void addShape(Shape* shape) {
           _shapes.push_back(shape);
        }

      void deleteShapeById(std::string id) {
      for (std::list<Shape*>::iterator it = _shapes.begin() ; it != _shapes.end(); it++){
        try{
          return (*it)->deleteShapeById(id);
        }catch(std::string e){
          if( (*it)->id() == id ){
            _shapes.erase(it);
            return;
          }
          if(id != ((*it)->id()) && (*it) == *(_shapes.rbegin())){
              throw std::string ("Expected delete shape but shape not found");
          }
        }
      }
    }

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
//     void deleteShapeById(std::string id) {
//     Iterator * it = createIterator();
//     bool match = 0;
//     for (it  ; !it->isDone(); it->next()){
//           if(!it->currentItem()->createIterator()->isDone()){
//             return it->currentItem()->deleteShapeById(id);
//           }
//           else if( it->currentItem()->id() == id ){
//             match = 1;
//             _shapes.remove(it->currentItem());
//             break;
//           }
//       }
//         if(match==0){
//             throw std::string ("Expected delete shape but shape not found");
//         }
//     //  return;
//     }
//
//
//   Shape* getShapeById(std::string id) const{
//       Iterator * it = createIterator();
//       bool match = 0;
//       for (it  ; !it->isDone(); it->next()){
//         if(!it->currentItem()->createIterator()->isDone()){
//               return it->currentItem()->getShapeById(id);
//             }
//         else if( it->currentItem()->id() == id ){
//                 match = 1;
//                 break;
//               }
//   }
//   if(match==0){
//       throw std::string ("Expected get shape but shape not found");
//   }
//   return it->currentItem();
// }

  private :
  std::list<Shape*> _shapes;
  std::string _id;
  double MATCH;
};

#endif