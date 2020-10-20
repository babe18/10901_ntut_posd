#ifndef TERMINAL_H
#define TERMINAL_H
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/ellipse.h"
#include "../src/shape.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/sort.h"
#include <string>
#include <regex>
#include <sstream>
#include <vector>

// std::string const regString = "^((Rectangle +\\( *\\-?[0-9]+\\.?[0-9]? *\\, *\\-?[0-9]+\\.?[0-9]? *\\) +)|(Ellipse +\\( *\\-?[0-9]+\\.?[0-9]? *\\, *\\-?[0-9]+\\.?[0-9]? *\\) +)|(Triangle +\\((\\[\\-?[0-9] *\\, *\\-?[0-9]\\] *\\,? *)*\\) +))+((area)|(perimeter)) +((inc)|(dec))";
std::string const regString = "^((Rectangle +\\(.*\\) +)|(Ellipse +\\(.*\\) +)|(Triangle +\\(.*\\) +))+((area)|(perimeter)) +((inc)|(dec))";
std::string const regRectangle = "Rectangle +\\( *\\-?[0-9]+\\.?[0-9]? *\\, *\\-?[0-9]+\\.?[0-9]? *\\) +";
std::string const regEllipse = "Ellipse +\\( *\\-?[0-9]+\\.?[0-9]? *\\, *\\-?[0-9]+\\.?[0-9]? *\\) +";
std::string const regTriangle = "Triangle +\\((\\[\\-?[0-9] *\\, *\\-?[0-9]\\] *\\,? *){3}\\) +";

class Terminal {
public:
    Terminal(std::string input): _input(input){
        if (checkInput(input)) {
            createShapes(_input);
            assignSortTargetAndSortWay(_input);
            if (_shapes.size() > 0)
                return;
        }
        throw std::string("invalid input");
    }

    std::string showResult() {
        std::stringstream ss;
        if (_sortWay == "inc")
            quickSort(_shapes.begin(), _shapes.end(), AscendingCompare(_sortFeature));
        else if (_sortWay == "dec")
            quickSort(_shapes.begin(), _shapes.end(), DescendingCompare(_sortFeature));
        for (auto shape: _shapes) {
            char buffer[50];
            if (_sortFeature == "area")
                sprintf(buffer, "%.3f", shape->area());
            else if (_sortFeature == "perimeter")
                sprintf(buffer, "%.3f", shape->perimeter());
            std::string str(buffer);
            ss << str;
            if (shape != _shapes.back()) {
                ss << "\n";
            }                
        }
        return ss.str();
    }

    std::string getSortTarget() {
        return _sortFeature;
    }

    std::string getSortWay() {
        return _sortWay;
    }

    ~Terminal() {
        for (auto p: _shapes)
            delete p;
        _shapes.clear();
    }
private:
    std::string const _input;
    std::string _sortFeature;
    std::string _sortWay;
    std::vector<Shape *> _shapes;

    bool checkInput(std::string input) {
        std::regex reg(regString);
        return std::regex_match(input, reg);
    }

    void assignSortTargetAndSortWay(std::string input) {
        std::smatch sm;
        std::regex_search(input, sm, std::regex("((area)|(perimeter))"));
        _sortFeature = sm[0].str();
        std::regex_search(input, sm, std::regex("((dec)|(inc))"));
        _sortWay = sm[0].str();
    }

    void createShapes(std::string input) {
        std::smatch sm;
        std::string temp = input;
        while(std::regex_search(temp, sm, std::regex(regRectangle))) {
            createRectangle(std::regex_replace(sm[0].str(), std::regex(" +"), ""));
            temp = sm.suffix().str();
        }
        temp = input;
        while(std::regex_search(temp, sm, std::regex(regEllipse))) {
            createEllipse(std::regex_replace(sm[0].str(), std::regex(" +"), ""));
            temp = sm.suffix().str();
        }
        temp = input;
        while(std::regex_search(temp, sm, std::regex(regTriangle))) {
            createTriangle(std::regex_replace(sm[0].str(), std::regex(" +"), ""));
            temp = sm.suffix().str();
        }
    }

    void createRectangle(std::string partString) {
        std::vector<std::string> fields = handleString(partString, "Rectangle");
        try
        {
            _shapes.push_back(new Rectangle(std::stod(fields[0]), std::stod(fields[1])));
        }
        catch(std::string e) {}
        fields.clear();
    }

    void createEllipse(std::string partString) {
        std::vector<std::string> fields = handleString(partString, "Ellipse");
        try
        {
            _shapes.push_back(new Ellipse(std::stod(fields[0]), std::stod(fields[1])));
        }
        catch(std::string e) {}
        fields.clear();
    }

    void createTriangle(std::string partString) {
        std::vector<std::string> fields;
        try
        {
            fields = handleTriangleString(partString);
            std::vector<TwoDimensionalCoordinate *> pointers;
            pointers.push_back(new TwoDimensionalCoordinate(std::stod(fields[0]), std::stod(fields[1])));
            pointers.push_back(new TwoDimensionalCoordinate(std::stod(fields[2]), std::stod(fields[3])));
            pointers.push_back(new TwoDimensionalCoordinate(std::stod(fields[4]), std::stod(fields[5])));
            _shapes.push_back(new Triangle(pointers));
        }
        catch(std::string e) {}
        fields.clear();
    }

    std::vector<std::string> handleString(std::string partString, std::string shapeName) {
        partString = std::regex_replace(partString, std::regex("["+shapeName+"\\(\\)]"), "");
        char * char_array = new char[partString.length() + 1];
        std::strcpy(char_array, partString.c_str());
        std::vector<std::string> fields;
        char * pch;
        pch = std::strtok(char_array, ",");
        while (pch != NULL)
        {
            fields.push_back(pch);
            pch = std::strtok(NULL, ",");
        }
        delete [] char_array;
        return fields;
    }

    std::vector<std::string> handleTriangleString(std::string partString) {
        partString = std::regex_replace(partString, std::regex("[Triangle\\(\\)]"), "");
        partString = std::regex_replace(partString, std::regex("\\],\\["), "_");
        partString = std::regex_replace(partString, std::regex("[\\[\\]]"), "");
        char * char_array = new char[partString.length() + 1];
        std::strcpy(char_array, partString.c_str());
        std::vector<std::string> fields, temp;
        char * pch;
        pch = std::strtok(char_array, "_");
        while (pch != NULL)
        {
            temp.push_back(pch);
            pch = std::strtok(NULL, "_");
        }
        
        for (auto t: temp) {
            delete [] char_array;
            char_array = new char[t.length() + 1];
            std::strcpy(char_array, t.c_str());
            pch = std::strtok(char_array, ",");
            while (pch != NULL)
            {
                fields.push_back(pch);
                pch = std::strtok(NULL, ",");
            }
        }
        delete [] char_array;
        return fields;
    }
};
#endif
