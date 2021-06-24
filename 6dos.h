#ifndef __6DOS_H__
#define __6DOS_H__

//Linked List for Associate Node - Adjacency List
typedef struct _List
{
    int dist; //distance from starting node/ connections
    bool visited;
    int vertex; //respensents different peoples
    struct _List *next;
} List;

typedef struct _Graph
{
    int num_vert;
    struct _List **adjLists;
} Graph;

Graph *build_Graph(int pop, int con); //population, connections
List *createList(int v);
Graph *createAGraph(int vertices);
void addEdge(Graph *graph, int s, int d);
void printGraph(Graph *graph);
void shortest_path(Graph *graph, Graph *iGraph, int start, int distance, int prevInd);
void addNode(Graph *graph, int s);
void addNode2tail(List *graph, int p);
void changeNode(List *graph, int p);

#endif