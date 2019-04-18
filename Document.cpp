#include "Document.h"

Document::Document() : lines{} {
    current_line_iterator = lines.begin();
}