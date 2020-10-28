#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "iterator.h"

class Shape {
private:
  std::string _id,_color;
public:
    Shape(std::string id); // interface for default color "white".
    Shape(std::string id, std::string color); // interface for color input by user.
    std::string id() const; // return id of shape
    std::string color() const; // return color of shape.
    virtual void addShape(Shape *shape); // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only compound shape can delete shape!"
    virtual Shape* getShapeById(std::string id) const; // throw std::string "Only compound shape can get shape!"
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual std::string type() const = 0;
    virtual Iterator* createIterator() const;
    virtual ~Shape();
};
#endif
