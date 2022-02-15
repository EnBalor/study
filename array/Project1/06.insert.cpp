#include <stdio.h>
#include <string.h>

char a[16] = "abcdef";

void insert(int position, char ch)
{
	printf("�ʱ� : %s\n", a);
	memmove(a + position + 1, a + position, strlen(a) - position + 1);
	a[position] = ch;
	printf("g���� : %s\n", a);
}

void Delete(int position)
{
	memmove(a + position, a + position + 1, strlen(a) - position);
	printf("c���� : %s\n", a);
}

void append(char ch)
{
	insert(strlen(a), ch);
	printf("h�߰� : %s\n", a);
}

void main()
{
	insert(3, 'g');
	append('h');
}

/*
	�迭�� �߰��� ���ҵ��� �����ϰ��� �ϴ� ��� ���ҵ��� �̵�������� �Ѵ�.
	memmove�� �߶󳻰� �ٿ��ִ°� �ƴ� �����ϴ� ����� �����µ� memcopy�ʹ� �ٸ� ������Ѵ�.
	memcpy�� �ٷ� �����ؼ� �ٿ�������
	memmove�� ���ۿ� �����ϰ� ���ۿ� ����� ���� �ٿ��ִ� ������ �����ȴ�. ���⼭ ���۴� �ӽ�����Ҷ�� �����ϸ� �ȴ�.
	memcpy�� ���������� ���������� memmove�� �������� �� ����.

	void* memmove(void* dest, const void* src, size_t num) ���·�
	dest�� ������ ���� �ٿ����� �޸𸮸� ����Ű�� ������(������)
	src�� ������ �޸𸮸� ����Ű�� ������(�����)
	size_t num�� ������ ���̷� ù��° ������ dest�� �ٿ��ִ´�.
	������ ��ġ ���ĸ� �ڿ������� ������ ������� �������� ������ �� ���� �� ������ ������ �� �ִ�.
	���Ե� ��ġ ������ ���ڵ��� �̵����� ���Ұ� �� ������ ����� ����ϴµ�
	�迭 ���κ��� �Է��� �ڸ� ������ �迭 + �Է��ڸ��� �� ���ĺ��ʹ� �� ĭ�� �̵��ؾ� �ϴ� �迭 + �Է��ڸ� + 1�� �ȴ�.

*/