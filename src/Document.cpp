#include "Document.h"

Document::Document() : lines{}  {
    line_num = 0;
    max_line_num = 0;
}

void Document::prefixPrint(string prefix) {
    if(line_num > 0) {
        cout << prefix << *(lines.begin() + line_num - 1) << endl;
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
    for(auto it = lines.begin(); it != lines.end(); ++it) {
        cout << *it << endl;
    }
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
    line_num--;
    string str;
    //Wait untill get '.' to finish appending
    while(1) {
        getline(cin, str);
        if(str == "." ) {
            break;
        }
        lines.insert(lines.begin() + line_num, str);
        line_num ++;
        max_line_num++;        
    }
}

//Change current line 
void Document::change() {
    if(line_num > 0) {
        string str;
        getline(cin, str);
        lines.at(line_num - 1) = str;
    } else {
        cout << "?" << endl;
    }
}

//Quit program
void Document::quit() {
    //Memory cleanup
    
    //Nothing to clean
}

//Delete current line
void Document::deleteCur() {
    if(line_num > 0) {
        lines.erase(lines.begin() + line_num - 1);
        line_num--;
        max_line_num--;
    } else {
        cout << "?" << endl;
    }
}

void Document::search(string str) {
    size_t tmp_cur_line = line_num;

    //Search from current line to end
    for(auto it = lines.begin() + line_num - 1; it != lines.end(); ++it, ++tmp_cur_line) {
        size_t res = it->find(str);
        if(res == string::npos) {
            //Not found
            continue;
        } else {
            line_num = tmp_cur_line;
            cout << *it << endl;
            break;
        }
    }

    tmp_cur_line = 1;
    //Search from start to current line
    for(auto it = lines.begin(); it != lines.begin() + line_num - 1; ++it, ++tmp_cur_line) {
        size_t res = it->find(str);
        if(res == string::npos) {
            //Not found
            continue;
        } else {
            line_num = tmp_cur_line;
            cout << *it << endl;
            break;
        }
    }


}

void Document::changeLine(int num) {
    if(num > 0 && num < max_line_num) {
        line_num = num;
        print();
    }
    else
        cout << "?" << endl;
}