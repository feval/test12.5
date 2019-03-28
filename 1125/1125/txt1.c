#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
extern int g_a;
main()
{
	int a,b;
	scanf("%d", &a);
	b = a > 60 ? 'A' : 'B';
	printf("%c", b);
    system("pause");
    return 0;
 }
    
    