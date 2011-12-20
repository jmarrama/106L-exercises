#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isHexInt(){

 int input;
 cin >> input;
 if(cin.fail()){ 
   cout << "You didn't enter an int! returning false" << endl;
   return false;
 }

 stringstream intConverter;
 intConverter << hex << input;

 cout << "integer to hex: " << intConverter.str() << endl;

 stringstream intTester;
 int test;
 string t = intConverter.str();
 intTester << t;
 intTester >> test;

 if(intTester.fail()){
  
   cout << "It failed, we have a character" << endl;
   return false;
 } 
 else{
   char remaining;
   intTester >> remaining;
   if(!intTester.fail()){
     cout << "It failed, we have a character" << endl;
     return false;
   }
 }

 cout << "it passed, test = " << test << endl;
 return true;

  
}

int main() {

  cout << isHexInt() << endl;

  return 0;

}

