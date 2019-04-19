#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    vector<string> lines;
    vector<string>::iterator it = lines.begin();
    int index = 0;

    lines.insert(lines.begin() + index, "Hello");
    for(auto it = lines.begin(); it != lines.end(); it ++) {
        cout << *it << endl;
    }
    index ++;
    lines.insert(lines.begin() + index, "Hello 2");
    for(auto it = lines.begin(); it != lines.end(); it ++) {
        cout << *it << endl;
    }
}