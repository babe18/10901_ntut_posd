#ifndef SHAPE_PARSER_H
#define SHAPE_PARSER_H
#include "../src/scanner.h"
#include "../src/shape_builder.h"
class ShapeParser {
public:
    ShapeParser(std::string input):_input(input) {}
    void parser() {
            Scanner scanner(_input);
            while(true){        
                string judgment;        
                try {
                    judgment = scanner.nextToken();
                }catch(std::string e) {
                    if(e=="next char doesn't exist.")  break;
                }
                if(judgment=="Rectangle"){
                    std::vector<std::string> parameter;
                    judgment=scanner.nextToken();
                    while(judgment!=")"){
                      if(judgment!="(" && judgment!="," ) parameter.push_back(judgment);
                      judgment=scanner.nextToken();
                    }
                    if(parameter.size()==2) sb.buildRectangle(stod(parameter.at(0)),stod(parameter.at(1)));
                  
                }
                else if(judgment=="Ellipse"){
                    std::vector<std::string> parameter;
                    judgment = scanner.nextToken();
                    while(judgment!=")"){
                      if(judgment!="(" && judgment!="," ) parameter.push_back(judgment);
                      judgment=scanner.nextToken();
                    }
                    if(parameter.size()==2)  sb.buildEllipse(stod(parameter.at(0)),stod(parameter.at(1)));
                   
                }
                else if(judgment=="Triangle"){
                    std::vector<std::string> parameter;
                    judgment= scanner.nextToken();
                    while(judgment != ")"){
                      if(judgment != "(" && judgment != "," && judgment != "[" && judgment != "]") parameter.push_back(judgment);
                      judgment = scanner.nextToken();
                    }
                    if(parameter.size() == 6){
                    sb.buildTriangle(stod(parameter.at(0)),stod(parameter.at(1)),stod(parameter.at(2)),stod(parameter.at(3)),stod(parameter.at(4)),stod(parameter.at(5)));
                    }
                }
                else if(judgment == "CompoundShape"){
                    sb.buildCompoundShapeBegin();
                }
                else if(judgment == "}"){
                    sb.buildCompoundShapeEnd();
                }
            }
    }
    std::deque<Shape*> getResult() {
        return sb.getResult();
    }


private:
    string _input;
    ShapeBuilder sb ;
};

#endif
