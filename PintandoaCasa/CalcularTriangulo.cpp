//calcular a área de um triângulo a partir do tamanho de seus lados

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    float a, b, c, p, area;
    cin >> a;
    cin >> b;
    cin >> c;
    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << fixed << setprecision(2) << area << endl;
    return 0;
}