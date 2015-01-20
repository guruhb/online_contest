#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyString {
    public : 
        MyString() : chbuf_(0), length_(0) {}
        MyString(char *str) : chbuf_(0), length_(0) { //FIXME improve the Initializer list properly 
            length_ = strlen(str);
            if(length_ > 1) 
                chbuf_ = (char *) malloc (length_);
            memcpy(chbuf_, str, length_);
            cout << chbuf_ << endl;
        }
    unsigned int length() { return length_; }

    unsigned int getNonVowelsCount(const char* startframe, const char* endframe) {
        char *t = chbuf_;
        if(length_ < 1) return 0;
        int sfl = strlen(startframe);

        //trim the startframe 
        //while(*startframe++ == *t++) ; //not required!

        //get endframe length
        int efl = strlen(endframe);
        int nvc = length_ - efl; //non vovels count
        //cout << " nvc : " << nvc << " efl : " << efl << endl; 
        for( ; *t && *(t + efl);  ) {
            *t = (char) tolower((int) *t);
            if(*t == 'a' || *t == 'e' || *t == 'i' || *t == 'o' || *t == 'u') {
                --nvc;
            }
            ++t;
        }
        return nvc;
    }
    
    MyString& operator= (const char* str) {
        int l = strlen(str);
        if(l < 1) return *this;

        if(chbuf_ != NULL) delete chbuf_;
        length_ = l;
        chbuf_ = (char *) malloc(length_);
        memcpy(chbuf_, str, length_);
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
        str = (char *) (*it).c_str();
        cout << str.getNonVowelsCount("www.", ".com") << "/" << str.length() << endl;
   }
    
    
   return 0;
}

