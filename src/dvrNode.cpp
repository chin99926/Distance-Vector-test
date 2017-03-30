/*********************************
    filename: dvrNode.cpp
    purpose:  define dvrNode.h
*********************************/

#include <iostream>
#include "dvrNode.h"

using namespace std;

bool
DvrNode::setCost(const int vid, const int tid, const int cost) {
// cout <<"inside node: ("<<vid<<", "<<tid<<")."<<endl;
   int tmp = _path[vid * _n + tid];
   if(tmp == 0 || tmp > cost) _path[vid * _n + tid] = cost;
   if(cost < getMin(tid)) _min[tid] = prvMin(tid) * 1000 + cost;

   return tmp == _path[vid * _n + tid];
}

bool
DvrNode::addCost(const int vid, const int tid, const int add) {
   _path[vid * _n + tid] += (_path[vid * _n + tid] / 1000) + add;
   return false;
}

void
DvrNode::setInf(const int vid) {
   for(int tid = 0; tid < _n; tid++)
      if(tid != _id) _path[vid * _n + tid] = 999;
}

void
DvrNode::renewMin() {
   for(int i = 0; i < _n; i++)
      _min[i] = (_min[i] % 1000) * 1001;
}
