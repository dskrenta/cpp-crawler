// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Crawler.h

#ifndef CRAWLER_H
#define CRAWLER_H

#include <iostream>
#include <fstream>
#include <string>
// #include <vector>
#include <unordered_set>
#include <queue>
#include <atomic>

// #include "cpr/cpr.h"
// #include "ThreadPool.h"
// #include "WebGraph.h"
#include <stdlib.h>

using namespace std;

class Crawler {
    public:
        Crawler(
            unordered_set <string> roots,
            const string &hostWhitelistFilename,
            const string &hostBlacklistFilename,
            const string &destDir,
            const int numPagesToCrawl,
            const int concurrencyLimit
        );
        ~Crawler();

        void readFileToSet(const string &filename, unordered_set <string> set);

        void startCrawl();
        void endCrawl();
        void logCrawlData();
        void parseUrls(string);

    private:
        unordered_set <string> hostWhitelist;
        unordered_set <string> hostBlacklist;
        unordered_set <string> seenUrls;
        queue <string> crawlQueue;
        // ThreadPool crawlpool;
        // WebGraph webGraph;
        atomic <int> numPagesCrawled {0};
        string dataDirectory;
};
#endif // CRAWLER_H
