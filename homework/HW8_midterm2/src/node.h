#ifndef NODE_H
#define NODE_H
#include <string>
#include "iterator.h"
#include "null_iterator.h"
#include "node_iterator.h"
#include "visitor.h"
#include <list>
class Node {
public:
    Node(std::string id, std::string name, double size);
    std::string id() const; 
    std::string name() const;
    virtual double size() const = 0;
    virtual std::string route() const;
    virtual void updatePath(std::string path); 
    virtual void accept(Visitor* visitor) = 0;
    virtual void addNode(Node *node); 
    virtual void addNodes(std::list<Node*> nodes);
    virtual void deleteNodeById(std::string id); 
    virtual Node* getNodeById(std::string id) const;
    virtual Iterator * createIterator() const;
    virtual ~Node();
private:
  std::string _id,_name,_route;
  double _size;
  std::list<Node*> nodes;
};
#endif
