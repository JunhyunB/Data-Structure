#include "LLIST.h"

typedef struct {
    LLIST* vertex_list;
} GRAPH;

typedef struct vertex {
    int data;
    LLIST* arc_list;
} VERTEX;

typedef struct arc {
    VERTEX* to_vertex;
} ARC;

GRAPH* create_graph();
bool g_insert_vertex(GRAPH* graph, int data);
int find_vertex(LLIST* list, void* search_data);
bool g_insert_arc(GRAPH* graph, int from, int to);
VERTEX* get_data_at(LLIST* vertex_list, int vertex_loc);