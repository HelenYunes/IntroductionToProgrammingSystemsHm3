#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int get_line(char s[]);
int getword(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

int get_line(char s[])
{
    int i = 0;
    char c = getc(stdin);
    while ((c != '\n') && (c != EOF) && (i < LINE))
    {
        s[i] = c;
        c = getc(stdin);
        i++;
    }
    s[i] = '\0';
    if (c != EOF)
        return ++i;

    return i;
}

int getword(char w[])
{
    char c = getc(stdin);
    int i = 0;
    while ((c != '\n') && (c != ' ') && (c != '\t') && (c != EOF) && (i < WORD))
    {
        w[i] = c;
        c = getc(stdin);
        i++;
    }
    w[i] = '\0';
    if (c != EOF)
        return ++i;
    return i;
}

int substring(char *str1, char *str2)
{
    // int length = strlen(s2);
    char *pointerToS2 = str2;
    while (*str1 != '\0')
    {
        str2 = pointerToS2;
        while (*str2 != '\0')
        {
            if (*str2 != *str1)
                break;
            str1++;
            str2++;
            if (*str2 == '\0')
                return 1;
        }
        str1++;
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    int sLength = strlen(s);
    int tLength = strlen(t);
    if ((sLength - tLength != n) || (sLength < tLength))
        return 0;
    while ((*s != '\0') && (*t != '\0'))
    {

        if (*s == *t)
        {
            t++;
            s++;
        }
        else
        {
            n--;
            s++;
        }
    }
    while ((*s != '\0') && (*t == '\0'))
    {
        s++;
        n--;
    }
    if (n == 0)
        return 1;
    return 0;
}
void print_lines(char *str)
{
    char l[LINE] = {'\0'};
    while (get_line(l) != 0)
    {
        if (substring(l, str))
            printf("%s\n", l);
    }
}

void print_similar_words(char *str)
{
    char w[WORD] = {'\0'};
    while (getword(w) != 0)
    {
        if (similar(w, str, 0) || similar(w, str, 1))
            printf("%s\n", w);
    }
}
int main()
{
    char w[WORD];
    char option;
    scanf(" %s", w);

    scanf(" %c", &option);

    if (option == 'a')
    {
        print_lines(w);
    }
    if (option == 'b')
    {
        print_similar_words(w);
    }
}
