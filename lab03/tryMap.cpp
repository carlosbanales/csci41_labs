#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/map/map/map/

  // FΙXМΕ: create a map that goes from string keys to int values
  map<string, int> m;
  // FΙXМΕ: add an entry using the .emplace() function that maps
  //        "Lawton" to 8675309
  m.emplace("Lawton", 8675309);
  // FΙXМΕ: add an entry using the .emplace() function that maps
  //        "Jacqui" to 2123487
  m.emplace("Jacqui", 2123487);
  // FΙXМΕ: create a queue that holds doubles
  // FΙXМΕ: add an entry using the .emplace() function that maps
  //        "Surya" to 3097643
  m.emplace("Surya", 3097643);
  // FΙXМΕ: add an entry using the .emplace() function that maps
  //        "Victoria" to 5397475
  m.emplace("Victoria",5397475);
  // FΙXМΕ: add an entry using the .emplace() function that maps
  //        "Antonio" to 3473987
  m.emplace("Antonio", 3473987);
  // FΙXМΕ: lookup the entry for "Jacqui" using the .at() function and
  //        print the result
  cout << m.at("Jacqui") << endl;
  // FΙXМΕ: lookup the entry for "Surya" using the .at() function and
  //        print the result
  cout << m.at("Surya") << endl;
  // FΙXМΕ: iterate through the map from beginning to end (look up how
  //        to use .begin() and .end()) and print out each element's
  //        key, a colon, a space, and then the element's value (i.e.,
  //        you want to print lines that look like "Tom: 5555555")

  for (auto i = m.begin(); i != m.end(); i++) {
    cout << i->first << ": " << i->second << endl;
  }

  return 0;
}
