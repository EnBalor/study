#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define LINE       printf("\n\n<*--------------------------------------*>\n\n");
#define show(x)    LINE; printf("          [이진 트리 출력]\n["); showTree(x); printf("]");

using namespace std;

//구조체 선언
//아래의 함수는 Node라는 구조체에 int형 데이터 Node의 좌우 자식 노드의 포인터를 갖고 있다
typedef struct binary_node {

	int data;

	struct binary_node *left;
	struct binary_node *right;

} BinNode;

BinNode *getBinaryNode(void);
void setBinNode(BinNode *ptr, int data, BinNode *left, BinNode *right);
BinNode *addNode(BinNode *ptr, int data);
void showTree(const BinNode *ptr);
void deleteTree(BinNode *ptr);
BinNode *searchTree(BinNode *ptr, int key);
BinNode *deleteNode(BinNode *root, int key);
BinNode *minValueNode(BinNode * node);
int countNode(BinNode *node);
int countLeaf(BinNode* node);
int height(BinNode* node);

int main()
{
	BinNode *root = NULL;
	BinNode *search = NULL;

	for (int i = 0; i < 5; i++)
	{
		//addNode로 값을 넘긴다, 넘긴 키값의 크기에 따라 좌우를 자동으로 배치
		addNode(root, i * 2);
		addNode(root, i * (-1));
	}

	showTree(root);
	search = searchTree(root, 8);
	(search != NULL) ? printf("검색 결과 값 : %d, 주소 : %p", search->data, search) : printf("검색결과 없음");

	deleteTree(root);

	printf("\n\n");

	root = NULL;

	root = addNode(root, 5);
	root = addNode(root, 1);
	root = addNode(root, 8);
	root = addNode(root, 4);
	root = addNode(root, 2);
	root = addNode(root, 6);
	root = addNode(root, 9);
	root = addNode(root, 7);
	root = addNode(root, 3);

	search = searchTree(root, 8);
	(search != NULL) ? printf("검색 결과 값 : %d, 주소 : %p", search->data, search) : printf("검색결과 없음");

	show(root);

	printf("\n");
	cout << countNode(root) << endl;
	cout << countLeaf(root) << endl;
	cout << height(root) << endl;


	deleteTree(root);

	return 0;
}

//노드 동적할당
BinNode *getBinaryNode(void)
{
	//메모리할당
	BinNode *newNode = (BinNode*)calloc(1, sizeof(BinNode));
	
	//초기화
	newNode->data = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	//노드 초기화 반환
	return newNode;
}

//노드 설정
void setBinNode(BinNode *node, int data, BinNode *left_child, BinNode *right_child)
{
	node->data = data;
	node->left = left_child;
	node->right = right_child;
}

int cnt = 0;

//노드추가
BinNode *addNode(BinNode *node, int data)
{

	//노드가 없을 시 생성한다
	if (node == NULL)
	{
		node = getBinaryNode();
		setBinNode(node, data, NULL, NULL);
		printf("node 생성완료 (%2d), counter : %d\n", node->data, cnt++);
	}

	//입력하는 키값이 노드의 키값과 같다.
	else if (data == node->data)
	{
		//검색 목적의 자료구조인데 중복이 많을 경우 트리를 사용하여 검색속도를 비효율적으로 할 필요가 없음
		//중복값이 있다 가정하면
		//첫번재 우선 발견 노드만 보고 중복 노드의 존재 가능성을 무시, 이 경우 이진트리는 의미가 없고 사용하지 않을 노드를 가지게 되며 메모리 낭비를 불러옴
		//두번째 모든 중복 노드를 검색하면, 모든 중복노드를 찾기위해 최 하위 노드까지 검색을 해야하는 낭비를 불러옴
		cout << "중복된 값은 비효율적";
	}

	//노드는 왼쪽이 더 작고 오른쪽이 큰 구조를 가지고 있기 때문에 아래와 같은 조건을 넣어준다
	//왼쪽 노드가 비었을 경우 위 == null로가서 노드를 생성하고 생성된 노드 주소를 반환한다, 노드가 생성되면 left에 연결한다
	else if(data < node->data)
	{
		node->left = addNode(node->left, data);
		cout << "left 생성" << endl;
	}

	//키값이 노드보다 크면 오른쪽으로 간다, 왼쪽으로 갔다가 오른쪽으로 갈 수 있고 내려가는 도중 방향이 바뀔 수 있다
	//재귀함수를 탈출하면 좌 우 연결이 자동으로 결정
	else
	{
		node->right = addNode(node->right, data);
		cout << "right 생성" << endl;
	}

	//노드에 반환
	return node;
}

