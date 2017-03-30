/********************************
    filename: main.cpp
    purpose : run DV routing
********************************/

#include <iostream>
#include <cstring>
#include <string>
#include "dvrMgr.h"
#include "dvrNode.h"

using namespace std;

int main() {
   string infilename, filenum, outfilename;
   char ans;
   DvrMgr *dvrMgr = new DvrMgr();

   do {
      infilename.clear(); filenum.clear(); outfilename.clear();
      dvrMgr->clear();

      cout << "Please input filename of desired file: ";
      cin >> infilename;

      if(!dvrMgr->readDvr(infilename))
         cout << "Can't find desired file under current directory...\n";
      else {
         dvrMgr->myStrGetTok(infilename, filenum, 2, '.');
         outfilename = "out" + filenum + ".txt";

         ofstream outfile;
         outfile.open(outfilename.c_str(), ios::out);
         if(outfile) {
            cout << "Start routing..."; dvrMgr->routing(outfile);
            cout << "     Finished!!" << endl;
         }
      }

      cout << "\nDo DV routing for next file? [y/n] : ";
      cin >> ans;
   } while(ans == 'Y' || ans == 'y');

   cout << "End of DV routing!!" << endl;
}
