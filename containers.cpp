#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <set>

using namespace std;

int NumberDuplicateEntries(map<string, string> m){

  int numDupes = 0;
  set<string> dupes;

  for(map<string, string>::iterator itr = m.begin(); itr != m.end(); ++itr){
    string value = itr->second;
    if(dupes.find(itr->second) != dupes.end()) numDupes ++;
    else dupes.insert(itr->second);
  }

  return numDupes;

}

void CountLetters(ifstream &fstr, map<char, int> &ccounts){

  while(fstr.good()){
    char c = static_cast<char>(fstr.get());
    ccounts[c] = ccounts[c] + 1;
  }

}

void PrintMatchingPrefixes(set<string> s, string prefix){

  //set<string>::iterator stop = s.upper_bound(prefix);

  //hack to get the upper bound of the prefix
  string end = prefix;
  end[end.length() - 1] = static_cast<char>(static_cast<int>(end[end.length() - 1]) + 1);
  set<string>::iterator stop = s.lower_bound(end);

  //cout << "end = " << end << "  stop = " << *stop << endl;

  for(set<string>::iterator itr = s.lower_bound(prefix); itr != stop; ++itr){
    cout << *itr << endl;
  }

}

int main() {

  map<string, string> m;
  m.insert(make_pair("1", "hello"));
  m.insert(make_pair("2", "bye"));
  m.insert(make_pair("3", "hello"));
  m.insert(make_pair("4", "hello"));

  cout << "num dupes: " << NumberDuplicateEntries(m) << endl;

  string filename = "test.txt";
  ifstream fstr(filename.c_str());
  map<char, int> ccounts;

  CountLetters(fstr, ccounts);

  //print map
  for(map<char, int>::iterator itr = ccounts.begin(); itr != ccounts.end(); ++itr)
    cout << itr->first << ": " << itr->second << endl;

  set<string> test;
  test.insert("abc");
  test.insert("abd");
  test.insert("abcde");
  test.insert("bas");
  test.insert("abc123");
  string prefix = "abc";
  
  PrintMatchingPrefixes(test, prefix);
   
  return 0;

}

