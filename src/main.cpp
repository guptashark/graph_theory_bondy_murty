#include "graph.hpp"

#include <iostream>
#include <cassert>

void test_no_loops(void);
void test_no_repeat_edges(void);
void test_complete(void);

int main(void) {

  test_no_loops();
  test_no_repeat_edges();
  test_complete();
  return 0;
}

// TODO: Namespace these functions.
void test_no_loops(void) {
  {
    Graph g;
    g.edges.push_back({'a', 'b'});
    g.edges.push_back({'c', 'b'});
    g.edges.push_back({'e', 'f'});
    g.edges.push_back({'f', 'f'});

    assert(g.no_loops() == false);
  }

  {
    Graph g;
    g.edges.push_back({'a', 'b'});
    g.edges.push_back({'c', 'b'});
    g.edges.push_back({'e', 'f'});
    g.edges.push_back({'f', 'g'});

    assert(g.no_loops() == true);
  }
}

void test_no_repeat_edges(void) {
  {
    Graph g;
    g.edges.push_back({'a', 'b'});
    g.edges.push_back({'c', 'b'});
    g.edges.push_back({'e', 'f'});
    g.edges.push_back({'f', 'e'});

    assert(g.no_repeat_edges() == false);
  }

  {
    Graph g;
    g.edges.push_back({'a', 'b'});
    g.edges.push_back({'c', 'b'});
    g.edges.push_back({'e', 'f'});
    g.edges.push_back({'f', 'g'});

    assert(g.no_repeat_edges() == true);
  }
}

void test_complete(void) {
  {
    Graph g;

    // Add vertices
    g.vertices.insert('a');
    g.vertices.insert('b');
    g.vertices.insert('c');
    g.vertices.insert('d');

    // Add edges
    g.edges.push_back({'a', 'b'});
    g.edges.push_back({'a', 'c'});
    g.edges.push_back({'a', 'd'});

    g.edges.push_back({'b', 'c'});
    g.edges.push_back({'b', 'd'});

    assert(g.is_complete() == false);

    // add a vertex to make it complete.
    g.edges.push_back({'c', 'd'});
    assert(g.is_complete() == true);

    // add a vertex to make it not a simple graph.
    g.edges.push_back({'c', 'd'});
    assert(g.is_complete() == false);
  }
}
