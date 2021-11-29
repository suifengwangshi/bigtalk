#include "func.h"
#include "func.cpp"
#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = 2;
    int s = sum(a, b); 
    cout << a << " + " << b << " = " << s << endl;
    return 0;
}