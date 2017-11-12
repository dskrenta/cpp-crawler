// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.h

#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/*
    vector roots
    read whitelist file and populate whitelist set
    read blacklist file and populate blacklist set
    set dest dir

    set up crawl threads here in another class (init)
*/

class Crawler {
    public:
        Crawler(
            vector <string> roots,
            const string &hostWhitelistFilename = "",
            const string &hostBlacklistFilename = "",
            const string &destDir = "../data"
        );
        ~Crawler();

    private:
        static bool isValidURL(string &url);

        unordered_set <string> hostWhitelist;
        unordered_set <string> hostBlacklist;
        unordered_set <string> seenUrls;
        queue <string> crawlQueue;
};
#endif // CRAWLER_H
