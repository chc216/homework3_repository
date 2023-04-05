#include <stdio.h>

struct student1 {   //struct키워드를 이용해 student1의 태그를 가진 구조체를 정의한다.
    char lastName;
    int studentId;
    char grade;
};

typedef struct {    //struct키워드와 typedef를 이용하여 구조체 정의와 동시에 해당 자료형을 student2로 정의한다.
    char lastName;
    int studentId;
    char grade;
} student2;

int main() {
    struct student1 st1 = {'A', 100, 'A'};  //구조체 변수 st1선언과 동시에 구조체 멤버에 값을 대입한다.
    printf("st1.lastName = %c\n", st1.lastName);
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);  //각각 멤버를 참조하여 값을 출력한다.

    student2 st2 = {'B', 200, 'B'}; //구조체 변수 st2선언과 동시에 구조체 멤버에 값을 대입한다.
    printf("\nst2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);  //각각 멤버를 참조하여 값을 출력한다.

    student2 st3;

    st3 = st2;  //구조체 변수 st3에 st2값을 모두 대입한다. st2, st3의 각 멤버의 값은 모두 동일하다.

    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade = %c\n", st3.grade);  //st3의 멤버를 각각 참조하여 값을 출력한다.

    /* equality test */
    //if(st3 == st2) /* not working */
    if(st3.lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade) //각각의 멤버를 비교하여 모두 동일하면 equal를 출력하도록 한다.
        printf("equal\n");
    else
        printf("not equal\n");

    return 0;
}
