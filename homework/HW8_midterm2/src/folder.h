#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include "node.h"
#include "node_iterator.h"
#include "iterator.h"
#include "visitor.h"
#include <cmath>
using namespace std;
class Folder : public Node {
public:
    Folder(std::string id, std::string name):Node(id,name,0) {
      _nodes.clear();
      _id=id;
      _name=name;     
    } 
    std::string id() const{
      return _id;
    }
    std::string name() const {
      return _name;
    }
    Iterator * createIterator()  const {
      return new NodeIterator<std::list<Node *>::const_iterator>(_nodes.begin(), _nodes.end());
    }
    double size() const {
      double size = 0.0; 
      Iterator * itsize = createIterator();
      for (itsize->first(); !itsize->isDone(); itsize->next()){
        size +=  itsize->currentItem()->size();
      }
      return size;
    }
    std::string route() const {
      return _path + "/"+_name;
    }
    void updatePath(std::string path){
      _path = path;
    }
    void accept(Visitor * visitor) {
      visitor->visitFolder(this);
    }
    void addNode(Node* node){
      _nodes.push_back(node);          
      node->updatePath(_path + "/"+_name);
      update_leaf_path(node, node->route());
    }
    void addNodes(std::list<Node*> nodes){
      for (std::list<Node*>::iterator it = nodes.begin() ; it != nodes.end(); it++){
        _nodes.push_back(*it);
        (*it)->updatePath(_path + "/"+_name);
        update_leaf_path((*it), (*it)->route());
      }
    }
    void update_leaf_path(Node*node , string route){
      Iterator * it = node->createIterator();
      //isfolder
      if(!it->isDone()){
        for(it->first();!it->isDone();it->next()){
          //folder_in_folder
          if(!it->currentItem()->createIterator()->isDone()){
            update_leaf_path(it->currentItem() , route+"/"+it->currentItem()->name());
          }
          it->currentItem()->updatePath(route);
        }
      }
    }
    Node* getNodeById(std::string id) const{
      Iterator * it = createIterator();
      bool match = 0;
      for (it->first(); !it->isDone(); it->next()){
        if( it->currentItem()->id() == id ){
                match = 1;
                break;
        }
        if(!it->currentItem()->createIterator()->isDone()){
            return it->currentItem()->getNodeById(id);
        }
      }
      if(match==0){
            throw std::string ("Expected get node but node not found.");
      }
      return it->currentItem();
    }
  
    void deleteNodeById(std::string id) {
      Iterator * it = createIterator();
      bool match = 0;
      for (it->first()  ; !it->isDone(); it->next()){
        if( it->currentItem()->id() == id ){
          match = 1;
          _nodes.remove(it->currentItem());
          break;
        }
        if(!it->currentItem()->createIterator()->isDone()){
          return it->currentItem()->deleteNodeById(id);
        }
      }
      if(match==0){
        throw std::string ("Expected delete node but node not found.");
      }
    }
private :
  std::string _id , _name , _path;
  std::list<Node*> _nodes;
};

#endif