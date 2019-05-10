#ifndef ARRAY_H
#define ARRAY_H

#include "struct.h"

void FreeQArray(QArray* q);
QArray BuildQArray(Graph* g);
Vertex ExtractMinQArray(QArray* q);
void DijkstraArray(Graph* g, size_t s);
void Relax(QArray* q, Vertex* u, Graph* g, int w, size_t i);

#endif // ARRAY_H
