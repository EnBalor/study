#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define LINE       printf("\n\n<*--------------------------------------*>\n\n");
#define show(x)    LINE; printf("          [���� Ʈ�� ���]\n["); showTree(x); printf("]");

using namespace std;

//����ü ����
//�Ʒ��� �Լ��� Node��� ����ü�� int�� ������ Node�� �¿� �ڽ� ����� �����͸� ���� �ִ�
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
		//addNode�� ���� �ѱ��, �ѱ� Ű���� ũ�⿡ ���� �¿츦 �ڵ����� ��ġ
		addNode(root, i * 2);
		addNode(root, i * (-1));
	}

	showTree(root);
	search = searchTree(root, 8);
	(search != NULL) ? printf("�˻� ��� �� : %d, �ּ� : %p", search->data, search) : printf("�˻���� ����");

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
	(search != NULL) ? printf("�˻� ��� �� : %d, �ּ� : %p", search->data, search) : printf("�˻���� ����");

	show(root);

	printf("\n");
	cout << countNode(root) << endl;
	cout << countLeaf(root) << endl;
	cout << height(root) << endl;


	deleteTree(root);

	return 0;
}

//��� �����Ҵ�
BinNode *getBinaryNode(void)
{
	//�޸��Ҵ�
	BinNode *newNode = (BinNode*)calloc(1, sizeof(BinNode));
	
	//�ʱ�ȭ
	newNode->data = 0;
	newNode->left = NULL;
	newNode->right = NULL;

	//��� �ʱ�ȭ ��ȯ
	return newNode;
}

//��� ����
void setBinNode(BinNode *node, int data, BinNode *left_child, BinNode *right_child)
{
	node->data = data;
	node->left = left_child;
	node->right = right_child;
}

int cnt = 0;

//����߰�
BinNode *addNode(BinNode *node, int data)
{

	//��尡 ���� �� �����Ѵ�
	if (node == NULL)
	{
		node = getBinaryNode();
		setBinNode(node, data, NULL, NULL);
		printf("node �����Ϸ� (%2d), counter : %d\n", node->data, cnt++);
	}

	//�Է��ϴ� Ű���� ����� Ű���� ����.
	else if (data == node->data)
	{
		//�˻� ������ �ڷᱸ���ε� �ߺ��� ���� ��� Ʈ���� ����Ͽ� �˻��ӵ��� ��ȿ�������� �� �ʿ䰡 ����
		//�ߺ����� �ִ� �����ϸ�
		//ù���� �켱 �߰� ��常 ���� �ߺ� ����� ���� ���ɼ��� ����, �� ��� ����Ʈ���� �ǹ̰� ���� ������� ���� ��带 ������ �Ǹ� �޸� ���� �ҷ���
		//�ι�° ��� �ߺ� ��带 �˻��ϸ�, ��� �ߺ���带 ã������ �� ���� ������ �˻��� �ؾ��ϴ� ���� �ҷ���
		cout << "�ߺ��� ���� ��ȿ����";
	}

	//���� ������ �� �۰� �������� ū ������ ������ �ֱ� ������ �Ʒ��� ���� ������ �־��ش�
	//���� ��尡 ����� ��� �� == null�ΰ��� ��带 �����ϰ� ������ ��� �ּҸ� ��ȯ�Ѵ�, ��尡 �����Ǹ� left�� �����Ѵ�
	else if(data < node->data)
	{
		node->left = addNode(node->left, data);
		cout << "left ����" << endl;
	}

	//Ű���� ��庸�� ũ�� ���������� ����, �������� ���ٰ� ���������� �� �� �ְ� �������� ���� ������ �ٲ� �� �ִ�
	//����Լ��� Ż���ϸ� �� �� ������ �ڵ����� ����
	else
	{
		node->right = addNode(node->right, data);
		cout << "right ����" << endl;
	}

	//��忡 ��ȯ
	return node;
}

BinNode *searchTree(BinNode *ptr, int key)
{
	//��尡 ������� ��� ��ȯ
	if (ptr == NULL)
	{
		cout << key << " �� ���� �����ϴ�" << endl;
		return NULL;
	}

	//Ű���� ����� Ű�� ������ ��� ��ȯ
	else if (key == ptr->data)
	{
		cout << key << " �� ��� ��ȯ" << endl;
		return ptr;
	}

	//Ű���� ����� Ű������ ������ ����� ���� �ڽ����� ������, root�� ���� �ڽ��� ket < root ���� �ڽ��� �ݴ�
	//�̷��� ���� �������� ���� ��� ����Ʈ���� ����ϴ� �ǹ̰� ������
	else if (key < ptr->data)
	{
		searchTree(ptr->left, key);
	}

	else
	{
		searchTree(ptr->right, key);
	}

}

//��� ����� ������ ���
void showTree(const BinNode *node)
{
	if (node != NULL) {
		showTree(node->left);
		//���� ��� ���� ���������� ���ٰ� ���� ������ ���� ���� �߰��� ��� ����
		printf("%d, ", node->data);
		showTree(node->right);
	}
}

//��� ����� �޸� ����
//��°� ������ �ٸ��� ���� �ڽ����� ���ٰ� ���������� ���� ��Ʈ�� ���ƿ��µ�
//��Ʈ ���� ������ ��� �������� ���� �޸𸮰� �������� �ʴ´�, �����Ͱ� ����������� ����
void deleteTree(BinNode *node)
{
	if (node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		free(node);
	}
}

//���� ��� �� ���� ���� ���� ã���ش�
BinNode *minValueNode(BinNode * node)
{
	// Ŀ�� ���
	BinNode *cur = node;

	while (cur && cur->left != NULL) {
		cur = cur->left;
	}
	return cur;
}

//Ư�� ��带 ����
BinNode *deleteNode(BinNode *root, int key)
{
	cout << "�Ű� ���� : " << key << "root->data : " << root->data << "root at" << root << endl;

	//root�� ������� ���
	if (root == NULL)
	{
		return root;
	}

	//key�� ����� Ű������ �۰ų� ū ���
	if (key < root->data)
	{
		root->left = deleteNode(root->left, key);
	}

	else if (key > root->data)
	{
		root->right = deleteNode(root->right, key);
	}

	//Ű�� ����� Ű���� ���� ��� ����
	else
	{
		//����� �ڳడ �Ѱ��� ���
		//���� ��尡 null�̶�� ������ ��带 temp�� �����صΰ� ���� ��带 free�� ����
		//temp�� ����� ������ ��带 ��ȯ, ��ȯ�� ������ ���� �� �� �ö󰣴�, �� �� ����� �����̳� �����ʿ� ����ȴ�
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

		//����� �ڳడ �ΰ��� ���
		//������ Ʈ������ ���� ���� ���� �����Ѵ�
		BinNode *temp = minValueNode(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}
}

//����� ����
int countNode(BinNode* node)
{
	if (node == NULL) return 0;

	return 1 + countNode(node->left) + countNode(node->right);
}

//�ܸ������ ����(�ܸ����� �ڽ��� ���� ���)
int countLeaf(BinNode* node)
{
	if (node == NULL) return 0;

	if (node->left == NULL && node->right == NULL) return 1;

	else return countLeaf(node->left) + countLeaf(node->right);
}

//Ʈ���� ���� ���ϱ�
int height(BinNode* node)
{
	int hleft, hright;
	if (node == NULL) return 0;
	hleft = height(node->left);
	hright = height(node->right);

	return (hleft > hright) ? hleft + 1 : hright + 1;
}