// Graph Coloring (backtracking) in C
#include <stdio.h>
#include <stdlib.h>
#define V 4

int isSafe(int v, int graph[V][V], int color[], int c) {
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i]) return 0;
	return 1;
}

int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
	if (v == V) return 1;
	for (int c = 1; c <= m; c++) {
		if (isSafe(v, graph, color, c)) {
			color[v] = c;
			if (graphColoringUtil(graph, m, color, v+1)) return 1;
			color[v] = 0;
		}
	}
	return 0;
}

int graphColoring(int graph[V][V], int m) {
	int *color = calloc(V, sizeof(int));
	if (!graphColoringUtil(graph, m, color, 0)) {
		printf("Solution does not exist\n");
		free(color);
		return 0;
	}
	printf("Solution Exists: Following are the assigned colors\n");
	for (int i = 0; i < V; i++) printf("%d ", color[i]);
	printf("\n");
	free(color);
	return 1;
}

int main() {
	int graph[V][V] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
	int m = 3; // colors
	graphColoring(graph, m);
	return 0;
}