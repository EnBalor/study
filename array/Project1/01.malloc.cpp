#include <stdio.h>
#include <stdlib.h>

//�����Ҵ�
void main()
{
	//ũ�Ⱑ 3�� �迭
	int arr[3] = { 1, 2, 3 };

	// ���� �Ҵ��� ���� ������ ���� ����
	int *pArr;

	// ���� �Ҵ�
	// malloc�� void ���� ��ȯ�ϱ� ������ (int *)�� �� �迭�� �ڷ����� ��ġ�ϱ� ���� ����ȯ
	// int��ũ�� * 3 �޸� �Ҵ�
	pArr = (int *)malloc(sizeof(int) * 3);

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