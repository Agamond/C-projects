#include <stdio.h>

#define MAXLINE 1000

void escape(char s[MAXLINE], char t[MAXLINE])
{
	int i = 0;
	int c = 0;

	while (t[i] != '\n')
	{
		switch (t[i])
		{
		case '\n': 
			s[c] = '\\';
			c++;
			s[c] = 'n';
			c++;
			break;
		case '\t':
			s[c] = '\\';
			c++;
			s[c] = 't';
			c++;
			break;
		default:
			s[i] = t[c];
			i++;
			c++;
			break;
		}
	}
}

void getline(char s[])
{
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


int main() 
{
	char text[MAXLINE];
	char changed_text[MAXLINE];
	

	while (1)
	{
		printf("print your text:\n");
		getline(text);
		if (text[0] == 'e' && text[1] == 'n' && text[2] == 'd')
		{
			return 0;
		}
		escape(changed_text, text);
		printf("Your text has been changed:\n");				
		printf("%s", changed_text);		
		printf("\n");
	}
}