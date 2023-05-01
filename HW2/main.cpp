#include <iostream>
#include <string>
using namespace std;

bool inputcheck (int x )
{
    if (x<0){
        return false;
        
    }
    return true;
}

bool getinputs (int&a, int&b, int&c , int&q, int&w, int&z, string type)
{
    cout<<"Please enter how many minutes you used this month "<<type<<": ";
    cin>>a;
    if (! inputcheck(a)){
        cout<<"Number of minutes cannot be smaller than 0."<<endl;
        return 1;
    } else {
        cout<<"Please enter how many SMSs you sent this month "<<type<<": ";
        cin>>b;
    }
    
    if (! inputcheck(b)){
        cout<<"Number of SMSs cannot be smaller than 0."<<endl;
        return 1;
    } else {
        cout<<"Please enter how many MBs you used this month "<<type<<": ";
        cin>>c;
    }
    
    if (! inputcheck(c)){
        cout<<"Number of MBs cannot be smaller than 0."<<endl;
        return 1;
    } else {
        cout<<"Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
        cin>>q>>w>>z;
    }
    
    if (! inputcheck(q)){
        cout<<"Number of additional minutes packages cannot be smaller than 0."<<endl;
        return 1;
    }
    
    if (! inputcheck (w)){
        cout<<"Number of additional SMS packages cannot be smaller than 0."<<endl;
        return 1;
    }
    
    if (! inputcheck (z)){
        cout<<"Number of additional internet packages cannot be smaller than 0."<<endl;
        return 1;
    }
    
    return 0;
}
    
double costCalculate(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten, int eleven, int twelve, int thirteen, int fourteen, int fifteen, int sixteen, int seventeen){
    
    double TotalCost;
    TotalCost=0.0;
    TotalCost += seven + eleven * (four + five + six);
    int user_total_minutes, user_total_sms, user_total_mbs;
    user_total_minutes = eight + (four * twelve);
    user_total_sms = nine + (five * thirteen);
    user_total_mbs = ten  + (six * fourteen);
    
    
    if (one > user_total_minutes){
        TotalCost+= (one - user_total_minutes) * fifteen;
       
    }
    if (two > user_total_sms){
        TotalCost+= (two - user_total_sms) * sixteen;
        
    }
    if (three > user_total_mbs){
        TotalCost+= ((three - user_total_mbs)*1024/100) * seventeen;
        
    }
    
    
    
    return TotalCost;
    
}
    
void displayResults (int packagep, string type2, double totalcost){
    if (totalcost <= packagep){
        cout << "Total cost of your phone usage " << type2 << " is " << totalcost << " TL. You did not exceed your package." << endl;
    }
    else if (totalcost > packagep && totalcost < 2 * packagep){
        cout << "Total cost of your phone usage " << type2 << " is " << totalcost << " TL. You exceeded your package." << endl;
    }
    else{
        cout << "Total cost of your phone usage " << type2 << " is " << totalcost << " TL. You exceeded your package too much. We suggest you to change your package." << endl;
    }
}






int main() {
    
    string Turkey = "in Turkey";
    string Internationally = "Internationally";
    int LocalMinutesUsed, LocalSmsUsed, LocalMbsUsed;
    int add_pack_minutes, add_pack_sms, add_pack_mbs;
    double totalcost2;
    double totalcost3;
    const int intpackageprice = 300;
    const int localpackageprice = 120;
    int IntMinutesUsed, IntSmsUsed, IntMbsUsed;
    int int_add_pack_minutes, int_add_pack_sms, int_add_pack_mbs;
    
    
    
    
    
    if (getinputs(LocalMinutesUsed,LocalSmsUsed,LocalMbsUsed,add_pack_minutes,add_pack_sms,add_pack_mbs,Turkey)){
        return 1;
    }
    
    totalcost2 = costCalculate(LocalMinutesUsed,LocalSmsUsed,LocalMbsUsed,add_pack_minutes,add_pack_sms,add_pack_mbs,120,250,1000,5120,30,250,250,1024,2,1,2);
    displayResults(localpackageprice,Turkey,totalcost2);
        
   
    if (getinputs(IntMinutesUsed,IntSmsUsed,IntMbsUsed,int_add_pack_minutes,int_add_pack_sms,int_add_pack_mbs,Internationally)){
        return 1;
    }
    totalcost3 = costCalculate(IntMinutesUsed,IntSmsUsed,IntMbsUsed,int_add_pack_minutes,int_add_pack_sms,int_add_pack_mbs,300,100,200,2048,100,50,100,1024,15,3,5);
    displayResults(intpackageprice,Internationally,totalcost3);
        
    
    return 0;
}

