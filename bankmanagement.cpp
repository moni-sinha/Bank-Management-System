#include<iostream>
#include<iomanip>
#include<string.h>
#include<windows.h>
using namespace std;
#define max 100
void changeColor(int desiredColor)
{ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
}
//opening account
void new_acc(int n,float* init_bal,float* bal,long long int* acc_no,string* name,string* type_of_acc)
{
	cout<<"\t\t\t\t\t\t ENTRY OF CUSTOMER "<<n+1<<endl;
	cout<<"\t\t\t\t\t ACCOUNT NUMBER           : ";
	cout<<n+1<<n<<n+1<<n+1<<n+1;
	cout<<endl<<"\t\t\t\t\t ACCOUNT HOLDER NAME      : ";
	cin>>name[n+1];
	cout<<"\t\t\t\t  'C' for current account and 'S' for savings account"<<endl;
	cout<<"\t\t\t\t\t ACCOUNT TYPE (C/S)       : ";
	cin>>type_of_acc[n+1];
	cout<<"\t\t\t\t\t INITIAL BALANCE  (in Rs) : ";
	cin>>init_bal[n+1];
	if(type_of_acc[n+1]=="c" || type_of_acc[n+1]=="C")
	{
		if(init_bal[n+1]<500)
		{
			while(init_bal[n+1]<500)
			{
				cout<<"\t\t\t\t\t   Maintain minimum of Rs 500"<<endl;
				cout<<"\t\t\t\t\t INITIAL BALANCE  (in Rs) : ";
				cin>>init_bal[n+1];
				cout<<endl;
			}
		}
	}
	bal[n+1]=init_bal[n+1];
	cout<<"\t\t\t\t\t  ACCOUNT CREATED SUCCESSFULLY";
	cout<<endl<<endl;
}

