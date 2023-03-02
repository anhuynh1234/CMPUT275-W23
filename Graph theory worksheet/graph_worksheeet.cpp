#include <iostream>
#include "graph.h"
#include "digraph.h"
// #include "digraph.h"

using namespace std;

int main() {
    Graph g = Graph();
    g.addVertex(1); 
    g.addVertex(2); 
    g.addVertex(4);
    g.addEdge(1,2); g.addEdge(2,3); g.addEdge(3,1);
    cout << g;
    Digraph dg = Digraph();
    dg.addVertex(1); dg.addVertex(2); dg.addVertex(4);
    dg.addEdge(1,2); dg.addEdge(2,3); dg.addEdge(3,1);
    cout << dg;
}