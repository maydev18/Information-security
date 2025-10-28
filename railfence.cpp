#include<bits/stdc++.h>
using namespace std;

string encode(string data , int k){
    vector<vector<char>> rail(k , vector<char>(data.size() , '_'));
    int r = 0 , c = 0 , add = 1;
    while(c < data.size()){
        rail[r][c] = data[c];
        c++;
        r += add;
        if(r == k){
            add = -1;
            r = k-2;
        }
        else if(r == -1){
            add = 1;
            r = 1;
        }
    }
    string encrypt = "";
    for(int i = 0 ; i < k ; i++){
        for(int j = 0;  j < data.size() ; j++){
            if(rail[i][j] != '_') encrypt += rail[i][j];
        }
    }
    cout << encrypt;
    return encrypt;
}
string decode(string data , int k){
    cout << data << endl;
    vector<vector<char>> rail(k , vector<char>(data.size() , '_'));
    int r = 0 , c = 0 , add = 1;
    while(c < data.size()){
        rail[r][c] = '*';
        c++;
        r += add;
        if(r == k){
            add = -1;
            r = k-2;
        }
        if(r == -1){
            add = 1;
            r = 1;
        }
    }
    string decrypt = "";
    int curr = 0;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0;  j < data.size() ; j++){
            if(rail[i][j] == '*') rail[i][j] = data[curr++];
        }
    }
    r = 0 , c = 0 , add = 1;
    while(c < data.size()){
        decrypt += rail[r][c];
        c++;
        r += add;
        if(r == k){
            add = -1;
            r = k-2;
        }
        if(r == -1){
            add = 1;
            r = 1;
        }
    }
    return decrypt;
}

//testing
int main(){
    srand(time(0));
    for(int test = 1 ; test <= 1 ; test++){
        int k = 3+rand()%100;
        int n = 100 + rand()%10000;
        string data = "";
        for(int i = 0 ; i < n ; i++){
            char ch = rand()%255;
            if(ch == '_'){
                i--;
                continue;
            }
            data += ch;
        }
        string en = encode(data , k);
        string de = decode(en , k);
        if(data == de){
            cout << test << " test passed " << endl;
        }
        else{
            cout << "Test failed for data = " + data + " and k = " << k << endl;
            break;
        }
    }
    return 0;
}
