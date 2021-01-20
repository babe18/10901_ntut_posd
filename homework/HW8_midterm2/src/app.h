#ifndef APP_H
#define APP_H
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include "node.h"
#include "node_iterator.h"
#include "iterator.h"
#include "visitor.h"
using namespace std;
class App : public Node{
public:
 
    App(std::string id, std::string name, double size):Node(id,name,size)  {
        _name=name;
        _id=id;
        _size=size;

      }
       double size() const {
            return _size;
        }

      std::string name() const {
          return _name;
        }

        void addNode(Node* node) {
           throw std::string ("only folder can add node.");
        }
        std::string route() const {
          std::string route ="/"+_name;
          route = _path +route;
          return route;
        }
        void updatePath(std::string path){
              _path = path;
        }
        void accept(Visitor * visitor) {
          visitor->visitApp(this);
        }


  private :
  std::string _id ,_name,_path;
  double MATCH ,_size;
};

#endif
