// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// main.h

#include <iostream>
#include "Crawler.h"

using namespace std;

int main() {
    unordered_set <string> roots;
    roots.insert("http://harvix.com");
    roots.insert("http://9gag.com");

    Crawler crawler(roots, "", "", "data", 50, 4);
}
