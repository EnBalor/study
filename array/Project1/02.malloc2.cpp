#include <stdio.h>
#include <stdlib.h>

//�����Ҵ�
void main()
{
	//�Է� ���� ���� ����
	int num;

	// ���� �Ҵ��� ���� ������ ���� ����
	int *pArr;

	printf("�Է��� �迭�� �� : ");
	scanf("%d", &num);

	//�Է��� �� ��ŭ �����Ҵ�
	pArr = (int*)malloc(sizeof(int) * num);

	//�迭�� �� �Է�
	for (int i = 0; i < num; i++)
	{
		printf("�迭�� �Է��� �� : ");
		scanf("%d", &pArr[i]);
	}

	//�Է��� �� ���
	for (int i = 0; i < num; i++)
	{
		printf("%d�� �迭 : %d\n", i, pArr[i]);
	}

	//�����Ҵ� ����
	free(pArr);
}