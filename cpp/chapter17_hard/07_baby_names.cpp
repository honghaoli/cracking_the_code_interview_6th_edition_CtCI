//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Each year, the government release a list of the 10000 most common baby names and their frequencies ( the number of babies with that name). The only problem with this is that some names have multiple spellings. For example, "John" and "Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used as the "real" name.
 * EXAMPLE
 *    INPUT:
 *          Names: John(15), Jon(12), Chris(13), Kris(4), Christopher(19)
 *          Synonyms:  (John, Jon), (John, Johnny), (Chris, Kris), (Chris, Christopher)
 *    OUTPUT:
 *          John(27), Kris(36)
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * create a tree structure for all alias, then use the root as the keyword.
 * Actually, maybe it's easier to keep only one parent at most, each time change both to another root.
 */

void remove_multiples(unordered_map<string, int> &names, vector<vector<string>> &synonyms) {
  unordered_map<string, string> unique_names;
  for (auto &pair : synonyms) {
    bool newname1 = (unique_names.count(pair.at(0)) == 0);
    bool newname2 = (unique_names.count(pair.at(1)) == 0);
    if (newname1 && newname2) {
      unique_names[pair.at(0)] = pair.at(0);
      unique_names[pair.at(1)] = pair.at(0);
      names[pair.at(0)] += names[pair.at(1)];
      names.erase(pair.at(1));
    } else if (newname1) {
      unique_names[pair.at(0)] = unique_names[pair.at(1)];
      names[unique_names[pair.at(1)]] += names[pair.at(0)];
      names.erase(pair.at(0));
    } else if (newname2) {
      unique_names[pair.at(1)] = unique_names[pair.at(0)];
      names[unique_names[pair.at(0)]] += names[pair.at(1)];
      names.erase(pair.at(1));
    } else {
      // This part needs careful treatment!
      // In this way, any name has at most one parent, so we change both.
      string temp = unique_names[pair.at(1)];
      unique_names[unique_names[pair.at(1)]] = unique_names[pair.at(0)];
      unique_names[pair.at(1)] = unique_names[pair.at(0)];
      names[unique_names[pair.at(0)]] += names[temp];
      names.erase(temp);
    }
  }
};



// 2nd method
/*
 * the book solution
 */



////////////////////
////////////////////// Test ////////////////////////
class Test {

 public:

  Test() {
    basicTests();
  }

 private:
  int num_fail = 0;

  void test1() {
    //  Names: John(15), Jon(12), Chris(13), Kris(4), Christopher(19)
    //  Synonyms:  (John, Jon), (John, Johnny), (Chris, Kris), (Chris, Christopher)
    //  Output:        John(27), Kris(36)
    unordered_map<string, int> names;
    vector<vector<string>> synonyms;

    names["John"] = 15;
    names["Jon"] = 12;
    names["Chris"] = 13;
    names["Kris"] = 4;
    names["Christopher"] = 19;

    synonyms.push_back(vector<string>{"John", "Jon"});
    synonyms.push_back(vector<string>{"John", "Johnny"});
    synonyms.push_back(vector<string>{"Chris", "Kris"});
    synonyms.push_back(vector<string>{"Chris", "Christopher"});

    cout << endl;
    cout << "original names:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
    cout << "synonyms:" << endl;
    for (auto &x : synonyms) {
      cout << "(" << x.at(0) << ", " << x.at(1) << "), ";
    }
    cout << endl;

    remove_multiples(names, synonyms);

    cout << "after:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
  }

  void test2() {
    //  Output:        John(33), Kari(8), Davis(2), Carleton(10).
    unordered_map<string, int> names;
    vector<vector<string>> synonyms;

    names["John"] = 10;
    names["Jon"] = 3;
    names["Davis"] = 2;
    names["Kari"] = 3;
    names["Johnny"] = 11;
    names["Carlton"] = 8;
    names["Carleton"] = 2;
    names["Jonathan"] = 9;
    names["Carrie"] = 5;

    synonyms.push_back(vector<string>{"Jonathan", "John"});
    synonyms.push_back(vector<string>{"Jon", "Johnny"});
    synonyms.push_back(vector<string>{"Johnny", "John"});
    synonyms.push_back(vector<string>{"Kari", "Carrie"});
    synonyms.push_back(vector<string>{"Carleton", "Carlton"});

    cout << endl;
    cout << "original names:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
    cout << "synonyms:" << endl;
    for (auto &x : synonyms) {
      cout << "(" << x.at(0) << ", " << x.at(1) << "), ";
    }
    cout << endl;

    remove_multiples(names, synonyms);

    cout << "after:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
  }

  void test3() {
    //  Output:        John(33), Kari(8), Davis(2), Carleton(10).
    unordered_map<string, int> names;
    vector<vector<string>> synonyms;

    names["John"] = 10;
    names["Jon"] = 3;
    names["Davis"] = 2;
    names["Kari"] = 3;
    names["Johnny"] = 11;
    names["Carlton"] = 8;
    names["Carleton"] = 2;
    names["Jonathan"] = 9;
    names["Carrie"] = 5;

    names["JohnTest"] = 1;

    synonyms.push_back(vector<string>{"Jonathan", "John"});
    synonyms.push_back(vector<string>{"Jon", "Johnny"});
    synonyms.push_back(vector<string>{"Johnny", "John"});
    synonyms.push_back(vector<string>{"Kari", "Carrie"});
    synonyms.push_back(vector<string>{"Carleton", "Carlton"});
    synonyms.push_back(vector<string>{"JohnTest", "John"});

    cout << endl;
    cout << "original names:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
    cout << "synonyms:" << endl;
    for (auto &x : synonyms) {
      cout << "(" << x.at(0) << ", " << x.at(1) << "), ";
    }
    cout << endl;

    remove_multiples(names, synonyms);

    cout << "after:" << endl;
    for (auto &x : names) {
      cout << x.first << "(" << x.second << "), ";
    }
    cout << endl;
  }

  void unit_test() {
    test1();
    test2();
    test3();
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    unit_test();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

