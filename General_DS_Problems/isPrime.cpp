/*
    #4amcodingclub
    It is easy to find if some number (say N) is prime or not. 
    You simply need to check if at least one number from numbers lower or equal to sqrt(n) 
    is a divisor of N.

    1. Brute Approach : isPrime_aproach01
    
    2. Brute Approach with small even number optimization : isPrime_aproach02
    Explanation:
    The code is almost similar to the previous version. Only at line 10, we checked if the n is even. Then, we return false.
    Also on line 12, we used the increment by 2 expression to skip every even number from 3 to sqrt(n).

    time complexity :  O(n*sqrt(n)). Can we do better?

    3. Approach 03 ( Optimization ) : Sieve of Eratosthenes
    Can we still do better?
    4. Approach 04
    5. Approach 05
*/

#include <iostream>
using namespace std;
#define FORREF
#ifndef FORREF

bool isPrime_approach01(int n)
{
    if (n == 1)
        return false; // by definition, 1 is not prime number
    if (n == 2)
        return true; // the only one even prime
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool isPrime_approach02(int n)
{
    if (n == 1)
        return false; // by definition, 1 is not prime number
    if (n == 2)
        return true; // the only one even prime
    if (n % 2 == 0) {
        // meaning if number is even it means it can't be prime
        return false;
    }

    for (int i = 3; i * i <= n; i += 2) // for odd number only
        if (n % i == 0)
            return false;
    return true;
}

int* p;

bool isPrime_approach03(int N)
{
    p = new int[N+1];

    for (int i = 2; i <= N; i++)
        p[i] = 1;

    for (int i = 2; i <= N; i++)
    {
        if (p[i])
            for (int j = 2 * i; j <= N; j += i)
                p[j] = 0;
    }
    p[1] = 0;
    p[0] = 0;
    return (p[N] == 1) ? true : false;
}

bool isPrime_Approach04(int N)
{
    p = new int[N + 3];
    for (int i = 3; i <= N; i++) {
        if (i % 2 == 0)
            p[i] = 0;
        else
            p[i] = 1;
    }
    for (int i = 3; i <= N; i += 2)
    {
        if (p[i])
            for (int j = i * i; j <= N; j += i)
                p[j] = 0;
    }
    p[2] = 1;
    p[1] = 0;
    p[0] = 0;
    return (p[N] == 1) ? true : false;
}


bool isPrime_Approach05(int N)
{
    p = new int[N + 3];
    for (int i = 3; i <= N; i += 2)
        p[i] = 1;

    for (int i = 3; i <= N; i += 2)
    {
        if (p[i])
            for (int j = i * i; j <= N; j += 2 * i)
                p[j] = 0;
    }
    p[1] = 0;
    p[0] = 0;
    p[2] = 1;
    return (p[N] == 1) ? true : false;
}

int main() {
    int n = 13;
    if (isPrime_Approach05(n))
        cout << "It is a Prime Number";
    else
        cout << "It is a Non-Prime Number";
    delete[]p;
}

#endif // !FORREF

