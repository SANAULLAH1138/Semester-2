#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(string text) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i++) {
        encrypted += char(text[i] + (i + 1)); 
    }
    return encrypted;
}

string decrypt(string encryptedText) {
    string decrypted = "";
    for (int i = 0; i < encryptedText.length(); i++) {
        decrypted += char(encryptedText[i] - (i + 1)); 
    }
    return decrypted;
}

int main() {
    string text;
    cout << "Enter String = ";
    getline(cin, text);

    cout << "Normal Text:= " << text << endl;

    string encryptedText = encrypt(text);

    ofstream outFile("encrypted.txt");
    outFile << encryptedText;
    outFile.close();
    cout << "Encrypted text inserted in file" << endl;

    ifstream inFile("encrypted.txt");
    string fileContent;
    getline(inFile, fileContent);
    inFile.close();

    string decryptedText = decrypt(fileContent);
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decryptedText << endl;

    return 0;
}

