# **Pattern Oriented Software Design 2020 Fall Midterm 2**  

## **Notice**  
* **Exam time: 18:00 ~ 22:00, 2020/12/09**  
* **The reopsitory to upload test is same as assignment.**  
* **If you use any website other than [Resources Allowed To Use](#resources-allowed-to-use), you'll get no point for this test.**  
* **If you access others' ssl-gitlab, you'll get no point for the test.**  
* **If you use your phone during the test, you'll get no point for the test.**  
* **If your code fails to compile on jenkins server, you'll get no point for the test.**  
* **We provide [SAMPLE UT TEST](test) and [MAKEFILE](makefile), the logic of sample unit tests are same as those on the Jenkins TA use to test your program but with some data differences. The makefile is exactly same as TA's.**  

## **Score**  
* TA Unit Test On Jenkins: 100%  
* Each TA Unit Test is allocated 2 to 5 points according to its difficulty level  
* Points will be deducted if you change given interface (for example, removing ```const```.)  

## **Resources Allowed To Use**  
[cplusplus](http://www.cplusplus.com/)  
[Cambridge Dictionary](https://dictionary.cambridge.org/)  
[Jenkins](https://ssl-jenkins.csie.ntut.edu.tw/)  
[GitLab](https://ssl-gitlab.csie.ntut.edu.tw/)  

## **Problems**
Write a program to simulate organizing apps and folders on your Home Screen:  

Write few funtions based on program to simulate organizing apps and folders that you written on midterm 1.  

* Find app/folder.  
* Build app/folder by input.  

## **Requirement**  
1. Add function `addNodes()` and `accept()` on `Node`.  
```
class Node{
public:
    virtual void addNodes(std::list<Node*> nodes);
    // App: throw std::string "only folder can add nodes.".
    // Folder: add nodes into folder and update the path of the nodes.

    virtual void accept(Visitor* visitor) = 0;
}
```

2. Add class `Visitor` in `visitor.h`.  
```
class Visitor {
public:
    virtual void visitApp(App* app) = 0;
    virtual void visitFolder(Folder* folder) = 0;
};
```
3. Add class `FindVisitor` in `find_visitor.h`.  
```
class FindVisitor : public Visitor {
public:
    FindVisitor(std::string name) {}
    
    void visitApp(App* app) {
        // find app when app's name matches given name,
        // add app's route as result.
    }
    
    void visitFolder(Folder* folder) {
        // find folder when folder's name matches given name,
        // add folder's route as result.
        // And find the tree structure bellow,
        // add the other match result with `\n`.
    }
    
    std::string getResult() const {
        // return result.
    }
}
```
4. Add class `NodeScanner` in `node_scanner.h`.  
```
class NodeScanner {
public:
    NodeScanner(std::string input) {}
    std::string nextToken() {
        // return next token.
        // throw exception std::string "next token doesn't exist." if next token not found.
    }

    // you can add other public functions if you needed.
}
```
* Purpose of the scanner is to scan through the input and able to send out each token by nextToken().  
* There for nextToken() should only return `Node_Name`, `Node_Size`, `{`, `}`, `(`, `)`, `,` and ignore the remaining.  
* `Node_Name` should only build up with a~z, A~Z.   
* `Node_Size` is always a vaild double.  
* For input of `App` it should be in form of `Node_Name (Node_Size)`. ex. gmail (21.45)  
* For input of `Folder` it should be in form of `Node_Name {}`. ex. favorite {} 
* Each `Node` should be separate with `,`  
* Ignore the token which is illegal. 
* Example:  
```
    facebook #(%30.32!@) => facebook (30.32)
    ~!@favorite {^chrome(50.15)%, $facebook(*30.32)}# => favorite {chrome(50.15), facebook(30.32)}
``` 

5. Add class `NodeBuilder` in `node_builder.h`.  
```
class NodeBuilder {
public:
    void buildApp(std::string name, double size) {
        // build a app with an unique id and push in a std::stack.
    }
    
    void buildFolderBegin(std::string name) {
        // notify begin of folder.
    }
    
    void buildFolderEnd() {
        // notify end of folder.
    }

    std::deque<Node*> getResult() {
        // return result.
    }
}
```
6. Add class `NodeParser` in `node_parser.h`.  
```
class NodeParser {
public:
    NodeParser(std::string input) {
        // initialize a scanner for handling input.
        // initialize a node builder for handling building node.
    }
    
    void parser() {
        // using NodeScanner::nextToken() to get all information to determine what to build,
        // and provide the argument the node needed.
        // use functions in NodeBuilder to build out the node.
        // the node with invalid argument should be ignored.
    }
    
    std::deque<Node*> getResult() {
        // return result.
    }
}
```
* Ignore the node with invalid argument.  
* Example:  
```
    chrome (50.15, 51.05), facebook (), instagram (20.21) => build instagram (20.21) only.
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
│   ├── utility.h
│   ├── visitor.h
│   ├── find_visitor.h
│   ├── node_scanner.h
│   ├── node_builder.h
│   └── node_parser.h
├── test
│   ├── ut_main.cpp
│   ├── ut_app.h
│   ├── ut_folder.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   ├── ut_visitor.h
│   ├── ut_node_scanner.h
│   ├── ut_node_builder.h
│   └── ut_node_parser.h
└── makefile
```