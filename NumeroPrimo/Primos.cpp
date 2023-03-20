#include <iostream>

using namespace std;

bool primo(int n)
{
    int i, cont = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int A, B, i;
    cin >> A >> B;
    for (i = A; i <= B; i++)
    {
        if (primo(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}