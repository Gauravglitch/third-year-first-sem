//unsigned binary multiplication
//security vunerability
#include<iostream>
#include<conio.h>
using namespace std;
long long add(long long,long long);
int main()
{
	int multiplicand,multiplier,lsb,sf=1; //sf=simplification factor
	long long ps=0;
	cout<<"enter the multiplicand:";
	cin>>multiplicand;
	cout<<"enter the multiplier:";
	cin>>multiplier;
	while(multiplier!=0)
	{
		lsb=multiplier%10;
		if(lsb)
		{
			ps=add(ps,sf*(long long)multiplicand);
		}
		sf*=10;
		multiplier/=10;
	}
	cout<<"the product is :"<<ps;
	getch();
	return 0;
}
long long add(long long b1, long long b2)
{
	int carry=0;
	long long sum=0,multi_f=1;
	while(b1!=0||b2!=0)
	{
		sum+=((b1%10+b2%10+carry)%2)*multi_f;
		carry=(b1%10+b2%10+carry)/2;
		b1/=10;
		b2/=10;
		multi_f*=10;
	}
    sum=carry*multi_f+sum;
	return sum;
}
//abba yei code ko logic lai array ko logic bata garnu 