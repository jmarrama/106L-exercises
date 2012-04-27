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
#include <set>

using namespace std;

struct TreeNode{
  int value;
  TreeNode* right;
  TreeNode* left;
};
typedef TreeNode TN;

struct GraphNode{
  int value;
  GraphNode** neighbors;
  int num_neigh;
};
typedef GraphNode GN;

int parseRoman(string num);
int getRomanValue(char n);
void printNumberPerms(string num);
map<char, string> getNumMap();
vector<int> mergeLists(vector<vector<int> > arrs);
void inter_three();
void inter_two();
void inter_one();
void printTree(TN* root);
bool isUni(TN* node, int rootVal);
pair<int, bool> numUniSubtrees(TN* node);
void printGraph(GN* node);
GN* deepCopy(GN* node);

int main(){
  //inter_one();
  //inter_two();
  //inter_three();

  cout << endl << "interview 4 : " << endl;

  TN l;
  l.left = NULL;
  l.right = NULL;
  l.value = 1;
  TN t;
  t.left = &l;
  t.right = NULL;
  t.value = 0;
  TN r;
  r.left = NULL;
  r.right = NULL;
  r.value = 0;
  TN root;
  root.left = &t;
  root.right = &r;
  root.value = 0;

  printTree(&root);
  cout << endl << isUni(&root, root.value) << endl;
  cout << endl << numUniSubtrees(&root).first << endl;

  //make graph
  GN a;
  a.neighbors = new GN*[2];
  a.value = 1;
  a.num_neigh = 2;
  GN b;
  b.neighbors = new GN*[2];
  b.num_neigh = 2;
  b.value = 2;
  GN c;
  c.neighbors = new GN*[1];
  c.num_neigh = 1;
  c.value = 3;
  GN d;
  d.neighbors = new GN*[2];
  d.num_neigh = 2;
  d.value = 4;
  a.neighbors[0] = &b;
  a.neighbors[1] = &c;
  b.neighbors[0] = &d;
  b.neighbors[1] = &c;
  c.neighbors[0] = &a;
  d.neighbors[0] = &a;
  d.neighbors[1] = &c;

  printGraph(&a);

  GN* newa = deepCopy(&a);
  cout << endl << endl;

  printGraph(newa);


  return 0;
}

GN* copyGN(GN* node){
  GN* nn = new GraphNode;
  cout << "created new node at " << nn << " with val " << node->value << endl;
  nn->neighbors = new GN*[node->num_neigh];
  nn->num_neigh = node->num_neigh;
  nn->value = node->value;
  return nn;
}

GN* deepRecCopy(map<GN*, GN*> & visited, GN* node){
  GN* nn;

  //get this nodes corresponding new node
  if(visited.find(node) == visited.end()){
    nn = copyGN(node);
    visited.insert(make_pair(node, nn));
  }else{ //if we've visited this node, return
    map<GN*, GN*>::iterator i = visited.find(node);
    nn = (*i).second;
    if(nn == NULL) cout << "returning null!" << endl;
    return nn;
  }

  //visit neighbors
  for(int i = 0; i < node->num_neigh; i++){

    //if neighbor hasn't been visited
    if(visited.find(node->neighbors[i]) == visited.end()){
      GN* neighbor = deepRecCopy(visited, node->neighbors[i]);
      nn->neighbors[i] = neighbor; 
      cout << "connected " << nn << " to " << neighbor << endl;
    }
    else{
      map<GN*, GN*>::iterator itr = visited.find(node->neighbors[i]);
      GN* neighbor = (*itr).second;
      nn->neighbors[i] = neighbor; 
      cout << "connected " << nn << " to " << neighbor << endl;
    }
  }

  return nn;
}

GN* deepCopy(GN* node){
  map<GN*, GN*> visited;

  GN* nn = deepRecCopy(visited, node);
}

void printRec(GN* node, set<GN*> &printed){
  
  fprintf(stderr, "herro?\n");
  if(printed.count(node)) return;
  printed.insert(node);

  for(int i = 0; i < node->num_neigh; i++){
    cout << "node with val " << node->value << " is connected to " << node->neighbors[i]->value << endl;
    fprintf(stderr, "herro?\n");
  }
  for(int i = 0; i < node->num_neigh; i++){
    printRec(node->neighbors[i], printed);
  }
}

