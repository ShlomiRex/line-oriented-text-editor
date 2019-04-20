/* Shlomi Domnenko 318643640 */

#ifndef EDITOR_H
#define EDITOR_H
#include "Document.h"
#include <iostream>

class Editor {
private:
    Document doc;
public:
    Editor();
    void loop();
};
#endif