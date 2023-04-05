#include <stdio.h>

void print_one(int *ptr, int rows);

int main() {
    int one[] = {0, 1, 2, 3, 4};    //int형 배열을 선언하여 초기화한다.
    printf("one     = %p\n", one);  
    printf("&one    = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);  //각각 배열의 시작주소, one[0]요소의 주소를 출력한다. 모두 동일한 값이 나온다.
    printf("\n");

    printf("------------------------------------\n");   
    printf(" print_one(&one[0], 5) \n");   
    printf("------------------------------------\n");
    print_one(&one[0], 5);  //배열 One[0]부터 one[4]까지 각각 주소와 요소의 값을 출력한다. 인수로 one[0]의 주소와 배열의 크기 5를 넘긴다.

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5);      //배열 One[0]부터 one[4]까지 각각 주소와 요소의 값을 출력한다. 인수로 배열의 시작주소와 배열의 크기 5를 넘긴다.

    return 0;
}

void print_one(int *ptr, int rows)  //매개변수로 int형 포인터, int형 변수를 선언한다.
{
    /* print out a one-dimensional array using a pointer */
    int i;
    printf("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); //인수로 배열의 주소를 넘겨받으면 매개변수 ptr을 이용하여 배열 인덱스가 0인 요소부터 인수로 넘겨받은 배열의 크기까지 포인터에 저장된 주소와 역참조를 통한 요소의 값을 출력한다.
    printf("\n");
}
