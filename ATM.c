#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max  100


/*
PPS Innovative Examination
Shashank Singh 9
Shivanshu Singh 10
Utsav Raj Singh 11
Utsav Anand Singh 12
COMP C
*/

//----------------------------------------------------------------------------------------------------

struct account	//structure
{
	int accountnumber;
	int pin;
	int balance;
	int beneficiary;
};

struct account accountarray[max];	//array
int numaccount = 0;

//----------------------------------------------------------------------------------------------------

int accountverify(int accountnumber,int pin)
{
	int i;
	
	for (i=0;i<numaccount;i++)
	{
		if (accountarray[i].accountnumber == accountnumber && accountarray[i].pin == pin)
		{
			return i;
		}
	}
	
	return -1;
}

//----------------------------------------------------------------------------------------------------

void changepin(int accountnumber,int pin,int index)
{
	int newpin, newpin2;
	
	printf("\nEnter your new ATM PIN: ");
    scanf("%d", &newpin);
    printf("Re-enter your new ATM PIN: ");
    scanf("%d", &newpin2);
    
    if (newpin==newpin2)
    {
    	accountarray[index].pin = newpin;
    	printf("\nPIN Updated!");
    	
    	printf("\nThank You for visting!");
	}
	
	else
	{
	
		printf("\nPIN doesn't match!");
		printf("\nPlease re-enter your PIN");
		changepin(accountnumber,pin,index);
	}
}

//----------------------------------------------------------------------------------------------------

void accountbalance(int index)
{
	int balance;
	
	balance = accountarray[index].balance;
	printf("\nYour current balance: Rs. %d",balance);
	
	printf("\nThank You for visting!");
}

//----------------------------------------------------------------------------------------------------

void moneywithdraw(int index)
{
	int money;
	
	printf("\nEnter the amount: Rs.");
	scanf("%d",&money);
	
	if (accountarray[index].balance < money)
	{
		printf("\nInsufficent Fund!");
		moneywithdraw(index);
	}
	
	else
	{
		accountarray[index].balance -= money;
		printf("\nMoney Withdraw: Rs. %d",money);
		printf("\nYour current balance: Rs. %d",accountarray[index].balance);
	}
	
	printf("\nThank You for visting!");
}

//----------------------------------------------------------------------------------------------------

void fundtransfer(int index)
{
	int bnf,bnf2;
	
	printf("\nEnter 5 digit Beneficiary Number:");
	scanf("%d",&bnf);
	printf("\nRe-enter 5 digit Beneficiary Number:");
	scanf("%d",&bnf2);
	
	if (bnf==bnf2)
    {
    	int money;
    	
    	printf("\nEnter the amount: Rs.");
		scanf("%d", &money);
	
		if (accountarray[index].balance < money)
		{
			printf("\nInsufficent Fund!");
			fundtransfer(index);
		}
	
		else
		{
			accountarray[index].balance -= money;
			printf("\nMoney Transfer: Rs. %d",money);
			printf("\nYour current balance: Rs. %d",accountarray[index].balance);
		}
    	
    		printf("\nThank You for visting!");
		}
	
	else
	{
	
		printf("\nBeneficiary Number doesn't match!");
		printf("\nPlease re-enter Beneficiary Number");
		fundtransfer(index);
	}
	
}

//----------------------------------------------------------------------------------------------------

int main()
{
	int choice,accountnumber,pin,index,j;
	
	struct account a1,a2,a3;
	
	//user 1
	accountarray[0].accountnumber = 12345678;
	accountarray[0].balance = 100000;
	accountarray[0].beneficiary = 00000;
	accountarray[0].pin = 2345;
	numaccount++;
	
	//user 2
	accountarray[1].accountnumber = 76859048;
	accountarray[1].balance = 100000;
	accountarray[1].beneficiary = 111111;
	accountarray[1].pin = 5678;
	numaccount++;
	
	//user 3
	accountarray[2].accountnumber = 87654321;
	accountarray[2].balance = 100000;
	accountarray[2].beneficiary = 22222;
	accountarray[2].pin = 4567;
	numaccount++;
	
	printf("\nEnter your account number: ");
    scanf("%d", &accountnumber);
    printf("Enter your ATM PIN: ");
    scanf("%d", &pin);
    
    index = accountverify(accountnumber,pin);
    
    if (index == -1)
    {
    	printf("Incorrect PIN!");
    	main();
	}
	
	else {
		printf("\n");
		printf("\nATM");
		printf("\n");
		printf("\n1.Change of PIN");
		printf("\n2.Balance Enquiry");
		printf("\n3.Money Withdrawal");
		printf("\n4.Fund Transfer");
		printf("\n5.Exit");
	
		printf("\nSelect a service:");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				changepin(accountnumber,pin,index);
				break;
		
			case 2:
				accountbalance(index);
				break;
		
			case 3:
				moneywithdraw(index);
				break;
		
			case 4:
				fundtransfer(index);
				break;
		
			case 5:
				printf("\nThank You for visting!");
				break;
		
		}
		
	}
	
	return 0;
	
}

//----------------------------------------------------------------------------------------------------