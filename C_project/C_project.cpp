#include <stdio.h>

void squeeze(char s1[], char s2[]);
void getline(char line[], int maxline);

int main() {
    char main[1000];
    char cutout[1000];

    printf("print first string:\n");
    getline(main, 1000);
    printf("print second string:\n");
    getline(cutout, 1000);
    squeeze(main, cutout);
    printf("after cutout:\n");
    printf("%s", main);

    printf("\r\nInput some text for EXIT!");
    char a;
    scanf("{}", a);
}

void squeeze(char main[], char cutout[]) {
    int i, j, k;
    k = 0;
    for (k = 0; cutout[k] != '\0'; k++) {
        for (i = j = 0; main[i] != '\0'; i++) {
            if (main[i] != cutout[k]) {
                main[j++] = main[i];
            }
        }
        main[j] = '\0';
    }
}

void getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}
