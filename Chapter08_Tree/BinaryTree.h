#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode {			// 이진 트리를 표현한 구조체
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;
	
BTreeNode* MakeBTreeNode(void);					// 노드의 생성
BTData GetData(BTreeNode* bt);					// 노드에 저장된 데이터를 반환
void SetData(BTreeNode* bt, BTData data);		// 노드에 데이터를 저장

// 서브 트리 주소 값 반환
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

// 서브 트리의 연결을 담당
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif // !__BINARY_TREE_H__
