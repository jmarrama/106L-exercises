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
#include <iterator>
#include <map>

using namespace std;

int parseRoman(string num);
int getRomanValue(char n);
void printNumberPerms(string num);
map<char, string> getNumMap();
vector<int> mergeLists(vector<vector<int> > arrs);

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
  numbers.push_back("12322-7");
  for(int i = 0; i < numbers.size(); ++i){ 
    cout << numbers[i] << " = " << endl; 
    printNumberPerms(numbers[i]); 
  }

  cout << endl << "interview 3 : " << endl;

  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  vector<int> b;
  b.push_back(4);
  b.push_back(5);
  b.push_back(6);
  vector<vector<int> > lists;
  lists.push_back(a);
  lists.push_back(b);
  vector<int> merged = mergeLists(lists);
  copy(merged.begin(), merged.end(), ostream_iterator<int>(cout, " ")); 

  return 0;
}

vector<int> mergeTwoLists(vector<vector<int> > arrs){

  return arrs[0];
}

vector<int> mergeLists(vector<vector<int> > arrs){

  if(arrs.size() == 2) return mergeTwoLists(arrs);

  return arrs[0];
}

map<char, string> getNumMap(){
  map<char, string> m;
  m.insert(make_pair('1', "ab"));
  m.insert(make_pair('2', "cd"));
  m.insert(make_pair('3', "e"));
  m.insert(make_pair('4', ""));
  m.insert(make_pair('5', "gh"));
  m.insert(make_pair('6', "q"));
  m.insert(make_pair('7', "w"));
  m.insert(make_pair('8', "e"));
  return m;
}

void printPerm(map<char, string> & numMap, string num, string cur, int pos){

  if(pos == num.length()){
    cout << cur << endl;
    return;
  }

  map<char, string>::iterator itr = numMap.find(num[pos]);
  if(itr != numMap.end()){
    string ms = itr->second;
    if(ms.length() == 0) printPerm(numMap, num, cur, ++pos);
    else {
      for(int i = 0; i < ms.length(); ++i){
        string newcur = cur;
        newcur += ms[i];
        printPerm(numMap, num, newcur, pos + 1);
      }
    }
  }
  else{
    printPerm(numMap, num, cur, ++pos);
  }
}

void printNumberPerms(string num){

  map<char, string> numMap = getNumMap();
  printPerm(numMap, num, "", 0);
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
