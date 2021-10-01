#include "graph.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

bool Graph::no_loops(void) const {
  bool no_loops = std::none_of(edges.begin(), edges.end(),
      [](Edge e) { return e.v1 == e.v2; });

  return no_loops;
}

// Lets make a copy of the edges vector and work with that.
bool Graph::no_repeat_edges(void) const {
  std::vector<Edge> v(edges);

  // transform to make all edge structures lower letter first.
  // (Ie, {'c', 'a'} should be turned into {'a', 'c'}

  std::for_each(v.begin(), v.end(),
      [](Edge &e) {
        if (e.v1 > e.v2) {
          char tmp = e.v2;
          e.v2 = e.v1;
          e.v1 = tmp;
        }
      });

  // sort the list of edges.
  auto cmp_fn = [](Edge &e1, Edge &e2) {
    if (e1.v1 < e2.v1) {
      return true;
    } else if (e1.v1 > e2.v1) {
      return false;
    } else {
      return e1.v2 < e2.v2;
    }
  };

  std::sort(v.begin(), v.end(), cmp_fn);
  auto it = std::adjacent_find(v.begin(), v.end());
  return it == v.end();
}

bool Graph::is_simple(void) const {
  return no_loops() && no_repeat_edges();
}
