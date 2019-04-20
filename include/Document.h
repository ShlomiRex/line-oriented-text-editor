#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Document {
private:
    vector<string> lines;
    //vector<string>::iterator cur_line;
    size_t line_num; //Starts at 1 (0 means invalid line number)
    size_t max_line_num;

    void prefixPrint(string prefix); //Prints current line with prefix, checks validity
public:
    Document();
    void print(); //Prints current line
    void tabPrint(); //Prints current line with tab
    void printAll(); //Prints all lines
    void append(); //Append text to document
    void insert(); //Insert text before document
    void change(); //Change current line 
    void quit(); //Quit program
    void deleteCur(); //Delete current line

    void changeLine(int num); //Changed current line to a given line
};
#endif