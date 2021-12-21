#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount, int graph_type)
{
	ArrayGraph *ret;

	ret = (ArrayGraph*)malloc(sizeof(ArrayGraph));
	if (ret == NULL)
		return (NULL);
	ret->maxVertexCount = maxVertexCount;
	ret->currentVertexCount = 0;
	ret->graphType = graph_type;
	ret->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int*));
	if (ret->ppAdjEdge == NULL)
	{
		free(ret);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		ret->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		if (ret->ppAdjEdge[i] == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(ret->ppAdjEdge[j]);
			free(ret);
			return (NULL);
		}
	}
	ret->pVertex = (int*)malloc(sizeof(int) * maxVertexCount);
	if (ret->pVertex == NULL)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID) ||
	pGraph->currentVertexCount >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->currentVertexCount++;
	pGraph->pVertex[vertexID] = USED;
	return (TRUE);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
	pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (!pGraph->ppAdjEdge[fromVertexID][toVertexID])
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	return(TRUE);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (vertexID < 0 ||
	vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	return (TRUE);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	// 관련 edge 지워주는 부분 추가하기
	pGraph->currentVertexCount--;
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) ||
	!checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
	return (TRUE);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		printf("UNDIRECTED\n");
	else
		printf("DIRECTED\n");
	printf("VERTEX\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("[%d]", i);
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("[%d]", pGraph->pVertex[i]);
	printf("\nEDGE\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("[%d]  ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("%2d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}