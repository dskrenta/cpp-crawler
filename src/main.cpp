// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// main.h

// #include "cpr/cpr.h"
#include "Crawler.h"

using namespace std;

int main() {
    // auto response = cpr::Get(cpr::Url{"http://example.com"});
    // cout << response.text << endl;
    unordered_set <string> roots;
    roots.insert("en.wikipedia.com");
    roots.insert("news.google.com");

    Crawler crawler(roots, "", "", "../data", 50, 2);
}
