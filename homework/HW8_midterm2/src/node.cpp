#include "node.h"
#include <string>
#include <list>
Node::Node(std::string id, std::string name, double size):_id(id),_name(name),_size(size){}

std::string Node::id() const{
  return _id;
}
std::string Node::name() const{
  return _name;
}
std::string Node::route() const{
  return _route;
}

void Node::updatePath(std::string path){}
void Node::addNode(Node *shape){
  throw std::string ("only folder can add node.");
}

void Node::addNodes(std::list<Node*> nodes){
  throw std::string ("only folder can add node.");
}

void Node::deleteNodeById(std::string id){
  throw std::string ("only folder can delete node.");
}

Node* Node::getNodeById(std::string id) const {
  throw std::string ("only folder can get node.");
}

Iterator * Node::createIterator() const{
  return new NullIterator();
}
Node::~Node() {};