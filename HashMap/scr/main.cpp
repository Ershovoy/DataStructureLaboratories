#include "IOHashMap.h"

int main()
{
	HashMap* hashMap = new HashMap;
	Map* map = new Map;

	printHashMapMenu(*hashMap, *map);

	delete hashMap;
	delete map;

	return 0;
}