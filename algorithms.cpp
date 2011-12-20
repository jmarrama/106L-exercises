#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>

using namespace std;

void PrintVector(vector<int> v){
 copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); 
}

void BiasedSort(vector<string> &v){

  //sort elems
  sort(v.begin(), v.end());
  
  //move all strings with "MeFirst" to front of array
  string topstr = "Me First";
  vector<string>::iterator topStart = lower_bound(v.begin(), v.end(), topstr);
  if(topStart != v.end()){
    vector<string>::iterator topEnd = upper_bound(v.begin(), v.end(), topstr);
    rotate(v.begin(), topStart, topEnd);
  } 
}

int count(vector<int>::iterator start, vector<int>::iterator stop, int element){

  int count = 0;
  for(vector<int>::iterator itr = start; itr != stop; ++itr){
    if(*itr == element) count ++;
  }
  return count;
}

int main(){

  vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(3);
  v.push_back(3);
  v.push_back(4);

  //remove(v.begin(), v.end(), 3);

  PrintVector(v);
  cout << endl;

  vector<string> s;
  s.push_back("hi");
  s.push_back("hello");
  s.push_back("Hello");
  s.push_back("Me First");
  s.push_back("bye");
  s.push_back("Bye");
  s.push_back("Me First");

  BiasedSort(s);

  copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));

  cout << "count of 3 = " << count(v.begin(), v.end(), 3) << endl;

  return 0;
}
