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
        max_line_num++;
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

        //get '.'
        getline(cin, str);
        if(str != ".") {
            cout << "You must end 'c' command with '.'" << endl;
        }
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
            return;
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
            return;
        }
    }


}

void Document::changeLine(int num) {
    //cout << "Changing line from " << line_num << " to " << num << " max line = " << max_line_num << endl;
    if(num > 0 && num <= max_line_num) {
        line_num = num;
        print();
    }
    else
        cout << "?" << endl;
}

void Document::replace(string old, string _new) {
    string current_line = lines.at(line_num - 1);
    size_t index_old = current_line.find(old);
    if(index_old != string::npos) {
        size_t line_size = current_line.size();
        size_t old_size = old.size();
        size_t new_size = _new.size();

        string line_before_old = current_line.substr(0, index_old);
        string line_after_old = current_line.substr(index_old + old_size);
        
        string new_current_line = line_before_old + _new + line_after_old;
        lines[line_num - 1] = new_current_line;

        /*
        cout << "OLD=" << old << endl;
        cout << "NEW=" << _new << endl;
        cout << "OLD INDEX=" << index_old << endl;
        cout << "LINE BEFORE OLD=" << line_before_old << endl;
        cout << "LINE AFTER OLD=" << line_after_old << endl;
        */
    } else {
        //Old string not found
        //What to do?..
    }
}
