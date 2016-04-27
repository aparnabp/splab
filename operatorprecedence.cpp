#include <iostream>
#include <stack>
using namespace std;

float isp(char c)
{
	if((c=='+')||(c=='-'))
		return 2;
	else if((c=='*')||(c=='/'))
		return 4;
	else if(c=='^')
	return 4.5;
	else if(c=='(')
	return 0;
	else if(c==')')
	return 4;
	else if(c=='x')
	return 4;
	else if(c=='$')
	return 0;
}
float icp(char c)
{
	if((c=='+')||(c=='-'))
		return 1;
	else if((c=='*')||(c=='/'))
		return 3;
	else if(c=='^')
	return 4.6;
	else if(c=='(')
	return 5;
	else if(c==')')
	return 0;
	else if(c=='x')
	return 5;
	else if(c=='$')
	return 0;
}
int main()
{
	string s;
	char p;
	stack<char> ss;
	cout<<"\nenter the input";
	cin>>s;
	s=s+"$";
	ss.push('$');
	int l=s.length();
	cout<<"stack"<<"\tinput";
	for(int i=0;i<l;i++)
	{
		if((ss.top()=='$')&&(s[i]=='$'))
		{
			cout<<"\naccepted";
			return 0;
		}
		else if((ss.top()=='x')||(ss.top()==')'))
		{
			if((s[i]=='x')||(s[i]=='('))
			{
				cout<<"\n rejected1";
				return 0;
			}
		}
		else if((ss.top()=='(')&&(s[i]=='$'))
		{
			cout<<"\nrejected2";
			return 0;
		}
		if(isp(ss.top())<=icp(s[i]))
		{
			cout<<"\n"<<ss.top()<<"  "<<"<."<<"  "<<s.substr(i,l);
			ss.push(s[i]);
		}
		else 
		{
			cout<<"\n"<<ss.top()<<"  "<<".>"<<"  "<<s.substr(i,l);
			p=ss.top();
			ss.pop();
			while(isp(ss.top())>=icp(p))
			{
				p=ss.top();
				ss.pop();
			}
			i--;
		}
	}
	cout<<"\nrejected";
}
