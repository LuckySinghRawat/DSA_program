#include <stdio.h>
int main()
{
    int test, count1 = 0, count2 = 0, count3 = 0,count4 = 0,count5 = 0,count6 = 0, arr[3], flag;
    printf("Enter Test case : ");
    scanf("%d", &test);
    char parnth[test][50];
    printf("Enter opening or closing pranthese : \n");
    for (int j = 0; j < test; j++)
    {
        scanf("%s",parnth[j]);
    }
    for (int j = 0; j < test; j++)
    {
        for (int i = 0; parnth[j][i] != '\0'; i++)
        {
            if (parnth[j][i] == '(' )
            {
                count1++;
            }
            else if (parnth[j][i] == ')' )
            {
                count2++;
            }
            else if (parnth[j][i] == '{' )
            {
                count3++;
            }
            else if (parnth[j][i] == '}' )
            {
                count4++;
            }
            else if (parnth[j][i] == '[' )
            {
                count5++;
            }
            else if (parnth[j][i] == ']' )
            {
                count6++;
            }
        }
        if(count1==count2 && count3==count4 && count5==count6){
            pirntf("Balanced");
        }else{printf("Unbalanced");}
    }
}
