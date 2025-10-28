#include <bits/stdc++.h>
using namespace std;
int encryptKey[26] = {0};
int decryptKey[26] = {0};

void makekeys(){
    for(int i = 0 ; i < 26 ; i++){
        encryptKey[i] = -1;
        decryptKey[i] = -1;
    }
    for(int i = 0 ; i < 26 ; i++){
        int r = rand()%26;
        if(decryptKey[r] != -1){
            i--;
            continue;
        }
        decryptKey[r] = i;
        encryptKey[i] = r;
    }
}
string encode(string data){
    for(int i = 0 ; i < data.size() ; i++){
        data[i]  = ('A' + encryptKey[data[i]-'A']);
    }
    return data;
}
string decode(string data){
    for(int i = 0 ; i < data.size() ; i++) data[i] = 'A' + decryptKey[data[i]-'A'];
    return data;
}
int main(){
    srand(time(0));
    for(int test = 1 ; test <= 1000 ; test++){
        makekeys();
        int n = 10 + rand()%10000;
        string data = "";
        for(int i = 0 ; i < n ; i++){
            data += 'A' + (rand()%26);
        }
        if(decode(encode(data)) != data){
            cout << "WRONG" << endl;
            break;
        }
        else{
            cout << test << " test passed successfully" << endl;
        }
    }
    return 0;
}