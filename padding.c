#include <stdio.h>

struct student { //문자열, 정수를 저장할 수 있는 구조체를 정의한다.
    char lastName[13];
    int studentId;
    short grade;
};

int main() {

    printf("[-----[최 현 철]    [2022078014]-----]");
    struct student pst;

    printf("size of student = %ld\n", sizeof(struct student));    /* 13 bytes */    //선언한 구조체 자료형의 크기를 출력한다. 19바이트가 출력될 것으로 예상되지만 패딩에 의해 24바이트가 출력된다.
    printf("size of int = %ld\n", sizeof(int));                  /* 4 bytes */      //4바이트가 출력된다.
    printf("size of short = %ld\n", sizeof(short));             /* 2 bytes */       //2바이트가 출력된다.

    return 0;
}
