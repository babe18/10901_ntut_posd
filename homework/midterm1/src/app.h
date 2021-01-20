#ifndef APP_H
#define APP_H
#include <string>
#include "node.h"
#include <cmath>

class App : public Node {
public:
    App(std::string id, std::string name, double size):Node(id,name,size) {
      _id = id;
      _name = name;
      _size = size;
    }

    std::string id() const{
      return _id;
    }

    std::string name() const{
      return _name;
    }

    std::string route() const{
      return _path + "/" + _name;
    }

    double size() const{
      return _size;
    }

    void updatePath(std::string path){
      _path = path;
    }

private:
  std::string _id,_name,_path = "";
  double _size;
};
#endif
