//#include "Disjoint_Set.h"
//
//int main() {
//	int i, arr[4] = { 1, 2, 3, 4 };
//	DisjointSet* set[4];
//	for (i = 0; i < 4; i++)
//		set[i] = DS_MakeSet(arr + i);
//
//	printf("Set1 == Set2 : %d\n", DS_FindSet(set[0]) == DS_FindSet(set[1]));
//
//	DS_UnionSet(set[0], set[2]);
//	printf("Set1 == Set3 : %d\n", DS_FindSet(set[0]) == DS_FindSet(set[2]));
//
//	DS_UnionSet(set[2], set[3]);
//	printf("Set3 == Set4 : %d\n", DS_FindSet(set[2]) == DS_FindSet(set[3]));
//
//	printf("Set1 == Set4 : %d\n", DS_FindSet(set[0]) == DS_FindSet(set[3]));
//
//	for (i = 0; i < 4; i++)
//		free(set[i]);
//}