#include <bits/stdc++.h>

using namespace std;

const int Nmax=10000;
struct Tlong
{
	char sign='+';
	int len=1;
	int digit[Nmax]={0};
};

void input_long(Tlong &a)
{
	string S;
	cin>>S;
	if (S[0]=='+'||S[0]=='-')
	{
		a.sign = S[0];
		S.erase(0, 1);
	}
	a.len = S.size();
	for (int i = 0; i < Nmax; i++)
		a.digit[i] = 0;
	for (int i=0;i<S.size(); i++)
		a.digit [Nmax - a.len + i]=S[i]-48;
}

void output_long(Tlong &a)
{
	if (a.len==1 && a.digit[Nmax-1]==0)
		cout<<0;
	if (a.sign=='-') cout<<'-';
	for (int i = Nmax - a.len; i< Nmax; ++i)
		cout<<a.digit[i];
}

int comp_abs(Tlong &a,Tlong &b)
{
	if (a.len > b.len) return 1;
	if (a.len < b.len) return -1;
	for (int i = Nmax -a.len; i<Nmax; ++i)
	{
		if (a.digit[i]>b.digit[i]) return 1;
		if (a.digit[i]<b.digit[i]) return -1;
	}
	return 0;
}

int comp (Tlong &a, Tlong &b)
{
	if (a.sign!=b.sign)
	{
		if (a.sign == '-') return -1;
		return 1;
	}
	if (a.sign == '+') return comp_abs(a, b);
		return -comp_abs(a,b);
}

int Lenlong(Tlong &a)
{
	int i = 0;
	while (i<Nmax-1 && a.digit[i]==0) ++i;
	return Nmax-i;
}


Tlong divhalf(Tlong &a, int b)
{
	Tlong res;
	int ost = 0;
	if(a.sign=='+' && b>0||a.sign=='-' && b<0)
		res.sign='+';
	else
		res.sign='-';
	b = abs(b);
	for (int i = Nmax - a.len ; i<Nmax;i++)
	{
		ost = ost *10 +a.digit[i];
		res.digit[i] = ost/b;
		ost %= b;
	}
	res.len=Lenlong(res);
	return res;
}

int main()
{
	Tlong a,b;
	int N;
	cin >> N ;
	input_long(a);
	input_long(b);
	while (comp(a,b)!=0)
	{
		if (comp(a,b)==1)
			a=divhalf(a,2);
		else
			b=divhalf(b,2);
	}
	output_long(a);
}
