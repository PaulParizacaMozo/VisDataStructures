#ifndef BINARYS_H
#define BINARYS_H

#include<iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

template <class T>
class NodoAB {
  public:
    T m_Dato;
    NodoAB<T> *m_pSon[2];

    NodoAB(T d)
    {
      m_Dato = d;
      m_pSon[0] = 0;
      m_pSon[1] = 0;
    }
};

template<class T>
class Tree {
  private:
    NodoAB<T>* m_pRoot;
    NodoAB<T>* pCurrent;
    //int cantidad;
  public:
    Tree() {
      m_pRoot = nullptr;
      pCurrent = nullptr;
    }

    void Insert_r(NodoAB<T>*& p, T d) { // Recursivo
      if(!p){
        p = new NodoAB<T>(d); return;
      }
      if(p->m_Dato == d) return;
      Insert_r(p->m_pSon[p->m_Dato < d], d);
    }
    void Insert_r(T d){
      Insert_r(m_pRoot, d);
    }

    void Insert_i(T d){ // Iterativo
      NodoAB<T>* pTmp = m_pRoot;
      if(!pTmp) {
        m_pRoot = new NodoAB<T>(d); return;
      }
      while(pTmp->m_pSon[pTmp->m_Dato < d] != nullptr){
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
      }
      if (pTmp->m_Dato != d){
        pTmp->m_pSon[pTmp->m_Dato < d]= new NodoAB<T>(d);
      }
      //Draw();
    }

    bool Find_r(NodoAB<T>* p, T d) {
      if(!p) return false;
      return (p->m_Dato == d) ? true : Find_r(p->m_pSon[p->m_Dato < d],d);
    }
    bool Find_r(T d){
      return Find_r(m_pRoot,d);
    }

    bool Find_i(T d,NodoAB<T>*& pTmp){
      pTmp = m_pRoot;
      if(pTmp == nullptr) return false;
      while (pTmp) {
        if(pTmp->m_Dato == d)
          return true;
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
      }
      return false;
    }

    bool Delete_one_Son(T d){
      NodoAB<T> * p = m_pRoot;
      NodoAB<T> * q = m_pRoot;
      while(p) {
        if(p->m_Dato == d){
          if(p->m_pSon[0]==0 && p->m_pSon[1]!=0 ) {
              q->m_pSon[q->m_Dato < d]=p->m_pSon[1];
              delete p;
              return true;
          }
          if(p->m_pSon[0]!=0 && p->m_pSon[1]==0 ){
              q->m_pSon[q->m_Dato < d]=p->m_pSon[0];
              delete p;
              return true;
          }
        }
        q = p;
        p = p->m_pSon[p->m_Dato <  d];
      }
      return false;
    }

    bool Delete_Hoja(T d){
      NodoAB<T> * p = m_pRoot;
      NodoAB<T> * q = m_pRoot;
      while(p){
        if(p->m_Dato == d) {
          // si ese no es una hoja, entonces destruyela
          if(p->m_pSon[0]==0 && p->m_pSon[1]==0 ){
              delete p;
              q->m_pSon[q->m_Dato<d]=0;
              return true;
          }
          else{
            return false;
          }
        }
        q = p;
        p = p->m_pSon[p->m_Dato <  d];
      }
    return false;
    }

    bool Delete_2_Son(T d){
      NodoAB<T> * p = m_pRoot;
      while(p){
        if(p->m_Dato == d){
          if(p->m_pSon[0]!=0 && p->m_pSon[1]!=0 ){
             // Si tengo 2 hijos, entonces:
             // Buscar el mayor de los menores de p
            NodoAB<T> * tmp = p->m_pSon[1];
            NodoAB<T> * aux = nullptr;
            if (tmp->m_pSon[0]) {
              while(tmp->m_pSon[0]){
                aux = tmp;
                tmp = tmp->m_pSon[0];
              }
              aux->m_pSon[0] = tmp->m_pSon[1];
            }
            swap(p->m_Dato, tmp->m_Dato);
            if(aux == nullptr){
              p->m_pSon[1] = tmp->m_pSon[1];
            }
            // Falta eliminar el NodoAB tmp. Pero tenga cuidado con perder todos sus hijos.
            delete tmp;
            return true;
          }
        }
        p = p->m_pSon[p->m_Dato <  d];
      }
      return false;
    }

