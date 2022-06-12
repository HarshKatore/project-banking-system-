/* Program To Define Structure for Customer Bank account that holds information like 1]account number 2]Name Of THE Account Holder 3]balance
 4] Internet banking facility availed (yes/no) 5]pin code (422001 to 422013),6]account type (savings/ deposit/recurring )
********************************************************************************************************************************************
a] Read account detail for N  customers.
b] Identify the Golden, Silver and general customer.
c] golden customer:balance>10,00000
   Silver customer : 10,00000 > balance >5,00000 
   general customer: Balance<5,00000
d] Display the List Of customers availing  internet banking facility
e] Display the customers belongings to a particular geographical location depending on postal code 
f] Display the customer list as per their account type.
*/
#include<stdio.h>
struct BankAccountHolder{
    int AccountNumber;
    char CustomerName[20];
    int AccountBalance;
    int IBF;
    int PinCode;
    int AccountType;

};
void IBFlist (int a,struct BankAccountHolder customer[]){
            printf("THE CUSTOMERS WHO HAVE AVAILED INTERNET BANKING FACILITY ARE:\n");
    for(int i=0;i<a;i++){
        if(customer[i].IBF==1){
            printf("%s\n",customer[i].CustomerName);
        }
    }
};
    void category(int a,struct BankAccountHolder customer[]){
    for (int i=0;i<a;i++){
        if(customer[i].AccountBalance>1000000){
            printf("THE CUSTOMER NAMED %s IS A GOLDEN CUSTOMER.\n",customer[i].CustomerName);
        }
        else if(500000<=customer[i].AccountBalance<=1000000){
            printf("THE CUSTOMER NAMED %s IS A SILVER CUSTOMER.\n",customer[i].CustomerName);

        }
        
        else 
        {    printf("THE CUSTOMER NAMED %s IS A GENERAL CUSTOMER.\n",customer[i].CustomerName);

        }
    }
    }
    void AccountType(int a,struct BankAccountHolder customer[])
    {
        printf("THE CUSTOMERS WHOSE ACCOUNT TYPE IS SAVINGS ARE AS FOLLOWS:\n");
         for (int i=0;i<a;i++){
        if(customer[i].AccountType==1){
            printf("\t%s\n",customer[i].CustomerName);
            printf("\n");
        }
         }
        printf("THE CUSTOMERS WHOSE ACCOUNT TYPE IS RECURRING ARE AS FOLLOWS:\n");
         for (int i=0;i<a;i++){
        if(customer[i].AccountType==2){
            printf("\t%s\n",customer[i].CustomerName);
            printf("\n");

        }
         }
        printf("THE CUSTOMERS WHOSE ACCOUNT TYPE IS DEPOSIT ARE AS FOLLOWS:\n");
         for (int i=0;i<a;i++){
        if(customer[i].AccountType==3){
            printf("\t%s\n",customer[i].CustomerName);
            printf("\n");

        }
         }
       
    }
    void location(int a, struct BankAccountHolder customer[]){
        int pin;
        printf("ENTER THE PIN-CODE TO GET LIST OF CUSTOMERS IN RESPECTIVE LOCATION:");
        scanf("%d,&pin");
                printf("\nTHE LIST OF THE CUSTOMERS BELONGING TO THAT LOCATION IS AS FOLLOWS:\n");
                for(int i=0;i<a;i++){
            if(customer[i].PinCode==pin){
                printf("%s",customer[i].CustomerName);
            }
        }
    }
void display(int a,struct BankAccountHolder customer[]){
     printf("\n\n\tA/C NO.   \tNAME\tBALANCE  \tIBF STATUS  \tPIN-CODE  \tA/C TYPE\n");
    for(int i=0;i<a;i++){
    printf("\t%d   \t\t%s\t%d  \t%d              \t%d  \t%d\n",customer[i].AccountNumber,customer[i].CustomerName,customer[i].AccountBalance,customer[i].IBF,customer[i].PinCode,customer[i].AccountType);
    }
    printf("\n\n");
}

