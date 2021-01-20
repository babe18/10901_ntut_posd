#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <list>
#include "iterator.h"
#include "node_iterator.h"
#include "node.h"

class Folder : public Node {
public:
    Folder(std::string id, std::string name):Node(id,name,0) {
      _id = id;
      _name = name;
    } // the default size of folder is zero.

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
      double _size = 0;

      Iterator * it = createIterator();

      for(it->first();!it->isDone();it->next()){

        _size += it->currentItem()->size();
        // std::cout<<it->currentItem()->size()<<endl;
      }

      return _size;
    }

    void updatePath(std::string path){
      _path = path + _path ;
    }

    void addNode(Node* node){
      _nodes.push_back(node);
      node->updatePath(_path+"/"+_name);
    }

    Node* getNodeById(std::string id) const{

      Iterator * it = createIterator();
      bool NoMatch = 1;

      for (it->first(); !it->isDone(); it->next()) {
              if (id == it->currentItem()->id()){
                  NoMatch = 0;
                  break;
              }
              else if (!it->currentItem()->createIterator()->isDone())
                return it->currentItem()->getNodeById(id);
      }
      if(NoMatch){
        throw std::string("Expected get node but node not found.");
      }

      return it->currentItem();
    }

    void deleteNodeById(std::string id){
      Iterator * it = createIterator();
      bool NoMatch = 1;

      for (it->first(); !it->isDone(); it->next()) {
              if (id == it->currentItem()->id()){
                  _nodes.remove(it->currentItem());
                  NoMatch = 0;
                  return ;
              }
              else if (!it->currentItem()->createIterator()->isDone()){
                it->currentItem()->deleteNodeById(id);
                return ;
              }
      }
      if(NoMatch){
        throw std::string("Expected delete node but node not found.");
      }
    }
    Iterator* createIterator() const{
        return new NodeIterator<std::list<Node*>::const_iterator>(_nodes.begin(), _nodes.end());
    }


private:
    std::list<Node*> _nodes;
    std::string _id,_name,_path;
};
#endif
