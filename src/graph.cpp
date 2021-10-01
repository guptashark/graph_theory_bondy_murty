#include "graph.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

using std::none_of;
using std::for_each;
using std::sort;
using std::adjacent_find;
using std::mem_fn;

bool Graph::no_loops(void) const {
  return none_of(edges.begin(), edges.end(), mem_fn(&Edge::is_loop));
}

// Lets make a copy of the edges vector and work with that.
bool Graph::no_repeat_edges(void) const {
  std::vector<Edge> v(edges);
  for_each(v.begin(), v.end(), [](Edge &e) {e.normalize();});
  sort(v.begin(), v.end());
  auto it = adjacent_find(v.begin(), v.end());
  return it == v.end();
}

bool Graph::is_simple(void) const {
  return no_loops() && no_repeat_edges();
}