    void Delete(T d){
        NodoAB<T> * p = m_pRoot;
         while(p)
        {
            if(p->m_Dato == d)
            {
              //Delete_Hoja(d);
              //Delete_one_Son(d);
              //Delete_2_Son(d);
                if (Delete_Hoja(d)) {
                  return;
                }
                else if (Delete_one_Son(d)) {
                  return;
                }
                else if (Delete_2_Son(d)) {
                  return;
                }
            }
            p = p->m_pSon[p->m_Dato <  d];
        }
    }

    NodoAB<T>* getFather_i(T d) {
      NodoAB<T>* aux = m_pRoot;
      if(!m_pRoot) return 0;
      while(aux->m_pSon[aux->m_Dato < d] != nullptr){
        if(aux->m_pSon[aux->m_Dato < d]->m_Dato == d)
          return aux;
        aux = aux->m_pSon[aux->m_Dato < d];
      }
      return 0;
    }

    NodoAB<T>* getSibling(T d) { //getBrother
      NodoAB<T>* pTmpPadre = getFather_i(d);
      if (pTmpPadre == nullptr) return 0;
      else if(pTmpPadre->m_pSon[0]->m_Dato == d)
        return pTmpPadre->m_pSon[1];
      else if (pTmpPadre->m_pSon[1]->m_Dato == d)
        return pTmpPadre->m_pSon[0];
      return 0;
    }

    NodoAB<T>* getUncle_i(T d){
      NodoAB<T>* pTmpPadre = getFather_i(d);
      if(!pTmpPadre) return 0;
      NodoAB<T>* pTmpTio = getSibling(pTmpPadre->m_Dato);
      return pTmpTio ? pTmpTio : 0;
    }

    NodoAB<T>* getGrandFather_i(T d) {
      if(getFather_i(d)==nullptr) return 0;
      NodoAB<T>* aux = getFather_i(getFather_i(d)->m_Dato);
      return aux ? aux : 0;
    }

    int getLevel(T d){ //retorna el nivel en el que se encuentra el dato pasado por parametro
      NodoAB<T>* pTmp = m_pRoot;
      if(!pTmp) return -1;
      int level = 0;
      while (pTmp) {
        if(pTmp->m_Dato == d) return level;
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
        level++;
      }
      return -1;
    }

    int GetNum_TotalNodes_InALevel(int level) {
      stack<NodoAB<T>*> pila;
      NodoAB<T>* p = m_pRoot;
      NodoAB<T>* q;
      int numNodoABs = 0;
      pila.push(p);
      while(!pila.empty()) {
        q = pila.top();
        pila.pop();
        if(getLevel(q->m_Dato) == level) numNodoABs++;
        if(q->m_pSon[0]) pila.push(q->m_pSon[0]);
        if(q->m_pSon[1]) pila.push(q->m_pSon[1]);
      }
      return numNodoABs;
    }

