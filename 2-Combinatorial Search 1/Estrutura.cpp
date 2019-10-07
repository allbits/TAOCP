#include "Estrutura.h"

Estrutura::Estrutura() {
 m_estr.resize(6);

 for(unsigned i = 0 ; i < m_estr.size(); i++){
    m_estr[i].resize(31);
 }
 
 //LLINK 0  -  RLINK 1
 m_estr[0][0] = 7;   m_estr[1][0] = 1;
 for(int i = 1; i < 8; i++){
    m_estr[0][i] = i-1;   m_estr[1][i] = i+1;
 }
 m_estr[1][7] = 0;

 //ULINK 2 -  DLINK 3
 m_estr[2][1] =  20; m_estr[3][1] =  12;
 m_estr[2][2] =  24; m_estr[3][2] =  16;
 m_estr[2][3] =  17; m_estr[3][3] =   9;
 m_estr[2][4] =  27; m_estr[3][4] =  13;
 m_estr[2][5] =  28; m_estr[3][5] =  10;
 m_estr[2][6] =  22; m_estr[3][6] =  18;
 m_estr[2][7] =  29; m_estr[3][7] =  14;
                     m_estr[3][8] =  10;
 m_estr[2][9] =   3; m_estr[3][9] =  17;
 m_estr[2][10] =  5; m_estr[3][10] = 28;
 m_estr[2][11] =  9; m_estr[3][11] = 14;
 m_estr[2][12] =  1; m_estr[3][12] = 20;
 m_estr[2][13] =  4; m_estr[3][13] = 21;
 m_estr[2][14] =  7; m_estr[3][14] = 25;
 m_estr[2][15] = 12; m_estr[3][15] = 18;
 m_estr[2][16] =  2; m_estr[3][16] = 24;
 m_estr[2][17] =  9; m_estr[3][17] =  3;
 m_estr[2][18] =  6; m_estr[3][18] = 22;
 m_estr[2][19] = 16; m_estr[3][19] = 22;
 m_estr[2][20] = 12; m_estr[3][20] =  1;
 m_estr[2][21] = 13; m_estr[3][21] = 27;
 m_estr[2][22] = 18; m_estr[3][22] =  6;
 m_estr[2][23] = 20; m_estr[3][23] = 25;
 m_estr[2][24] = 16; m_estr[3][24] =  2;
 m_estr[2][25] = 14; m_estr[3][25] = 29;
 m_estr[2][26] = 24; m_estr[3][26] = 29;
 m_estr[2][27] = 21; m_estr[3][27] =  4;
 m_estr[2][28] = 10; m_estr[3][28] =  5;
 m_estr[2][29] = 25; m_estr[3][29] =  7;
 m_estr[2][30] = 27;

//LEN 4 - TOP 5
 m_estr[4][1] = 2;
 m_estr[4][2] = 2;
 m_estr[4][3] = 2;
 m_estr[4][4] = 3;
 m_estr[4][5] = 2;
 m_estr[4][6] = 2;
 m_estr[4][7] = 3;

 m_estr[5][8]  =  0; 
 m_estr[5][9]  =  3; 
 m_estr[5][10] =  5; 
 m_estr[5][11] =  -1;
 m_estr[5][12] =  1; 
 m_estr[5][13] =  4; 
 m_estr[5][14] =  7; 
 m_estr[5][15] =  -2;
 m_estr[5][16] =  2; 
 m_estr[5][17] =  3; 
 m_estr[5][18] =  6; 
 m_estr[5][19] =  -3;
 m_estr[5][20] =  1; 
 m_estr[5][21] =  4; 
 m_estr[5][22] =  6; 
 m_estr[5][23] =  -4;
 m_estr[5][24] =  2; 
 m_estr[5][25] =  7; 
 m_estr[5][26] =  -5;
 m_estr[5][27] =  4; 
 m_estr[5][28] =  5; 
 m_estr[5][29] =  7; 
 m_estr[5][30] =  -6;
}


Estrutura::~Estrutura() {
}

ostream &operator<<(ostream& output, const Estrutura& pEst){

//   cout<<"      ";
//   for(int i = 0; i < 31; i++){
//      cout<<i<<" ";
//   }
//   cout<<endl;

   cout<<"LLINK ";
   for(int i = 0; i < 8; i++){
      cout<<"("<<i<<")"<<pEst.lLink(i)<<" ";
   }
   cout<<endl;

   cout<<"RLINK ";
   for(int i = 0; i < 8; i++){
      cout<<"("<<i<<")"<<pEst.rLink(i)<<" ";
   }
   cout<<endl;

   cout<<"LEN   ";
   for(int i = 1; i < 8; i++){
      cout<<"("<<i<<")"<<pEst.len(i)<<" ";
   }
   cout<<endl;
   
   cout<<"ULINK ";
   for(int i = 1; i < 31; i++){
      cout<<"("<<i<<")"<<pEst.uLink(i)<<" ";
   }
   cout<<endl;

   cout<<"DLINK ";
   for(int i = 1; i < 30; i++){
      cout<<"("<<i<<")"<<pEst.dLink(i)<<" ";
   }
   cout<<endl;

   cout<<"TOP   ";
   for(int i = 8; i < 31; i++){
      cout<<"("<<i<<")"<<pEst.top(i)<<" ";
   }
   cout<<endl;


  return output;
}



