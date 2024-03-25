#include "tinyxml2.h"
#include <iostream>
#include <regex>
#include <string>

using namespace tinyxml2;
using namespace std;

void test() {
    XMLDocument doc;
    doc.LoadFile("coolshell.xml");
    if (doc.ErrorID()) {
        cerr << "LoadFile erro " << endl;
        return;
    }
    XMLElement *itemNode = doc.FirstChildElement("rss")
                               ->FirstChildElement("channel")
                               ->FirstChildElement("item");
    while (itemNode) {

        string title = itemNode->FirstChildElement("title")->GetText();
        cout << "title ok " << title << endl;
        string link = itemNode->FirstChildElement("link")->GetText();
        cout << "link ok " << link << endl;

        regex rg("<[^>]*>");
        string content =
            itemNode->FirstChildElement("content:encoded")->GetText();
        content = regex_replace(content, rg, "");
        cout << "content ok " << content << endl;
        string description =
            itemNode->FirstChildElement("description")->GetText();
        // cout << "description ok " << description << endl;
        description = regex_replace(description, rg, "");
        cout << "description ok " << description << endl;

        itemNode = itemNode->NextSiblingElement("item");
    }
}

int main() {
    test();
    return 0;
}
