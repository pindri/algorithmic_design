#ifndef GRAPH_H
#define GRAPH_H

void InitializeGraph(Graph* g, IntMatrix weight_matrix);
void ResetGraph(Graph* g);
void DeallocateGraph(Graph* g);
void InitSSSP(Graph* g);
int* Adj(Graph* g, Vertex* u);
void UpdateDistance(Vertex* vert_q, Vertex* v, int new_w);
void ShortestPath(Graph* g, size_t to);


#endif // GRAPH_H
