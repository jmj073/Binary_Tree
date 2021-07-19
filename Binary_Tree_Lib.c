#include "Binary_Tree_H.h"

//노드 생성
SBNode* SB_CreateNode(DataType NewData) {
	SBNode* NewNode = (SBNode*)malloc(sizeof(SBNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

//전위 순회 이진트리 출력
void SB_PreorderPrintTree(SBNode* Node) {
	if (Node == NULL)
		return;

	printf("%c", Node->Data);
	SB_PreorderPrintTree(Node->Left);
	SB_PreorderPrintTree(Node->Right);
}

void SB_SPreorderPrintTree(SBNode* Node) {
	SBNode* Stack[100];
	int Top = 0;
	Stack[Top++] = Node;

	while (Top) {
		Node = Stack[--Top];
		printf("%c", Node->Data);
		if (Node->Right != NULL)
			Stack[Top++] = Node->Right;
		if (Node->Left != NULL)
			Stack[Top++] = Node->Left;
	}
}

//중위 순회 이진트리 출력
void SB_InorderPrintTree(SBNode* Node) {
	if (Node == NULL)
		return;

	SB_InorderPrintTree(Node->Left);
	printf("%c", Node->Data);
	SB_InorderPrintTree(Node->Right);
}

void SB_SInorderPrintTree(SBNode* Node) {
	SBNode* Stack[100];
	int Top = 0;

	while (1) {
		while (Node != NULL) {
			Stack[Top++] = Node;
			Node = Node->Left;
		}
		if (!Top)
			break;
		Node = Stack[--Top];
		printf("%c", Node->Data);
		Node = Node->Right;
	}
}

//중위 순회 이진트리 출력 (괄호 포함)
void ET_InorderPrintTree(SBNode* Node) {
	if (Node == NULL)
		return;

	printf("(");
	ET_InorderPrintTree(Node->Left);
	printf("%c", Node->Data);
	ET_InorderPrintTree(Node->Right);
	printf(")");
}

//후위 순회 이진트리 출력
void SB_PostorderPrintTree(SBNode* Node) {
	if (Node == NULL)
		return;

	SB_PostorderPrintTree(Node->Left);
	SB_PostorderPrintTree(Node->Right);
	printf("%c", Node->Data);
}

void SB_SPostorderPrintTree(SBNode* Node) {
	SBNode* Stack[100] = { 0 };
	int Top = 0;

	do {
		while (Node) {
			if (Node->Right)
				Stack[Top++] = Node->Right;
			Stack[Top++] = Node;
			Node = Node->Left;
		}
		Node = Stack[--Top];
		if (Top && Node->Right == Stack[Top - 1]) {
			Top--;
			Stack[Top++] = Node;
			Node = Node->Right;
		}
		else {
			printf("%c", Node->Data);
			Node = NULL;
		}
	} while (Top);
}

void SB_SSPostorderPrintTree(SBNode* Node) {
	SBNode* Stack[100] = { 0 };
	int Top = 0;

	do {
		while (Node) {
			Stack[Top++] = Node;
			Node = Node->Left;
		}
		Node = Stack[--Top];
		if (Node->Right && Stack[Top + 1] != Node->Right) {
			Stack[Top++] = Node;
			Node = Node->Right;
		}
		else {
			printf("%c", Node->Data);
			Node = NULL;
		}
	} while (Top);
}

//후위 순회를 이용한 트리 소멸
void DestroyTree(SBNode* Node) {
	if (Node == NULL)
		return;

	DestroyTree(Node->Left);
	DestroyTree(Node->Right);

	free(Node);
}

//수식 트리 구축
void ET_BuildExpressionTree(char* PostfixExpression, SBNode** Node) {
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token) {
	case '+': case '-': case'*': case'/':
		*Node = SB_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;
	default:
		(*Node) = SB_CreateNode(Token);
		break;
	}
}

//수식 트리 계산
double ET_Evaluate(SBNode* Tree) {
	char Temp[2];
	double Left = 0, Right = 0, Result = 0;

	if (Tree == NULL)
		return 0;

	switch (Tree->Data) {
	case '+': case '-': case '*': case '/':
		Left = ET_Evaluate(Tree->Left);
		Right = ET_Evaluate(Tree->Right);

		if (Tree->Data == '+') Result = Left + Right;
		else if (Tree->Data == '-') Result = Left - Right;
		else if (Tree->Data == '*') Result = Left * Right;
		else if (Tree->Data == '/') Result = Left / Right;

		break;

	default:
		/*memset(Temp, 0, sizeof(Temp));
		Temp[0] = Tree->Data;
		Result = atof(Temp);
		break;*/
		Result = (double)((Tree->Data) - '0');
	}
	return Result;
}

// 이진 탐색
SBNode* SB_SearchNode(SBNode* Tree, DataType Target) {
	if (Tree == NULL)
		return NULL;
	if (Tree->Data == Target)
		return Tree;
	else if (Tree->Data > Target)
		return SB_SearchNode(Tree->Left, Target);
	else
		return SB_SearchNode(Tree->Right, Target);
}

// 노드 삽입
void SB_InsertNode(SBNode** Tree, SBNode* Child) {
	if (*Tree == NULL) {
		*Tree = Child;
		return;
	}
	SBNode* cur = *Tree;
	while (1) {
		if (cur->Data < Child->Data) {
			if (cur->Right == NULL) {
				cur->Right = Child;
				break;
			}
			cur = cur->Right;
		}
		else if (cur->Data > Child->Data) {
			if (cur->Left == NULL) {
				cur->Left = Child;
				break;
			}
			cur = cur->Left;
		}
		else
			break;
	}
}

SBNode* SB_RemoveNode(SBNode* Tree, SBNode* Parent, DataType Target) {
	SBNode* Removed = NULL, * Temp;
	if (Tree == NULL)
		return NULL;

	if (Tree->Data > Target)
		Removed = SB_RemoveNode(Tree->Left, Tree, Target);
	else if (Tree->Data < Target)
		Removed = SB_RemoveNode(Tree->Right, Tree, Target);
	else {
		Removed = Tree;

		if (Tree->Left == NULL && Tree->Right == NULL) {
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		else if (Tree->Left != NULL && Tree->Right != NULL) {
			Temp = SB_SearchMinNode(Tree->Right);
			Removed = SB_RemoveNode(Tree, NULL, Temp->Data);
			Tree->Data = Temp->Data;
		}
		else {
			if (Tree->Left != NULL)
				Temp = Tree->Left;
			else
				Temp = Tree->Right;

			if (Parent->Left == Tree)
				Parent->Left = Temp;
			else
				Parent->Right = Temp;
		}

	}
}

//최소값 노드 찾기
SBNode* SB_SearchMinNode(SBNode* Tree) {
	while (Tree->Left != NULL)
		Tree = Tree->Left;

	return Tree;
}