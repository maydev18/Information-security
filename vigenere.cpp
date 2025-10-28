#include <bits/stdc++.h>
using namespace std;



string encode(string data , string key){
    string ans = "";
    int j = 0;
    for(int i = 0 ; i < data.size() ; i++){
        ans += 'A' + (data[i] + key[j])%26;
        j = (j + 1)%key.size();
    }
    return ans;
}
string decode(string data , string key){
    string ans = "";
    int j = 0;
    for(int i = 0 ; i < data.size() ; i++){
        ans += 'A' + ((data[i] - key[j]) + 26 )%26;
        j = (j + 1)%key.size();
    }
    return ans;
}
int main(){
    cout << decode(encode("WEAREDISCOVEREDSAVEYOURSELF" , "DECEPTIVE") , "DECEPTIVE");
}


