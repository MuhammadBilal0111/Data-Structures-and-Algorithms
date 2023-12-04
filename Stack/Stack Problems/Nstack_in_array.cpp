#include <iostream>
using namespace std;
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;
    int freespot;
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        // initializing top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // initializing next
        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }
        // update last index
        next[S - 1] = -1;
        // update freespot
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

        // insert element
        arr[index] = x;

        // update next;
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;
        return true;
    }
    bool pop(int m)
    {
        // check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;
        return arr[index];
    }
};
int main()
{
    return 0;
}