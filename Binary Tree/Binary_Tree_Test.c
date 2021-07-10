//#include "Binary_Tree_H.h"
//
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