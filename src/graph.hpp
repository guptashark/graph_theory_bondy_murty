#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <set>

// An edge is a pair of vertices.
struct Edge {
  char v1;
  char v2;

  bool is_loop(void) const { return v1 == v2; }

  void normalize(void) {
    if (v1 > v2) {
      char tmp = v2;
      v2 = v1;
      v1 = tmp;
    }
  }

  bool operator==(const Edge &rhs) const {
    return v1 == rhs.v1 && v2 == rhs.v2;
  }

  bool operator<(const Edge &rhs) const {
    if (v1 < rhs.v1) {
      return true;
    } else if (v1 > rhs.v1) {
      return false;
    } else {
      return v2 < rhs.v2;
    }
  }
};

// TODO: Make a more specific name, put all this in a namespace.
struct Graph {
  std::set<char> vertices;
  std::vector<Edge> edges;

  // Returns true if the graph has no loops. (An edge from a vertex
  // to itself.)
  bool no_loops(void) const;

  // Returns true if the graph no two edges joining the same vertices.
  bool no_repeat_edges(void) const;

  // Returns true if no_loops and no_repeat_edges are true.
  bool is_simple(void) const;

  // Returns true if the graph is complete.
  bool is_complete(void) const;
};

#endif
