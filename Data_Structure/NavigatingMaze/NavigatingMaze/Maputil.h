#include "Mapdef.h"
#include "Maplinkedstack.h"

#ifndef _MAP_UTIL_
#define _MAP_UTIL_

int pushLSMapPostion(LinkedStack* pStack, MapPosition data);
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif _MAP_UTIL_