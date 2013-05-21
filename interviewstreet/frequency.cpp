#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<functional>
#include <algorithm>  

using namespace std;

int cmp(const pair<string,int>& x,const pair<string,int>& y)  
{  
    return x.second>y.second;  
}  




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string tmpstr ;
    int arg ;
    map<string, int> frq ;
    cin >> arg ;
    for(int i = 0; i < arg ; i++){
        cin >> tmpstr ;
        map<string, int>::iterator it = frq.find(tmpstr);
        if(it == frq.end()){
            frq[tmpstr] = 1 ;
        }
        else 
            frq[tmpstr] = frq[tmpstr] +1 ;
    }

    cin >> arg ;
    vector<pair<string,int> > vec; 
    for(map<string,int>::iterator curr=frq.begin();curr!=frq.end();curr++)  
        vec.push_back(make_pair(curr->first,curr->second));  

    sort(vec.begin(),vec.end(),cmp);
    
     for(int i=0;i<arg && i < vec.size();i++)  
         cout << vec[i].first << endl ; 

    return 0;
}
