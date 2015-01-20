#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyString {
    public : 
        MyString() : chbuf_(NULL), length_(0) {}
        MyString(char *str) : chbuf_(0), length_(0) { //FIXME improve the Initializer list properly 
            length_ = strlen(str);
            if(length_ > 1) 
                chbuf_ = (char *) malloc (length_);
            memcpy(chbuf_, str, length_);
            //cout << chbuf_ << endl;
        }
    unsigned int length() { return length_; }
    
    
    int non_vowels(const string &s) {
       
        char *sp = strchr(s.c_str(), (int) '.'); // www.
        char *ep = strrchr(s.c_str(), (int) '.'); // .com
        char t;
        int nvc = s.length() - 4;
        ++sp;
        while( sp != ep) {
            t = tolower(*sp);
           // cout << t << " "; 
            if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
                --nvc;
            ++sp;
                 
        }
        //cout << s << " nvc : " << nvc << "   " ;

        return nvc;
    }
    
    
    MyString& operator= (const char* str) {
        int l = strlen(str);
        if(l < 1) return *this;

        if(chbuf_ != NULL) delete chbuf_;
        length_ = l;
        chbuf_ = (char *) malloc(length_);
        memcpy(chbuf_, str, (length_+1));
        //chbuf_[length_] = NULL;

        //cout << " =  " << chbuf_  << " length_ " << length_ << endl; 
        return *this; 
    }
    ~MyString() {
        if(chbuf_ != NULL) delete chbuf_;
        length_ = 0;
    }
    private : 
        char *chbuf_;
        unsigned int length_;
};


int main() {
    MyString str;

   //cout << str.getNonVowelsCount("www.", ".com") << "/" << str.length()+4 << endl; 
   int ntest; 
   cin >> ntest;

   vector<string> inputs;
   string s;
   while(ntest--) {
        cin >> s;
        inputs.push_back(s);
   }
    
   for(vector<string>::iterator it = inputs.begin(); it != inputs.end(); ++it) {
        //str = (char *) (*it).c_str();
        //cout << *it << " ref cnt : " << (*it).length() << endl;
        cout << str.non_vowels(*it) << "/" << (*it).length() << endl;
   }
    
    
   return 0;
}

