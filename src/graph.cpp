#include "graph.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

using std::none_of;
using std::for_each;
using std::sort;
using std::adjacent_find;
using std::mem_fn;
using std::vector;

bool Graph::add_vertex(char v) {
  if (auto [it, success] = vertices.insert(v); success) {
    for (auto &row : adjacency_matrix) row.push_back(0);
    vector<int> new_row(vertices.size());
    adjacency_matrix.push_back(new_row);

    return true;
  }

  return false;
}

void Graph::add_vertices(std::initializer_list<char> v_lst) {
  for (auto v : v_lst) {
    if (auto [it, success] = vertices.insert(v); success) {
      for (auto &row : adjacency_matrix) row.push_back(0);
      vector<int> new_row(vertices.size());
      adjacency_matrix.push_back(new_row);
    }
  }
}

bool Graph::add_edge(Edge e) {
  if (vertices.contains(e.v1) && vertices.contains(e.v2)) {
    edges.push_back(e);
    adjacency_matrix[e.v1 - 'a'][e.v2 - 'a']++;
    adjacency_matrix[e.v2 - 'a'][e.v1 - 'a']++;
    return true;
  } else {
    return false;
  }
}

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

// A complete graph with n vertices must have n choose 2 edges.
// We need to add a list of vertices to the graph.
bool Graph::is_complete(void) const {
  auto nv = vertices.size();
  bool correct_num_edges = (nv * (nv - 1) / 2) == edges.size();
  return correct_num_edges && is_simple() && no_loops();
}

void Graph::print_adjacency_matrix(void) const {
  for (auto row : adjacency_matrix) {
    for (auto edge : row) std::cout << edge << " ";
    std::cout << std::endl;
  }
}
