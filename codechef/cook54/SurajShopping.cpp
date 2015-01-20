#include <iostream>
using namespace std;

const int PANAGRAM_BIT_SET = 0x03FFFFFF;
int main() {
    string str;
    //cin >> str;  only works till space 
    getline(cin, str); 
    //cout << str.size() << endl;
    int bitflag = 0;
    int tbit = 0;
    char lchar = ' ';
    for(int i = 0; i < str.size(); ++i) {
        //cout << (char)tolower(str[i]);
        lchar = (char)tolower(str[i]); 
        if(lchar  >= 'a' && lchar <= 'z') { 
            tbit = 1 << (lchar  - 'a');
            //cout << " char " << (char)tolower(str[i]) << " tbit : " << hex << tbit << endl; 
            bitflag |= tbit;
        }
    }
   
   //cout << "bitflag : " << hex << bitflag << endl;  
    if(PANAGRAM_BIT_SET == bitflag)
        cout << "pangram" << endl;
    else 
        cout << "not pangram" << endl;


    //cout << endl;
    return 0;
}
