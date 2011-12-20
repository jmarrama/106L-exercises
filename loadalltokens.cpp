#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<string> LoadAllTokens(string filename){

  ifstream fstr(filename.c_str());
  istream_iterator<string> endItr;
  vector<string> tokens;

  //go through the file
  for(istream_iterator<string> itr(fstr); itr != endItr; ++itr){
    //cout << *itr << endl;
    tokens.push_back(*itr);
  }

  return tokens;
}

int main() {

  string filename = "test.txt";
  cout << "Loading in file " << filename << endl;

  vector<string> file = LoadAllTokens(filename);

  for(vector<string>::iterator it = file.begin(); it != file.end(); ++it){
    cout << *it << " " << endl;
  }
 
  return 0;

}

