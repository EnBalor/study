#include <stdio.h>
#include <stdlib.h>

//�����Ҵ�
void main()
{
	//ũ�Ⱑ 3�� �迭
	int arr[3] = { 1, 2, 3 };

	// ���� �Ҵ��� ���� ������ ���� ����
	int *pArr;

	//int�� �ڷḦ �迭�� ũ�⸸ŭ �Ҵ��ϱ� ���� ����
	//pArr = (int *)malloc(sizeof(int) * 3);

	//int�� �ڷ� ũ���� ������ 3�� �Ҵ�
	pArr = (int *)calloc(3, sizeof(int));

	if (pArr == NULL)
	{
		printf("error");
	}

	//�ش� �ݺ����� ���� �޸𸮸� �Ҵ��Ѵ�.
	for (int i = 0; i < 3; i++)
	{
		pArr[i] = arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pArr[i]);
	}
	// �Ҵ�� ���� ����
	free(pArr);
}