#include <stdio.h>
#include <string.h>
int i, j, k;
void intialization(int n, char a[n][20]) {
    printf("Enter student roll numbers separated by space : ");
    for (i = 0; i < n; i++) scanf("%s", a[i]);
    printf("\n");
}
void shell_sort(int n, char a[n][20]) {
    char temp[20];
    for (i = n / 2; i > 0; i /= 2) {
        for (j = i; j < n; j++) {
            strcpy(temp, a[j]);
            for (k = j; k >= i && strcasecmp(temp, a[k - i]) < 0;
                 k -= i)
                strcpy(a[k], a[k - i]);
            strcpy(a[k], temp);
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    char a[n][20];
    intialization(n, a);
    shell_sort(n, a);
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    return 0;
}
