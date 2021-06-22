#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "6dos.h"

List *build_Graph(int size)
{
    Graph *new_graph = createAGraph(size);
    for (int i = 0; i < size; i++)
    {
        int number = i;
        while (number == i)
        {
            number = (rand() % (size + 1));
            List *tmp = new_graph->adjLists[i];
            while (tmp != NULL)
            {
                if (number == (tmp->vertex))
                {
                    number = i;
                    tmp = NULL;
                }
                else
                {
                    tmp = tmp->next;
                }
            }
        }
        addEdge(new_graph, i, number);
    }
    printGraph(new_graph);
    return NULL;
}

// Create a List
List *createList(int v)
{
    List *newList = malloc(sizeof(List));
    newList->vertex = v;
    newList->next = NULL;
    return newList;
}

// Create a graph
Graph *createAGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vert = vertices;

    graph->adjLists = malloc(vertices * sizeof(List *));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(Graph *graph, int s, int d)
{
    // Add edge from s to d
    List *newList = createList(d);
    newList->next = graph->adjLists[s];
    graph->adjLists[s] = newList;

    // Add edge from d to s
    newList = createList(s);
    newList->next = graph->adjLists[d];
    graph->adjLists[d] = newList;
}

// Print the graph
void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v < graph->num_vert; v++)
    {
        List *temp = graph->adjLists[v];
        printf("\n Person %d\n: ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    List *grid = build_Graph(20);
    return 0;
}
