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
#include "ThreadPool"
#include "WebGraph"

using namespace std;

class Crawler {
    public:
        Crawler(
            vector <string> roots,
            const string &hostWhitelistFilename = "",
            const string &hostBlacklistFilename = "",
            const string &destDir = "../data"
        );
        ~Crawler();

        void startCrawl();
        void endCrawl();
        void logCrawlData();
        void parseUrls(string);

    private:
        unordered_set <string> hostWhitelist;
        unordered_set <string> hostBlacklist;
        unordered_set <string> seenUrls;
        queue <string> crawlQueue;
        ThreadPool crawlpool;
        WebGraph webGraph;
        int numPagesCrawled = 0;
};
#endif // CRAWLER_H
