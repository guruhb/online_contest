#include <iostream>
//#include <array>
#include <vector>
#include <string> 

using namespace std;
int validPalindromIndex(const string& s);

int main() {
    int nlines;
    cin >> nlines; 
    
    vector<string> strvec;
    //FIXME: instead of having a string array, have the resultant integer array 
    //accept individual string and store the result in an resultant array
    string str;
    for(int i = 0; i < nlines; i++) {
        cin >> str;
        strvec.push_back(str);    
    }
    
    for(int i = 0; i < nlines; i++) {
        //cout << strvec[i] << endl;
        cout << validPalindromIndex(strvec[i]) << endl;
    }

    return 0;
}


int validPalindromIndex(const string& s) {
        for(int j = 0, k = s.size()-1; j < k ; ++j, --k) {
            if(s[j] != s[k]) {
                //cout <<"size : " << s.size() <<  " i j : " << s[j] << " i k : " << s[k] << endl;  
                if((j + 1) < s.size() && s[j+1] == s[k]) {
                    return j;
                }
                if(s[j] == s[k-1]) {
                    //cout << "k : " <<  k << endl; 
                    return k; //break; // might be break here ! 
                } else {
                    //cout << "j : " << j << endl; 
                    //break; // might be break here ! 
                    return j;
                }
            }//
        }
    return -1;
}
