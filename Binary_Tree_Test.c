#include "Binary_Tree_H.h"

void main(void) {
	SBNode* Tree = NULL;
	Tree = SB_CreateNode('6');
	SBNode* A = SB_CreateNode('2');
	SBNode* B = SB_CreateNode('1');
	SBNode* C = SB_CreateNode('4');
	SBNode* D = SB_CreateNode('8');
	SBNode* E = SB_CreateNode('7');
	SBNode* F = SB_CreateNode('9');
	SBNode* G = SB_CreateNode('3');
	SBNode* H = SB_CreateNode('5');
	SB_InsertNode(&Tree, A);
	SB_InsertNode(&A, B);
	SB_InsertNode(&A, C);
	SB_InsertNode(&Tree, D);
	SB_InsertNode(&D, E);
	SB_InsertNode(&D, F);
	SB_InsertNode(&C, G);
	SB_InsertNode(&C, H);

	SB_PreorderPrintTree(Tree);
	printf("\n");
	SB_SPreorderPrintTree(Tree);
	printf("\n");
	SB_InorderPrintTree(Tree);
	printf("\n");
	SB_SInorderPrintTree(Tree);
	printf("\n");
	SB_PostorderPrintTree(Tree);
	printf("\n");
	SB_SPostorderPrintTree(Tree);
	printf("\n");
	SB_SSPostorderPrintTree(Tree);
	DestroyTree(Tree);
}

//void main(void) {
//	SBNode* Root = NULL;
//
//	char PostfixExpression[20] = "71*52-/";
//	ET_BuildExpressionTree(PostfixExpression, &Root);
//
//	printf("Preorder ...\n");
//	SB_PreorderPrintTree(Root);
//	printf("\n\n");
//
//	printf("Inorder ...\n");
//	ET_InorderPrintTree(Root);
//	printf("\n\n");
//
//	printf("postorder ...\n");
//	SB_PostorderPrintTree(Root);
//	printf("\n\n");
//
//	printf("Evaluation Resualt : %.3lf\n", ET_Evaluate(Root));
//
//	DestroyTree(Root);
//}