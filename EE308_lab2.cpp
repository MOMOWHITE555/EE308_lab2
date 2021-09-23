#include <vector> 
#include <string> 
#include <fstream> 
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

string keyword[32] = {"auto","break","case","char","const","continue","default","do","double",
                       "else","enum","extern","float","for","goto","if","int","long","register",
					   "return","short","signed","sizeof","static","struct","switch","typedef",
					   "union","unsigned","void","volatile","while"};

	
int main()
{	
	int totalnum,switch_num,if_else_num,if_else_if_else_num;
	int t;
	int case_num[100];
	int su[100];

	string temp;
	string line;
	
	ifstream myfile("sample_lab2.txt");	
	ofstream outfile("out.txt",ios::app); 
    if (!myfile.is_open()) 
    { 
        cout << "we can not open the file." << endl; 
        return 0;
    } 
    while(getline(myfile,temp)) 
    { 
        outfile << temp; 
        outfile << endl;
    } 
    myfile.close(); 
    outfile.close();
    
    void level_12(string a);
    void level_34(string b);
    while(getline(myfile,line))
    {
    	istringstream is(line);
    	string s;
    	level_34(line);
		while (is>>s)
		{
			level_12(s);	
		}
	}
	cout<<"The total num is: "<<totalnum<<endl;
	cout<<"The switch num is: "<< switch_num<<endl;
	cout<<"The case num is:  "<< case_num[switch_num]<<endl;
	
	for(int a=1;a<=switch_num;a++) cout<<" "<<case_num[a];
	cout<<"The if_else_num is:  "<<if_else_num<<endl;
	cout<<"The if_else_if_else_num is: "<<if_else_if_else_num<<endl;  
	
	return 0;
} 

void level_12(string s) 
{
	int switch_num=0;
	int case_num[100];
	int totalnum=0;
	
	char s1[500],s2[500];
	for(int i=0;i<32;i++)
	{
		int l1=s.length(), l2=keyword[i].length();
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for (int j=0;j<l1;j++)
		{
			s1[j]=s[j];
		}
		for (int j=0;j<l2;j++)
		{
			s2[j]=keyword[i][j];
		}
		if(strcmp(s1,s2)==0)
		{
			if (strcmp(s2,"switch")==0)
			{
				switch_num++;
			}
			if (strcmp(s2,"case")==0)
			{
				case_num[switch_num]++;
			}
			totalnum++;
			break;
		} 
	}
}

void level_34(string s) 
	{
		int t=0;
		int su[100];
		int if_else_num=0,if_else_if_else_num=0;
		
		if (s.find("else if")!=string::npos)
		{
	  		t++;
	  		su[t]=2;	
		}
		else
		{
			if(s.find("if")!=string::npos)
			{
				t++;
				su[t]=1;
			}
			else
			{
				if(s.find("else")!=string::npos)
				{
					if (su[t]==1)
					{
				   		if_else_num++;
				   		t--;	
					}
					else
					{
						if (su[t]==2)
						{
							if_else_if_else_num++;
							t--;	
						}
					}
				}
			}
		}
	}
	


    
