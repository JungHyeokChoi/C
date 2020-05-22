#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapdef.h"
#include "Maplinkedstack.h"
#include "Maputil.h"

int main() {
	LinkedStack *pStack = NULL;

	MapPosition startPos, endPos;

	int mazeArray[HEIGHT][WIDTH] = {
		{0,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1,1},
		{1,1,0,1,1,1,1,1},
		{1,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,1,1},
		{1,1,1,1,1,0,0,1},
		{1,1,1,1,1,1,1,0}
	};

	pStack = createLinkedStack();
	if (pStack != NULL) {
		startPos.x = 0;
		startPos.y = 0;
		endPos.x = 7;
		endPos.y = 7;

		printf("<Create Maze>\n\n");
		printMaze(mazeArray);
		printf("\n");

		findPath(mazeArray, startPos, endPos, pStack);

		printf("<Show Maze>\n\n");
		showPath(pStack, mazeArray);
		printf("\n");

		deleteLinkedStack(pStack);
	}
	return 0;
}