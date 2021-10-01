#include "graph.hpp"

#include <iostream>
#include <cassert>

void test_no_loops(void);
void test_no_repeat_edges(void);

int main(void) {

  test_no_loops();
  test_no_repeat_edges();
  return 0;
}


// TODO: Namespace these.

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
