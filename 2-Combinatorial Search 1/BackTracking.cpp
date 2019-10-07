#include "BackTracking.h"

BackTracking::BackTracking(Estrutura *est) {
 m_est = est;
 
}

int BackTracking::unHide(int p){
   int q = p - 1;
   while (q != p){
      int x = m_est->top(q);
      int u = m_est->uLink(q);
      int d = m_est->dLink(q);
      
      if(x <= 0){
         q = d;
      }else{
         m_est->dLink(u,q);
         m_est->uLink(d,q);
         m_est->len(x,m_est->len(x)+1);
         q--;
      }
   }
   return 0;
}
int BackTracking::unCover(int i){
   int l = m_est->lLink(i);
   int r = m_est->rLink(i);

   m_est->rLink(l,i);
   m_est->lLink(r,i);

   int p = m_est->uLink(i);
   
   while (p != i){
      unHide(p);
      p = m_est->uLink(p);
   }
   return 0;
}

int BackTracking::hide(int p){
  int q = p + 1;

  while (q != p){
     int x = m_est->top(q);
     int u = m_est->uLink(q);
     int d = m_est->dLink(q);
  
     if (x <= 0){
        q = u;
     }else{
       m_est->dLink(u,d); 
       m_est->uLink(d,u); 
       m_est->len(x,m_est->len(x)-1);
       q++;
     }
     
  }

  return 0;
}

void BackTracking::bkt(){
  int i,j,p;
  
 // int N = 7;
 // int Z = 30;
  int l = 0;
  vector <int> x(10);

  X2: ;
//     cout<<"X2"<<endl;
     if(m_est->rLink(0) == 0 ){
        for(int k = 0 ; k < l ; k++){ // imprime solucao
           cout<<x[k]<<" ";
        } 
        cout<<endl;
        goto X8;
     }

     i = m_est->rLink(0);
//     cout<<*m_est<<endl;
     cover(i);
//     cout<<*m_est<<endl;
     x[l] = m_est->dLink(i);
//     exit(1);
  X5: ;
//     cout<<"X5"<<endl;
     if(x[l] == i)
       goto X7;
     
     p = x[l] + 1;
     while(p != x[l]){
        j = m_est->top(p); 
        if(j <= 0){
           p = m_est->uLink(p);
        }else{
           cover(j);
           p++;
        }
     }
     l++;
     goto X2;

  X6: ;
//     cout<<"X6"<<endl;
     p = x[l] - 1;
     while(p != x[l]){
        j = m_est->top(p);
        if(j <= 0){
           p = m_est->dLink(p);
        }else{
          unCover(j);
          p--;
        }
     }
     i = m_est->top(x[l]);
     x[l] = m_est->dLink(x[l]);
     goto X5;

  X7: ;
//     cout<<"X7"<<endl;
     unCover(i);
  X8: ;
//     cout<<"X8"<<endl;
     if( l == 0 ) return;
     l--;
     goto X6;
}


int BackTracking::cover(int i){
   int p = m_est->dLink(i);

   while ( p != i){
      hide(p);
      p = m_est->dLink(p);
   }
   int l = m_est->lLink(i);
   int r = m_est->rLink(i);

   m_est->lLink(r,l);
   m_est->rLink(l,r);

   return 0;
}
BackTracking::~BackTracking() {
}
