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
    g.add_vertices({'a', 'b', 'c', 'd', 'e', 'f'});
    g.add_edge({'a', 'b'});
    g.add_edge({'c', 'b'});
    g.add_edge({'e', 'f'});
    g.add_edge({'f', 'f'});

    assert(g.no_loops() == false);
  }

  {
    Graph g;
    g.add_vertices({'a', 'b', 'c', 'd', 'e', 'f'});
    g.add_edge({'a', 'b'});
    g.add_edge({'c', 'b'});
    g.add_edge({'e', 'f'});
    g.add_edge({'f', 'g'});

    assert(g.no_loops() == true);
  }
}

void test_no_repeat_edges(void) {
  {
    Graph g;
    g.add_vertices({'a', 'b', 'c', 'd', 'e', 'f'});
    g.add_edge({'a', 'b'});
    g.add_edge({'c', 'b'});
    g.add_edge({'e', 'f'});
    g.add_edge({'f', 'e'});

    assert(g.no_repeat_edges() == false);
  }

  {
    Graph g;
    g.add_vertices({'a', 'b', 'c', 'd', 'e', 'f', 'g'});
    g.add_edge({'a', 'b'});
    g.add_edge({'c', 'b'});
    g.add_edge({'e', 'f'});
    g.add_edge({'f', 'g'});

    assert(g.no_repeat_edges() == true);
  }
}

void test_complete(void) {
  {
    Graph g;

    // Add vertices
    g.add_vertices({'a', 'b', 'c', 'd'});

    // Add edges
    g.add_edge({'a', 'b'});
    g.add_edge({'a', 'c'});
    g.add_edge({'a', 'd'});

    g.add_edge({'b', 'c'});
    g.add_edge({'b', 'd'});

    assert(g.is_complete() == false);

    // add an edge to make it complete.
    g.add_edge({'c', 'd'});
    assert(g.is_complete() == true);

    g.print_adjacency_matrix();

    // add an edge to make it not a simple graph.
    g.add_edge({'c', 'd'});
    assert(g.is_complete() == false);
  }
}
