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
        //cout << "INPUT: " << str << endl;

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
        } else if(str == "Q") {
            //Quit
            doc.quit();
            return; //Exit gracefully
        } else {
            //Check number
            //Try parsing str to int
            try {
                int num = std::stoi( str );
                doc.changeLine(num);
            } catch(std::invalid_argument) {
                //Check '/'

                if(str.size() > 0) {
                    if(str.at(0) == '/') {
                        //Searches string
                        string text_to_search = str.substr(1);
                        
                        doc.search(text_to_search);
                    } else if(str.at(0) == 's' && str.size() > 2) {
                        //Replace string
                        size_t slash_index = str.find("/", 2);
                        if(slash_index != string::npos) {
                            string _old;
                            //Get _old string (between 2 slashes)
                            for(int i = 2; i < slash_index; i++) {
                                _old += str[i];
                            }

                            //s/OLD/NEW (without slash at the end)
                            string _new = str.substr(slash_index+1);

                            //Check if s/OLD/NEW/
                            if(str[str.size()-1] == '/') {
                                _new = _new.substr(0, _new.size()-1);
                            }

                            //cout << "SLASH INDEX = " << slash_index << "\nOLD = " << _old << "\nNEW = " << _new << endl;
                            doc.replace(_old, _new);
                        } else {
                            cout << "?" << endl;
                        }
                    } else {
                        cout << "?" << endl;
                    }
                } else {
                    cout << "?" << endl;
                }
            }
        }
        str = "";
    }
    
}