#include <stdio.h>
int main()
{
    int test, arr[3], flag;
    printf("Enter Test case : ");
    scanf("%d", &test);
    char parnth[test][50];
    printf("Enter opening or closing pranthese : \n");
    for (int j = 0; j < test; j++)
    {
        scanf("%s", parnth[j]);
    }
    for (int j = 0; j < test; j++)
    {
        int count1 = 0, count2 = 0;
        for (int i = 0; parnth[j][i] != '\0'; i++)
        {
            if (parnth[j][i] == '(')
            {
                count1++;
            }
            if (parnth[j][i] == ')')
            {
                count2++;
            }
        }
        if (count1 > count2)
        {
            printf("%d\n", count2 * 2);
        }
        else
        {
            printf("%d\n", count1 * 2);
        }
    }
}