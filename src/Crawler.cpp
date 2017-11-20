// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.cpp

#include "Crawler.h"
#include "ThreadPool.h"

Crawler::Crawler(
    unordered_set <string> inputRoots,
    const string &hostWhitelistFilename = "",
    const string &hostBlacklistFilename = "",
    const string &destDir = "data",
    const int numPagesToCrawl = 50,
    const size_t concurrencyLimit = 2
) : pool(concurrencyLimit) {
    roots = inputRoots;
    dataDirectory = destDir;
    readFileToSet(hostWhitelistFilename, hostWhitelist);
    readFileToSet(hostBlacklistFilename, hostBlacklist);
    startCrawl();
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
    for (unordered_set <string>::iterator it = roots.begin(); it != roots.end(); it++) {
        pool.schedule([] {
            // cout << "hello" << endl;
            /*
            stringstream ss;
            size_t generatedHash = h(*it);
            ss << generatedHash;
            string filename = ss.str();
            string command = "curl " + *it + " -o " + dataDirectory + "/" + filename.c_str();
            system(command.c_str());
            */
        });
    }
}

/*
void Crawler::startCrawl() {
    // loop through roots
    // enqueue roots
    // register callback functions

    cout << "Start Crawl" << endl;
    string command = "curl http://harvix.com -o crawled.txt";
    system(command.c_str());
}
*/

void Crawler::endCrawl() {
    cout << "End Crawl" << endl;
}
