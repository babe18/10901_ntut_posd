#ifndef NODE_SCANNER_H
#define NODE_SCANNER_H
#include <cctype>
#include <string>
#include <deque>
#include <vector>
class NodeScanner {
public:
    NodeScanner(std::string input) {
      buffer = input;
      buffer = rmSpace(buffer);
      result = normalization(buffer);
    }
    std::vector<string> normalization(std::string buffer){
      while(buffer.length() > couter){
        //isalnum
        if (isalnum(buffer[couter]) && !isdigit(buffer[couter])) {
          int start = couter;
          while (couter < buffer.length() && isalnum(buffer[couter]) ) {
            couter++;
          }
          english_parameter = buffer.substr(start, couter - start);
          english_result.push_back(english_parameter);
          couter=couter-1;
        }
        //is_symbol
        else if (buffer[couter] =='(') {
          while (buffer[couter] =='(') {
            symbol_size ++;
            couter++;
          }
          couter=couter-1;
        }
        //is_digit
        else if (isdigit(buffer[couter]) || buffer[couter]=='-') {
          int start = couter;
          while (couter < buffer.length() && isdigit(buffer[couter]) || buffer[couter]=='.' || buffer[couter]=='-') {
            couter++;
          }
          digit_parameter = buffer.substr(start, couter - start);
          digit_result.push_back(digit_parameter);
          couter=couter-1;
        }
        //folder 
        else if(english_result.size()==1 && buffer[couter] == '{'){
          result.push_back(english_result[0]);
          result.push_back("{");
          build_folder_size ++;
          english_result.clear();
        }
        else if(buffer[couter] == '}' && end_folder_size < build_folder_size){
          end_folder_size++;
          result.push_back("}");
        }
        //APP
        else if(english_result.size()==1 && buffer[couter] == ')'  && digit_result.size()==1 && symbol_size==1){
          result.push_back(english_result[0]);
          result.push_back("(");
          result.push_back(digit_result[0]);
          result.push_back(")");
        }
        //判斷comma
        else if((result[result.size()-1] == "}" || result[result.size()-1] == ")" )&& buffer[couter] == ',') {
            result.push_back(",");
        }
        if(buffer[couter] == ')'){
          symbol_size = 0;
          english_result.clear();
          digit_result.clear();
        }
        couter++;
      }
      return result;
    }
    //刪除不必要的東西
    std::string rmSpace(std::string buffer){
      int couter = 0;
      string str ;
      while(buffer.length() > couter){
        if(buffer[couter] =='{' || buffer[couter] =='}' || buffer[couter] ==','|| buffer[couter] =='(' || buffer[couter] ==')' || isalnum(buffer[couter]) || buffer[couter] =='-' || buffer[couter] =='.'){
          str+= buffer[couter];
        }
        couter++;
      }
      return str;
    }              

    std::string nextToken() {
      if (result.size()<=number) {
        throw std::string("next token doesn't exist.");
      } 
      string next_result = result[number];
      number++;
      return next_result;
    }

private:
    vector<string> digit_result,english_result,result;
    string english_parameter , digit_parameter , buffer;
    int couter = 0 , number = 0 , build_folder_size = 0 , end_folder_size = 0 , symbol_size = 0;
};

#endif
