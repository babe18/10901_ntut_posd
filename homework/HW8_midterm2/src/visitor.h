#ifndef VISITOR_H
#define VISITOR_H

class App;
class Folder;
class Visitor {
public:
    virtual void visitApp(App* app) = 0;
    virtual void visitFolder(Folder* folder) = 0;
};
#endif
