#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **x;    //int형 이중포인터 변수를 선언한다.

    printf("sizeof(x) = %lu\n", sizeof(x));     //이중포인터 변수의 크기를 출력한다.
    printf("sizeof(*x) = %lu\n", sizeof(*x));   //이중포인터 변수가 역참조할 메모리의 크기를 출력한다.
    printf("sizeof(*x) = %lu\n", sizeof(*x));   //이중포인터 변수가 역참조한 곳을 통해 역참조를 할 메모리의 크기를 출력한다. 모두 동일하게 8byte가 나온다.
    
}