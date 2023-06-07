#include <iostream>
#include <math.h>

using namespace std;

struct ponto{
    float x;
    float y;
};

int main()
{
    ponto p;
    float d;
    cout << "Digite a coordenada X do ponto: ";
    cin >> p.x;
    cout << "Digite a coordenada Y do ponto: ";
    cin >> p.y;
    d = sqrt(pow(p.x,2) + pow(p.y,2));
    cout << "A distancia do ponto ate a origem e: " << d << endl;
    return 0;
}