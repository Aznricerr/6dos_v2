#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "6dos.h"

Graph *build_Graph(int pop, int con)
{
    Graph *new_graph = createAGraph(pop);
    for (int j = 0; j < con / 2; j++)
    {
        for (int i = 0; i < pop; i++)
        {
            int number = i;
            while (number == i)
            {
                number = (rand() % (pop));
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
    }
    //printGraph(new_graph);
    return new_graph;
}

// Create a List
List *createList(int v)
{
    List *newList = malloc(sizeof(List));
    newList->visited = false;
    newList->dist = 32767;
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

void addNode(Graph *graph, int s)
{
    List *newList = createList(s);
    newList->next = graph->adjLists[s];
    graph->adjLists[s] = newList;
}

void addNode2tail(List *graph, int p)
{
    List *newList = createList(p);
    List *tmp = graph;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newList;
}

void changeNode(List *graph, int p)
{
    List *tmp = graph;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->vertex = p;
}

// Print the graph
void printGraphLite(Graph *graph)
{
    int v;
    for (v = 0; v < graph->num_vert; v++)
    {
        List *temp = graph->adjLists[v];
        printf("Person %d\n: ", v);
        while (temp)
        {
            if (temp->next != NULL)
                printf("%d -> ", temp->vertex);
            else
                printf("%d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Print the graph
void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v < graph->num_vert; v++)
    {
        List *temp = graph->adjLists[v];
        printf("Person %d - (%d connections away):\n", v, temp->dist);
        while (temp)
        {
            if (temp->next != NULL)
                printf("%d -> ", temp->vertex);
            else
                printf("%d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void shortest_path(Graph *graph, Graph *iGraph, int start, int distance, int prevInd)
{
    List *sList = graph->adjLists[start];
    List *iList = iGraph->adjLists[start];
    if ((iList->visited) == false)
    {
        iList->dist = distance;
        iList->visited = true;
        if (distance > 0)
        {
            addNode2tail(iList, prevInd);
        }
        //sList = sList->next;
        while (sList != NULL)
        {
            shortest_path(graph, iGraph, sList->vertex, distance + 1, start);
            sList = sList->next;
        }
        return;
    }
    else if ((iList->visited) == true)
    {
        if (iList->dist > distance)
        {
            iList->dist = distance;
            changeNode(iList, prevInd);
            //sList = sList->next;
            while (sList != NULL)
            {
                shortest_path(graph, iGraph, sList->vertex, distance + 1, start);
                sList = sList->next;
            }
            return;
        }
        else
        {
            return;
        }
    }
    return;
}

int main()
{
    int N = 20;
    int K = 4;
    Graph *grid = build_Graph(N, K);
    Graph *iGraf = createAGraph(N);
    for (int i = 0; i < N; i++)
    {
        addNode(iGraf, i);
    }
    shortest_path(grid, iGraf, 1, 0, -1);

    //Will make this more dynamic later
    for (int k = 0; k < N; k++)
    {
        List *sheesh = iGraf->adjLists[k];
        if (sheesh->dist > 1)
        {
            List *sh = sheesh->next;
            sheesh->next = iGraf->adjLists[sh->vertex];
        }
    }
    double logg = log((double)(N)) / log((double)(K));
    printf("Connection to Origin - On Average should be %f degrees away\n", logg);
    printGraph(iGraf);
    printf("\n\n\n");
    printf("Original Connections\n");
    printGraphLite(grid);
    return 0;
}
