#include <stdio.h>

//void change(int);

//int main() 
//{
//	int a = 5;
//	printf("before change [a] : %d", a);
//	change(a);
//	printf("after change [a] : %d", a);
//}

//void change(int a) 
//{
//	a = 10;
//}

void change(int*);

int main()
{
	int a = 5;
	printf("before change [a] : %d", a);
	change(&a);
	printf("after change [a] : %d", a);
	return 0;
}

void change(int *a)
{
	*a = 10;
}

/*
	���� �̸� �տ� &(���ۼ���)�� ���̸� �� ������ �ּҸ� �˷���
	�ش� ������ ��� ����Ǿ� �ִ����� ��Ÿ��
	scanf�� &�� ����ϴµ� �̴� & ���� ������ ���
	������ �Է��ϴ� ���� �ƴ� �ӽ� ��������� �Է��ϰ� �� ������ �ӽ� �����Ѱ��� �����ϰ� ������ ���� �����ϰ� �ӽ� ��������� ���� �����.
	scanf������ ����� ���� ���� �ٲٴ� ���� ������ ���� �� �ֱ� ����
	������ �������̰ų� �迭�� ���� �ּ��̹Ƿ� �Է����� �ʾƵ� �ȴ�
	���� �ּ�ó���� Ŀ�带 �����ϸ� ���� ������ �ʴ´�
*/