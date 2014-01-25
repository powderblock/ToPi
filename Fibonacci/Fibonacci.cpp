#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long a = 1;
unsigned long b = 0;
unsigned long c;

int main()
{
for (int i = 0; i < 100; ++i)
{
cout << "\n" << a;
c = a + b;
b = a;
a = c;
}
}