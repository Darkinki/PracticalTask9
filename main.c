#include <stdio.h>
#include <stdlib.h>
#include "mathAddition.h"

int main()
{
    srand(time(NULL));

    long long int P, G, x, a, y, k, r, s, Hm, u1, u2, v;

    do
    {
        P = rand() % 30 + 1;
    } while (P <= 2);

    G = primitive(P);
    a = rand() % 30 + 1;
    y = power(G, a, P);
    k = rand() % 30 + 1;
    r = power(G, k, P);
    Hm = rand() % 30 + 1;

    s = (Hm - a * r) * power(k, P - 2, P - 1) % (P - 1);
    u1 = Hm * power(s, P - 2, P - 1) % (P - 1);
    u2 = r * power(s, P - 2, P - 1) % (P - 1);
    v = (power(G, u1, P) * power(y, u2, P)) % P;

    printf("Digital signature El-Gamal\n\n");
    printf("Signature: (%lld,%lld)\n", r, s);
    printf("Testing: %lld\n", v);

    return 0;
}
