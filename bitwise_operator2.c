#include <stdio.h>

void find_maximums(int n, int k) {
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int and_result = i & j;
            int or_result = i | j;
            int xor_result = i ^ j;

            if (and_result < k && and_result > max_and) {
                max_and = and_result;
            }

            if (or_result < k && or_result > max_or) {
                max_or = or_result;
            }

            if (xor_result < k && xor_result > max_xor) {
                max_xor = xor_result;
            }
        }
    }

    printf("%d\n",max_and);
    printf("%d\n",max_or);
    printf("%d\n",max_xor);
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    find_maximums(n, k);

    return 0;
}
