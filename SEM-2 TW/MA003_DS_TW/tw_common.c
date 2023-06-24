/*For this program, you will generate two different types of graphs and compute using them.
[Generate from provided two files]
File format
• Input will be based on file.
• Assume vertices are numbered 0..n-1.
• In this case, we will assume each file contains exactly one graph.
• Every graph has a two line "header".
◦ Line 1: isDirected isWeighted
◦ Line 2: n m
On line 1, if isDirected==0 the graph is undirected, else it is directed. If
isWeighted==0 the graph is unweighted else it is weighted.
On line 2, n is the number of vertices (nodes) and m is the number of
edges.

The next m lines contain information about the edges. If the graph isWeighted, the next m lines
each contain three integers, u, v and w, where u and v are the endpoints of the edge and w is the
weight on that edge. If the graph is not weighted, each of the m lines contains only u and v. If the
graph is undirected, there is an edge (u, v) and an edge (v, u). If the graph isDirected, the edge is
from u to v.
IF Directed (and Unweighted)
Generate Adjacency Matrix
Instantiate directed graph
Traverse the graph with DFS and BFS
Else Undirected
Generate Adjacency List
Instantiate undirected graph
Traverse the graph with DFS and BFS*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int n, m, isDirected, isWeighted;
int adjMatrix[MAX_NODES][MAX_NODES] = {0};
int adjList[MAX_NODES][MAX_NODES] = {0};

void dfs(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] && !visited[i]) {
            dfs(i, visited);
        }
    }
}

void bfs(int start) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES], front = 0, rear = 0;
    visited[start] = 1;
    printf("%d ", start);
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

void printAdjMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) {
            if (adjList[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void generateAdjMatrix(FILE *fp) {
    int u, v, w;
    for (int i = 0; i < m; i++) {
        if (isWeighted) {
            fscanf(fp, "%d %d %d", &u, &v, &w);
        } else {
            fscanf(fp, "%d %d", &u, &v);
        }
        adjMatrix[u][v] = 1;
        if (!isDirected) {
            adjMatrix[v][u] = 1;
        }
    }
    printAdjMatrix();
}

void generateAdjList(FILE *fp) {
    int u, v, w;
    for (int i = 0; i < m; i++) {
        if (isWeighted) {
            fscanf(fp, "%d %d %d", &u, &v, &w);
        } else {
            fscanf(fp, "%d %d", &u, &v);
        }
        adjList[u][v] = 1;
        if (!isDirected) {
            adjList[v][u] = 1;
        }
    }
    printAdjList();
}

int main() {
    FILE *fp;
    fp = fopen("file1.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);
    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    }else {
        generateAdjList(fp);
    }
    fclose(fp);

    fp = fopen("file2.txt", "r");
    fscanf(fp, "%d %d", &isDirected, &isWeighted);
    fscanf(fp, "%d %d", &n, &m);

    if (isDirected && !isWeighted) {
        generateAdjMatrix(fp);
    } else {
        generateAdjList(fp);
    }
    
    fclose(fp);

    printf("\nDFS: ");
    int visited[MAX_NODES] = {0};
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    printf("\nBFS: ");
    bfs(0);
    printf("\n");
    
    return 0;
}
