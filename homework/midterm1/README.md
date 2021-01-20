# **Pattern Oriented Software Design 2020 Fall Midterm 1**  

## **Notice**  
* **Exam time: 18:00 ~ 21:00, 2020/10/28**  
* **If you use any website other than [Resources Allowed To Use](#resources-allowed-to-use), you'll get no point for this test.**  
* **If you access others' ssl-gitlab, you'll get no point for the test.**  
* **If you use your phone during the test, you'll get no point for the test.**  
* **If your code fails to compile on jenkins server, you'll get no point for the test.**  
* **DO NOT use any Type Checking or Dynamic Type that would violate OCP to implement Composite pattern and Iterator pattern, if you do so, there will be a deduction of 40% where applicable.**  
* **We provide [SAMPLE UT TEST](test) and [MAKEFILE](makefile), the logic of sample unit tests are same as those on the Jenkins TA use to test your program but with some data differences. The makefile is exactly same as TA's.**  

## **Score**  
* TA Unit Test On Jenkins: 100%  
* Each TA Unit Test is allocated 1 to 5 points according to its difficulty level  
* Points will be deducted if you change given interface (for example, removing ```const```.)  

## **Resources Allowed To Use**  
[cplusplus](http://www.cplusplus.com/)  
[Cambridge Dictionary](https://dictionary.cambridge.org/)  
[Jenkins](https://ssl-jenkins.csie.ntut.edu.tw/)  
[GitLab](https://ssl-gitlab.csie.ntut.edu.tw/)  

## **Problems**
Write a program to simulate organizing apps and folders on your Home Screen:  

<img src="ios_home_page.jpg" width="250"/>

* Create app/folder on page.  
* Add app/folder in folder.  
* Delete app/folder from folder.  
* Get app/folder from folder.  
* Get app/folder id, name, size, route.  

## **Requirement**  
1. Add class `Node` in `node.h`, add the implementation in `node.cpp` if you think it's suitable.
```
class Node {
public:
        Node(std::string id, std::string name, double size);

        std::string id() const;

        std::string name() const;
        
        virtual std::string route() const; // the "virtual" of this funtion is optional.

        virtual double size() const;

        virtual void updatePath(std::string path);
        
        virtual void addNode(Node* node);
        
        virtual Node* getNodeById(std::string id) const;
        
        virtual void deleteNodeById(std::string id);

        virtual Iterator* createIterator() const;

        virtual ~Node();
};
```
* `path`: should initalize with empty std::string.  
* `id()`: return id.  
* `name()`: return name.  
* `route()`: return path + `/` + name.  
* `size()`:  
    App - return size of itself.  
    Folder - return sum of all containing nodes size.  
* `updatePath()`:  
    App - update the path with the given path.  
    Folder - update the path with the given path and update the path of it's children.  
* `addNode()`:  
    App - throw std::string "only folder can add node.".  
    Folder - add node into folder and update the path of the node.  
* `getNodeById()`:  
    App - throw std::string "only folder can get node.".  
    Folder - search and return a node through id, search all the containing nodes and the tree structure below, if not found, throw std::string "Expected get node but node not found."  
* `deleteNodeById()`:  
    App - throw std::string "only folder can delete node.".  
    Folder - search and delete a node through id, search all the containing nodes and the tree structure below, if not found, throw std::string "Expected delete node but node not found."  
* `createIterator()`:  
    App - return NullIterator.  
    Folder - return NodeIterator.  

2. Implement class `App` in `app.h`.  
```
class App : public Node {
public:
    App(std::string id, std::string name, double size) {}
    
    // implement any functions inherit from Node that you think is suitable.
};
```

3. Implement class `Folder` in `folder.h`.  
```
class Folder : public Node {
public:
    Folder(std::string id, std::string name) {} // the default size of folder is zero.
    
    // implement any functions inherit from Node that you think is suitable.
    
private:
    std::list<Node*> _nodes;
};
```
* `_nodes`: should initalize as empty std::list.  

4. Add class `Iterator` in `iterator.h`.  
```
class Iterator {
public:
    virtual void first() = 0;
    
    virtual void next() = 0;
    
    virtual bool isDone() const = 0;
    
    virtual Node* currentItem() const = 0;
};
```

5. Implement interface class `NullIterator` in `null_iterator.h`.  
```
class NullIterator : public Iterator {
public:
    void first() {
        // throw std::string "No child member!"
    }

    void next() {
        // throw std::string "No child member!"
    }
    
    bool isDone() const {
        // return true
    }
    
    Node* currentItem() const {
        // throw std::string "No child member!"
    }
};
```

6. Implement `NodeIterator` class in `node_iterator.h`.  
```
template<class ForwardIterator>
class NodeIterator : public Iterator {
public:
    NodeIterator(ForwardIterator begin, ForwardIterator end) {
        // initialize iterator.
    }
    
    void first() {
        // initialize iterator.
    }
    
    void next() {
        // move iterator to next position,
        // throw std::string "Moving past the end!" when iterator move over the range of the structure.
    }
    
    bool isDone() const {
        // return true when iterator reach the end of the structure.
    }
    
    Node* currentItem() const {
        // return the Node that iterator currently point at.
    }
};
```

7. Implement following funtion and class in `utility.h`.  
```
template<class Filter>
std::deque<Node*> filterNode(Node* node, Filter filter) {
    // access the node with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the nodes under the input node tree sturctur that match the given filter.
    // throw std::string "Only folder can filter node!" when the input node is not iterable.
}

class SizeFilter {
public:
    SizeFilter(double upperBound, double lowerBound) {}
    bool operator() (Node* node) const {}
};
```
* Example usage of `filterNode()` with `SizeFilter`:  
```
filterNode(my_favorite_folder, SizeFilter(80, 50));
return the nodes that size in range of 80 >= && 50 <=, but don't include my_favorite_folder itself.
```

## **File structure:**  
```
├── bin
│   └── ut_main
├── src
│   ├── node.h
│   ├── node.cpp
│   ├── app.h
│   ├── folder.h
│   ├── iterator.h
│   ├── null_iterator.h
│   ├── node_iterator.h
│   └── utility.h
├── test
│   ├── ut_main.cpp
│   ├── ut_app.h
│   ├── ut_folder.h
│   ├── ut_iterator.h
│   └── ut_utility.h
└── makefile
```