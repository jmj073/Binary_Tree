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

//��� ����
SBNode* SB_CreateNode(DataType NewData);
//���� ��ȸ ����Ʈ�� ���
void SB_PreorderPrintTree(SBNode* Node);
//���� ��ȸ ����Ʈ�� ���
void SB_InorderPrintTree(SBNode* Node);
//���� ��ȸ ����Ʈ�� ��� (��ȣ ����)
void ET_InorderPrintTree(SBNode* Node);
//���� ��ȸ ����Ʈ�� ���
void SB_PostorderPrintTree(SBNode* Node);
//���� ��ȸ�� �̿��� Ʈ�� �Ҹ�
void DestroyTree(SBNode* Node);
//���� Ʈ�� ����
void ET_BuildExpressionTree(char* PostfixExpression, SBNode** Node);
//���� Ʈ�� ���
double ET_Evaluate(SBNode* Tree);
// ���� Ž��
SBNode* SB_SearchNode(SBNode* Tree, DataType Target);
// ��� ����
void SB_InsertNode(SBNode** Tree, SBNode* Child);
//��� ����
SBNode* SB_RemoveNode(SBNode* Tree, SBNode* Parent, DataType Target);
//�ּҰ� ��� ã��
SBNode* SB_SearchMinNode(SBNode* Tree);

#endif //BINARY_TREE_H