#include <stdio.h>
#include <stdlib.h>

//�����Ҵ�
void main()
{
	// ���� �Ҵ��� ���� ������ ���� ����
	int *pArr;

	//calloc�� �Ҵ�� ������ ���� ��� 0���� �ٲٱ� ������ �迭�� �Ҵ��ϰ� ���� �ʱ�ȭ�� �ʿ䰡 ���� �� ����ϸ� ���� 
	pArr = (int *)calloc(3, sizeof(int));

	if (pArr == NULL)
	{
		printf("error");
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pArr[i]);
	}
	// �Ҵ�� ���� ����
	free(pArr);
}