#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <fstream>
#include <stack>
#include <time.h>
using namespace std;

template <typename T>
class NodoAVL {    //NodoAVL del árbol AVL
  public:
    T m_Dato;
    NodoAVL<T> *m_pSon[2];
    int m_FE;   //Factor de equilibrio

    NodoAVL(T d){
      m_Dato = d;
      m_pSon[0] = m_pSon[1] = nullptr;
      m_FE = 0;
    }
};

template<typename T>
class Avl {  //árbol AVL
  public:  //private
    NodoAVL<T>* m_pRoot;
    NodoAVL<T>* pCurrent;
    bool m_flag;
  public:
    Avl() {
      m_pRoot = nullptr;
      pCurrent = nullptr;
      m_flag = 0;
    }

    int getBalance(NodoAVL<T>* aux){
      if(aux == nullptr)
        return -1;
      else
        return altura(aux->m_pSon[0]) - altura(aux->m_pSon[1]);
    }

    int altura(NodoAVL<T>* aux){
      if(aux == nullptr)
        return -1;
      else
       return max(altura(aux->m_pSon[0]), altura(aux->m_pSon[1])) + 1;
    }

    void Insert_r(NodoAVL<T>*& p, T d) { // Recursivo
      if(!p){     //Parte que agrega NodoAVL al llegar a una hoja o en la raiz
        p = new NodoAVL<T>(d); return;
      }
      if(p->m_Dato == d){
        m_flag = false;
        return;
      }     //Bloque que evita repetir el NodoAVL
      Insert_r(p->m_pSon[p->m_Dato < d], d);//Llamamos recursivamente a la misma función
      if(m_flag){
        if(p->m_Dato < d)
          p->m_FE++;  //Para sumar o restar factores de equilibrio
        else
          p->m_FE--;
        switch(p->m_FE){    //Bloque donde encontramos a 2, -2 o 0.
          case 0: m_flag=false; return;
          case 2:
            if(p->m_pSon[1]->m_FE == 1){
              SimpleRotation(p,true);
              m_flag=false; return;
            }
            else{
              DoubleRotation(p,true);
              m_flag=false; return;
            }
            break;
          case -2:
            if(p->m_pSon[0]->m_FE == -1){
              SimpleRotation(p,false);
              m_flag=false; return;
            }
            else{
              DoubleRotation(p,false);
              m_flag=false; return;
            }
            break;
        }
      }
    }
    void Insert_r(T d){
      m_flag = true;
      Insert_r(m_pRoot, d);
    }

    bool Find_i(T d,NodoAVL<T>*& pTmp){
      pTmp = m_pRoot;
      if(pTmp == nullptr) return false;
      while (pTmp) {
        if(pTmp->m_Dato == d)
          return true;
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
      }
      return false;
    }

    //RDD o RII
    void SimpleRotation(NodoAVL<T>*& p, bool der) {  //Rotación Simple
      NodoAVL<T>* q = p->m_pSon[der];
      p->m_pSon[der] = q->m_pSon[!der];
      q->m_pSon[!der] = p;
      p->m_FE = q->m_FE = 0;
      p = q;
    }

    //RDD o RII
    void DoubleRotation(NodoAVL<T>*& p, bool der) {   //Rotación Doble
      NodoAVL<T>* q = p->m_pSon[der];
      NodoAVL<T>* r = q->m_pSon[!der];
      p->m_pSon[der] = r->m_pSon[!der];
      q->m_pSon[!der] = r->m_pSon[der];
      r->m_pSon[!der] = p;
      r->m_pSon[der] = q;
      p->m_FE = -1 * getBalance(p);
      q->m_FE = -1 * getBalance(q);
      r->m_FE = -1 * getBalance(r);
      p = r;
    }

