#ifndef SCANNER_H
#define SCANNER_H
#include <string>

class Scanner{
public:
    Scanner(std::string input) : _input(input) {

    }
    // ~Scanner();

    std::string next() {
        std::string result = "";
        skipWhiteSpace();
        for(auto token: tokenList) {
            if(_input.compare(pos, token.length(), token) == 0) {
                pos = pos + token.length();
                result = token;
            }
        }

        return result;
    }

    void skipWhiteSpace() {
        
        while(_input[pos] == ' ' || _input[pos] == '\n') {
            pos++;
        }
    }

    double nextDouble() {
        std::string s = "";
        skipWhiteSpace();
        while(1){
            if((_input[pos] <= '9' && _input[pos] >= '0') || _input[pos] == '.') {
                s = s + _input[pos];
                pos++;
            }
            else{
                break;
            }
        }

        return std::stod(s);
    }

    bool isDone(){
        skipWhiteSpace();
        return pos == _input.length();
    }

private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::string mixedshape = "mixed";
    const std::vector<std::string> tokenList = {"mixed", "{", "rect", "}", "tri"};
    
};

#endif