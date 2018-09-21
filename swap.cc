#include <iostream>
using namespace std;

int x = 6, y = 4;
void swap(int &a, int &b){
    x += y;
    y = x - y;
    x = x - y;

}

int main ()
{
    swap(x, y);
    cout << x << " " << y << endl;

    return 0;
}
