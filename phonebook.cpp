#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void disp();
class phonebook{
	protected:
		string name;
		string num;
		
		
	public:
	string temp;	
	bool search(string s);
 void add(string s,string n);
 void disp_rec(string s);
 void disp_all();
};

void phonebook::disp_all()
{
	fstream file;
	string w;
	file.open("data_base.txt",ios::in);
	while(getline(file,w))
	{
	 cout<<w<<endl;
	}
	file.close();
}


void phonebook::disp_rec(string s)
{
 if(search(s))
 {
 	cout<<s<<endl;
 	cout<<temp<<endl;
 	
 }
 else 
 {
   cout<<"Record not present"<<endl;
 }	
}

 bool phonebook::search(string s)
 {
 	string word;
 	fstream file;
 	file.open("data_base.txt",ios::in);
 	while(getline(file,word))
 	{
	 if(word==s)
	 {
	 	getline(file,temp);
	  return true;
	 }
	}
	file.close();
	return false;
	
 	
 }
 
void phonebook::add(string s,string n)
 {
 	name=s;
 	num=n;
 	if(search(s))
 	{
 		
 		return;
	 }
	 fstream file;
	 file.open("data_base.txt",ios::app);
	 file<<name<<endl;
	 file<<num<<endl;
	 file.close();
	 
 }
void disp()
{
	system("cls");
		 cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Exit\n";
 } 
 
int main() 
{
	char c;`	
	int x;
	phonebook ph;
	fstream file;
	string w;
	
	disp();

	cin>>x;
	if(x==1)
	{
		string s,n;
		
		cout<<"Enter number & name";
		cin>>s;
		cin>>n;
		ph.add(s,n);
		
	}
	else
	if(x==3)
	{
		system("cls");
		cout<<"ENTER THE NAME"<<endl;
		cin>>w;
		if(ph.search(w))
		{
			
			cout<<ph.temp;
		}
		else
		{
			cout<<"The number is not present";
		}
	}
	
	
	else if(x==2)
	{
		ph.disp_all();
	}
	
	
	
	
	return 0;
}
