/*
 
 
   interview 1 - blonde lady - ? -
    interpreting roman numerals

  interview 2 - cool enthusiastic guy - 
    print all permutations of a phone number
    angles between hands on a clock

  interview 3 - fat mean guy -
    merge k sorted arrays of length n into one
    practical considerations of both approaches
    merge 2 sorted arrays w/ code

  interview 4 - sorta nice ethnic guy -
    check if a tree is a "uni" tree - i.e. tree of all the same value
    check how many subtrees are uni subtrees
    deep copy a graph

 
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int parseRoman(string num);
int getRomanValue(char n);
void printNumberPerms(string num);
map<char, string> getNumMap();

int main(){

  cout << "interview 1 : " << endl;

  vector<string> tests;
  tests.push_back("IXIV");
  tests.push_back("LLXV");
  tests.push_back("IVXL");
  tests.push_back("CVXL");
  for(int i = 0; i < tests.size(); ++i){ cout << tests[i] << " = " << parseRoman(tests[i]) << endl; }

  cout << endl << "interview 2 : " << endl;

  vector<string> numbers;
  numbers.push_back("1234567");
  for(int i = 0; i < numbers.size(); ++i){ 
    cout << numbers[i] << " = " << endl; 
    printNumberPerms(numbers[i]); 
  }

  return 0;
}

map<char, string> getNumMap(){

  map<char, string> m;
  m.insert(make_pair('1', "ab"));
  m.insert(make_pair('2', "cd"));
  m.insert(make_pair('3', "e"));
  m.insert(make_pair('4', ""));
  m.insert(make_pair('5', "fgh"));
  m.insert(make_pair('6', "q"));
  m.insert(make_pair('7', "w"));
  m.insert(make_pair('8', "e"));
  return m;
}

void printNumberPerms(string num){

  cout << "hello" << endl;
  map<char, string> numMap = getNumMap();

}

int parseRoman(string num){

  /*
   * Do it from right to left, can check for errors that way
   */
  int sum = 0;
  int prev = -1;
  
  for(int i = (num.length() -1); i >= 0; --i){
    
    int cur = getRomanValue(num[i]);
    if(cur == -1) continue;

    if(cur < prev){

      //subtract cur, cause its a small subtractor
      sum -= cur;

      //make sure that the next elem isn't smaller than prev also,
      //otherwise this would be an invalid number
      if(i != 0) if(getRomanValue(num[i-1]) < prev) return -1; 
      
    }
    else{
      sum += cur;
    }

    prev = cur;
  }

  return sum;
}

int getRomanValue(char n){

  if(n == 'I') return 1;
  else if(n == 'V') return 5;
  else if(n == 'X') return 10;
  else if(n == 'L') return 50;
  else if(n == 'C') return 100;

  return -1;
}
