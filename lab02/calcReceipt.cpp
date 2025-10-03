#include <cstdlib>  // for exit
#include <fstream>  // for ifstream
#include <string>   // for getline, stoi
#include <iomanip>  // for setw and setfill
#include <iostream> // lol you know what this is for
#include "vec.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " order_file.csv" << endl;
    exit(1);
  }

  ifstream ifs(argv[1]);
  Vec prices;

  string currentLine;
  while (getline(ifs, currentLine)) {
    // FΙXМΕ: add the price from the current line into the prices Vec

    // Hint: use find, substr, and stoi to extract the prices

    int commaIndex = currentLine.find(',');
   
    string priceStr = currentLine.substr(commaIndex + 1);
    
    int cents = stoi(priceStr);
    
    prices.push_back(cents);
  }

  // FΙXМΕ: print the *sorted* prices, a line with exactly 6 '-'s, and
  // finally the total. Prices should be displayed with dollar signs
  // and cents.

  // Hint: when printing out prices, use setw(2) and setfill('0') to
  // guarantee you output the cents correctly

     // each line is "description,priceInCents"

  prices.sort();

  int total = 0;
  for (int i = 0; i < prices.size(); i++) {
    int cents = prices.at(i);
    int dollars = cents / 100;
    int rem = cents % 100;
    
    cout << "$" << dollars << "." << setw(2) << setfill('0') << rem << endl;
    total += cents;
  }

  cout << "------" << endl;

  int td = total / 100;
  int tr = total % 100;
  
  cout << "$" << td << "." << setw(2) << setfill('0') << tr << endl;

  return 0;
}
