#include <iostream>

const int N = 40;

void sum(int &p, int n, int d[])

{

p = 0;

for(int i = 0; i < n; ++i)

p = p + d[i];

}

int main(){

int accum = 0;

int data[N];

for(int i = 0; i < N; ++i)

data[i] = i;

sum(accum, N, data);

cout << "sum is" << endl << accum;

return 0;

}