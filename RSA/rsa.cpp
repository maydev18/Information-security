#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using ll = long long;
int exp(int a , int b , int mod){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = (1ll * ans * a) % mod;
        }
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ans;
}
//a*x + b*y = gcd
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modinv(ll a, ll m) {
    long long x, y;
    long long g = gcd(a, m, x, y);
    if (g != 1) return -1; // no inverse
    x %= m;
    if (x < 0) x += m;
    return x;
}

int main() {
    ll p = 17, q = 11;
    ll n = p * q;                
    ll phi = (p - 1) * (q - 1);   

    // public exponent e (coprime with phi)
    ll e = 7;
    long long d = modinv(e, phi); 

    if (d == -1) {
        cerr << "Failed to compute modular inverse\n";
        return 1;
    }

    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "n = " << n << "\n";
    cout << "phi = " << phi << "\n";
    cout << "e = " << e << "\n";
    cout << "d = " << d << "\n\n";

    // Test message 
    ll m = 88; 
    cout << "Plaintext m = " << m << endl;

    // Encrypt: c = m^e mod n
    ll c = exp(m, e, n);
    cout << "Ciphertext c = " << c << endl;

    // Decrypt: m' = c^d mod n
    ll m2 = exp(c, d, n);
    cout << "Decrypted m' = "  << m2 << endl;

    if (m2 == m) cout << "SUCCESS: decrypted matches original\n";
    else cout << "FAIL: mismatch\n";

    return 0;
}
