//
// Created by Darkinki on 06.12.2023.
//

#ifndef PRACTICALTASK9_MATHADDITION_H
#define PRACTICALTASK9_MATHADDITION_H

#include <time.h>
#include <math.h>


long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

int primitive(long long int r)
{
    int array[1000], i, j, k, flag = 0, count;
    array[0] = array[1] = 0;

    for (i = 2; i < r; i++)
        array[i] = 1;

    for (i = 2; i * i <= r; i++)
        if (array[i])
            for (j = i; i * j < r; j++)
                array[i * j] = 0;

    i = 0;
    count = 0;

    while (array[i] != 0)
    {
        for (k = (r - 1) / 2; k > 0; k--)
            if (power(i, k, r) == 1)
                flag = 1;

        if (flag == 0)
            return i;

        i++;
        flag = 0;
    }
    return 3;
}


#endif //PRACTICALTASK9_MATHADDITION_H
