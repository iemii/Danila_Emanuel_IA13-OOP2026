
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100], * p, a[20][20], aux[20];
    int n = 0;
    scanf("%[^\n]", s);
    p = strtok(s, " ");
    while (p)
    {
        strcpy(a[n], p);
        n = n + 1;
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l1 = strlen(a[i]);
            int l2 = strlen(a[j]);
            if (l1 < l2)
            {
                strcpy(aux, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], aux);
            }
            else
                if (l1 == l2)
                {
                    if (strcmp(a[i], a[j]) > 0)
                    {
                        strcpy(aux, a[i]);
                        strcpy(a[i], a[j]);
                        strcpy(a[j], aux);
                    }
                }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%s\n", a[i]);
}
