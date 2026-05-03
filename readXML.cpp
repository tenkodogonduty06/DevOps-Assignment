#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

int main(int argc, char* argv[]) {

    int test;
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <xml file>" << endl;
        return 1;
    }

    XMLDocument doc;

    if (doc.LoadFile(argv[1]) != XML_SUCCESS) {
        cout << "Failed to load XML file." << endl;
        return 1;
    }

    XMLElement* catalog = doc.FirstChildElement("catalog");

    for (XMLElement* book = catalog->FirstChildElement("book");
        book != nullptr;
        book = book->NextSiblingElement("book")) {

        // Get the <title> inside each <book>
        XMLElement* title = book->FirstChildElement("title");

        if (title && title->GetText()) {
            cout << title->GetText() << endl;
        }
    }

    return 0;
}