void  search(int a,struct BankAccountHolder customer[]){
   printf("ENTER THE ACCOUNT NUMBER TO SEARCH:");
   int n;
   int flag=0;
   scanf("%d",&n);
    for(int i=0;i<a;i++){
        if(customer[i].AccountNumber==n){
             printf("THE DATA OF THE GIVEN ACCOUNT NUMBER IS AS FOLLOWS:");
             printf("\n\n\tA/C NO.\tNAME\tBALANCE\tIBF STATUS\tPIN-CODE\tA/C TYPE\n");
             printf("\t%d\t%s\t%d\t%d\t        %d        \t%d\n",customer[i].AccountNumber,customer[i].CustomerName,customer[i].AccountBalance,customer[i].IBF,customer[i].PinCode,customer[i].AccountType);
             flag++;
        }
        
    }
    if(flag==0){
         printf("\nTHE DATA OF THE GIVEN ACCOUNT NUMBER IS NOT FOUND!!!");

    }
}
    
struct BankAccountHolder ReadDetails(int a,struct BankAccountHolder customer[]){
    for (int i=0;i<a;i++){
    printf("=======ENTER INFORMATION OF customer @%d=======\n",i+1);
    printf("\n");
    printf("ENTER ACCOUNT NUMBER :");
    scanf("%d",&customer[i].AccountNumber);
  
    getchar();
    printf("ENTER NAME OF ACCOUNT HOLDER :");
    
    scanf ("%s",&customer[i].CustomerName);
    printf("ENTER CURRENT BALANCE OF AN ACCOUNT :");
    scanf("%d",&customer[i].AccountBalance);
   
    printf("HAVE YOU AVAILED INTERNET BANKING FACILITY? (PRESS '1' FOR 'YES' OR '0' FOR 'NO') :");
    scanf("%d",&customer[i].IBF);

    printf("ENTER PIN CODE OF YOUR LOCATION (NOTE:IT SHOULD BE BETWEEN 422001 TO 422013) :");
    scanf("%d",&customer[i].PinCode);

    printf("ENTER THE ACCOUNT TYPE (PRESS 1 FOR SAVINGS,2 FOR RECURRING, 3 FOR DEPOSIT): ");
    scanf("%d",&customer[i].AccountType);
    printf("\n\n");


    }
    return customer[a];
}
int main(){
    printf("\t\tWELCOME TO THE BANKING SYSTEM\n");
    printf("\t\t*****************************\n");
    printf("ENTER THE NUMBER OF CUSTOMER RECORD YOU WANT TO STORE:  ");
    int a;
    scanf("%d",&a);
    struct BankAccountHolder customer[a];
    printf("\n\n");
    customer[a]= ReadDetails(a,customer);
   int menu;
   do{ 
   printf("\t**********BANKING SYSTEM MENU************\n");
   printf("PRESS 1 TO DISPLAY ALL RECORD.\n");
   printf("PRESS 2 TO SEARCH A RECORD.\n ");
   printf("PRESS 3 TO GET THE LIST OF CUSTOMERS AVAILING INTERNET BANKING FACILITY.\n ");
   printf("PRESS 4 TO KNOW WHETHER A CUSTOMER IS GOLDEN, SILVER OR GENERAL.\n");
   printf("PRESS 5 TO GET THE LIST OF THE CUSTOMER AS PER ACCOUNT TYPE.\n");
   printf("PRESS 6 TO SORT THE CUSTOMERS AS PER GEOGRAPHICAL LOCATIONS.\n");
   printf("PRESS 0 TO EXIT\n");
   printf("ENTER YOUR CHOICE(0 TO 6):");
   scanf("%d",&menu);
    switch(menu){
    case 1:
    display(a,customer);
    break;
     case 2:
    search(a,customer);
    break;
     case 3:
    IBFlist (a,customer);
    break;
     case 4:
    category(a,customer);
    break;
     case 5:
    AccountType(a,customer);
    break;
     case 6:
    location(a,customer);
    break;
   }
  
   }
   while(menu>0);
    return 0;
}
