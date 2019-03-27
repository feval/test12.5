#include<stdio.h>
#include<stdlib.h>

int islittleend() {
	int num = 0x11223344;
	char*p = (char*)&num;
	if (*p == 0x11) {
		return 0;
	}
	return 1;
}
int main() {
	int a = 0xffffff00;
	printf("%d\n", a);
	//unsigned int i;
	//for (i = 9; i >= 0; --i) {
	//	printf("%u\n", i);
	//}

	//char a = 128;
	//printf("%u\n", a);

	system("pause");
	return 0;
}