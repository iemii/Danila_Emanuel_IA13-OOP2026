#include <stdio.h>
using namespace std;
int main()
{
    char s[100];
    int x, i, uc, suma = 0;
    FILE* fin;
    fin = fopen("ini.txt", "r");
    while (fgets(s, 100, fin))
    {
        x = 0;
        i = 0;
        while (s[i] != NULL)
        {
            uc = s[i] - '0';
            x = x * 10 + uc;
            i = i + 1;
        }
        suma = suma + x;
    }
    fclose(fin);
    printf("%d", suma);

}
