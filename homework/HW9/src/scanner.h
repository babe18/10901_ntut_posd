#ifndef SCANNER_H
#define SCANNER_H
#include <cctype>
#include <string>
#include <deque>

class Scanner {
public:
    Scanner(std::string input) {
      buffer = input;
      couter = 0;
    }
    std::string nextToken() {
      while (couter < buffer.length() && isspace(buffer[couter])) {
          couter++;
      }
      if (couter >= buffer.length()) {
        throw std::string("next char doesn't exist.");
      } 
      else if (isalnum(buffer[couter]) || buffer[couter]=='-') {
        int start = couter;
        while (couter < buffer.length() && isalnum(buffer[couter]) || buffer[couter]=='.' || buffer[couter]=='-') {
          couter++;
        }
        return buffer.substr(start, couter - start);
      } 
      else {
        return std::string(1,buffer[couter++]);
      }
    }

private:
    std::string buffer;
    int couter;
};

#endif
