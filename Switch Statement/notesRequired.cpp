#include<iostream>

using namespace std;

int main(){
    int amount;
    cout<<"Enter the amount : ";
    cin>>amount;

    int num = 1;
    int note = 0;

    switch (num)
    {
    case 1:
        note = amount/100;
        amount = amount-(note*100);
        cout<<note<<" Rs. 100 notes required, ";
        num++; 

    case 2:
        note = amount/50;
        amount = amount-(note*50);
        cout<<note<<" Rs. 50 notes required, ";
        num++;

    case 3:
        note = amount/20;
        amount = amount-(note*20);
        cout<<note<<" Rs. 20 notes required and ";
        num++;

    case 4:
        note = amount/1;
        amount = amount-(note*1);
        cout<<note<<" Rs. 1 notes required."<<endl;
        num++;
    
    default:
        cout<<"Insufficient money!"<<endl;
        break;
    }
}