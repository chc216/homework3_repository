#include <stdio.h>

#define MAX_SIZE 100

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer;  //float형 배열 input과, 변수 answer를 전역으로 선언한다.
int i;  //int형 전역변수를 선언한다.

int main(void)
{
    for(i = 0; i < MAX_SIZE; i++)   //배열 Input에 0부터 99까지 각 요소에 대입한다.
        input[i] = i;

    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);    

    answer = sum1(input, MAX_SIZE); //전역변수 answer에 sum1함수의 리턴값을 저장한다. 인수로 배열 Input의 시작주소와 MAX_SIZE를 넘겼으므로 배열 Input요소들의 총합값이 반환된다.
//sum1가 호출되면서 함수의 printf가 실행된다.    
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);

    answer = sum2(input, MAX_SIZE); //전역변수 answer에 sum2함수의 리턴값을 저장한다. 인수로 배열 Input의 시작주소와 MAX_SIZE를 넘겼으므로 배열 Input요소들의 총합값이 반환된다.
    //sum2가 호출되면서 함수의 printf가 실행된다.
    //sum1에서 매개변수로 선언한 list[]와 sum2에서 매개변수로 선언한 포인터변수 list가 동일한 주소임을 알 수 있다. 즉, 메모리의 stack영역에선 stack변수가 재사용됨을 알 수 있다.
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);

    answer = sum3(MAX_SIZE, input); //전역변수 answer에 sum3함수의 리턴값을 저장한다. 인수로 MAX_SIZE와 배열 Input의 시작주소를 넘겼으므로 배열 Input요소들의 총합값이 반환된다.
//sum2가 호출되면서 함수의 printf가 실행된다.    
//sum1,2,3의 매개변수가 stack영역에서 재사용됨을 알 수 있다.
    printf("The sum is: %f\n\n", answer);

    return 0;
}

float sum1(float list[], int n) {   //매개변수로 float형 배열 포인터 ㅣist와 int형 변수 n을 선언한다. 각각 메모리상의 stack영역에 생성된다.
    printf("list \t= %p\n", list);  //배열 포인터 list가 인수로 넘겨받아 갖고 있는 배열의 주소를 출력한다.
    printf("&list \t= %p\n\n", &list);  //배열 포인터 List가 저장된 메모리상의 주소를 출력한다.

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++)  //변수 tempsum에 배열 list의 각 요소를 중첩하여 더한다.
        tempsum += list[i];
    return tempsum; //list의 총합을 반환한다.
}

float sum2(float *list, int n)  //매개변수로 float형 포인터변수와 int형 변수를 선언한다.
{
    printf("list \t= %p\n", list);  //인수로 넘겨받은 주소를 List에 저장했으므로 해당 값을 출력한다.
    printf("&list \t= %p\n\n", &list);  //메모리 stack영역에 저장된 포인터 변수 List의 주소를 출력한다.

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++)  //함수 sum1과 동일하다.
        tempsum += *(list + i);
    return tempsum;
}

/* stack variable reuse test */
float sum3(int n, float *list)  //함수 sum2와 매개변수가 순서만 바뀌었다. 
{
    printf("list \t= %p\n", list);  //인수로 넘겨받은 주소값을 출력한다.
    printf("&list \t= %p\n\n", &list);  //매개변수에서 선언된 포인터 변수의 메모리상 주소를 출력한다

    int i;
    float tempsum = 0;
    for(i = 0; i < n; i++)  //함수 sum1과 동일하다.
        tempsum += *(list + i);
    return tempsum;
}