BinNode *searchTree(BinNode *ptr, int key)
{
	//노드가 비어있을 경우 반환
	if (ptr == NULL)
	{
		cout << key << " 인 노드는 없습니다" << endl;
		return NULL;
	}

	//키값이 노드의 키와 같으면 결과 반환
	else if (key == ptr->data)
	{
		cout << key << " 인 노드 반환" << endl;
		return ptr;
	}

	//키값이 노드의 키값보다 작으면 노드의 왼쪽 자식으로 내려감, root의 왼쪽 자식은 ket < root 우측 자식은 반대
	//이렇게 값이 생성되지 않을 경우 이진트리를 사용하는 의미가 없어짐
	else if (key < ptr->data)
	{
		searchTree(ptr->left, key);
	}

	else
	{
		searchTree(ptr->right, key);
	}

}

//모든 노드의 데이터 출력
void showTree(const BinNode *node)
{
	if (node != NULL) {
		showTree(node->left);
		//좌측 노드 먼저 최하위노드로 갔다가 우측 끝으로 가기 위해 중간에 출력 삽입
		printf("%d, ", node->data);
		showTree(node->right);
	}
}

//모든 노드의 메모리 해제
//출력과 순서가 다른데 왼쪽 자식으로 갔다가 오른쪽으로 갔다 루트로 돌아오는데
//루트 먼저 해제할 경우 오른쪽의 노드들 메모리가 해제되지 않는다, 포인터가 사라져버리기 때문
void deleteTree(BinNode *node)
{
	if (node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		free(node);
	}
}

//하위 노드 중 가장 작은 값을 찾아준다
BinNode *minValueNode(BinNode * node)
{
	// 커서 노드
	BinNode *cur = node;

	while (cur && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

//특정 노드를 삭제
BinNode *deleteNode(BinNode *root, int key)
{
	cout << "매개 변수 : " << key << "root->data : " << root->data << "root at" << root << endl;

	//root가 비어있을 경우
	if (root == NULL)
	{
		return root;
	}

	//key가 노드의 키값보다 작거나 큰 경우
	if (key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}

	else if (key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}

	//키가 노드의 키값과 같을 경우 삭제
	else
	{
		//노드의 자녀가 한개일 경우
		//왼쪽 노드가 null이라면 오른쪽 노드를 temp에 저장해두고 현재 노드를 free로 해제
		//temp에 저장된 오른쪽 노드를 반환, 반환된 오른쪽 노드는 한 층 올라간다, 위 층 노드의 왼쪽이나 오른쪽에 연결된다
		if (root->left == NULL)
		{
			BinNode *temp = root->right;
			free(root);
			return temp;
		}

		else if (root->right == NULL)
		{
			BinNode *temp = root->left;
			free(root);
			return temp;
		}

		//노드의 자녀가 두개일 경우
		//오른쪽 트리에서 가장 작은 수를 선택한다
		BinNode *temp = minValueNode(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}
}

//노드의 갯수
int countNode(BinNode* node)
{
	if (node == NULL) return 0;

	return 1 + countNode(node->left) + countNode(node->right);
}

//단말노드의 갯수(단말노드는 자식이 없는 노드)
int countLeaf(BinNode* node)
{
	if (node == NULL) return 0;

	if (node->left == NULL && node->right == NULL) return 1;

	else return countLeaf(node->left) + countLeaf(node->right);
}

//트리의 높이 구하기
int height(BinNode* node)
{
	int hleft, hright;
	if (node == NULL) return 0;
	hleft = height(node->left);
	hright = height(node->right);

	return (hleft > hright) ? hleft + 1 : hright + 1;
}