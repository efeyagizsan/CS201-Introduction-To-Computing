#include <iostream>
#include <string>
using namespace std;

void searchtypefordoublestar (string& source1, string& search1){
    string searchWithoutLast2Signs = search1.substr(0,search1.length()-2);
    int searchPosition2 = source1.find(searchWithoutLast2Signs);

    while(searchPosition2 != string::npos){
        int pidx = source1.rfind(" ",searchPosition2);
        int postidx = source1.find(" ",searchPosition2);
        cout << "index: " << searchPosition2-1 << " word: " << source1.substr(pidx+1,((postidx-1)-pidx)) << endl;
        searchPosition2 = source1.find(searchWithoutLast2Signs, searchPosition2+1);
    }
}



void searchtypeforstar (string& source2, string& search2){
    string sws = search2.substr(0,search2.length()-1);
    int sP = source2.find(sws);

    while(sP != string::npos){
        if(source2.substr(source2.rfind(" ",sP)+1,sws.length()) != sws &&
           source2.substr(source2.find(" ",sP)-sws.length(),sws.length()) != sws){
            int pSI = source2.rfind(" ",sP);
            int poSI = source2.find(" ",sP);
            cout << "index: " << sP-1 << " word: " << source2.substr(pSI+1,((poSI-1)-pSI)) << endl;
        }
        sP = source2.find(sws,sP+1);
    }
}

void searchtypeforplus (string& source3, string& search3){
    string SWS = search3.substr(0,search3.length()-1);
    int searchPosition = source3.find(SWS);

    while(searchPosition != string::npos){
        if(source3.at(searchPosition-1) == ' '){
            int postSpaceIndex = source3.find(" ",searchPosition);
            cout << "index: " << searchPosition-1 << " word: " << source3.substr(searchPosition,(postSpaceIndex-searchPosition)) << endl;
        }
        searchPosition = source3.find(SWS,searchPosition+1);
    }
}

void searchtypefordot (string&source4, string& search4){
    string SwS = search4.substr(0,search4.length()-1);
    int searchPosition1 = source4.find(SwS);

    while(searchPosition1 != string::npos){
        if(source4.at(searchPosition1 + SwS.length()) == ' '){
            int prevSpaceIndex = source4.rfind(" ",searchPosition1);
            int postSpaceIndex = source4.find(" ",searchPosition1);
            cout << "index: " << searchPosition1-1 << " word: " << source4.substr(prevSpaceIndex+1,((postSpaceIndex-1)-prevSpaceIndex)) << endl;
        }
        searchPosition1 = source4.find(SwS,searchPosition1+1);
    }
}







string getsource(string SR){
    string sourcestring;
    bool check = true;

    while (check && cin >> SR){
        if (SR == "End" || SR == "eNd" || SR == "enD" || SR == "ENd" || SR == "EnD" || SR == "eND" || SR == "end" || SR == "END")
            check = false;
        else if (check = true)
            sourcestring += SR + " ";
    }

    return sourcestring.substr(0, sourcestring.length() -1);
}

bool sourcecheck(const string & SR1){
    bool check = false;

    for(unsigned int i = 0; i < SR1.length(); ++i)
        if ((SR1.at(i) <= 31) || (33 <= SR1.at(i) && SR1.at(i) <= 47) || (58 <= SR1.at(i) && SR1.at(i) <= 64) ||
            (91 <= SR1.at(i) && SR1.at(i) <= 96) ||(123 <= SR1.at(i) && SR1.at(i) <= 127))
            check = true;

    return check;
}


int main(){


    string sr1, sourcestring1, search1;

    cout << "Enter source string: ";
    sourcestring1 = getsource(sr1);

    while (sourcecheck(sourcestring1)){
        cout << "Enter source string: ";
        sourcestring1 = getsource(sr1);
    }

    sourcestring1 = " " + sourcestring1 + " ";



    cout << "Enter search string: ";
    cin >> search1;

    while(search1 != "Quit" && search1 != "qUit" && search1 != "quIt" && search1 != "quiT" && search1 != "QUit" && search1 != "QuIt" && search1 != "QuiT" && search1 != "qUIt" && search1 != "qUiT" && search1 != "quIT" && search1 != "QUIt" && search1 != "QUiT" && search1 != "QuIT" && search1 != "qUIT" && search1 != "QUIT" && search1 != "quit" ){
        string sl2s = search1.substr(search1.length()-2);
        string sls = search1.substr(search1.length()-1);

        if((search1.length() < 2) || (sls != "+" && sls != "." && sls != "*")){
            cout << "Enter search string: ";
            cin >> search1;
            continue;
        }




        if (sls == "+"){
            searchtypeforplus(sourcestring1,search1);
        }




        else if (sls == "."){

            searchtypefordot(sourcestring1,search1);
        }




        else if (sls == "*" && sl2s != "**"){
            searchtypeforstar(sourcestring1,search1);
        }




        else if (sl2s == "**" && search1.length() > 2){
            searchtypefordoublestar(sourcestring1,search1);

        }


        cout << "Enter search string: ";
        cin >> search1;
    }

    return 0;
}

