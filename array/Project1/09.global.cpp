#include <stdio.h>

//��������
int num = 10;

void printGlobal()
{
	printf("%d\n", num);
}

int main()
{
	//������ 10 ���
	printf("%d\n", num);

	//���� ���� 20���� ����
	num = 20;

	//printglobal �Լ����� �������� �� ���
	printGlobal();

	return 0;
}