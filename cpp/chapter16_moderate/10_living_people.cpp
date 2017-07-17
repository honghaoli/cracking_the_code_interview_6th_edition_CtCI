//
// Created by Honghao Li on 7/12/17.
//



/*
 * PROBLEM
 * Given a list of people with their birth and death years, implement a method to compute the year with the most number of people alive. You may assume that all people were born between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should be included in that year's count. For example, Person (birth = 1908, death = 1909) is included in the counts for both 1908 and 1909.
 */




#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../lib/helper.h"


using namespace std;



// 1st method
/*
 * store birth and dead year in two arrays, then go through it...
 * This is O(P + R), P: number of person;  R: range of years.
 * The book solution provide another algorithm with O(P log P)...
 */
struct Person {
  Person(int birthyear, int deathyear) : birth(birthyear), death(deathyear) {}
  int birth = 0;
  int death = 0;
};

class Stats {

 public:
  Stats() {
    birthYears.resize(years, 0);
    deathYears.resize(years, 0);
  }

  void clearData() {
    fill(birthYears.begin(), birthYears.end(), 0);
    fill(deathYears.begin(), deathYears.end(), 0);
  }

  void addOnePerson(Person p) {
    if (p.birth < start_year) {
      printf("Wrong birth year %d < min %d!!!\n", p.birth, start_year);
      exit(EXIT_FAILURE);
    }
    if (p.death > end_year) {
      printf("Wrong death year %d < max %d!!!\n", p.death, end_year);
      exit(EXIT_FAILURE);
    }
    birthYears.at(p.birth - start_year)++;
    deathYears.at(p.death - start_year)++;
  }

  int findMostYear() {
    int pop = birthYears[0];
    int maxp = pop;
    int maxi = 0;

    for (int i = 1; i < years + 1; ++i) {
      pop += birthYears[i];
      pop -= deathYears[i-1];
      if (pop > maxp) {
        maxp = pop;
        maxi = i;
      }
    }

    return maxi + start_year;
  }

 private:

  const int start_year = 1900;
  const int end_year = 2000;
  const int years = end_year - start_year + 1;

  vector<int> birthYears;
  vector<int> deathYears;
};


// 2nd method
/*
* The book solution provide another algorithm with O(P log P)...
 * two arrays with length the number of person, one for birth year, one for death year.
 * sort the two arrays.
 * The go through the min of two arrays. if in birth array, add one population; otherwise in death array, subtract one popultion.
 * So it's O(P log P) for sorting...
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
    cout << endl;
    Stats stats;
    printf("max population year is: %d\n", stats.findMostYear());
    stats.addOnePerson(Person(1905, 1907));
    printf("max population year is: %d\n", stats.findMostYear());
    stats.addOnePerson(Person(1907, 1909));
    printf("max population year is: %d\n", stats.findMostYear());
  }

  void test2() {
    cout << endl;
    Stats stats;
    stats.addOnePerson(Person(1900, 1950));
    stats.addOnePerson(Person(1901, 1951));
    stats.addOnePerson(Person(1902, 1952));
    stats.addOnePerson(Person(1903, 1953));
    stats.addOnePerson(Person(1953, 1963));
    stats.addOnePerson(Person(1963, 1970));
    stats.addOnePerson(Person(1962, 1975));
    stats.addOnePerson(Person(1961, 1985));
    stats.addOnePerson(Person(1960, 1995));
    printf("max population year is: %d\n", stats.findMostYear());
  }

  void basicTests() {
    printf("C++ version: %ld\n", __cplusplus);
    // customize your own tests here

    test1();
    test2();
  }

};


////////////////////// Main ////////////////////////
int main() {
  Test t = Test();  // change the method you want to test here.
  return 0;
}

