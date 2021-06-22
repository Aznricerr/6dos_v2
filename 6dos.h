#ifndef __6DOS_H__
#define __6DOS_H__

//Linked List for Associate Node - Adjacency List
typedef struct _List
{
    int vertex; //respensents different peoples
    struct _List *next;
} List;

typedef struct _Graph
{
    int num_vert;
    struct _List **adjLists;
} Graph;

List *build_Graph(int size);
List *createList(int v);
Graph *createAGraph(int vertices);
void addEdge(Graph *graph, int s, int d);
void printGraph(Graph *graph);

#endif