#include <bits/stdc++.h>
using namespace std;
double a;
int b, c, d;
int main(int argc, char** argv){
    scanf("%lf��", &a);
    b = a;
    c = (a - b) * 60;
    d = ((a - b) * 60 - c) * 60;
    if(b != 0)cout << b << "��"; 
    if(c != 0)cout << c << "��";
    if(d != 0)cout << d << "��";
    cout << endl;
    system("pause > nul");
    return 0;
}