#include <stdio.h>
#include <stdlib.h>

//�����Ҵ�
void main()
{
	int arr[3];

	// ���� �Ҵ��� ���� ������ ���� ����
	int *pArr;

	//�迭�� �� �Է�
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i + 1;
	}

	//�޸� �Ҵ�
	pArr = (int *)calloc(3, sizeof(int));

	for (int i = 0; i < 3; i++)
	{
		pArr[i] = arr[i];
		printf("%d\n", pArr[i]);
	}

	printf("\n");

	//�Ҵ�� �޸� ���Ҵ�
	realloc(pArr, sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		pArr[i] = arr[i];
		printf("%d\n", pArr[i]);
	}
	// �Ҵ�� ���� ����
	free(pArr);
}