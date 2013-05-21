#include <iostream>
#include <vector>
#include <string>


using namespace std;




class Circular {
public :
    Circular( int n ):vec(n){
        curcount = 0 ;
        maxsize = n ;
        nextpos = 0 ;
    }
    void A( const char *p ){
        if( nextpos == maxsize) 
            nextpos = 0;
        vec[nextpos] = p ;
        if(curcount != maxsize)//add
            curcount ++ ;
        nextpos ++ ;
    }
    int R(int count){
        if(count >= curcount)//too mutch
            curcount = 0 ;
        else {
            curcount = curcount - count ;//move the last one
        }
        return 0;
    }

    void L(){
        int beg = 0 ;
        if( nextpos-curcount >= 0){
            beg = nextpos-curcount ;
        }
        else {
            beg = maxsize + ( nextpos - curcount );
        }
        for(int i= beg, c=1; c <= curcount; ++i, ++c ) {
            if(i == maxsize)
                i = 0 ;
            cout << vec[i] << endl ;
            if( i+1 == nextpos)
                break ;
        }
    }


private:
    vector<string> vec; 
    int nextpos ;
    int curcount ;
    int maxsize;
        
};
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int eflag = 1;
    int arg ;
    cin >> arg ;
    Circular cr(arg);

    while(eflag){
        char cmd;
        string tmpstr ;
        cin >> cmd ;
        switch(cmd){
            case 'A':
                cin >> arg ;
                for(int i = 0; i < arg ; i++){
                    cin >> tmpstr ;
                    cr.A(tmpstr.c_str());
                }
                break ;
            case 'R':
                cin >> arg ;
                cr.R(arg);
                break ;
            case 'L':
                cr.L();
                break ;
            case 'Q':
                eflag = 0 ;
                break ;
            default :
                cout << "input error!" << endl ;
                break ;
        }
    }

    return 0;
}
