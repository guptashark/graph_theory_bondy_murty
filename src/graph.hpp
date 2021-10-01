#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

// An edge is a pair of vertices.
struct Edge {
  char v1;
  char v2;

  bool operator==(const Edge &rhs) const {
    return v1 == rhs.v1 && v2 == rhs.v2;
  }
};

// TODO: Make a more specific name, put all this in a namespace.
struct Graph {
  std::vector<Edge> edges;

  // Returns true if the graph has no loops. (An edge from a vertex
  // to itself.)
  bool no_loops(void) const;

  // Returns true if the graph no two edges joining the same vertices.
  bool no_repeat_edges(void) const;

  // Returns true if no_loops and no_repeat_edges are true.
  bool is_simple(void) const;
};

#endif
