
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std;

int main()
{
    double initial, rate, recurring, years, subsist, end, balance, gain, yearlytotal;
    int endMonth = 0;
    
    cout<<"Input the initial investment: ";
    cin>>initial;
    cout<<"Input the yearly interest rate (APY): ";
    cin>>rate;
    cout<<"Input your average monthly contribution: ";
    cin>>recurring;
    cout<<"Input your monthly living expenses (rent, food, etc.): ";
    cin>>subsist;
    
    double x = (1 + ((rate/12)/100));
    
    balance = initial;
    
    double adj = (1 + (((rate/100))/12));
    
    double numerator = log(subsist/(initial * (log(adj))));
    
    double result = numerator/(log(adj));   //one-shot formula to find when the account starts earing a certain amount of interest (not counting recurring contribution)
    
    int yearsresult = ((result+1) / 12);
    
    
    cout<<endl;
    for(int i = 0; gain<subsist; i++){
        gain = ((balance * x)) - balance;
        balance +=recurring;
        balance = (balance * x);
        if(subsist - gain < gain/20){
            cout<<"\nAfter month "<<i+1<<": $"<<fixed<<setprecision(2)<<balance<<setprecision(2)<<"  (+$"<<gain<<")/month"<<endl;
        }
        endMonth = i+1;
    }
    
    
    
    int series_remainder_months = round(((endMonth-1)%12) + 0.5);
    double remaindermonths = result-(12 * yearsresult);
    int correctedMonths = round(remaindermonths + 0.5);
    
    if (remaindermonths < 1){
        correctedMonths = 0;
    }
    
    if (yearsresult < 0){
        yearsresult = 0;
    }
    
    int difference = result - endMonth;
    int d_years = difference/12;
    int d_months = difference - (12 * d_years);
    
    if((endMonth/12) == 1){
        cout<<"\n\nYou would start earning a passive income of $"<<subsist<<"/month after 1 year and "<<series_remainder_months<<" months."<<endl;
    }
    else{
        cout<<"\n\nYou would start earning a passive income of $"<<subsist<<"/month after "<<(endMonth/12)<<" years and "<<series_remainder_months<<" months."<<endl;
    }
    cout<<"\nThis is "<<d_years<<" years and "<<d_months<<" months sooner than if you made no recurring contributions."<<endl;
    
    
    

    return 0;
}
