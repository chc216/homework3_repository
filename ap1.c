#include <stdio.h>
#include <stdlib.h>

void main() {
    printf("[-----[최 현 철]    [2022078014]-----]");
    int list[5];    //int형 배열을 선언합니다.
    int *plist[5] = {NULL,};    //포인터 배열을 선언합니다. 모든 요소의 값을 NULL값으로 초기화 합니다.

    plist[0] = (int *)malloc(sizeof(int));  //plist[0]은 int형 포인터이므로 int크기만큼을 동적할당 받아 해당 메모리 주소를 저장합니다.
    list[0] = 1;    
    list[1] = 100;  //배열 list의 0,1번째 요소에 1과 100을 각각 대입합니다.
    *plist[0] = 200;    //plist[0]이 가리키고 있는 곳에 200을 저장합니다.

    printf("list[0]         = %d\n", list[0]); //list[0]의 값을 참조하여 출력합니다. 출력값은 1입니다.
    printf("&list[0]        = %p\n", &list[0]);//요소 List[0]의 메모리상 주소를 출력합니다.
    printf("list            = %p\n", list);    //배열 이름은 배열의 시작주소이므로 배열의 시작주소를 출력합니다.
    printf("&list           = %p\n", &list);   //주소연산자를 통해 배열의 시작주소를 출력합니다. 모두 동일한 주소가 출력됩니다.

    printf("----------------------------------------\n\n");

    printf("list[1]         = %d\n", list[1]);  //요소 List[1]의 값을 출력합니다. 출력값은 100입니다.
    printf("&list[1]        = %p\n", &list[1]); //list[1]의 메모리상 주소를 출력합니다.
    printf("*(list+1)       = %d\n", *(list + 1));  //list는 배열의 시작주소이므로 배열의 시작주소에서 해당 자료형 하나의 크기만큼 더한 주소값을 역참조합니다. 출력값은 100입니다.
    printf("list+1          = %p\n", list+1);       //배열의 시작주소에서 4byte를 더한 주소가 출력됩니다.

    printf("----------------------------------------\n\n");

    printf("*plist[0]       = %d\n", *plist[0]);    //포인터 plist[0]이 갖고 있는 주소를 통해 역참조합니다. 출력값은 200입니다.
    printf("&plist[0]       = %p\n", &plist[0]);    //포인터 배열의 요소 plist[0]이 메모리상에서 저장된 주소를 출력합니다.
    printf("&plist          = %p\n", &plist);       //포인터 배열의 시작주소를 출력합니다.  
    printf("plist           = %p\n", plist);        //위와 동일하게 포인터 배열의 시작주소를 출력합니다.
    printf("plist[0]        = %p\n", plist[0]);     //동적할당을 통해 받은 주소값을 출력합니다.
    printf("plist[1]        = %p\n", plist[1]);     //NULL값으로 초기화를 했으므로 모두 0x0이 출력됩니다.
    printf("plist[2]        = %p\n", plist[2]);     //위와동일
    printf("plist[3]        = %p\n", plist[3]);
    printf("plist[4]        = %p\n", plist[4]);

    free(plist[0]); //포인터 배열의 요소 plist[0]에 동적할당을 받았으므로 할당받은 해당 메모리 주소를 free해주어야합니다.
}
