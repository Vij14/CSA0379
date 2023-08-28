#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // Number of vertices

// Structure to represent an edge
struct Edge {
    int dest;
    int weight;
};

// Structure to represent a vertex
struct Vertex {
    int index;
    int distance;
};

// Min-heap structure
struct MinHeap {
    int size;
    int capacity;
    struct Vertex **array;
};

// Create a new vertex
struct Vertex *createVertex(int index, int distance) {
    struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
    vertex->index = index;
    vertex->distance = distance;
    return vertex;
}

// Create a new edge
struct Edge *createEdge(int dest, int weight) {
    struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
    edge->dest = dest;
    edge->weight = weight;
    return edge;
}

// Create a min-heap
struct MinHeap *createMinHeap(int capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Vertex **)malloc(capacity * sizeof(struct Vertex *));
    return minHeap;
}

// Swap two vertices
void swapVertices(struct Vertex **a, struct Vertex **b) {
    struct Vertex *temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify function
void minHeapify(struct MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->distance < minHeap->array[smallest]->distance)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->distance < minHeap->array[smallest]->distance)
        smallest = right;

    if (smallest != index) {
        swapVertices(&minHeap->array[index], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Extract the vertex with the minimum distance from the heap
struct Vertex *extractMin(struct MinHeap *minHeap) {
    if (minHeap->size == 0)
        return NULL;

    struct Vertex *minVertex = minHeap->array[0];
    struct Vertex *lastVertex = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastVertex;
    minHeap->size--;
    minHeapify(minHeap, 0);

    return minVertex;
}

// Decrease the distance value of a vertex in the heap
void decreaseDistance(struct MinHeap *minHeap, int index, int newDistance) {
    int i;
    for (i = 0; i < minHeap->size; i++) {
        if (minHeap->array[i]->index == index) {
            minHeap->array[i]->distance = newDistance;
            break;
        }
    }

    while (i && minHeap->array[i]->distance < minHeap->array[(i - 1) / 2]->distance) {
        swapVertices(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[V][V], int src) {
    struct MinHeap *minHeap = createMinHeap(V);
    struct Vertex *vertices[V];

    for (int i = 0; i < V; i++) {
        vertices[i] = createVertex(i, INT_MAX);
        minHeap->array[i] = vertices[i];
        minHeap->size++;
    }

    vertices[src]->distance = 0;
    decreaseDistance(minHeap, src, 0);

    while (minHeap->size > 0) {
        struct Vertex *minVertex = extractMin(minHeap);
        int u = minVertex->index;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && minHeap->array[v]->distance > minVertex->distance + graph[u][v]) {
                minHeap->array[v]->distance = minVertex->distance + graph[u][v];
                decreaseDistance(minHeap, v, minHeap->array[v]->distance);
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, vertices[i]->distance);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 4, 0, 0, 0},
        {0, 0, 1, 7, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 2, 0, 5},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
