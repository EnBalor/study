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
	변수 이름 앞에 &(엠퍼센드)를 붙이면 그 변수의 주소를 알려줌
	해당 변수가 어디에 저장되어 있는지를 나타냄
	scanf에 &을 사용하는데 이는 & 없이 실행할 경우
	변수에 입력하는 것이 아닌 임시 저장공간에 입력하고 그 변수에 임시 저장한값을 대입하고 대입한 값을 저장하고 임시 저장공간의 값을 지운다.
	scanf내에서 출력을 위해 값을 바꾸다 보면 문제가 생길 수 있기 때문
	변수가 포인터이거나 배열일 때는 주소이므로 입력하지 않아도 된다
	위의 주석처리된 커드를 실행하면 값은 변하지 않는다
*/