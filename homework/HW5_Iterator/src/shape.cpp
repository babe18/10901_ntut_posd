#include "shape.h"
#include <string>

Shape::Shape(std::string id):_id(id),_color("white") {}

Shape::Shape(std::string id, std::string color):_id(id),_color(color) {}

std::string Shape::id() const{
  return _id;
}

std::string Shape::color() const{
  return _color;
}

void Shape::addShape(Shape *shape){
  throw std::string ("Only compound shape can add shape!");
}

void Shape::deleteShapeById(std::string id){
  throw std::string ("Only compound shape can delete shape!");
}

Shape* Shape::getShapeById(std::string id) const {
  throw std::string ("Only compound shape can get shape!");
}

Iterator * Shape::createIterator() const{
  return new NullIterator();
}
