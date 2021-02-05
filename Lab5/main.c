#include <stdio.h>
int main (void) {
    no5();
    no6();
    no8();
}

int no5() {
     printf("Question No.5\n\n");

    int i = 0;
    while (i>=0) {
        i += 1;
    }
    printf("%d\n",i);
    printf("---------------------------------\n\n");
    return i;
}

int no6() {
     printf("Question No.6\n\n");

    int i = -1;
    while (i<0) {
        i -= 1;
    }
    printf("%d\n",i);
    printf("---------------------------------\n\n");
    return i;
}

int no8() {
     printf("Question No.8\n\n");

    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n");
    printf("---------------------------------\n\n");

    return 0;
}




