// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.cpp

#include "Crawler.h"

Crawler::Crawler(
    unordered_set <string> roots,
    const string &hostWhitelistFilename = "",
    const string &hostBlacklistFilename = "",
    const string &destDir = "../data",
    const int numPagesToCrawl = 50,
    const int concurrencyLimit = 2
) {
    readFileToSet(hostWhitelistFilename, hostWhitelist);
    readFileToSet(hostBlacklistFilename, hostBlacklist);
    if (numPagesCrawled < numPagesToCrawl) {
        startCrawl();
    }
    endCrawl();
}

Crawler::~Crawler() {

}

void Crawler::readFileToSet(const string &filename, unordered_set <string> set) {
    if (filename.length() > 0) {
        ifstream file (filename);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                set.insert(line);
            }
            file.close();
        }
    }
}

void Crawler::startCrawl() {
    cout << "Start Crawl" << endl;
}

void Crawler::endCrawl() {
    cout << "End Crawl" << endl;
}
