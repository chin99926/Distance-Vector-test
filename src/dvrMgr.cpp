/******************************
   filename: dvrMgr.cpp      
   purpose:  define dvrMgr.h 
******************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "dvrMgr.h"
#include "dvrNode.h"

using namespace std;

bool
DvrMgr::readDvr(const string& fileName) {
   ifstream file;
   file.open(fileName.c_str(), ios::in);
   if(!file.is_open()) return false;

   int lineNo = 0; _T = 0;
   string txtLine;
   vector<int> txtTokens;

   while(file.good()) {
      txtLine.clear(); txtTokens.clear();
      getline(file, txtLine);
      if(!parse2Int(txtLine, txtTokens)) break;

      if(lineNo == 0) _nodeNum = txtTokens[0];
      else {
         DvrNode* node = new DvrNode(lineNo - 1, _nodeNum);
         _nodeList.push_back(node);
         for(int n = 0; n < _nodeNum; n++) {
            if(txtTokens[n] == 0 && n != lineNo - 1) node->setInf(n);
            else {
               node->setCost(n, n, txtTokens[n]);
               node->setDir(n, txtTokens[n]);
            }
         }
      }

      lineNo++;
   }

   for(int m = 0; m < _nodeNum; m++) _nodeList[m]->renewMin();

   file.clear();
   file.close();
   return true;
}

bool
DvrMgr::parse2Int(const string& line, vector<int>& tokens) const {
   string token;
   size_t n = myStrGetTok(line, token, 0, ' ');
   while(token.size()) {
      int num = 0;
      for(size_t i = 0; i < token.size(); i++)
         if(isdigit(token[i])) { num *= 10; num += int(token[i] - '0'); }
      tokens.push_back(num);
      n = myStrGetTok(line, token, n, ' ');
   }

   return !(tokens.size() == 0);
}

size_t
DvrMgr::myStrGetTok(const string& str, string& tok,
                    size_t pos, const char del) const {
   size_t begin = str.find_first_not_of(del, pos);
   if(begin == string::npos) { tok = ""; return begin; }
   size_t end = str.find_first_of(del, begin);
   tok = str.substr(begin, end - begin);
   return end;
}

void
DvrMgr::routing(ostream& outfile) {
   printOnce(outfile);

   while(!routeOnce()) {
      _T++; outfile << '\n';
      printOnce(outfile);
   }
   _T = 0;
}

bool
DvrMgr::routeOnce() const {
   bool stable = true;

   for(int fid = 0; fid < _nodeNum; fid++) {
      DvrNode *fn = _nodeList[fid];
      for(int vid = 0; vid < _nodeNum; vid++) {
         DvrNode *vn = _nodeList[vid];
         if(fid != vid && fn->hasLink(vid)) {
            for(int tid = 0; tid < _nodeNum; tid++) {
               int tmp = fn->getDir(vid) + vn->prvMin(tid);
               if(tmp < 999)  stable = fn->setCost(vid, tid, tmp) && stable;
            }
         }
      }
   }
   for(int m = 0; m < _nodeNum; m++) _nodeList[m]->renewMin();
   return stable;
}

void
DvrMgr::printOnce(ostream& outfile) const {
   outfile << "T = " << _T;
   for(int n = 0; n < _nodeNum; n++) {
      DvrNode *node = _nodeList[n];

      outfile << "\nFrom node " << n << "\n(";
      for(int printn = 0;printn < _nodeNum; printn++) {
         if(node->getMin(printn) == 999) outfile << "inf";
         else outfile << node->getMin(printn);
         if(printn < _nodeNum - 1) outfile << ", ";
         else outfile << ")\n";
      }

      for(int t = 0; t < _nodeNum; t++) {
         for(int v = 0; v < _nodeNum; v++) {
            outfile << setw(6) << right;
            if(n == v || n == t) outfile << 'x';
            else if(node->getCost(v, t) == 0 || node->getCost(v, t) == 999)
               outfile << ' ';
            else outfile << node->getCost(v, t);
         }
         if(t < _nodeNum - 1) outfile << endl;
      }
   }
}
