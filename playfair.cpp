#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
char arr[5][5];
void build_matrix(string key){
    vector<bool> hash(26 , 0);
    hash['J'-'A'] = 1;
    int curr = 0;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(curr < key.size() && !hash[key[curr]-'A']){
                hash[key[curr]-'A'] = 1;
                arr[i][j] = key[curr];
                curr++;
            }
        }
    }
    char ch = 'A';
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(hash[ch-'A']){
                ch++;
                j--;
            }
            else if(ch <= 'Z' && (arr[i][j] > 'Z' || arr[i][j] < 'A')){
                hash[ch-'A'] = 1;
                arr[i][j] = ch;
                ch++;
            }
        }
    }
}
vector<int> findpos(char c1 , char c2){
    vector<int> ans(4);
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(arr[i][j] == c1){
                ans[0] = i;
                ans[1] = j;
            }
            if(arr[i][j] == c2){
                ans[2] = i;
                ans[3] = j;
            }
        }
    }
    return ans;
}
string makestring(string data){
    string ans = "";
    int n = data.size();
    for(int i = 0 ; i < n ; i++){
        if(i == n-1){
            ans += data[i];
            ans += 'Z';
        }
        else{
            if(data[i] != data[i+1]){
                ans += data[i];
                ans += data[i+1];
                i++;
            }
            else{
                ans += data[i];
                ans += 'Z';
            }
        }
    }
    return ans;
}
string encode(string data , string key){
    build_matrix(key);
    data = makestring(data);
    string encrypt = "";
    for(int i = 0 ; i < data.size() ; i += 2){
        auto v = findpos(data[i] , data[i+1]);
        if(v[0] == v[2]){
            encrypt += arr[v[0]][(v[1]+1)%5];
            encrypt += arr[v[2]][(v[3]+1)%5];
        }
        else if(v[1] == v[3]){
            encrypt += arr[(v[0]+1)%5][v[1]];
            encrypt += arr[(v[2]+1)%5][v[3]];
        }
        else{
            encrypt += arr[v[0]][v[3]];
            encrypt += arr[v[2]][v[1]];
        }
    }
    return encrypt;
}
string decode(string data){
    string decrypt = "";
    for(int i = 0 ; i < data.size() ; i += 2){
        auto v = findpos(data[i] , data[i+1]);
        if(v[0] == v[2]){
            decrypt += arr[v[0]][((v[1]-1)+5)%5];
            decrypt += arr[v[2]][((v[3]-1)+5)%5];
        }
        else if(v[1] == v[3]){
            decrypt += arr[((v[0]-1)+5)%5][v[1]];
            decrypt += arr[((v[2]-1)+5)%5][v[3]];
        }
        else{
            decrypt += arr[v[0]][v[3]];
            decrypt += arr[v[2]][v[1]];
        }
    }
    string decry = "";
    for(int i = 0 ; i < decrypt.size() ; i++){
        if(decrypt[i] != 'Z'){
            decry += decrypt[i];
        }
    }
    return decry;
}
void flushOut(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            arr[i][j] = '!';
        }
    }
}

//testing the code
int main(){   
    srand(time(0)); 
    for(int test = 1 ; test <= 1000 ; test++){
        int keysize = 5+rand()%100;
        int datasize = 1 + rand()%10000;
        string key = "" , data = "";
        for(int i = 0 ; i < keysize ; i++){
            int r = 'A' + rand()%26;
            key += char(r);
        }
        for(int i = 0 ; i < datasize ; i++){
            int r = 'A' + rand()%26;
            if(r == 'Z' || r == 'J'){
                i--;
                continue;
            }
            data += char(r);
        }
        string en = encode(data , key);
        string de = decode(en);
        if(data != de){
            cout << "Wrong" << endl << de << endl << data << endl << key << endl << test ;
            break;
        }
        else{
            cout << test << " test passed successfully" << endl;
        }
        flushOut();
    }
}