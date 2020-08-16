#include <stdio.h>
int isprime(int n);
int main(void)
{
    int begin, end;
    int i, j = 3, k = 1;
    int first, second;
    int prime[1000];
    prime[0] = 2;
    scanf("%d %d", &begin, &end);
    printf("GOLDBACH'S CONJECTURE:\nEvery even number n >= 4 is the sum of two primes.\n");
    for (i = begin; i <= end; i++)
    {
        if (i % 2 != 0)
            continue;
        for (; j < i; j++)
            if (j % 2 != 0 && isprime(j))
                prime[k++] = j;
        for (first = 0; first < k; first++)
        {
            for (second = 0; second < k; second++)
                if (i == prime[first] + prime[second])
                {
                    printf("%d=%d+%d\n", i, prime[first], prime[second]);
                    break;
                }
            if (i == prime[first] + prime[second])
                break;
        }
    }
    return 0;
}
int isprime(int n)
{
    int i;
    for (i = 2; i * i < n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}