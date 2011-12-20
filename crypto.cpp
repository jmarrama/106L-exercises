#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

//use a deque for vigenere encryption

string VigenereEncrypt(deque<int> cypher, string cleartext){
  stringstream enc;

  for(int i = 0; i < cleartext.length(); ++i){
   
    enc << static_cast<char>(static_cast<int>(cleartext[i]) + cypher.front());
    int toback = cypher.front();
    cypher.pop_front();
    cypher.push_back(toback); 

  }

  return enc.str();
}

int main() {
  deque<int> cypher;
  cypher.push_back(1);
  cypher.push_back(2);
  cypher.push_back(3);
  cypher.push_back(2);
  string cleartext = "Hello!";

  string cyphertext = VigenereEncrypt(cypher, cleartext);

  cout << "Hello! = " << cyphertext << endl;

  return 0;

}

