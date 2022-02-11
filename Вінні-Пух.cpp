#include <iostream>

using namespace std;

const int Nmax=100006;
struct TLong
{
    char sign='+';
    int len=1;
    int digit[Nmax]={0};
};


void input_long(TLong & a)
{
    string S;
    cin >> S;
    if (S[0]=='+' || S[0]=='-')
    {
        a.sign=S[0];
        S.erase(0,1);
    }
    a.len=S.size();
    for (int i=0; i<Nmax; i++)
        a.digit[i]=0;
    for (int i=0; i<S.size(); i++)
        a.digit[Nmax-a.len+i]=S[i]-48;
}

void output_long(TLong & a)
{
    if (a.len==1 && a.digit[Nmax-1]==0)
        cout<<0;
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

TLong div_half(TLong & a, int b)
{
    TLong res;
    int ost=0;
    if ((b < 0 && a.sign == '-') || (b>0 && a.sign == '+'))
        res.sign='+';
    else res.sign='-';
    b=abs(b);
    for (int i=Nmax-a.len; i<Nmax; ++i)
    {
        ost=ost*10 + a.digit[i];
        res.digit[i]=ost/b;
        ost%=b;
    }
    res.len=Lenlong(res);
    return res;
}

int modhalf(TLong & a, int b)
{
    TLong res;
    int ost=0;
    b=abs(b);
    for (int i=Nmax-a.len; i<Nmax; ++i)
    {
        ost=ost*10 + a.digit[i];
        res.digit[i]=ost/b;
        ost%=b;
    }
    return ost;
}


int main()
{
    TLong a,res;
    long long N;
    input_long(a);
    cin >> N;
    if (modhalf(a,N)!=0)
       cout << modhalf(a,N);
    else cout << N;
    return 0;
}
