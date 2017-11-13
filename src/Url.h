// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Url.h

#ifndef URL_H
#define URL_H

#include <iostream>

using namespace std;

class Url {
    public:
        Url(string);
        ~Url();

        string getUrl();
        void setUrl(string);

        static bool isValidUrl();

    private:
        url string;
};
#endif // URL_H
