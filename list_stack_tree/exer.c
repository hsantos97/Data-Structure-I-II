#include<stdio.h>
int main()
{
	int x, y;
	printf("informe dois numeros\n");
	scanf("%d %d", &x, &y);
	for(x;x<=y;x++)
		printf("%d ", x);
	return 0;
}
