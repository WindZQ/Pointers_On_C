#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *init_alp(char *temp)
{
    int i;
    char alp = 'A';
    for(i = 0; i < 26; ++i)
    {
        *(temp + i) = alp;
        alp++;
    }
    *(temp + i) = '\0';
    return temp;
}

int prepare_key(char *key)
{
    int i = 0, j = 0, k = 0;
    char alp[27];
    char *temp = alp;

    char *p = NULL;
    if(NULL == key)
        return 0;

    for(i = 0; *(key + i) != '\0'; ++i)
    {
        if(!(isalpha(*(key + i))))
            return 0;
    }

    for(i = 0; *(key + i) != '\0'; ++i)
    {
        if(*(key + i) != ' ')
        {
            for(j = i + 1; *(key + j) != '\0'; ++j)
            {
                if(*(key + i) == *(key + j))
                    *(key + j) = ' ';
            }
            *(key + k) = toupper(*(key + i));
            k++;
        }
    }
    *(key + k) = '\0';
    temp = init_alp(temp);
    p = temp;
    while((p = (strpbrk(p, key))) != NULL)
    {
        *p = ' ';
        p++;
    }

    for(i = 0, k = 0; *(temp + i) != '\0'; ++i)
    {
        if(*(temp + i) != ' ')
        {
            *(temp + k) = *(temp + i);
            k++;
        }
    }
    *(temp + k) = '\0';
    key = strcat(key, temp);
    return 1;
}

void encrypt(char *data, char const *key)
{
    int i, state;
    char temp[27];
    char *init = NULL;
    char *p = NULL;
    char chg;

    init = init_alp(temp);

    for(i = 0; *(data + i) != '\0'; ++i)
    {
        if(isalpha(*(data + i)))
        {
            if(isupper(*(data + i)))
                state = 1;
            else
            {
                *(data + i) = toupper(*(data + i));
                state = 0;
            }
            p = strchr(init, *(data + i));
            chg = *(key + (p - init));
            *(data + i) = state ? chg : tolower(chg);
        }
    }
}

void decrypt(char *data, char const *key)
{
    int i, state;
    char temp[27];
    char *init = NULL;
    char *p = NULL;
    char chg;

    init = init_alp(temp);

    for(i = 0; *(data + i) != '\0'; ++i)
    {
        if(isalpha(*(data + i)))
        {
            if(isupper(*(data + i)))
                state = 1;
            else
            {
                *(data + i) = toupper(*(data + i));
                state = 0;
            }
            p = strchr(key, *(data + i));
            chg = *(init + ( p - key));
            *(data + i) = state ? chg : tolower(chg);
        }
    }
}

int main()
{
    char key[28] = "Hellomnnnnab";
    char temp[28];
    char *key_m = temp;
    char data[] = "Hello world!";

    key_m = init_alp(key_m);
    printf("%s\n", key);
    if(prepare_key(key))
    {
        printf("\nAlpha:");
        printf("%s\n", key_m);
        printf("Key:");
        printf("%s\n", key);

        printf("\nEncode:");
        printf("%s\n", data);
        encrypt(data, key);
        printf("%s\n", data);

        printf("\nDecode:");
        printf("%s\n", data);
        decrypt(data, key);
        printf("%s\n", data);
    }
    else
        printf("Key error!\n");
    return 0;
}
