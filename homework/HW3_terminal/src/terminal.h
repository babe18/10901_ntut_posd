#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>     // std::cout
#include "triangle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "sort.h"
#include "shape.h"
#include <sstream>      //istringstream
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <regex>
using namespace std;
class Terminal
{
public:
    Terminal(string instruction): _instruction(instruction){
      std::vector<string>* _strVec=new vector<string>(0);
      if(!isIncompelet(instruction)){
        //test = new Terminal("Rectangle (3,7) Ellipse (2,2) perimeter inc")把指令切割
        _strVec=split(instruction,')');
        string *m;
        std::vector<string>::iterator it;
         it=_strVec->begin();
         it=rmSpace(it,_strVec);
         it=checkFormat(it,_strVec);
         checkMode(_strVec);
        _shapeVec = analysis(it,_strVec);
        _shapeVec = sortShape(_shapeVec,getFeatur(_mode[1]),getOrder(_mode[2]));
      }
      else throw string("invalid input");
    }
    //正確是否有找到Feature&Order
    bool isIncompelet(string instruction){
        for(string s:_modeFeature){
          if(instruction.find(s) != std::string::npos){
            for(string s1:_modeOrder){
              if(instruction.find(s1) !=std::string::npos ){
                return false;
              }
            }
          }
        }
      return true;
    }
    string getOrder(int mode){
      if(_mode[2]==0) return NULL;
      return _modeOrder[_mode[2]-1];
    }
    string getFeatur(int mode){
      if(_mode[1]==0) return NULL;
      return _modeFeature[_mode[1]-1];
    }
    string getClassName(string str){
          std::smatch m;
          std::regex e ("\\(");
          std::regex_search ( str, m, e );
          return m.prefix().str();
    }
    // return result For example: [XXX, XXX, XXX],制定輸出格式
    string showResult(){
         if(_isThrow) throw string("invalid input");
         string result="";
         for (std::vector<Shape*>::iterator it = _shapeVec->begin() ; it != _shapeVec->end(); ++it){
           switch (_mode[1]) {
             case 1:
                if(((*it)->area())==0) break;
                else
                	b = round (((*it)->area()) * 1000) / 1000;
                  result+=(to_string(b)).erase(to_string(b).length()-3,to_string(b).length()-1);
                  break;
             case 2:
                if(((*it)->perimeter())==0) break;
                else
                  c = round (((*it)->perimeter()) * 1000) / 1000;
                  result+=(to_string(c)).erase(to_string(c).length()-3,to_string(c).length()-1);//只取字串的小數點後三位數
                  break;
           };
           if(*it != *(_shapeVec->end()-1) && ((*it)->perimeter() > 0 || (*it)->area() > 0)){
             result+="\n";
           }
         }
         return result;
    }
    //判斷order方式inc or dec
    std::vector<Shape*>* sortShape(std::vector<Shape*>* shapeVec,string featur,string order){
      if(order=="inc"){
        quickSort(shapeVec->begin(),shapeVec->end(),AscendingCompare(featur));
      }
      else if(order=="dec"){
        quickSort(shapeVec->begin(),shapeVec->end(),DescendingCompare(featur));
      }
      return shapeVec;
    }
    //判斷是什麼形狀Triangle or Ellipse or Rectangle
    std::vector<Shape*>* analysis(std::vector<string>::iterator it,std::vector<string>* vec){
      std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
      std::vector<Shape*>::iterator itShape=shapeVec->begin();
      shapeVec->clear();
        for(it=vec->begin();it!=vec->end()-1;it++){
            string className=getClassName(*it);
            std::vector<double> numVec=getParameter(*it);
            std::vector<double>::iterator itNum=numVec.begin();
            if(className=="Triangle "){
              Triangle *tp;
              try{
                _l1=sqrt(pow((*(itNum+2)-*itNum),2)+pow((*(itNum+3)-*(itNum+1)),2));
                _l2=sqrt(pow((*(itNum+4)-*(itNum+2)),2)+pow((*(itNum+5)-*(itNum+3)),2));
                _l3=sqrt(pow((*(itNum+4)-*itNum),2)+pow((*(itNum+5)-*(itNum+1)),2));
                if(!((_l1+_l2)>_l3 && (_l1+_l3)>_l2 && (_l3+_l2)>_l1)){
                    throw string ("invalid input");
                  }
                else{
                  TwoDimensionalCoordinate t1(*itNum,*(itNum+1));
                  TwoDimensionalCoordinate t2(*(itNum+2),*(itNum+3));
                  TwoDimensionalCoordinate t3(*(itNum+4),*(itNum+5));
                  std::vector<TwoDimensionalCoordinate*> triangleVector;
                  triangleVector.push_back(&t1);
                  triangleVector.push_back(&t2);
                  triangleVector.push_back(&t3);
                  tp=new Triangle(triangleVector);
                  }
                }
                catch(std::string *caught){
                  continue;
                }
                shapeVec->push_back(tp);
            }
            else if(className=="Ellipse "){
              shapeVec->push_back(new Ellipse(*itNum,*(itNum+1)));
            }
            else if(className=="Rectangle "){
              shapeVec->push_back(new Rectangle(*itNum,*(itNum+1)));
            }
        }
        if (shapeVec->empty()){
          throw string("invalid input");
        }
        return shapeVec;
    }
    //讀取參數 回傳std::vector<double>
    std::vector<double> getParameter(string str){
      vector<double> number(0);
      int i;
      string stemp="";
      for(i=str.find('(')+1;i<str.size();i++){
        if( ((str[i]==',') && (str[i-1]!=']')  && (str[i+1]!='[')) || ((str[i]==',') && (str[i-1]==']')  && (str[i+1]=='['))  || (str[i]==')')){
          number.push_back(strToInt(stemp));
          stemp="";
        }
        else if((str[i]=='[') || (str[i]==']'))
             stemp+="";
        else stemp+=str[i];
      }
      return number;
    }
    //remove additional space
    std::vector<string>::iterator rmSpace(std::vector<string>::iterator it,std::vector<string>* vec){
      string temp="";
      _Throw=false;
        for(it=vec->begin();it!=vec->end()-1;it++){
          for(char c:(*it)){
            if(c==' ' && _Throw==false){
              temp+=" ";
              _Throw=true;
            }
            else if (c==' '&& _Throw!=false){
            continue ;
            }
            else if (c=='R' ||c=='T' ||c=='E'){
               temp+=c;
              _Throw=false;
            }
            else temp+=c;
        }
        *it=temp;
        temp="";
    }
    return it=vec->begin();
  }
    std::vector<string>::iterator checkFormat(std::vector<string>::iterator it,std::vector<string>* vec){
      bool run=false;
      for(it=vec->begin();it!=vec->end()-1;){
        for(int i=0;i<3;i++){
            regex pattern(_format[i]);
            if(regex_match(*it, pattern)){
                run=true;
                break;
            }
        }
        if(run){
          run=false;
          it++;
        }else{
          it=vec->erase(it);
        }
      }
      return it=vec->begin();
    }
    //利用delimiter切割字串
    std::vector<string>* split(string instruction,char delimiter){
      std::vector<string>* strVec=new vector<string>(0);
      string str;
      strVec->clear();
      while(_index < instruction.length()){
        while(instruction[_index] != delimiter && _index < instruction.length()){
          str+=instruction[_index++];
        }
        str+=instruction[_index++];
        strVec->push_back(str);
        str="";
        }
      return strVec;
    }
    double strToInt(string strVal){
      double val;
      istringstream is(strVal);
      is>>val;
      return val;
    }
    void checkMode(std::vector<string>* vec){
        std::vector<string>::iterator it=vec->end()-1;
        int i=0;
        //判斷Feature
        for(i=0;i<3;i++){
          regex pattern(_modeFeature[i]);
          if(regex_search(*it,pattern)){
            _mode[1]=i+1;
            break;
          }
        }
        //判斷Order
        for(i=0;i<2;i++){
          regex pattern(_modeOrder[i]);
          if(regex_search(*it,pattern)){
            _mode[2]=i+1;
            break;
          }
        }
         if(i==2){
         _isThrow=true;
         }
    }
private:
    std::vector<Shape*>* _shapeVec;
    string _instruction;
    int _index=0;
    int _count=0;
    double _l1=0,_l2=0,_l3=0,b=0,c=0;
    int _mode[3]={0};//_mode[0]=count,_mode[1]= 0:error     mode[2]= 0:error
                                            // 1:area               1:ascending
                                            // 2:perimeter          2:descending
    bool _Throw=false;
    bool _isThrow=false;
    string _modeFeature[2]={"area","perimeter"};
    string _modeOrder[2]={"inc","dec"};
    string _shapeName[3]={"^Triangle $","^Rectangle $","^Ellipse $"};
    string _format[3]={"^(Triangle )(\\(\\[\\-?[0-9]{1,}+(\\.\\d{1,})?,-?[0-9]{1,}+(\\.\\d{1,})?\\]\\,\\[\\-?[0-9]{1,}+(\\.\\d{1,})?,-?[0-9]{1,}+(\\.\\d{1,})?\\]\\,\\[\\-?[0-9]{1,}+(\\.\\d{1,})?,-?[0-9]{1,}+(\\.\\d{1,})?\\]\\))$",
                        "^(Rectangle )(\\(\\+?[1-9]{1,}+(\\.\\d{1,})?,\\+?[1-9]{1,}+(\\.\\d{1,})?\\))$",
                        "^(Ellipse )(\\(\\+?[1-9]{1,}+(\\.\\d{1,})?,\\+?[1-9]{1,}+(\\.\\d{1,})?\\))$"};
};
#endif
