#include "Document.h"

Document::Document() : lines{}  {
    line_num = 0;
    max_line_num = 0;
}

void Document::prefixPrint(string prefix) {
    if(line_num > 0) {
        cout << prefix << *(lines.begin() + line_num) << endl;
    } else {
        cout << "?" << endl;
    }
}

 //Prints current line
void Document::print() {
    prefixPrint("");
}

//Prints current line with tab
void Document::tabPrint() {
    ostringstream oss;
    oss << line_num << "\t";
    string prefix = oss.str();
    prefixPrint(prefix);
}

//Prints all lines
void Document::printAll() {

}

//Append text to document
void Document::append() {
    string str;
    //Wait untill get '.' to finish appending
    while(1) {
        getline(cin, str);
        if(str == "." ) {
            break;
        }
        lines.insert(lines.begin() + line_num, str);
        line_num ++;
        if(line_num > max_line_num) {
            max_line_num = line_num;
        }
    }
}

//Insert text before document
void Document::insert() {

}

//Change current line 
void Document::change() {

}

//Quit program
void Document::quit() {

}

//Delete current line
void Document::deleteCur() {

}