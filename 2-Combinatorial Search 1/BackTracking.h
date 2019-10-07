#ifndef BACKTRACKING_H 
#define BACKTRACKING_H

#include <stdexcept>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include "Estrutura.h"

using namespace std;

class BackTracking{

public:
	BackTracking(Estrutura *est);

   void bkt();

   int cover(int i);
   int unCover(int i);
   int hide(int p);
   int unHide(int p);	

	~BackTracking();

private:
   Estrutura *m_est;

};

#endif
