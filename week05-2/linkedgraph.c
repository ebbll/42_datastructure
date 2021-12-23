#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = (LinkedGraph *)malloc(sizeof(pGraph));
	if (!pGraph)
		return (NULL);
	pGraph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList) * maxVertexCount);
	if (!pGraph->ppAdjEdge)
	{
		free(pGraph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = createLinkedList();
		if (!pGraph->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
				free(pGraph->ppAdjEdge[j]);
			free(pGraph->ppAdjEdge);
			free(pGraph);
			return (NULL);
		}
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!pGraph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
		{
			free(pGraph->ppAdjEdge[i]);
		}
		free(pGraph->ppAdjEdge);
		free(pGraph);
		return (NULL);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->currentEdgeCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	return (pGraph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = (LinkedGraph *)malloc(sizeof(pGraph));
	if (!pGraph)
		return (NULL);
	pGraph->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList) * maxVertexCount);
	if (!pGraph->ppAdjEdge)
	{
		free(pGraph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = createLinkedList();
		if (!pGraph->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
				free(pGraph->ppAdjEdge[j]);
			free(pGraph->ppAdjEdge);
			free(pGraph);
			return (NULL);
		}
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!pGraph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
			free(pGraph->ppAdjEdge[i]);
		free(pGraph->ppAdjEdge);
		free(pGraph);
		return (NULL);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->currentEdgeCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	return (pGraph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount ? FALSE : TRUE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID))
		return (FAIL);
	if (pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || pGraph->maxVertexCount <= vertexID)
		return (FALSE);
	return (TRUE);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID);

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

int getEdgeCountLG(LinkedGraph* pGraph);

int getVertexCountLG(LinkedGraph* pGraph);

int getMaxVertexCountLG(LinkedGraph* pGraph);

int getGraphTypeLG(LinkedGraph* pGraph);

void displayLinkedGraph(LinkedGraph* pGraph);
