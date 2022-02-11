#include <iostream>

using namespace std;

const int Nmax=10000;
struct TLong
{
    char sign='+';
    int len=1;
    int digit[Nmax]={0};
};



void output_long(TLong & a)
{
    if (a.len==1 && a.digit[Nmax-1]==0)
        a.sign='+';
    if (a.sign=='-') cout<<'-';
    for (int i=Nmax-a.len; i<Nmax; ++i)
        cout << a.digit[i];
}


int Lenlong(TLong & a)
{
    int i=0;
    while (i<Nmax-1 && a.digit[i]==0) ++i;
    return Nmax-i;
}

TLong multy_half(TLong & a, int b)
{
    TLong res;
    int S=0,p=0;
    if ((b < 0 && a.sign == '-') || (b>0 && a.sign == '+'))
        res.sign='+';
    else res.sign='-';
    b=abs(b);
    for (int i=Nmax-1; i>=0; --i)
    {
        S=a.digit[i]*b + p;
        res.digit[i]=S%10;
        p=S/10;
    }
    res.len=Lenlong(res);
    return res;
}


int main()
{
    TLong a,res;
    int N;
    a.digit[Nmax-1]=1;
    cin >> N;
    for (int i=1; i<=N; ++i)
        a=multy_half(a,i);
    output_long(a);
    return 0;
}