int main()
{
	float init_bal[max];
	float bal[max];
	long long int acc_no[max];
	string name[max];
	string type_of_acc[max];
	int close[max];
	int min[max];
	float monthly_int_rate=0.005/12.0;
	int acc;
	int i;
	int n=0;
	int next=1;
	while(next==1)
	{
		changeColor(11);   	
		system("cls");
		cout<<" "<<setw(68)<<"======================"<<endl;
		cout<<" "<<setw(68)<<"BANK MANAGEMENT SYSTEM"<<endl;
		cout<<" "<<setw(68)<<"======================"<<endl<<endl;
		cout<<" "<<setw(64)<<"::MAIN MENU::"<<endl;
		cout<<" "<<setw(64)<<"_____________"<<endl<<endl;
		cout<<" "<<setw(76)<<"* * * * * * * * * * * * * * * * * * *"<<endl;
		cout<<"\t\t\t\t\t*                                   * "<<endl;
		cout<<"\t\t\t\t\t*  1. CREATE NEW ACCOUNT            *"<<endl;
		cout<<"\t\t\t\t\t*  2. DEPOSIT                       *"<<endl;
		cout<<"\t\t\t\t\t*  3. WITHDRAWAL                    *"<<endl;
		cout<<"\t\t\t\t\t*  4. CLOSE AN EXISTING ACCOUNT     *"<<endl;
		cout<<"\t\t\t\t\t*  5. OPEN A CLOSED ACCOUNT         *"<<endl;
		cout<<"\t\t\t\t\t*  6. DISPLAY A PARTICULAR ACCOUNT  *"<<endl;
		cout<<"\t\t\t\t\t*  7. EXIT                          *"<<endl;
		cout<<"\t\t\t\t\t*                                   * "<<endl;
		cout<<" "<<setw(76)<<"* * * * * * * * * * * * * * * * * * *"<<endl;
			int choice;
			cout<<endl<<setw(66)<<"Enter ur choice: ";
			cin>>choice;
			cout<<endl;
			switch(choice)
			{
				case 1:
				{
					new_acc(n,init_bal,bal,acc_no,name,type_of_acc);
					n++;
					break;
				}	
				case 2:
				{
					cout<<"\t\t\t\t ID to be accessed\t\t\t    : ";
					cin>>acc;
					if(acc>=1 && acc<=n)
					{
						if(type_of_acc[acc]=="s" || type_of_acc[acc]=="S")
						{
							bal[acc]=bal[acc]+(bal[acc]*monthly_int_rate);
							cout<<"\t\t\t Monthy interest rate of "<<monthly_int_rate<<" added to the balance amount"<<endl;
						}
						if(close[acc]==1)
							cout<<"\t\t\t\t\t   THIS ACCOUNT IS NOT ACCESSIBLE."<<endl<<endl;
						else
						{
							int dep;
							cout<<"\t\t\t\t Amount deposited (in Rs)\t\t    : ";
							cin>>dep;
							bal[acc]=bal[acc]+dep;
							cout<<"\t\t\t\t Balance amount (in Rs)\t\t\t    : "<<bal[acc]<<endl<<endl;
						}
					}
					else
					{
						cout<<"\t\t\t\t This account is not accessible. Enter valid ID."<<endl<<endl<<endl;
					}
					break;
				}
				case 3:
				{
					cout<<"\t\t\t\t ID to be accessed\t\t\t    : ";
					cin>>acc;
					if(acc>=1 && acc<=n)
					{
						if(type_of_acc[acc]=="s" || type_of_acc[acc]=="S")
						{
							bal[acc]=bal[acc]+(bal[acc]*monthly_int_rate);
							cout<<"\t\t\t Monthy interest rate of "<<monthly_int_rate<<" added to the balance amount"<<endl;
						}
						if(close[acc]==1)
							cout<<"\t\t\t\t\t THIS ACCOUNT IS NOT ACCESSIBLE."<<endl<<endl;
						else
						{
							int with;
							cout<<"\t\t\t\t Amount withdrawn (in Rs)\t\t    : ";
							cin>>with;
							if(with>bal[acc])
								cout<<"\t\t\t    Amount cannot be withdrawn, due to insufficient balance."<<endl<<endl;
							else
							{
								bal[acc]=bal[acc]-with;
								if(type_of_acc[acc]=="c" || type_of_acc[acc]=="C")
								{
									if(bal[acc]>500)
										cout<<"\t\t\t\t Balance amount (in Rs)\t\t\t    : "<<bal[acc]<<endl<<endl;
									else
									{
										cout<<endl<<"\t\t\t**WARNING:: Ur balance is falling below the minimum amount required. **"<<endl;
										cout<<"\t\t\t  ** If u want to withdraw, ur account will be temporarily closed. **"<<endl<<endl;
										cout<<"\t\t\t\t Balance amount (in Rs)\t\t\t    : "<<bal[acc]<<endl;
										close[acc]=1;
										cout<<"\t\t\t\t\t  ** YOUR ACCOUNT IS DEAD NOW. **"<<endl<<endl;
									}
								}
								else
								{
									cout<<"\t\t\t\t Balance amount (in Rs)\t\t\t    : "<<bal[acc]<<endl<<endl;
								}	
							}
						}
					}
					else
					{
						cout<<"\t\t\t\t This account is not accessible. Enter valid ID."<<endl<<endl;
					}
					break;
				}
				case 4:
				{
					cout<<"\t\t\t\t ID to be accessed\t\t\t    : ";
					cin>>acc;
					if(acc>=1 && acc<=n)
					{
						if(close[acc]==1)
							cout<<"\t\t\t\t\t THIS ACCOUNT IS ALREADY CLOSED."<<endl<<endl;
						else
						{
							close[acc]=1;
							cout<<"\t\t\t   THIS ACCOUNT IS CLOSED NOW. NO MORE TRANSACTIONS CAN TAKE PLACE."<<endl<<endl;
						}
					}
					else
					{
						cout<<"\t\t\t\t\This account is not accessible. Enter valid ID."<<endl<<endl;
					}
					break;
				}
				case 5:
				{
					cout<<"\t\t\t\t ID to be accessed\t\t\t\t  : ";
					cin>>acc;
					if(acc>=1 && acc<=n)
					{
						if(type_of_acc[acc]=="c" || type_of_acc[acc]=="C")
						{
							if(bal[acc]<500)
							{
								cout<<"\t\t   You have to add minimal amount, to open this account(in Rs)    : ";
								cin>>min[acc];
								if((bal[acc]+min[acc])<500)
								{
									while((bal[acc]+min[acc])<500)
									{
										cout<<"\t\t\t\t  You didn't reached the minimum amount required."<<endl;
										cout<<"\t\t\t\t\t  Add minimal amount\t\t\t  : ";
										cin>>min[acc];
										cout<<endl;
									}
									bal[acc]=bal[acc]+min[acc];
									cout<<"\t\t\t\t\t  Balance amount (in Rs)\t\t  : "<<bal[acc]<<endl<<endl;
								}
							}
						}
						close[acc]=0;
						cout<<"\t\t\t\t     ACCOUNT OF CUSTOMER "<<acc<<" IS ACCESSIBLE NOW."<<endl<<endl;
					}
					else
					{
						cout<<"\t\t\t\t\t This account is not accessible. Enter valid ID."<<endl<<endl;
					}
					break;
				}
				case 6:
					{
						cout<<"\t\t\t\t\t ID to be accessed\t    : ";
						cin>>acc;
						cout<<"\t\t\t\t\t ACCOUNT NUMBER\t\t    : "<<acc_no[acc]<<endl;
						cout<<"\t\t\t\t\t ACCOUNT HOLDER\t\t    : "<<name[acc]<<endl;
						cout<<"\t\t\t\t\t ACCOUNT TYPE\t\t    : "<<type_of_acc[acc]<<endl;
						cout<<"\t\t\t\t\t BALANCE STATUS\t\t    : ";
						if(close[acc]==1)
							cout<<"CLOSED"<<endl<<endl;
						else
							cout<<bal[acc]<<endl<<endl;
						break;
					}
				case 7:
					exit;
					break;
				default:
					cout<<"\t\t\t\t\t Enter valid choice."<<endl<<endl;
			}
		cout<<setw(80)<<"To return to the MAIN_MENU, press 1,to exit,press 0 : ";
		cin>>next;
	}
	system("cls");
	//printing details
	changeColor(14);
	cout<<endl<<setw(60)<<"ACCOUNT HOLDER LIST"<<endl;
	cout<<setw(60)<<"___________________"<<endl<<endl;
	cout<<"========================================================================================================="<<endl;
	cout<<"  CUSTOMER ID"<<setw(20)<<"ACCOUNT NUMBER"<<setw(20)<<"ACCOUNT HOLDER"<<setw(20)<<"ACCOUNT TYPE"<<setw(25)<<"BALANCE STATUS"<<endl;
	cout<<"========================================================================================================="<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"     "<<i<<" ";
		cout<<setw(20)<<acc_no[i]<<setw(19)<<name[i]<<setw(22)<<type_of_acc[i]<<setw(29);
		if(close[i]==1)
		{
			cout<<"CLOSED";
		}
		else
		{
			cout<<"   Balance (in Rs) : "<<bal[i]<<"/-";
		}
		cout<<endl;
	}
	return 0;
}
