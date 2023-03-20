#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Hora: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    return 0;
}