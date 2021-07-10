#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

typedef struct tagBTNode {
	DataType Data;

	struct tagSBTNode* Left;
	struct tagSBTNode* Right;
} SBNode;

//노드 생성
SBNode* SB_CreateNode(DataType NewData);
//전위 순회 이진트리 출력
void SB_PreorderPrintTree(SBNode* Node);
//중위 순회 이진트리 출력
void SB_InorderPrintTree(SBNode* Node);
//중위 순회 이진트리 출력 (괄호 포함)
void ET_InorderPrintTree(SBNode* Node);
//후위 순회 이진트리 출력
void SB_PostorderPrintTree(SBNode* Node);
//후위 순회를 이용한 트리 소멸
void DestroyTree(SBNode* Node);
//수식 트리 구축
void ET_BuildExpressionTree(char* PostfixExpression, SBNode** Node);
//수식 트리 계산
double ET_Evaluate(SBNode* Tree);
// 이진 탐색
SBNode* SB_SearchNode(SBNode* Tree, DataType Target);
// 노드 삽입
void SB_InsertNode(SBNode** Tree, SBNode* Child);
//노드 삭제
SBNode* SB_RemoveNode(SBNode* Tree, SBNode* Parent, DataType Target);
//최소값 노드 찾기
SBNode* SB_SearchMinNode(SBNode* Tree);

#endif //BINARY_TREE_H