#ifndef GRAPH_H_
#define GRAPH_H_

#include <initializer_list>
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
 private:
  std::set<char> vertices;
  std::vector<Edge> edges;

 public:
  // add a vertex. This will fail if the vertex already exists.
  bool add_vertex(char v);

  // silent errors. Any vertices already existing will not be re-added.
  void add_vertices(std::initializer_list<char> v_lst);

  // add an edge. Fails if the edge contains vertices not in the graph.
  bool add_edge(Edge e);

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
