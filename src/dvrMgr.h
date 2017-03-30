/****************************
   filename: dvrMgr.h      
   purpose:  define DvrMgr 
****************************/

#ifndef DVR_MGR_H
#define DVR_MGR_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "dvrNode.h"

// extern DvrMgr *dvrMgr;

class DvrMgr
{
public:
   DvrMgr() {}

   bool readDvr(const string&);
   bool parse2Int(const string&, vector<int>&) const;
   size_t myStrGetTok(const string&, string&, size_t, const char) const;

   void routing(ostream&);
   bool routeOnce() const;
   void printOnce(ostream&) const;

   void clear() { _T = _nodeNum = 0; _nodeList.clear(); }

private:
   int              _T;
   int              _nodeNum;
   vector<DvrNode*> _nodeList;

};
#endif // DVR_MGR_H
