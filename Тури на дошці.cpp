#include <iostream>

using namespace std;

const int Nmax=9000;
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

TLong multy(TLong & a, TLong & b)
{
    TLong res;
    int S=0,p=0;
    if (b.sign == a.sign)
        res.sign='+';
    else res.sign='-';
    for (int i=Nmax-1;i>=Nmax-b.len-1;--i)
        for (int j=Nmax-1; j>=Nmax-a.len-1;--j)
        {
            S=a.digit[j]*b.digit[i]+p+res.digit[i+j-Nmax+1];
            p=S/10;
            res.digit[i+j-Nmax+1]=S%10;
        }

    res.len=Lenlong(res);
    return res;
}

int comp_abs(TLong & a, TLong & b)
{
    if (a.len > b.len) return 1;
    if (a.len < b.len) return -1;
    for (int i=Nmax-a.len; i<Nmax; ++i)
    {
        if (a.digit[i] > b.digit[i]) return 1;
        if (a.digit[i] < b.digit[i]) return -1;
    }
    return 0;
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

TLong fact(TLong&a,TLong propusk)
{
   TLong one,b,factorial;
   one.digit[Nmax-1]=1;
   b=one;
   factorial=a;
   while (comp_abs(a,b)==1)
   {
        if (comp_abs(b,propusk)>0)
           factorial=multy(factorial,b);
        b=add_abs(b,one);
   }
   return factorial;
}


TLong sub_abs(TLong&a,TLong&b)
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


int main()
{
    TLong K,N,res,sub_N;
    input_long(K);
    input_long(N);
    if (comp_abs(N,K)==1)
    {
        sub_N=sub_abs(N,K);
        res=fact(N,sub_N);
    }
    else
    {
        sub_N=sub_abs(K,N);
        res=fact(K,sub_N);
    }
    output_long(res);
    return 0;
}
