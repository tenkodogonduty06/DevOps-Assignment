#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <xml file>" << endl;
        return 1;
    }

    XMLDocument doc;

    // Load file from command line
    if (doc.LoadFile(argv[1]) != XML_SUCCESS) {
        cout << "Failed to load XML file." << endl;
        return 1;
    }

    // Get <catalog>
    XMLElement* catalog = doc.FirstChildElement("catalog");

    // Loop through all <book> elements
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