void printGraph(GN* node){

  set<GN*> printed;
  printRec(node, printed);
}

//first = num uni trees, second = is subtree uni
pair<int, bool> numUniSubtrees(TN* node){
  if(node == NULL) return make_pair(0, true);
  
  pair<int, bool> l = numUniSubtrees(node->left);
  pair<int, bool> r = numUniSubtrees(node->right);

  //if both subtrees are uni and values match...
  if(l.second && r.second &&
      (node->left == NULL || node->left->value == node->value) &&
      (node->right == NULL || node->right->value == node->value)){
    return make_pair(l.first + r.first + 1, true);
  }

  //if this isn't a uni subtree
  return make_pair(l.first + r.first, false);
} 

bool isUni(TN* node, int rootVal){
  if(node == NULL) return true;
  if(node->value != rootVal) return false;
  return (isUni(node->right, rootVal) && isUni(node->left, rootVal));
}

void printTree(TN* node){
  if(node == NULL) return;
  
  printTree(node->left);
  cout << node->value << endl;
  printTree(node->right);
}

vector<int> mergeTwoLists(vector<int> a, vector<int> b){

  vector<int> out(a.size() + b.size());
  vector<int>::iterator ai = a.begin();
  vector<int>::iterator bi = b.begin();
  vector<int>::iterator oi = out.begin();

  while(ai != a.end() && bi != b.end()){
    if(*ai < *bi){
      *oi = *ai;
      ++ai;
    }
    else{
      *oi = *bi;
      ++bi;
    }

    ++oi;
  }

  //insert remaining stuff
  if(ai != a.end()){
    copy(ai, a.end(), oi);
  }
  else if(bi != b.end()){
    copy(bi, b.end(), oi);
  }

  return out;
}

vector<int> mergeLists(vector<vector<int> > arrs){

  if(arrs.size() == 2) return mergeTwoLists(arrs[0], arrs[1]);
  else if(arrs.size() == 1) return arrs[0];

  while(arrs.size() != 1){

    int numArrs = 0;
    vector<vector<int> >::iterator aitr = arrs.begin();
    vector<vector<int> >::iterator astore = arrs.begin();

    while(aitr != arrs.end()){

      vector<vector<int> >::iterator paitr = aitr;
      ++aitr;
      if(aitr != arrs.end()){
        *astore = mergeTwoLists(*aitr, *paitr); 
        ++aitr; 
      }
      else{
        *astore = *paitr;
      }

      ++astore;
      ++numArrs;
    }

    //resize arrs
    arrs.resize(numArrs);
  }

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
    if(ms.length() == 0) printPerm(numMap, num, cur, pos + 1);
    else {
      for(int i = 0; i < ms.length(); ++i){
        string newcur = cur;
        newcur += ms[i];
        printPerm(numMap, num, newcur, pos + 1);
      }
    }
  }
  else{
    printPerm(numMap, num, cur, pos + 1);
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

void inter_three(){
  cout << endl << "interview 3 : " << endl;

  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(5);
  a.push_back(7);
  vector<int> b;
  b.push_back(4);
  b.push_back(5);
  b.push_back(6);
  vector<int> c;
  c.push_back(0);
  c.push_back(10);
  vector<vector<int> > lists;
  lists.push_back(a);
  lists.push_back(b);
  lists.push_back(c);
  vector<int> merged = mergeLists(lists);
  copy(merged.begin(), merged.end(), ostream_iterator<int>(cout, " \n")); 
}

void inter_two(){
  cout << endl << "interview 2 : " << endl;

  vector<string> numbers;
  numbers.push_back("1234567");
  numbers.push_back("12322-7");
  for(int i = 0; i < numbers.size(); ++i){ 
    cout << numbers[i] << " = " << endl; 
    printNumberPerms(numbers[i]); 
  }

}

void inter_one(){
  cout << "interview 1 : " << endl;

  vector<string> tests;
  tests.push_back("IXIV");
  tests.push_back("LLXV");
  tests.push_back("IVXL");
  tests.push_back("CVXL");
  for(int i = 0; i < tests.size(); ++i){ cout << tests[i] << " = " << parseRoman(tests[i]) << endl; }
}



