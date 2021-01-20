#include "terminal.h"
#include <fstream>
#include <string.h>
using namespace std;
string readFile(string);
void writeFile(string,string);
int main(int argc, char *argv[]){
    string instruction;

    string input(argv[1]);
    string output(argv[2]);
    string featur(argv[3]);
    string order(argv[4]);

    string featurOrder=" ";
    featurOrder+=featur;
    featurOrder+=" ";
    featurOrder+=order;
    string fileName="./";
    fileName+=input;
    instruction=readFile(fileName);
    instruction+=featurOrder;
    Terminal terminal(instruction);

    string outputName("./");
    outputName+=output;
    writeFile(outputName,terminal.showResult());
}
string readFile(string path){
  std::string item_name;
  std::ifstream nameFileout;
  string str="";
  nameFileout.open(path);
  while (nameFileout >> item_name)
  {
      str+=item_name;
      str+=" ";
  }
  nameFileout.close();
  return str;
}

void writeFile(string path,string str){
  std::ofstream out(path);
  out << str;
  out.close();
}
