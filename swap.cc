#include <iostream>
using namespace std;

int x = 6, y = 4;
void swap(int &a, int &b)
{
    int newx = b;

    y = x;
    x = newx;
    
}

int main ()
{
    swap(x, y);
    cout << x << " " << y << endl;

    return 0;
}
