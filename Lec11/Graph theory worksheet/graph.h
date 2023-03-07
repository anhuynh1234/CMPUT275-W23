

#ifndef GRAPH_H_
#define GRAPH_H_

#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph {
    public:
        Graph();
        void addVertex(int v);
        virtual void addEdge(int u, int v);
    private:
        unordered_map<int, unordered_set<int>> nbrs;
};

#endif