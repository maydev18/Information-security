#include <iostream>
#include <string>
using namespace std;

string encode(string data , int k){
    for(int i = 0 ; i < data.size() ; i++){
        char code = 'A' + (data[i] - 'A' + k)%26;
        if(data[i] > 'Z' || data[i] < 'A') continue;
        data[i] = code;
    }
    cout << data << endl;
    return data;
}
string decode(string data , int k){
    for(int i = 0 ; i < data.size() ; i++){
        int n = data[i] - 'A' - k;
        n = ((n % 26) + 26) % 26;
        char code = 'A' + n;
        if(data[i] > 'Z' || data[i] < 'A') continue;
        data[i] = code;
    }
    cout << data << endl;
    return data;
}
int main(){
    decode(encode("MAYANK" , 26) , 26);
    return 0;
}