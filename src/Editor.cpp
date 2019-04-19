#include "Editor.h"
using namespace std;



Editor::Editor() {
    this->doc = Document{};
}

void Editor::loop() {
    string str;
    while(1) {
        getline(cin, str);
        
        if(str == "") 
            continue;
        cout << "INPUT: " << str << endl;

        if(str == "p") {
            doc.print();
        } else if(str == "n") {
            doc.tabPrint();
        } else if(str == "%p") {
            doc.printAll();
        } else if(str == "a") {
            doc.append();
        } else if(str == "i") {
            doc.insert();
        } else if(str == "c") {
            doc.change();
        } else if(str == "d") {
            doc.deleteCur();
        } else if(str == "/text") {
            //Search text
        } else if(str == "Q") {
            //Quit
            doc.quit();
        } else if(str[0] == 's') {
            //s/old/new
        } else {
            //Check number
            //Try parsing str to int
            try {
                int num = std::stoi( str );
                cout << "ASD" << endl;
            } catch(std::invalid_argument) {
                cout << "?" << endl;
            }
        }
        str = "";
    }
    
}