    void Print_i() {
      stack<NodoAVL<T>*> pila;
      pCurrent = m_pRoot;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          cout<<pCurrent->m_Dato<<"("<<pCurrent->m_FE<<")  ";
          pCurrent = pCurrent->m_pSon[1];
        }
      }
    }


    void In_Order(NodoAVL<T>*& p){ // [1] subarbol Izq [2] Raiz [3] subarbol Der
      if(p) {
        cout<<p->m_Dato<<" ("<<-1 * getBalance(p)<<")"<<endl;
        In_Order(p->m_pSon[0]);
        //cin.get();
        In_Order(p->m_pSon[1]);

      }
    }
    void In_Order(){
      In_Order(m_pRoot);
    }

    Avl<T> & operator<<(T d) {
      Insert_r(d);
      return *this;
    }
    friend ostream & operator<< (ostream & os , Avl<T>& arb) {
      arb.Print_i();
      cout<<endl;
      arb.In_Order();
      return os;
    }

    void Draw(){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede añadir datos donde se quedo el cursor
      limpiar.open("archivoAvl.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoAvl.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";
      archivo<<"\tnode[fillcolor = \"#EEEEEE\"]\n";
      archivo<<"\tnode[color = \"#03DEFC\"]\n";

      stack<NodoAVL<T>*> pila;
      pCurrent = m_pRoot;
      //NodoAVL<T>* pTmp = m_pRoot;
      //NodoAVL<T>* pTmpSig;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t\""<<pCurrent->m_Dato<<" | "<<pCurrent->m_FE<<"\" -> \""<<pCurrent->m_pSon[0]->m_Dato<<" | "<<pCurrent->m_pSon[0]->m_FE<<"\"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t\""<<pCurrent->m_Dato<<" | "<<pCurrent->m_FE<<"\" -> \""<<pCurrent->m_pSon[1]->m_Dato<<" | "<<pCurrent->m_pSon[1]->m_FE<<"\"\n";
          if(m_pRoot->m_pSon[0] == nullptr){
            if(m_pRoot->m_pSon[1] == nullptr){
              archivo<<"\t"<<pCurrent->m_Dato<<"\n";
            }
          }
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      archivo<<"\n}";
      archivo.close();


      system("dot -Tjpg archivoAvl.dot -o archivoAvl.jpg");
    }

    void DrawFind(T valorA){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede añadir datos donde se quedo el cursor
      limpiar.open("archivoAvl.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoAvl.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";
      archivo<<"\tnode[fillcolor = \"#EEEEEE\"]\n";
      archivo<<"\tnode[color = \"#03DEFC\"]\n";

      stack<NodoAVL<T>*> pila;
      pCurrent = m_pRoot;
      //NodoAVL<T>* pTmp = m_pRoot;
      //NodoAVL<T>* pTmpSig;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t\""<<pCurrent->m_Dato<<" | "<<pCurrent->m_FE<<"\" -> \""<<pCurrent->m_pSon[0]->m_Dato<<" | "<<pCurrent->m_pSon[0]->m_FE<<"\"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t\""<<pCurrent->m_Dato<<" | "<<pCurrent->m_FE<<"\" -> \""<<pCurrent->m_pSon[1]->m_Dato<<" | "<<pCurrent->m_pSon[1]->m_FE<<"\"\n";
          if(m_pRoot->m_pSon[0] == nullptr){
            if(m_pRoot->m_pSon[1] == nullptr){
              archivo<<"\t"<<pCurrent->m_Dato<<"\n";
            }
          }
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      NodoAVL<T> *Tmp;
      bool opc = Find_i(valorA,Tmp);
      if(opc){
        archivo<<"\t\""<<Tmp->m_Dato<<" | "<<Tmp->m_FE<<"\"[fillcolor = yellow];\n";
      }

      archivo<<"\n}";
      archivo.close();


      system("dot -Tjpg archivoAvl.dot -o archivoAvl.jpg");
    }

};

//Comentarrrrrrrr
/*
int main(){
  Avl<int> A;
  A<<70<<80<<100<<120<<170<<180<<115<<90<<95<<200<<300<<400<<500<<600;
  cout<<"---| Root = "<<A.m_pRoot->m_Dato<<endl;
  cout<<A<<endl;
  A.DrawFind(180);
  //system("dot -Tjpg archivo.dot -o archivo.jpg");
  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Insert\t[2] Delete\t\t[3] Dibujar"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A<<dato;
    } else if( op==2 ){
      cout<<"Se elimino dato"<<endl;
    } else if( op==3 ){
      A.In_Order(); cout<<endl;
      A.Draw();
      system("dot -Tjpg archivo.dot -o archivo.jpg");
    } else break;
  }
  // cout<<A.getHeight(100)<<endl;

  return 0;
}
*/

#endif // AVL_H
