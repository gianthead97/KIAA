#include <stdio.h>



int main(int argc, char const *argv[])
{
    int niz[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &niz[i]);


    int i = 0;
    int j = n-1;
    while(i != j)
    {
        while(niz[i] == 0 && i != j)i++;
        while(niz[j] == 1 && i != j)j--;

        int tmp = niz[i];
        niz[i] = niz[j];
        niz[j] = tmp;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", niz[i]);
    return 0;
}
