#include <iostream>

using namespace std;

const long long Nmax=10000;
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

int Lenlong(TLong & a)
{
    int i=0;
    while (i<Nmax-1 && a.digit[i]==0) ++i;
    return Nmax-i;
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

void zero(TLong&a)
{
    for (int i=0; i<Nmax; i++)
        a.digit[i]=0;
}
TLong multy(TLong & a, TLong & b)
{
    TLong res;
    int S=0,p=0;
    if (b.sign == a.sign)
        res.sign='+';
    else res.sign='-';
    for (int i=Nmax-1; i>=Nmax-b.len-1; --i)
        for (int j=Nmax-1; j>=Nmax-a.len-1; --j)
        {
            S=a.digit[j]*b.digit[i] + p + res.digit[i+j - Nmax +1];
            p=S/10;
            res.digit[i+j-Nmax+1]=S%10;
        }

    res.len=Lenlong(res);
    return res;
}

int main()
{
    TLong a,b,res,etalon,sum;
    int N,K,max_ind=0;
    etalon.digit[Nmax-1]=0;
    sum.digit[Nmax-1]=1;
    cin >> N >> K;
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=K;j++)
        {
            input_long(a);
            sum=multy(sum,a);
        }
        if (comp_abs(sum,etalon)==1 || comp_abs(sum,etalon)==0)
        {
            etalon=sum;
            max_ind=i;
        }
        zero(sum);
        sum.digit[Nmax-1]=1;
    }
    cout << max_ind;
}
