#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
using namespace std;
int icp(string);
int isp(string);
int k;
int main()
{
		int c,p,top;
	ifstream f("in.txt");
	string line,element;
	while(getline(f,line))
	{
		c=0,p=1,top=-1;
		list<string> line1;
		list<string> line2;
		stringstream s(line);
		while(getline(s,element,' '))
		{
			line1.push_back(element);
			c++;
		}
	string 	temp1=*line1.begin();
		string stack[20];
			for(list<string>::iterator iter=line1.begin();iter!=line1.end();iter++)
			{
				p++;

				list<string>::iterator  after=iter;
				after++;
				 if(c==3)
				 {
					 cout<<"\n"<<*iter<<*after;
					 after++;
					 cout<<*after<<"\n";
					 break;
				 }
				 else
				 {
					if(p<3)
					{
						iter++;
						iter++;
						p=p+2;
					}				 				
				 	if((*iter!="+")&&(*iter!="-")&&(*iter!="*")&&(*iter!="/")&&(*iter!="(")&&(*iter!=")"))
				 		line2.push_back(*iter);
				 	else
				 	{
				 		if(top==-1)
				 		{
				 			top++;
				 			stack[top]=*iter;
				 		}				 		
				 		else if((isp(stack[top])>=icp(*iter))&&(*iter!="(")&&(*iter!=")"))
				 		{
				 			line2.push_back(stack[top]);
				 			stack[top]=*iter;
				 		}
				 		else if((isp(stack[top])<icp(*iter))&&(*iter!=")")||(*iter=="("))
				 		{
				 			top++;
				 			stack[top]=*iter;
				 		}
				 		else if(*iter==")")
				 		{
				 			while(stack[top]!="(")
				 			{
				 			line2.push_back(stack[top]);
				 			top--;
				 			}
				 			top--;
				 		}
				 	}
				 }
			}
			while(top!=-1)
				 			{
				 			line2.push_back(stack[top]);
				 			top--;
				 			}
			string stack1[20];
			int t=-1;
			for(list<string>::iterator iter=line2.begin();iter!=line2.end();iter++)
			{
				 	if((*iter!="+")&&(*iter!="-")&&(*iter!="*")&&(*iter!="/")&&(*iter!="(")&&(*iter!=")")) 		
					{
						t++;
						stack1[t]=*iter;
					}
					else
					{
						string op1=stack1[t];
						t--;
						string op2=stack1[t];
						cout<<"\nt"<<k<<"="<<op2<<*iter<<op1;
						stringstream ss;
						ss<<k;
						string temp="t"+ss.str();
						k++;
						stack1[t]=temp;
					}
			}
			if(c!=3)
			cout<<"\n"<<temp1<<"="<<"t"<<(k-1);
	}
}
int icp(string s1)
{
	if((s1=="(")||(s1==")"))
		return (0);
	else if((s1=="+")||(s1=="-"))
		return (2);
else if((s1=="*")||(s1=="/"))
		return (5);
}
int isp(string s1)
{
	if((s1=="(")||(s1==")"))
		return (0);
	else if((s1=="+")||(s1=="-"))
		return (2);
else if((s1=="*")||(s1=="/"))
		return (5);
}