#include<iostream>
using namespace std;
class Account{
    int accountNumber;
    string accountHolderName;
    protected:
        int balance;
        string accountType;
    public:
        Account(int number,int balance,string type,string name):accountNumber(number),balance(balance),accountType(type),accountHolderName(name){}
        void deposite(int amount){
            if(amount>0){
                balance+=amount;
                cout<<"Amount deposited successfully"<<endl;
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
        virtual float calculateInterest(){
            return balance*(0/100.0);
        }
        virtual void printStatement(){
            cout<<"Statement"<<endl;
            cout<<"Interest Rate: 0%"<<endl;
            cout<<"Current Balance: "<<balance<<endl;    
        }
        virtual void withdraw(int amount){
            if(amount>=0){
                if(balance>=amount){
                    balance-=amount;
                    cout<<"Amount withdrawed successfully"<<endl;
                }
                else{
                    cout<<"Insufficient balance"<<endl;
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
        void getAccountInfo(){
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Account Holder Name: "<<accountHolderName<<endl;
            cout<<"Account Type: "<<accountType<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};
class SavingsAccount: public Account{
    int interestRate,minimumBalance;
    public:
        SavingsAccount(int number,int balance,string type,string name,int rate,int minimum):Account(number,balance,type,name),interestRate(rate),minimumBalance(minimum){}
        float calculateInterest(){
            return balance*(interestRate/100.0);
        }
        void printStatement(){
            cout<<"Statement"<<endl;
            cout<<"Accoun Type: "<<accountType<<endl;
            cout<<"Minimum Balance: "<<minimumBalance<<endl;
            cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
            cout<<"Current Balance: "<<balance<<endl;    
        }
        void withdraw(int amount){
            if(amount>=0){
                if(balance>=amount){
                    balance-=amount;
                    cout<<"Amount withdrawed successfully"<<endl;
                    cout<<"Current balance: "<<balance<<endl;
                    cout<<"Applying interest"<<endl;
                    balance+=calculateInterest();
                    cout<<"Interest amount: "<<calculateInterest();
                }
                else{
                    cout<<"Insufficient balance"<<endl;
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
};
class FixedDepositeAccount: public Account{
    const int fixedInterestRate;
    string maturityDate;
    public:
        FixedDepositeAccount(int number,int balance,string type,string name,int rate,string date):Account(number,balance,type,name),fixedInterestRate(rate),maturityDate(date){}
        float calculateInterest(){
            return balance*(fixedInterestRate/100.0);;
        }
        void printStatement(){
            cout<<"Statement"<<endl;
            cout<<"Accoun Type: "<<accountType<<endl;
            cout<<"Maturity Date: "<<maturityDate<<endl;
            cout<<"Fixed Interest Rate: "<<fixedInterestRate<<"%"<<endl;
            cout<<"Current Balance: "<<balance<<endl;    
        }
        void withdraw(int amount){
            if(amount>=0){
                if(balance>=amount){
                    balance-=amount;
                    cout<<"Amount withdrawed successfully"<<endl;
                    cout<<"Current balance: "<<balance<<endl;
                    cout<<"Applying interest"<<endl;
                    balance+=calculateInterest();
                    cout<<"Interest amount: "<<calculateInterest();
                }
                else{
                    cout<<"Insufficient balance"<<endl;
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
};
class CheckingAccount: public Account{
    int interestRate;
    public:
        CheckingAccount(int number,int balance,string type,string name,int rate):Account(number,balance,type,name),interestRate(rate){}
        float calculateInterest(){
            return balance*(interestRate/100.0);
        }
        void printStatement(){
            cout<<"Statement"<<endl;
            cout<<"Accoun Type: "<<accountType<<endl;
            cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
            cout<<"Current Balance: "<<balance<<endl;    
        }
        void withdraw(int amount){
            if(amount>=0){
                if(balance>=amount){
                    balance-=amount;
                    cout<<"Amount withdrawed successfully"<<endl;
                    cout<<"Current balance: "<<balance<<endl;
                    cout<<"Applying interest"<<endl;
                    balance+=calculateInterest();
                    cout<<"Interest amount: "<<calculateInterest();
                }
                else{
                    cout<<"Insufficient balance"<<endl;
                }
            }
            else{
                cout<<"Invalid input"<<endl;
            }
        }
};
int main(){
    Account *acc;
    int acc_num,balance,rate,minimum;
    string name,date;
    cout<<"For Saving Account"<<endl;
    cout<<"Enter Account Number: ";
    cin>>acc_num;
    cout<<"Enter Account Holder Name: ";
    cin>>name;
    cout<<"Enter Balance: ";
    cin>>balance;
    cout<<"Enter Interest Rate: ";
    cin>>rate;
    cout<<"Enter minimum balance: ";
    cin>>minimum;
    SavingsAccount saving(acc_num,balance,"Saving Account",name,rate,minimum);
    cout<<endl<<"For Fixed Deposite Account"<<endl;
    cout<<"Enter Account Number: ";
    cin>>acc_num;
    cout<<"Enter Account Holder Name: ";
    cin>>name;
    cout<<"Enter Balance: ";
    cin>>balance;
    cout<<"Enter Fixed Interest Rate: ";
    cin>>rate;
    cout<<"Enter maturity date: ";
    cin>>date;
    FixedDepositeAccount fixed(acc_num,balance,"Fixed Deposite Account",name,rate,date);
    cout<<endl<<"For Checking Account"<<endl;
    cout<<"Enter Account Number: ";
    cin>>acc_num;
    cout<<"Enter Account Holder Name: ";
    cin>>name;
    cout<<"Enter Balance: ";
    cin>>balance;
    cout<<"Enter Interest Rate: ";
    cin>>rate;
    CheckingAccount checking(acc_num,balance,"Checking Account",name,rate);    
    int c1,c2;
    while(1){
        cout<<endl<<"Enter the appropriate key according to the function you wat to perform\n1.Deposite amount\n2.Withdraw Amount\n3.Calculate Interest\n4.Print Statement\n5.Display Account Information\nAny other key to exit\nEnter: ";
        cin>>c1;
        switch(c1){
            case 1:
                cout<<"Enter the appropriate key according to the account type\n1.Saving Account\n2.Fixed Deposite Account\n3.Checking Account\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&saving;
                        acc->deposite(balance);
                        break;
                    case 2:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&fixed;
                        acc->deposite(balance);
                        break;
                    case 3:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&checking;
                        acc->deposite(balance);
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            case 2:
                cout<<"Enter the appropriate key according to the account type\n1.Saving Account\n2.Fixed Deposite Account\n3.Checking Account\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&saving;
                        acc->withdraw(balance);
                        break;
                    case 2:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&fixed;
                        acc->withdraw(balance);
                        break;
                    case 3:
                        cout<<"Enter amount: ";
                        cin>>balance;
                        acc=&checking;
                        acc->withdraw(balance);
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            case 3:
                cout<<"Enter the appropriate key according to the account type\n1.Saving Account\n2.Fixed Deposite Account\n3.Checking Account\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        acc=&saving;
                        cout<<"Interest Ammount: "<<acc->calculateInterest()<<endl;
                        break;
                    case 2:
                        acc=&fixed;
                        cout<<"Interest Ammount: "<<acc->calculateInterest()<<endl;
                        break;
                    case 3:
                        acc=&checking;
                        cout<<"Interest Ammount: "<<acc->calculateInterest()<<endl;
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            case 4:
                cout<<"Enter the appropriate key according to the account type\n1.Saving Account\n2.Fixed Deposite Account\n3.Checking Account\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        acc=&saving;
                        acc->printStatement();
                        break;
                    case 2:
                        acc=&fixed;
                        acc->printStatement();
                        break;
                    case 3:
                        acc=&checking;
                        acc->printStatement();
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            case 5:
                cout<<"Enter the appropriate key according to the account type\n1.Saving Account\n2.Fixed Deposite Account\n3.Checking Account\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        acc=&saving;
                        acc->getAccountInfo();
                        break;
                    case 2:
                        acc=&fixed;
                        acc->getAccountInfo();
                        break;
                    case 3:
                        acc=&checking;
                        acc->getAccountInfo();
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            default:
                cout<<"Exited successfully"<<endl;
                return 0;
        }
    }    
}