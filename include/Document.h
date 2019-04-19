#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <vector>
#include <string>

using namespace std;
class Document {
private:
    vector<string> lines;
    vector<string>::iterator current_line_iterator;
public:
    Document();
};
#endif