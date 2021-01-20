#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H
#include "node.h"
#include "app.h"
#include "folder.h"
#include <stack>
#include <vector>
#include <sstream>      
#include <string>
using namespace std;
class NodeBuilder {
public:
    NodeBuilder() {}
    void buildApp(string name, double size) {
        _id +=1;
        id = std::to_string(_id);
        Node * a = new App(id,name, size);
        _pushdown.push(a);
    }
    void buildFolderBegin(string name) {
        _id +=1;
        id = std::to_string(_id);
        f_id.push(id); 
        Node * f = new Folder(id, name);
        _pushdown.push(f); 
    }
    void buildFolderEnd() {
        vector<Node *> v;
        while((_pushdown.top())->id() !=f_id.top()){
            v.push_back(_pushdown.top());
            _pushdown.pop();
        }
        for(auto it=v.rbegin(); it!=v.rend(); it++){      
            _pushdown.top()->addNode(*it);
        }
        f_id.pop();
    }
    deque<Node*> getResult() {
        deque<Node *> result;
        while(!_pushdown.empty()){
            if(_pushdown.top()->createIterator()->isDone())  result.push_back(_pushdown.top());
            else{
                result.push_back(_pushdown.top());
                Iterator * it = _pushdown.top()->createIterator();
            }
            _pushdown.pop();
        }
        return deque<Node*>(result.rbegin(),result.rend());
    }

private:
    stack<Node *> _pushdown;
    deque<Node *> result;
    stack<string> f_id;
    string id,name;
    int _id = 0;
};

#endif