#include <iostream>

using namespace std;

const int Nmax=6000;
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
        a.sign='+';
    if (a.sign=='-') cout<<'-';
    for (int i=Nmax-a.len; i<Nmax; ++i)
        cout << a.digit[i];
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

int comp(TLong & a, TLong & b)
{
    if (a.sign!=b.sign)
    {
        if (a.sign=='-') return -1;
        return 1;
    }
    if (a.sign=='+') return comp_abs(a,b);
    return -comp_abs(a,b);
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
    return res;
}

TLong sub(TLong & a, TLong & b)
{
    TLong res;
    if (a.sign!=b.sign)
    {
        res=add_abs(a,b);
        if (a.sign == '+')
            res.sign='+';
        else res.sign='-';
    }
    else
    {
        if (comp_abs(a,b)==1)
           res=sub_abs(a,b);
        else res=sub_abs(b,a);

        if (comp(a,b)!=-1)
            res.sign='+';
        else res.sign='-';

    }
    return res;
}

TLong add(TLong & a, TLong & b)
{
    TLong res;
    if (a.sign == b.sign)
    {
        res=add_abs(a,b);
        if (a.sign == '+')
            res.sign='+';
        else res.sign='-';
    }
    else
    {
        b.sign=a.sign;
        res=sub(a,b);
    }
    return res;
}

void zero(TLong&a)
{
    for (int j=0; j<Nmax; j++)
        a.digit[j]=0;
}

TLong chisla_fi2(int mas[],int N,TLong&a)
{
    TLong b,memory;
    if (mas[0])
        b.digit[Nmax-1]=1;
    if (mas[1])
        a.digit[Nmax-1]=1;
    for (int i=2;i<N;++i)
    {
        memory=a;
        if (mas[i])
            a=add(a,b);
        else
            zero(a);
        b=memory;
    }
}

void inp_mas(int mas[],int&N)
{
    cin >> N;
    for (int i=0;i<N;i++)
        cin >> mas[i];
}


int mas[10000];
int main()
{
    TLong a,b,res;
    int N;
    inp_mas(mas,N);
    chisla_fi2(mas,N,a);
    output_long(a);
    return 0;
}
