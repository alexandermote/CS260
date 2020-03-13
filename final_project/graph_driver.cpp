#include "graph.h"

int main()
{

    Graph map;
    map.size = 0;

    Vertex a;
    a.name = 'a';
    Vertex b;
    b.name = 'b';
    Vertex c;
    c.name = 'c';
    Vertex d;
    d.name = 'd';
    Vertex e;
    e.name = 'e';
    Vertex f;
    f.name = 'f';
    Vertex g;
    g.name = 'g';

    map.add_vertex(a);
    map.add_vertex(b);
    map.add_vertex(c);
    map.add_vertex(d);
    map.add_vertex(e);
    map.add_vertex(f);
    map.add_vertex(g);

    map.add_edge(&a, &b, 5);
    map.add_edge(&a, &c, 15);
    map.add_edge(&a, &d, 20);
    map.add_edge(&a, &e, 30);
    map.add_edge(&b, &c, 8);
    map.add_edge(&d, &f, 59);
    map.add_edge(&c, &g, 17);

    map.shortest_path(c);
    cout << endl;
    map.mst(b);
}