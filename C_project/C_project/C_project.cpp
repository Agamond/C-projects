#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int copy(char to[], char from[], int dlina);
char reverse(char s[]);

int main() 
{
    int current_text;               // Длина текущей строки 
    int max_symbol;                 // Кол-во символов необходимое для записи в самые длинные строки
    int longest_text;               // Текущая длина массива longest_buffer
    char current_buffer[MAXLINE];   // Текущая введенная строка
    char longest_buffer[MAXLINE];   // Все строки, длина которых превышает 5 символов
    char reverse_buffer[MAXLINE];
    int i;

    i = 0;
    longest_text = 0;
    max_symbol = 10;
    printf("Print you're text:\n");
    while ((current_text = getline(current_buffer, MAXLINE)) > 0) 
    {
        if (current_text < max_symbol)
        {
            for (i = 0; current_buffer[i] != '\n'; ++i)
            {
                reverse_buffer[i] = reverse(current_buffer);
            }
            printf("Reverse text:\n");
            printf("%s\n", reverse_buffer);
        }
        if (current_text > max_symbol) 
        {
            longest_text = copy(longest_buffer, current_buffer, longest_text);
        }
        printf("All texts more than 5 symbols:\n");
        printf("%s\n", longest_buffer);
        printf("Print you're text:\n");
        if (current_buffer[0] == 'e' && current_buffer[1] == 'n' && current_buffer[2] == 'd')
        {
            return 0;
        }
    }
}

int getline(char s[], int lim) 
{
    int c, i, sc;

    sc = 0;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
    {
        if (c == ' ') 
        {
            ++sc;
            if (sc < 2) 
            {
                ++sc;
                s[i] = c;
            }
            else
            {
                --i;
            }
        }
        else if (c == '\t')
        {
            ++sc;
            if (sc < 2)
            {
                ++sc;
                s[i] = c;
            }
            else
            {
                --i;
            }
        }
        else
        {
            sc = 0;
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int copy(char to[], char from[], int lenght) 
{
    int i;
    int p;

    p = 0;
    i = lenght;
    while (from[p] != '\0') {
        to[i] = from[p];
        ++i;
        ++p;
    }
    to[i] = '\0';
    return i;
}

char reverse(char s[])
{
    int i;
    int counter;
    char reverse[MAXLINE];

    counter = 0;
    for (i = 0; s[i] != '\n'; ++i)
    {
        ;
    }
    while (i >= 0)
    {
        reverse[counter] = s[i];
        ++counter;
        --i;
    }
}

