#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<functional>
#include <algorithm>  

//g++ multiplyExceptSelf.cpp

using namespace std;
typedef long long int64;

int main() {
    int arg;
    cin >> arg ;

    int64 vec[arg+2] ;
    int64 kulvstart[arg+2];
    int64 kulvend[arg+2] ;

    kulvstart[0] = kulvstart[arg+1] = 1 ;
    kulvend[0] = kulvend[arg+1] = 1 ;

    for(int i = 1; i <= arg ; i++){
        cin >> vec[i] ;
    }
    
    for(int i = 1; i <= arg ; i++){
        kulvstart[i] =  kulvstart[i-1]*vec[i] ;
    }

    for(int i = arg ; i >=1 ; i--){
        kulvend[i] = kulvend[i+1]*vec[i] ;
    }

    for(int i = 1 ; i <= arg ; ++i){
        cout << kulvstart[i-1]*kulvend[i+1] << endl ;
    }


    return 0;
}
