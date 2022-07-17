#include <iostream>
using namespace std;

int main()
{
    clock_t t;
    t = clock();
    char text[] = "AABCAABCCABCABACBACBBACBACBACB";
    char pat[] = "CA";
    int m = strlen(text);
    int n = strlen(pat);
    int count = 0;
    int pres = 0;
    for (int i = 0; i < m - n; i++)
    {
        int k = i;
        for (int j = 0; j < n; j++)
        {
            if (text[k] == pat[j])
            {
                k++;
                count++;
                if (count == n)
                {
                    cout << "\nThe pattern is at index :" << i;
                    pres = 1;
                }
            }
            else
            {
                count = 0;
                break;
            }
        }
    }
    if (pres == 0)
    {
        cout << "The pattern is not found.";
    }
    t = clock() - t;
    cout << "\nThe time taken in seconds :" << (double)t / CLOCKS_PER_SEC;
    return 0;
}