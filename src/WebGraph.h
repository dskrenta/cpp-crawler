// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// WebGraph.h

#ifndef WEB_GRAPH_H
#define WEB_GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include "Url.h"

using namespace std;

class WebGraph {
    public:
        WebGraph();
        ~WebGraph();

        void addNode(Url);
        void addEdge(Url, Url);
        bool adjacent(Url);
        vector <Url> neighbors();

    private:
        vector <Url> nodeList;
        multimap <Url, Url> edgeList;
};
#endif // WEB_GRAPH_H
