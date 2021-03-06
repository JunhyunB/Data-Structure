#include "LLIST.h"
#include "ADT_graph.h"

GRAPH* create_graph() {
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->vertex_list = create_list();

    return graph;
}

bool g_insert_vertex(GRAPH* graph, int data) {
    // create new vertex
    VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
    new_vertex->data = data;
    new_vertex->arc_list = create_list();
    // insertion of the duplicated vertex is not allowed!
    int vertex_loc = find_vertex(graph->vertex_list, new_vertex);
    if(vertex_loc != -1) {
        free(new_vertex);
        return false; // there already exist!
    }
    // insert vertex into list
    return add_node_at(graph->vertex_list, 
                        graph->vertex_list->count, 
                        new_vertex);
}

int find_vertex(LLIST* list, void* search_data) {
    list->pos = list->front;
    int iter_i = 0;
    while(list->pos != NULL) {// pos == NULL 이면 맨 뒤!
        VERTEX* left = (VERTEX*)(list->pos->data_ptr);
        VERTEX* right = (VERTEX*)(search_data);

        if(left->data == right->data)
            return iter_i;
        list->pos = list->pos->next;
        iter_i++;
    }
    return -1;
}

bool g_insert_arc(GRAPH* graph, int from, int to) {
    // search from_vertex;
    VERTEX tmp_vertex1;
    tmp_vertex1.data = from;
    tmp_vertex1.arc_list = NULL;

    int vertex_loc = find_vertex(graph->vertex_list, &tmp_vertex1);
    if(vertex_loc == -1) {
        printf("from vertex %c: not found\n", (char)from);
        return false;
    }

    // get a VERTEX with 'from' data
    VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    // search to_vertex
    VERTEX tmp_vertex2;
    tmp_vertex2.data = to;
    tmp_vertex2.arc_list = NULL;

    vertex_loc = find_vertex(graph->vertex_list, &tmp_vertex2);
    if(vertex_loc == -1) {
        printf("to_vertex %c: not found\n", (char)to);
        return false;
    }

    // get a VERTEX with 'to' data
    VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);

    // create destination
    ARC* new_arc = (ARC*)malloc(sizeof(ARC));
    new_arc->to_vertex = to_vertex;

    // insert vertex into list
    return add_node_at(from_vertex->arc_list, // list of arc
                        from_vertex->arc_list->count, // end of list
                        new_arc); // arc is inserted
}

VERTEX* get_data_at(LLIST* vertex_list, int vertex_loc) {
    
}