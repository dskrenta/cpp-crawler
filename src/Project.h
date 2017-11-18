// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// Project.h

#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include "leveldb/db.h"

using namespace std;

class Project {
    public:
        Project(
            vector <string> roots,
            const string hostWhiteListFilename,
            const string hostBlacklistFilename,
            const string dbDirPath
        );
        ~Project();

        void search(string query);

    private:
        void addUrlRoots(vector <string> roots);
        void addHostWhitelist(const string hostWhiteListFilename);
        void addHostBlacklist(const string hostBlacklistFilename);

        void openDB();

        leveldb::DB* documentStore;
        leveldb::DB* invertedIndex;
};
#endif // PROJECT_H
