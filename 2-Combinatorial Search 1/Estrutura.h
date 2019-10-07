#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdexcept>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Estrutura{

public:
	Estrutura();

   int uLink(int i)const{return m_estr[2][i];}
   int dLink(int i)const{return m_estr[3][i];}
   int lLink(int i)const{return m_estr[0][i]; }
   int rLink(int i)const{return m_estr[1][i]; }
   int len(int i)const{return m_estr[4][i]; }
   int top(int i)const{return m_estr[5][i]; }
   
   int rLink(int i,int r){m_estr[1][i] = r; return 0;}
   int lLink(int i,int l){m_estr[0][i] = l; return 0;}
   int dLink(int i,int d){m_estr[3][i] = d; return 0;}
   int uLink(int i,int u){m_estr[2][i] = u; return 0;}
   int len(int i, int x){m_estr[4][i] = x; return 0; }
	
   friend ostream &operator<<(ostream&, const Estrutura&);

	~Estrutura();

private:


	 vector < vector <int> > m_estr;

};

#endif
