#ifndef NODE_PARSER_H
#define NODE_PARSER_H
#include "../src/node_scanner.h"
#include "../src/node_builder.h"
class NodeParser {
public:
    NodeParser(std::string input):_input(input) {}
    void parser() {
            NodeScanner scanner(_input);
            while(true){        
                string judgment1,judgment2;        
                try {
                    judgment1 = scanner.nextToken();                   
                }catch(std::string e) {
                  break;
                }
                if(judgment1=="}"){
                    nb.buildFolderEnd();
                }
                try {
                    judgment2 = scanner.nextToken();                    
                }catch(std::string e) {
                  break;
                }
                if(judgment2=="}"){
                    nb.buildFolderEnd();
                }
                if(judgment1==","){
                    judgment1=judgment2;
                    judgment2=scanner.nextToken();
                }
                if(judgment2=="("){
                    size=strTodouble(scanner.nextToken());
                    nb.buildApp(judgment1,size);
                    scanner.nextToken();     
                }
                else if(judgment2=="{"){
                    nb.buildFolderBegin(judgment1);
                }
            }
    }
    std::deque<Node*> getResult() {
        return nb.getResult();
    }
    double strTodouble(string strVal){
      double val;
      istringstream is(strVal);
      is>>val;
      return val;
    }

private:
    string _input,id,name;
    NodeBuilder nb ;
    double size;
};

#endif
