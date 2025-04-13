#include <iostream>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freespot;

public:
    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }

        next[S - 1] = -1;
        freespot = 0;
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }

        int index = freespot;
        freespot = next[index];

        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1; // or throw exception
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
