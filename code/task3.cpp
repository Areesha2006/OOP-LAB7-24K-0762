#include<iostream>
using namespace std;
class Currency{
    protected:
        string currencyCode,currencySymbol;
        float amount,exchangeRate;
    public:
        Currency(float amount,float rate,string code,string symbol):amount(amount),exchangeRate(rate),currencySymbol(symbol),currencyCode(code){}
        virtual float convertToBase(){
            return amount*exchangeRate;
        }
        virtual void display(){
            cout<<amount<<" "<<currencyCode;
        }
        void convertTO(Currency &targetCurrency){
            float base=convertToBase();
            float converted=base/targetCurrency.exchangeRate;
            display();
            cout<<"="<<converted<<" "<<targetCurrency.currencyCode<<endl;
        }
};
class Dollar: public Currency{
    public:
        Dollar(float amount):Currency(amount,277,"USD","$"){}
        float convertToBase(){
            return amount*277;
        }
        void display(){
            cout<<amount<<" "<<currencyCode;
        }
};
class Euro: public Currency{
    public:
        Euro(float amount):Currency(amount,300,"EUR","€"){}
        float convertToBase(){
            return amount*300;
        }
        void display(){
            cout<<amount<<" "<<currencyCode;
        }
};
class Rupee: public Currency{
    public:
        Rupee(float amount):Currency(amount,3.34,"INR","₹"){}
        float convertToBase(){
            return amount*3.34;
        }
        void display(){
            cout<<amount<<" "<<currencyCode;
        }
};
int main(){
    float usd_amount,euro_amount,rupee_amount,converted;
    Currency *curr;
    cout<<"Enter the amount in USD: ";
    cin>>usd_amount;
    cout<<"Enter the amount in EUR: ";
    cin>>euro_amount;
    cout<<"Enter the amount in Indian Rupee: ";
    cin>>rupee_amount;
    Dollar usd(usd_amount);
    Euro euro(euro_amount);
    Rupee rupee(rupee_amount);
    curr=&usd;
    converted=curr->convertToBase();
    cout<<usd_amount<<" USD in base currency(PKR)="<<converted<<" PKR"<<endl;
    curr->convertTO(euro);
    curr->convertTO(rupee);
    curr=&euro;
    converted=curr->convertToBase();
    cout<<euro_amount<<" EUR in base currency(PKR)="<<converted<<" PKR"<<endl;
    curr->convertTO(usd);
    curr->convertTO(rupee);
    curr=&rupee;
    converted=curr->convertToBase();
    cout<<rupee_amount<<" INR in base currency(PKR)="<<converted<<" PKR"<<endl;
    curr->convertTO(usd);
    curr->convertTO(euro);
    return 0;
}