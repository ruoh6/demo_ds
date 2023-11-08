#pragma once
#include <stdio.h>
#include <stdlib.h>

namespace Graph {
    // DFS algorithm in C
    struct node {
        int vertex;
        struct node* next;
    };

    struct node* createNode(int v);

    struct Graph {
        int numVertices;
        int* visited;

        // We need int** to store a two dimensional array.
        // Similary, we need struct node** to store an array of Linked lists
        struct node** adjLists;
    };

    // DFS algo
    // ������������㷨��
    // 1������visited���飬��¼�����ʵĶ���(vertex)������Ϊ��������������±����Ƕ�����
    // 2��ͼ�ṹ������������ڽӱ�(adjList[struct node*])
    // 3���ڵ�ṹ�������š���һ����ָ��(struct noded* next)
    // 4��ȡ���ڵ�tmp����visited[vertex]=1
    // 5���ݹ����tmp�����нڵ�

    // 1)Start by putting any one of the graph's vertices on top of a stack.
    // 2)Take the top item of the stack and add it to the visited list.
    // 3)Create a list of that vertex's adjacent nodes.
    // Add the ones which aren't in the visited list to the top of the stack.
    // 4)Keep repeating steps 2 and 3 until the stack is empty.
    void DFS(struct Graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex]; // ȡ���ýڵ������
        struct node* temp = adjList;

        graph->visited[vertex] = 1;
        printf("Visited %d \n", vertex);

        while (temp != NULL) {
            int connectedVertex = temp->vertex;

            if (graph->visited[connectedVertex] == 0) { // ��δ���ʽڵ�
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }
    }

    // Create a node
    struct node* createNode(int v) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->vertex = v;
        newNode->next = NULL;
        return newNode;
    }

    // Create graph
    struct Graph* createGraph(int vertices) {
        struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
        graph->numVertices = vertices;

        graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

        graph->visited = (int*)malloc(vertices * sizeof(int));

        int i;
        for (i = 0; i < vertices; i++) {
            graph->adjLists[i] = NULL;
            graph->visited[i] = 0;
        }
        return graph;
    }

    // Add edge
    void addEdge(struct Graph* graph, int src, int dest) {
        // Add edge from src to dest
        struct node* newNode = createNode(dest);
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;

        // Add edge from dest to src
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }

    // Print the graph
    void printGraph(struct Graph* graph) {
        int v;
        for (v = 0; v < graph->numVertices; v++) {
            struct node* temp = graph->adjLists[v];
            printf("\n Adjacency list of vertex %d\n ", v);
            while (temp) {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }

    int test03() {
        struct Graph* graph = createGraph(4);
        // 0 -> 2 -> 1 ->^
        // 1 -> 2 -> 0 ->^
        // 2 -> 3 -> 1 -> 0 ->^
        // 3 -> 2 ->^
        addEdge(graph, 0, 1); // 0->1;0->2
        addEdge(graph, 0, 2); // 0->2
        addEdge(graph, 1, 2); // 1->2
        addEdge(graph, 2, 3); // 2->3

        printGraph(graph);

        DFS(graph, 0);
        return 0;
    }


} // namespace end
