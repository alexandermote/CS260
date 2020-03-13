#include <iostream>

using std::cout;
using std::endl;

# define V 7 // number of vertices in graph

struct Vertex;

struct Edge
{
    Vertex *ver1;
    Vertex *ver2;
    int cost;
};

struct Vertex
{
    char name;
    Edge *connection;
    Vertex()
    {
        connection = (Edge*)malloc(V * sizeof(Edge));
    }
};

struct Graph
{
    int size;
    Vertex *matrix;
    Graph()
    {
        matrix = (Vertex*)malloc(V * sizeof(Vertex));
    }
    public:
        void add_vertex(Vertex new_vertex) // O(1)
        {
            int graph_placement = new_vertex.name - 'a';
            matrix[graph_placement] = new_vertex;
            size++;
        }
        void add_edge(Vertex *v1, Vertex *v2, int val) // bidirectional, O(1)
        {
            Edge new_edge;

            new_edge.ver1 = v1;
            new_edge.ver2 = v2;
            new_edge.cost = val;

            int v1_connection_placement = v2->name - 'a';
            int v2_connection_placement = v1->name - 'a';
            v1->connection[v1_connection_placement] = new_edge;
            v2->connection[v2_connection_placement] = new_edge;
        }
        int smallest_connection(int costs[], bool vertices[]) // O(n)
        {
            int smallest = 9999;
            int smallest_vert;
            for (int i = 0; i < size; i++)
            {
                if (vertices[i] == false && costs[i] < smallest)
                {
                    smallest = costs[i];
                    smallest_vert = i;
                }
            }
            return smallest_vert;
        }
        void shortest_path(Vertex start) // O(n^2)... yikes
        {
            // initialize shortest path arrays
            int path_array[size];
            bool vertex_used[size];
            int infinity = 9999;
            for (int i = 0; i < size; i++)
            {
                vertex_used[i] = false;
                path_array[i] = infinity;
            }

            // determine starting position
            int start_name = start.name - 'a';
            path_array[start_name] = 0;

            // shortest path algorithm
            for (int i = 0; i < size; i++)
            {
                // determine smallest distance to unchecked vertex
                int small_vert_pos = smallest_connection(path_array, vertex_used);
                // check connections from that vertex
                vertex_used[small_vert_pos] = true;
                for (int i = 0; i < size; i++)
                {
                    // if a connection exists, the vertex hasn't been used, using that connection is cheaper, AND there is a path back to the start...
                    if (matrix[small_vert_pos].connection[i].cost && vertex_used[i] == false && (matrix[small_vert_pos].connection[i].cost + path_array[small_vert_pos]) < path_array[i] && path_array[small_vert_pos] != infinity)
                    {
                        //use that connection instead
                        path_array[i] = matrix[small_vert_pos].connection[i].cost + path_array[small_vert_pos];
                    }
                }
            }
            // print the shortest path to each vertex in order
            for (int i = 0; i < size; i++)
            {
                char endpoint = i + 'a';
                cout << start.name << " to " << endpoint << ": " << path_array[i] << endl;
            }
        }
        void mst(Vertex start) // O(n^2)... double yikes
        {
            int lineage[size];
            int path_array[size];
            bool vertex_used[size];
            int infinity = 9999;
            for (int i = 0; i < size; i++)
            {
                vertex_used[i] = false;
                path_array[i] = infinity;
            }

            // determine starting position
            int start_name = start.name - 'a';
            path_array[start_name] = 0;
            lineage[start_name] = start_name; // no lineage; start vertex is the progenitor

            // tree connection algorithm
            for (int i = 0; i < size; i++)
            {
                // determine smallest distance to unchecked vertex
                int small_vert_pos = smallest_connection(path_array, vertex_used);
                // check connections from that vertex
                vertex_used[small_vert_pos] = true;
                for (int i = 0; i < size; i++)
                {
                    if (matrix[small_vert_pos].connection[i].cost && vertex_used[i] == false && matrix[small_vert_pos].connection[i].cost < path_array[i])
                    {
                        lineage[i] = small_vert_pos;
                        path_array[i] = matrix[small_vert_pos].connection[i].cost;
                    }
                }
            }
            // print statement gives all connections in tree
            for (int i = 0; i < size; i++)
            {
                char parent = lineage[i] + 'a';
                char child = i + 'a';
                cout << parent << " to " << child << ": " << matrix[i].connection[lineage[i]].cost << endl;
            }
        }
};