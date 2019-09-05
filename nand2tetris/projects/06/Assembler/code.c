#include<stdio.h>
#include<stdlib.h>

char* destcode(char* mnem)
{
	char* ret = (char*)malloc(3*sizeof(char));
	int a=0, m=0, d=0, i;
	for(i=0; i<3; i++)
		ret[i]='0';
	for(i=0; mnem[i]!='\0'; i++)
	{
		if(mnem[i]=='A')a++;
		else if(mnem[i]=='M')m++;
		else if(mnem[i]=='D')d++;
	}
	if(a==1)ret[0]='1';
	if(d==1)ret[1]='1';
	if(m==1)ret[2]='1';
	return ret;
}

char* compcode(char* mnem)
{
	char* ret = (char*)malloc(7*sizeof(char));
	int a=0, m=0, d=0, one=0, zero=0, minus=0, not=0, plus=0, andb=0, orb=0, i;
	for(i=0; i<7; i++)ret[i]='0';
	for(i=0; mnem[i]!='\0'; i++)
	{
		if(mnem[i]=='A')a++;
		else if(mnem[i]=='M')m++;
		else if(mnem[i]=='D')d++;
		else if(mnem[i]=='1')one++;
		else if(mnem[i]=='0')zero++;
		else if(mnem[i]=='-')minus++;
		else if(mnem[i]=='!')not++;
		else if(mnem[i]=='+')plus++;
		else if(mnem[i]=='&')andb++;
		else if(mnem[i]=='|')orb++;
	}
	if(m==1)ret[0]='1';
	if(andb==1)return ret;
	if(orb==1)
	{
		for(i=2; i<=6; i+=2)
		{
			ret[i]='1';
		}
		return ret;
	}
	if(zero==1)
	{
		for(i=1; i<=5; i+=2)
		{
			ret[i]='1';
		}
		return ret;
	}
	if(one==1 && a==0 && m==0 && d==0)
	{
		for(i=1; i<=6; i++)
		{
			ret[i]='1';
		}
		if(minus)
		{
			ret[4]=ret[6]='0';
		}
		return ret;
	}
	if(((a^d)||(m^d))&&one)
	{
		ret[5]='1';
		if(d)
		{
			ret[3]=ret[4]='1';
			if(plus)
			{
				ret[2]=ret[6]='1';
			}
		}
		else
		{
			ret[1]=ret[2]='1';
			if(plus)
			{
				ret[4]=ret[6]='1';
			}
		}
		return ret;
	}
	if((a&&d)||(m&&d))
	{
		ret[5]='1';
		if(minus)
		{
			ret[6]='1';
			if(mnem[i-1]=='A' || mnem[i-1]=='M')
			{
				ret[2]='1';
			}
			else ret[4]='1';
		}
		return ret;
	}
	if(d)
	{
		ret[3]=ret[4]='1';
	}
	else
	{
		ret[1]=ret[2]='1';
		if(minus&&one)ret[3]='1';
	}
	if(minus)ret[5]='1';
	if((d||a||m)&&(not||minus))ret[6]='1';
	return ret;
}

char* jumpcode(char* mnem)
{
	char* ret = (char*)malloc(3*sizeof(char));
	int q=0, e=0, g=0, n=0, N=0, t=0, m=0, i;
	for(i=0; i<3; i++)ret[i]='0'+(i<2);
	for(i=0; mnem[i]!='\0'; i++)
	{
		if(mnem[i]=='Q')q++;
		else if(mnem[i]=='E')e++;
		else if(mnem[i]=='G')g++;
		else if(mnem[i]=='n')n++;
		else if(mnem[i]=='N')N++;
		else if(mnem[i]=='T')t++;
		else if(mnem[i]=='M')m++;
	}
	if(n)
	{
		ret[0]=ret[1]=ret[2]='0';
		return ret;
	}
	if(g||q)ret[0]='0';
	if(n||t||N)ret[1]='0';
	if(g||N||m)ret[2]='1';
	return ret;
}
