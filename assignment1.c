#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array elements:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", (float)sum/n);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, max, min;

    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("Max = %d\nMin = %d", max, min);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;

    scanf("%d %d", &r, &c);

    int **A = (int**)malloc(r * sizeof(int*));
    int **B = (int**)malloc(r * sizeof(int*));
    int **sum = (int**)malloc(r * sizeof(int*));
    int **diff = (int**)malloc(r * sizeof(int*));

    for(int i = 0; i < r; i++) {
        A[i] = (int*)malloc(c * sizeof(int));
        B[i] = (int*)malloc(c * sizeof(int));
        sum[i] = (int*)malloc(c * sizeof(int));
        diff[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Enter Matrix A:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &B[i][j]);

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }

    printf("Addition:\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    printf("Subtraction:\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            printf("%d ", diff[i][j]);
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n;
    scanf("%d", &n);

    struct student *s = (struct student*)malloc(n * sizeof(struct student));

    for(int i=0;i<n;i++) {
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    for(int i=0;i<n;i++) {
        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }

    free(s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct emp {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, maxIndex = 0;

    scanf("%d", &n);
    struct emp *e = (struct emp*)malloc(n * sizeof(struct emp));

    for(int i=0;i<n;i++)
        scanf("%d %s %f", &e[i].id, e[i].name, &e[i].salary);

    for(int i=1;i<n;i++)
        if(e[i].salary > e[maxIndex].salary)
            maxIndex = i;

    printf("Highest Salary: %s %.2f", e[maxIndex].name, e[maxIndex].salary);

    free(e);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    char name[50];
};

int main() {
    struct record *r = NULL;
    int n = 0, choice;

    while(1) {
        printf("\n1.Add 2.Display 3.Delete 4.Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            n++;
            r = realloc(r, n * sizeof(struct record));
            scanf("%d %s", &r[n-1].id, r[n-1].name);
        }
        else if(choice == 2) {
            for(int i=0;i<n;i++)
                printf("%d %s\n", r[i].id, r[i].name);
        }
        else if(choice == 3) {
            int id, found = 0;
            scanf("%d", &id);

            for(int i=0;i<n;i++) {
                if(r[i].id == id) {
                    for(int j=i;j<n-1;j++)
                        r[j] = r[j+1];
                    n--;
                    r = realloc(r, n * sizeof(struct record));
                    found = 1;
                    break;
                }
            }
            if(!found) printf("Not found");
        }
        else {
            free(r);
            break;
        }
    }
    return 0;
}
#include <stdio.h>

union data {
    int i;
    float f;
    char c;
};

int main() {
    union data d;

    d.i = 10;
    printf("Integer: %d\n", d.i);

    d.f = 5.5;
    printf("Float: %f\n", d.f);

    d.c = 'A';
    printf("Char: %c\n", d.c);

    return 0;
}
#include <stdio.h>

union data {
    int i;
    float f;
    char c;
};

int main() {
    union data d;

    d.i = 10;
    printf("Integer: %d\n", d.i);

    d.f = 5.5;
    printf("Float: %f\n", d.f);

    d.c = 'A';
    printf("Char: %c\n", d.c);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n;
    scanf("%d", &n);

    struct student *s = malloc(n * sizeof(struct student));

    for(int i=0;i<n;i++)
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(s[i].marks > s[j].marks) {
                struct student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("Sorted by marks:\n");
    for(int i=0;i<n;i++)
        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);

    free(s);
    return 0;
}
