#include <stdio.h>
#include <string.h>

char a[16] = "abcdef";

void insert(int position, char ch)
{
	printf("초기 : %s\n", a);
	memmove(a + position + 1, a + position, strlen(a) - position + 1);
	a[position] = ch;
	printf("g삽입 : %s\n", a);
}

void Delete(int position)
{
	memmove(a + position, a + position + 1, strlen(a) - position);
	printf("c삭제 : %s\n", a);
}

void append(char ch)
{
	insert(strlen(a), ch);
	printf("h추가 : %s\n", a);
}

void main()
{
	insert(3, 'g');
	append('h');
}

/*
	배열의 중간에 원소들을 삽입하고자 하는 경우 원소들을 이동시켜줘야 한다.
	memmove는 잘라내고 붙여넣는게 아닌 복사하는 기능을 가졌는데 memcopy와는 다른 기능을한다.
	memcpy는 바로 복사해서 붙여넣지만
	memmove는 버퍼에 복사하고 버퍼에 복사된 것을 붙여넣는 식으로 구현된다. 여기서 버퍼는 임시저장소라고 생각하면 된다.
	memcpy는 성능적으로 유리하지만 memmove가 안정성이 더 높다.

	void* memmove(void* dest, const void* src, size_t num) 형태로
	dest는 복사한 것을 붙여넣을 메모리를 가리키는 포인터(목적지)
	src는 복사할 메모리를 가리키는 포인터(출발지)
	size_t num은 복사할 길이로 첫번째 인자인 dest에 붙여넣는다.
	삽입할 위치 이후를 뒤에서부터 복사해 출발지와 목적지가 겹쳤을 때 복사 전 원본을 유지할 수 있다.
	삽입될 위치 이후의 문자들을 이동시켜 원소가 들어갈 공간을 만들어 줘야하는데
	배열 선두부터 입력할 자리 뒤쪽인 배열 + 입력자리고 이 이후부터는 한 칸씩 이동해야 하니 배열 + 입력자리 + 1이 된다.

*/