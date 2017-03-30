/*******************************************************
    filename: readme.txt
    purpose : define how to compile and run program
*******************************************************/

compile :
   Makefile is defined under b02901119/src, type :
   "make" to compile and link files
   "make clean" to remove previous .o files

* Functions DvrMgr::myStrGetTok and DvrMgr::parse2Int 
  is credited to code from course DSnP.
* All files including .h, .cpp, .txt have to be under
  b02901119/src.

run :
   file "main" is created after make, execute to run
   program.

* Input filename (e.g. in1.txt) to specify DV routing.
* After routing, file (e.g. out1.txt) is created under
  the same directory.
* To continue routing, type "Y" or "y"; to stop program,
  type "N" or "n".
* This program uses cost 999 to represent infinity, using
  cost over 999 will cause executing error.
