#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

class hill
{
private:
    int **mat;
    int **inverse_mat;
    int n = 2, m = 2;
    map<char, int> in_numeric;

public:
    hill();
    ~hill();

    string removeSpace(string msg);
    string encrypt(string message);
    string decrypt(string ciphertext);

    void matrixInverse();
    int mod(int number, int divisor);
    int modInverse(int number, int divisor);
    string matrixMultiply(int temp[], int k);

    void print();
};

// constructor
hill::hill()
{
    // this is the default constructor
    this->mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        this->mat[i] = new int[m];
    }

    mat[0][0] = 5;
    mat[0][1] = 8;
    mat[1][0] = 17;
    mat[1][1] = 3;

    // to calculate the inverse of the matrix
    matrixInverse();

    // to print the matrix and its inverse
    print();

    // mapping of alphabetic to number
    for (int i = 97; i <= 122; i++)
    {
        in_numeric[(char)i] = i - 97;
    }
}

// destructor
hill::~hill()
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
        delete[] inverse_mat[i];
    }
    delete[] mat;
    delete[] inverse_mat;
}

// function to find the inverse of a matrix
void hill::matrixInverse()
{
    inverse_mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        this->inverse_mat[i] = new int[m];
    }

    // finding the determinant (ab - bc);
    int det = mod(mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0], 26);

    cout << det << endl;
    // finding (1/det) modulus 26
    det = modInverse(det, 26);

    cout << det << endl;

    // caculating the cofactor matrix
    int cofactor[n][m];
    cofactor[0][0] = mat[1][1];
    cofactor[0][1] = -1 * mat[0][1];
    cofactor[1][0] = -1 * mat[1][0];
    cofactor[1][1] = mat[0][0];

    // finding the inverse matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << cofactor[i][j] << " ";
            inverse_mat[i][j] = mod((det * mod(cofactor[i][j], 26)), 26);
            // cout << cofactor[i][j] << " ";
        }
        // cout << endl;
    }
}

// function to find the modulus of a +ve and -ve numbers
int hill::mod(int number, int divisor)
{
    int mod;

    mod = abs(number) % divisor;
    if (number < 0)
    {
        mod = divisor - mod;
    }

    return mod;
}

// function to find the modulus of a number like (1/9)
int hill::modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// function to print the matrix and inverse matrix
void hill::print()
{
    cout << "\nMatrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nInverse Matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << inverse_mat[i][j] << " ";
        }
        cout << endl;
    }
}

// function to multiply matrix
string hill::matrixMultiply(int temp[], int k)
{
    int result[n] = {0};
    string output = "";
    if (k == 0)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i] += temp[j] * mat[j][i];
            }
            result[i] = mod(result[i], 26);
            output += (result[i] + 65);
            // cout << result[i] << " " << output << endl;
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i] += temp[j] * inverse_mat[j][i];
            }
            result[i] = mod(result[i], 26);
            output += (result[i] + 97);
        }
    }

    return output;
}

// function to remove space from the message
string hill::removeSpace(string msg)
{
    string output = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
        {
            output += msg[i];
        }
    }
    return output;
}

// function to encrypt the message
string hill::encrypt(string message)
{
    message = removeSpace(message);
    cout << "\nMessage: " << message << endl;

    string ciphertext = "";

    for (int i = 0; i < message.length(); i += n)
    {
        int temp[n];
        for (int j = 0; j < n; j++)
        {
            if ((i + j) > message.length())
            {
                temp[j] = in_numeric['x'];
            }
            else
            {
                temp[j] = in_numeric[message[i + j]];
            }
        }

        ciphertext += matrixMultiply(temp, 0);
    }

    return ciphertext;
}

// function to decrypt the message
string hill::decrypt(string ciphertext)
{
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += n)
    {
        int temp[n];
        for (int j = 0; j < n; j++)
        {
            temp[j] = in_numeric[tolower(ciphertext[i + j])];
        }

        plaintext += matrixMultiply(temp, 1);
    }

    return plaintext;
}

// main function
int main()
{
    // string message = "abcd";
    string message = "we are discovered save yourself";

    hill obj;
    string ciphertext = obj.encrypt(message);
    cout << "\nEncrypted message: " << ciphertext << endl;

    string plaintext = obj.decrypt(ciphertext);
    cout << "Decrypted message: " << plaintext << endl;

    cout << endl;
    return 0;
}