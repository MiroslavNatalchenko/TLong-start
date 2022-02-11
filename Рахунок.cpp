#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100000;

struct TLong
{
    int len=1;
    int digit[Nmax]={0};
};

void input_long(TLong&a)
{
    string S;
    cin >> S;
    a.len=S.size();
    for(int i=0;i<S.size();++i)
        a.digit[Nmax-a.len+i]=S[i]-48;
}

void output_long(TLong &a)
{
    for(int i=Nmax-a.len;i<Nmax;++i)
        cout << a.digit[i];
    cout << '\n';
}

void inc_1(TLong&a)
{
   int i=Nmax-1;
   while(a.digit[i]==9)
   {
      a.digit[i]=0;
      --i;
   }
   if(i<=Nmax-a.len-1)
   {
      i=Nmax-a.len-1;
      a.len++;
      a.digit[i]=1;
   }
   else
      ++a.digit[i];
}


int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   TLong a;
   int N;
   cin >> N;
   for (int i=0;i<N;++i)
   {
      input_long(a);
      inc_1(a);
      output_long(a);
   }
}
