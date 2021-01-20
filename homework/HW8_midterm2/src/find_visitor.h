#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include <cmath>
#include <vector>
#include "iterator.h"
#include "node_iterator.h"
#include "app.h"
#include "node.h"
#include "folder.h"
#include "visitor.h"

class FindVisitor : public Visitor {
public:
    FindVisitor(std::string name):_name(name) {}
    void visitApp(App* app) {
        if(_name==app->name()){
            result = app->route();
        }
    }
    void visitFolder(Folder* folder) {
        if(_name==folder->name()) result = folder->route();
        Iterator * it = folder->createIterator();
        if(!it->isDone()){
            for(it->first();!it->isDone();it->next()){
                if(it->currentItem()->name()==_name) {
                    if(result!="") result +="\n";
                    result += it->currentItem()->route();
                }
                if(!it->currentItem()->createIterator()->isDone()){
                    Iterator * it2 = it->currentItem()->createIterator();
                    for(it2->first(); !it2->isDone(); it2->next()){
                        if(it2->currentItem()->name()==_name) {
                            if(result!="") result +="\n";
                            result += it2->currentItem()->route();
                        }
                        if(!it2->currentItem()->createIterator()->isDone()){
                            Iterator * it3 = it2->currentItem()->createIterator();
                            for(it3->first(); !it3->isDone(); it3->next()){
                                if(it3->currentItem()->name()==_name) {
                                    if(result!="") result +="\n";
                                    result += it3->currentItem()->route();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::string getResult() const {
        return result;
    }
private:
      string result ="";
      string _name;
};
#endif
