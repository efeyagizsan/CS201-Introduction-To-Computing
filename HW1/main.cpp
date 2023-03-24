#include <iostream>
using namespace std;
int main() {

    double friesP,HamburgerP,CheeseburgerP,WaterP,SodaP,Subtotal,VAT,ServiceFee,Discount,TotalPrice;
    friesP = 59.50;
    HamburgerP = 100;
    CheeseburgerP = 111;
    WaterP = 10;
    SodaP = 30;

    int water,soda,fries,hamburger,cheese,student;
    cheese = 0;
    cout<<"Enter the quantity of each product you have ordered: "<<endl;
    cout<<"Water: ";
    cin>>water;
    cout<<"Soda: ";
    cin>>soda;
    cout<<"Fries: ";
    cin>>fries;
    cout<<"Hamburger: ";
    cin>>hamburger;


    if (hamburger > 0){
        cout<<"Add cheese to your hamburger(s)? (1 for yes, 0 for no): ";
        cin>>cheese;

    }
    if (cheese == 0){
        Subtotal = (friesP * fries) + (HamburgerP * hamburger) + (WaterP * water) + (SodaP * soda);
        VAT = ((friesP * fries)/10) + ((HamburgerP * hamburger)/10) + ((SodaP * soda)/2);

    } else {
        Subtotal = (friesP * fries) + (CheeseburgerP * hamburger) + (WaterP * water) + (SodaP * soda);
        VAT = ((friesP * fries)/10) + ((CheeseburgerP * hamburger)/10) + ((SodaP * soda)/2);

    }




    Discount = 0;

    cout<<"Are you a student? (1 for yes, 0 for no): ";
    cin>>student;

    if (student == 1){
        cout<<"Student discount applied!";
        Discount = (Subtotal + VAT)/4;
    }

    if ((Subtotal + VAT - Discount) >= 375 ){
        ServiceFee = ( Subtotal + VAT -Discount ) *6/100;
    }

    if ((Subtotal + VAT - Discount) < 375 && (Subtotal+VAT - Discount) >= 175){
        ServiceFee = (Subtotal+VAT-Discount) *8/100;

    }
    if ( 175 > (Subtotal+VAT - Discount)  ){
        ServiceFee = (Subtotal+VAT-Discount)/10;
    }

    TotalPrice = Subtotal + VAT + ServiceFee - Discount;

    if (TotalPrice == 0){
        cout<<endl;
        cout<<"==================================="<<endl;
        cout<<"         Restaurant Invoice          "<<endl;
        cout<<"==================================="<<endl;
        cout<<"The customer has not made a purchase or placed an order!"<<endl;

    }

    if (TotalPrice > 0){
        cout<<endl;
        cout<<"==================================="<<endl;
        cout<<"         Restaurant Invoice          "<<endl;
        cout<<"==================================="<<endl;

    }

    if (water > 0){
        cout<<"Water ("<<water<<"): "<<WaterP*water<<" TL"<<endl;

    }
    if (soda > 0){
        cout<<"Soda ("<<soda<<"): "<<SodaP*soda<<" TL"<<endl;

    }
    if (fries > 0){
        cout<<"Fries ("<<fries<<"): "<<friesP*fries<<" TL"<<endl;

    }
    if (hamburger > 0 && cheese ==0){
        cout<<"Hamburgers ("<<hamburger<<"): "<<HamburgerP*hamburger<<" TL"<<endl;

    }
    if (cheese ==1){
        cout<<"Hamburgers ("<<hamburger<<"): "<<CheeseburgerP*hamburger<<" TL"<<endl;

    }

    if (TotalPrice > 0){
        cout<<"Subtotal: "<<Subtotal<<" TL"<<endl<<endl;
        cout<<"VAT: "<<VAT<<" TL"<<endl;
        if (Discount != 0){
            cout<<"Student discount: "<<-Discount<<" TL"<<endl;
        }

        cout<<"Service fee: "<<ServiceFee<<" TL"<<endl;
        cout<<"Total price: "<<TotalPrice<<" TL"<<endl;
    }
    
    return 0;



}


