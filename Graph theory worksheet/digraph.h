
#ifndef _DIGRAPH_H_
#define _DIGRAPH_H_

#include "graph.h"

class Digraph : public Graph {
    public:
    void addEdge(int u, int v);
};

#endif