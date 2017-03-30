/*****************************
   filename: dvrNode.h      
   purpose:  define dvrNode 
*****************************/

#ifndef DVR_NODE_H
#define DVR_NODE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DvrNode
{
public:
   DvrNode(int i, int n) : _id(i), _n(n) {
      _path = new int[n * n];
      _min = new int[n];
      _dir = new int[n];
      for(int p = 0; p < n * n; p++) _path[p] = 0;
      for(int m = 0; m < n; m++) _min[m] = 999999;
      for(int d = 0; d < n; d++) _dir[d] = 999;
   }
   ~DvrNode() {}

   bool setCost(const int, const int, const int);
   bool addCost(const int, const int, const int);
   void setDir(const int vid, const int cost) { _dir[vid] = cost; }
   void setInf(const int);

   int getCost(const int vid, const int tid) const {
      return _path[vid * _n + tid];
   }
   int prvMin(const int tid) const { return _min[tid] / 1000; }
   int getMin(const int tid) const { return _min[tid] % 1000; }
   int allMin(const int tid) const { return _min[tid]; }
   int getDir(const int tid) const { return _dir[tid]; }
   void renewMin();

   bool hasLink(const int vid) const { return getDir(vid) != 999; }
private:
   int  _id;
   int  _n;
   int *_path;
   int *_min;
   int *_dir;

};

#endif // DVR_NODE_H