    void Print_i() {
      stack<NodoAB<T>*> pila;
      pCurrent = m_pRoot;
      cout<<"Print_i:\n";
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          cout<<pCurrent->m_Dato<<" ";
          pCurrent = pCurrent->m_pSon[1];
        }
      }
    }

    int getTotalNodoABs(){
      int total = 0;
      stack<NodoAB<T>*> pila;
      pCurrent = m_pRoot;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          total++;
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      return total;
    }

    int getHeight(NodoAB<T>* p){ // Retorna Altura
      if(!p) return -1;
      else{
        int alturaIzq = getHeight(p->m_pSon[0]);
        int alturaDer = getHeight(p->m_pSon[1]);
        if(alturaIzq > alturaDer)
          return alturaIzq+1;
        else
          return alturaDer+1;
      }
    }
    int getHeight(T d){
      NodoAB<T>* pTmp = m_pRoot;
      if(pTmp == nullptr) return 0;
      while (pTmp) {
        if(pTmp->m_Dato == d)
          break;
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
      }
      int altura = getHeight(pTmp);
      return altura;
    }

    NodoAB<T>* getRoot(){
      return m_pRoot;
    }

    void Pre_Order(NodoAB<T>* p){ // [1] Raiz [2] subarbol Izq [3] subarbol Der
      if(p) {
        cout<<p->m_Dato<<" ";
        Pre_Order(p->m_pSon[0]);
        Pre_Order(p->m_pSon[1]);
      }
    }
    void Pre_Order() {
      cout<<"Pre Orden => ";
      Pre_Order(m_pRoot);
    }

    void In_Order(NodoAB<T>* p){ // [1] subarbol Izq [2] Raiz [3] subarbol Der
      if(p) {
        In_Order(p->m_pSon[0]);
        cout<<p->m_Dato<<" ";
        In_Order(p->m_pSon[1]);
      }
    }
    void In_Order(){
      cout<<"In Orden => ";
      In_Order(m_pRoot);
    }

    void Post_Order(NodoAB<T>* p){ // [1] subarbol Izq [2] subarbol Der [3] Raiz
      if(p) {
        Post_Order(p->m_pSon[0]);
        Post_Order(p->m_pSon[1]);
        cout<<p->m_Dato<<" ";
      }
    }
    void Post_Order(){
      cout<<"Post Orden => ";
      Post_Order(m_pRoot);
    }

    Tree<T> & operator<<(T d) {
      Insert_i(d);
      //Insert_r(d);
      return *this;
    }
    friend ostream & operator<< (ostream & os , Tree<T>& arb) {
      arb.In_Order();
      return os;
    }

    void DrawNodoABs(NodoAB<T>* p, ofstream & archivo){ // [1] Raiz [2] subarbol Izq [3] subarbol Der
      if(p) {
        archivo.open("archivoAbinario.dot",ios::app);
        cout<<p->m_Dato<<" -> ";
        DrawNodoABs(p->m_pSon[0],archivo);
        DrawNodoABs(p->m_pSon[1],archivo);
      }
    }
    void Draw(){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoAbinario.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoAbinario.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";
      archivo<<"\tnode[fillcolor = \"#EEEEEE\"]\n";
      archivo<<"\tnode[color = \"#31CEFG\"]\n";

      stack<NodoAB<T>*> pila;
      pCurrent = m_pRoot;
      //NodoAB<T>* pTmp = m_pRoot;
      //NodoAB<T>* pTmpSig;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[0]->m_Dato<<"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[1]->m_Dato<<"\n";
          //
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
      system("dot -Tjpg archivoAbinario.dot -o archivoAbinario.jpg");
    }

    void DrawFind(T valorA){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoAbinario.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoAbinario.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";
      archivo<<"\tnode[fillcolor = \"#EEEEEE\"]\n";
      archivo<<"\tnode[color = \"#31CEFG\"]\n";

      stack<NodoAB<T>*> pila;
      pCurrent = m_pRoot;
      //NodoAB<T>* pTmp = m_pRoot;
      //NodoAB<T>* pTmpSig;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[0]->m_Dato<<"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[1]->m_Dato<<"\n";
          //
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
      NodoAB<T> *Tmp;
      bool opc = Find_i(valorA,Tmp);
      if(opc){
        archivo<<"\t"<<Tmp->m_Dato<<"[fillcolor = yellow];\n";
      }

      archivo<<"\n}";
      archivo.close();
      system("dot -Tjpg archivoAbinario.dot -o archivoAbinario.jpg");
    }

};


/*
int main() {
  Tree<int> A;
  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Insert\t[2] Delete\t\t[3] Dibujar"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A<<dato;
    } else if( op==2 ){
      cout<<"Ingrese dato a eliminar ->";cin>>dato;
      A.Delete(dato);
    } else if( op==3 ){
      A.In_Order(); cout<<endl;
      A.Draw();
      system("dot -Tpdf archivoAbinario.dot -o archivoAbinario.pdf");
      system("zathura archivoAbinario.pdf &");
    } else break;
  }
  //A<<100<<55<<140<<32<<80<<122<<165<<28<<71<<92<<154<<86<<96<<98<<99;

  //A.Pre_Order(); cout<<endl;
  //A.In_Order(); cout<<endl;
  //A.Post_Order(); cout<<endl;

  //cout<<A<<endl;
  // cout<<"Altura => "<<A.getHeight(A.getRoot()->m_Dato)<<endl;
  //A.Print_i(); cout<<endl;
  //cout<<A.getTotalNodoABs()<<endl;
  //cout<<"Level de 86 => "<<A.getLevel(86)<<endl;
  //cout<<"num NodoABs level 3 => "<<A.GetNum_TotalNodes_InALevel(0)<<endl;
  //cout<<A.getGrandFather_i(99)->m_Dato<<endl; //retorna 96
  //cout<<A.getUncle_i(140)->m_Dato<<endl;
  return 0;
}
*/
/*
  * Insert_r  funciona
  * Insert_i  funciona
  * Find_r    funciona
  * Find_i    funciona
  * GetFather_i   funciona
  * GetGrandFather  funciona
  * GetSibling_i  funciona
  * GetUncle_i  funciona
  * GetLevel    funciona
  * GetNum_TotalNodes_InALevel  funciona
  * GetTotalNodoABs   funciona
  * GetHeight(r)   funciona
  * In_order    funciona
  * Pre_order   funciona
  * Post_order  funciona
  * Print_i   funciona
*/


#endif // BINARYS_H
