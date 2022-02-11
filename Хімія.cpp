#include <iostream>

using namespace std;

const unsigned int Nmax=10000;
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
    if(a.len == 1 && a.digit[Nmax-1] == 0)
           a.sign='+';
}

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

TLong sub_abs(TLong & a, TLong & b)
{
    TLong res;
    int S=0,p=0;
    for (int i=Nmax-1;i>=0;--i)
    {
        S=a.digit[i] - b.digit[i] - p;
        if (S<0)
        {
            res.digit[i]=S+10;
            p=1;
        }
        else
        {
            res.digit[i]=S;
            p=0;
        }
    }
    res.len=Lenlong(res);
    res.sign='+';
    return res;
}

TLong add_abs(TLong & a, TLong & b)
{
    TLong res;
    int S=0,p=0;
    for (int i=Nmax-1;i>=0;--i)
    {
        S=a.digit[i]+b.digit[i] + p;
        res.digit[i]=S%10;
        p=S/10;
    }
    res.len=Lenlong(res);
    res.sign='+';
    return res;
}


TLong fibanachi(int N)
{
    TLong a,b;
    a.digit[Nmax-1]=1;
    b.digit[Nmax-1]=1;
    for (int i=0;i<N;i++)
    {
        a=add_abs(a,b);
        b=sub_abs(a,b);
    }
    return a;

}

int main()
{
    TLong a,b,res;
    int N;
    cin >> N;
    res=fibanachi(N);
    output_long(res);
    return 0;
}
