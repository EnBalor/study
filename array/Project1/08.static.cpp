#include <stdio.h>

void increse()
{
	static int num = 0;

	printf("%d\n", num);

	num++;
}

int main()
{
	increse();
	increse();
	increse();
	increse();

	return 0;
}