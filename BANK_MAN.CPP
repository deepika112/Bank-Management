#include<process.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
long int account_count=1;
struct bank
{

	long int pin,adhaar_no,account_no;
	char first_name[10],middle_name[10],last_name[10],nominee_name[20],address[30];
	float account_balance;
	bank *link;
}*start_data,*ptr,*last_data,*temp;
void create(long int p,long int adhaar,char f_name[],char m_name[],char l_name[],char nominee[],char add[],float bal)
{

	ptr=new bank;
	ptr->pin=p;
	ptr->adhaar_no=adhaar;
	ptr->account_no=account_count;
	strcpy(ptr->first_name,f_name);
	strcpy(ptr->middle_name,m_name);
	strcpy(ptr->last_name,l_name);
	strcpy(ptr->nominee_name,nominee);
	strcpy(ptr->address,add);
	ptr->account_balance=bal;
	ptr->link=NULL;
	account_count++;
}
void insert_data()
{
	if(start_data==NULL)
	{
		start_data=ptr;
		last_data=ptr;
	}
	else
	{
		last_data->link=ptr;
		last_data=ptr;
	}
}
int search_data(long int acc)
{
	bank *sec_temp;
	sec_temp=start_data;
	while(sec_temp!=NULL)
	{
		if(acc==sec_temp->account_no)
		{
			temp = sec_temp;
			return 1;
		}
		else
			sec_temp=sec_temp->link;
	}
	return 0;
}
void change_data(int choice,float amount)
{
	if(choice==1)
		temp->account_balance +=amount;
	else if(choice==2)
		temp->account_balance-=amount;
	else
		cout<<temp->account_balance;
}
void display_data(bank *start)
{
	temp = start;
	cout<<"\n ACCOUNT NUMBER:"<<temp->account_no;
	cout<<"\n FIRST NAME:"<<temp->first_name;
	cout<<"\n SECOND NAME:"<<temp->middle_name;
	cout<<"\n LAST NAME:"<<temp->last_name;
	cout<<"\n ACCOUNT BALANCE:"<<temp->account_balance;
}
void main()
{	int choice,sign_in;
	clrscr();
	cout<<"\n\t\t\t\t HELLO WELCOME";
	cout<<"\n*******************************************************************";
	cout<<"\n PLEASE SELECT ANYONE OPTION";
	cout<<"\n 1:SIGN_IN/SIGN_UP\n 2:EXIT";
	cin>>sign_in;
	while(sign_in==1)
	{
		cout<<"\n\n\n 1: SIGN_IN\n 2: SIGN_UP\n 3: EXIT\n";
		cin>>choice;
		switch(choice)
		{
			case 3:
				cout<<"\n\t\t\t\t THANK YOU\n";
				cout<<"******************************************************************";
				getch();
				exit(1);
				break;
			case 1:
				long int acc_no;
				int ch,t;
				float amt;
				cout<<"\n ENTER ACCOUNT NUMBER:\n";
				cin>>acc_no;
				t=search_data(acc_no);
				if (t==1)
				{
				display_data(temp);
				cout<<"\n\n\nPLEASE SELECT ANYONE \n1: DEPOSIT\n2: WITHDRAW\n3: CHECK BALANCE\n";
				cin>>ch;
				if(ch==1||ch==2)
				{
					cout<<"\n\nENTER AMOUNT:\n";
					cin>>amt;
				}
				change_data(ch,amt);
				display_data(temp);
				}
				else
					cout<<"no data found";
				break;
			case 2:
				long int p,adhaar;
				char f_name[10],m_name[10],l_name[10],nominee[20],add[30];
				cout<<"\n PLEASE ENTER DETAILS:";
				cout<<"\n FIRST NAME:\n";
				gets(f_name);
				cout<<"\n MIDDLE NAME:\n";
				gets(m_name);
				cout<<"\n LAST NAME:\n";
				gets(l_name);
				cout<<"\n NOMINEE NAME:\n";
				gets(nominee);
				cout<<"\n ADDRESS:\n";
				gets(add);
				cout<<"\n PIN:\n";
				cin>>p;
				cout<<"\n ADHAAR NUMBER:\n";
				cin>>adhaar;
				create(p,adhaar,f_name,m_name,l_name,nominee,add,500);
				insert_data();
				display_data(last_data);
				break;
			default:
				cout<<"\n PLEASE SELECT A NUMBER";
				cout<<"******************************************************************";
		}
		continue;
	}
	getch();
}