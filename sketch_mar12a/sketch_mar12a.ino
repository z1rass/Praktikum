#include<iostream>
#include <map>

using namespace std;


void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    String inputText = Serial.readString();
    processText(inputText);
}

void processText(String userInput) {
  map<char, string> morseMap = {
            {'A', "01"}, {'B', "1000"}, {'C', "1010"},
            {'D', "100"}, {'E', "0"}, {'F', "0010"},
            {'G', "110"}, {'H', "0000"}, {'I', "00"},
            {'J', "0111"}, {'K', "101"}, {'L', "0100"},
            {'M', "11"}, {'N', "10"}, {'O', "111"},
            {'P', "0101"}, {'Q', "1011"}, {'R', "010"},
            {'S', "000"}, {'T', "1"}, {'U', "001"},
            {'V', "0001"}, {'W', "011"}, {'X', "1001"},
            {'Y', "1011"}, {'Z', "1100"},
            {'0', "11111"}, {'1', "01111"}, {'2', "00111"},
            {'3', "00011"}, {'4', "00001"}, {'5', "00000"},
            {'6', "10000"}, {'7', "11000"}, {'8', "11100"},
            {'9', "11110"}, {' ', " "}
  };
  for (char i : userInput) {
        auto it = morseMap.find(i);
        if (it != morseMap.end()) {
            cout << it->second << ' ';
        } else {
            cout << "Символ не найден в morseMap" << endl;
        }
    }
}
