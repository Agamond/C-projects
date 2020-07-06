#include <stdio.h>

#define MAXLINE 1000

void escape(char s[MAXLINE], char t[MAXLINE]) {
    int i = 0;
    int c = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[c] = '1';
                c++;
                s[c] = 'n';
                c++;
                i++;
                break;
            case '\t':
                s[c] = '1';
                c++;
                s[c] = 't';
                c++;
                i++;
                break;
            default:
                s[c] = t[i];
                i++;
                c++;
                break;
        }
    }
}

void getline(char s[]) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}

int main() {
    char text[MAXLINE] ={0,};
    char changed_text[MAXLINE]={0,};

    while (1) {
        printf("print your text:\n");
        getline(text);
        if (text[0] == 'e' && text[1] == 'n' && text[2] == 'd') {
            break;
        }
        escape(changed_text, text);
        printf("Your text has been changed:\n");
        printf("%s", changed_text);
        printf("\n");
        for (int i= 0; i<=sizeof(changed_text);i++)
            changed_text[i]=0;
        for (int i= 0; i<=sizeof(text);i++)
            changed_text[i]=0;
    }
    return 0; 
}