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
        pool.schedule([this, it] {
            /*
            stringstream ss;
            size_t generatedHash = h(*it);
            ss << generatedHash;
            string filename = ss.str();
            string command = "curl -Ls -o " + this->dataDirectory + "/" + filename.c_str() + " -w 'Downloaded: %{url_effective} \n' " + *it;
            system(command.c_str());
            */
            this->crawlTask(*it);
        });
    }
}

void Crawler::crawlTask(string url) {
    stringstream ss;
    size_t generatedHash = h(url);
    ss << generatedHash;
    string filename = ss.str();
    // string command = "curl -Ls -o " + this->dataDirectory + "/" + filename.c_str() + " -w 'Downloaded: %{url_effective} \n' " + url;
    string command = "curl -Ls " + url + " | tee " + this->dataDirectory + "/" + filename.c_str();
    cout << this->exec(command.c_str()) << endl;
    // system(command.c_str());
}

string Crawler::exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
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
