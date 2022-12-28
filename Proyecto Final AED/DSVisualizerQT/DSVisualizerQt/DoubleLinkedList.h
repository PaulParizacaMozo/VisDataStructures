#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class NodoDL {
  public:
    T m_Dato;
    NodoDL<T>* m_pAnt;
    NodoDL<T>* m_pSig;

    NodoDL(T d) {
      m_Dato = d;
      m_pAnt = nullptr;
      m_pSig = nullptr;
    }
};

template<class T>
class DoubleLinkedList {
  private:
    NodoDL<T>* m_pHead;
    NodoDL<T>* m_pLast;
    NodoDL<T>* m_pCurrent;
    int m_size;
  public:
    DoubleLinkedList(){
      m_pHead = 0;
      m_pLast = 0;
      m_pCurrent = 0;
      m_size = 0;
    }
    ~DoubleLinkedList(){}

    int Size(){
      return this->m_size;
    }

    void Push_Front(T d){ //Iterativo
      NodoDL<T>* pNew = new NodoDL<T>(d);
      if(!m_pHead) // si head no tiene nada
        m_pHead = m_pLast = pNew; // inserto primer nodo
      else {
        pNew->m_pSig = m_pHead;
        m_pHead->m_pAnt = pNew;
        m_pHead = pNew;
      }
      m_size++;
    }

    void Push_Back(T d){ //Iterativo
      if (!m_pHead){ // Si no hay nada insertamos 1er nodo
        m_pHead = m_pLast = new NodoDL<T>(d);
      } else {
        NodoDL<T>* pNuevo = new NodoDL<T>(d);
        m_pLast->m_pSig = pNuevo; // insertamos despues de pLast
        pNuevo->m_pAnt = m_pLast; // pAnt del nuevoNodo apunta a pLast
        m_pLast = pNuevo; //Ahora pLast es el ultimo nodo
      }
      m_size++;
    }

    void InsertByIndex(int indice,T d){
      NodoDL<T>* pTmp = m_pHead;
      NodoDL<T>* pTmpSig;
      if(indice>(m_size) || indice<0) return;
      if(indice==m_size){
        Push_Back(d); return;
      }
      if(indice==0) {
        Push_Front(d); return;
      } else {
        for (int i=0; i<(indice-1); i++){
          pTmp = pTmp->m_pSig;
        }
        pTmpSig = pTmp->m_pSig;
        NodoDL<T>* pNew = new NodoDL<T>(d);
        pTmp->m_pSig = pNew;
        pNew->m_pAnt = pTmp;
        pNew->m_pSig = pTmpSig;
        pTmpSig->m_pAnt = pNew;
      }
      m_size++;
    }

    void Delete_Front(){
      if (!m_pHead) return;
      NodoDL<T>* pTmp = m_pHead;
      NodoDL<T>* pSig = pTmp->m_pSig;
      if (m_size==1){
        delete pTmp;
        m_pHead = m_pLast = nullptr;
        m_size--;
        return;
      }
      m_pHead = pSig;
      pTmp->m_pSig = nullptr;
      pSig->m_pAnt = nullptr;
      delete pTmp;
      m_size--;
    }

    void Delete_Last(){
      if (!m_pLast) return;
      if(m_size==1){
        NodoDL<T>* pTmp = m_pLast;
        delete pTmp;
        m_pLast = nullptr;
        m_pHead = nullptr;
        m_size--;
        return;
      }
      NodoDL<T>* pTmp = m_pLast;
      NodoDL<T>* pPrev = pTmp->m_pAnt;
      m_pLast = pPrev;
      pTmp->m_pAnt = nullptr;
      pPrev->m_pSig = nullptr;
      delete pTmp;
      m_size--;
    }

    bool Find(T d){
      NodoDL<T>* pTmp = m_pHead;
      if(!m_pHead) return false; //Si esta vacio retorna
      while(pTmp){
        if(pTmp->m_Dato == d)
          return true;
        pTmp = pTmp->m_pSig;
      }
      return false;
    }

    // Iteradores
    void begin() { m_pCurrent = m_pHead; }
    void end() { m_pCurrent = m_pLast; }
    void operator++() {
      if(m_pCurrent->m_pSig)
        m_pCurrent = m_pCurrent->m_pSig;
    }
    void operator--() {
      if(m_pCurrent->m_pAnt)
        m_pCurrent = m_pCurrent->m_pAnt;
    }
    T GetData() {
      return m_pCurrent->m_Dato;
    }

    void Print() { // Iterativo
      NodoDL<T>* pTmp = m_pHead;
      if(!m_pHead) return; //Si esta vacio sale
      while(pTmp) { // mientras existe pTmp
        cout<<pTmp->m_Dato<<" <--> ";
        pTmp = pTmp->m_pSig;
      }
    }

    void PrintReverse() { // Iterativo
      NodoDL<T>* pTmp = m_pLast;
      if(!m_pHead) return; //Si esta vacio sale
      while(pTmp) { // mientras existe pTmp
        cout<<" <--> "<<pTmp->m_Dato;
        pTmp = pTmp->m_pAnt;
      }
    }

    friend ostream & operator<< (ostream &os, DoubleLinkedList<T>& Dlista) {
      Dlista.Print();
      return os;
    }

    void Draw(){
      ofstream limpiar, archivo;
      limpiar.open("archivoListaDoble.dot",ios::out); limpiar<<""; limpiar.close();
      archivo.open("archivoListaDoble.dot",ios::app);
      if(archivo.fail()){  cout<<"No se puede abrir archivo"<<endl; exit(1); }
      NodoDL<T>* pTmp = m_pHead;
      archivo<<"digraph G{\n";
      if(m_size==0){
        archivo<<"\t{rank=same\n";
        archivo<<"\t\tnull1 [label=\"NULL\" shape=none];\n";
        archivo<<"\t\thead [label=\"head\" shape=rect style=rounded];\n";
        archivo<<"\t\ttail [label=\"tail\" shape=rect style=rounded];\n";
        archivo<<"\t\tnull2 [label=\"NULL\" shape=none];\n";
        archivo<<"\t\tnull1 -> head [dir=both arrowhead=none];\n";
        archivo<<"\t\ttail -> null2;\n";
        archivo<<"\t}\n}";
        return;
      }
      archivo<<"\tnode [shape=plaintext]\n";
      archivo<<"\t{rank=same\n";
      archivo<<"\t\tnull1 [label=\"null\" shape=circle];\n";
      archivo<<"\t\tnull2 [label=\"null\" shape=circle];\n";
      archivo<<"";
      int i = 0;
      std::string t4 = "\t\t\t\t";
      do { // mientras existe pTmp
        //cout<<pTmp->m_Dato<<" ";
        //archivo<<"\t\tnodo_"<<i<<"[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\"";
        archivo<<"\t\tnodo_"<<i<<"[label=<<table border=\"0\" cellspacing=\"0\" cellborder=\"1\">\n\t\t\t<tr>\n";
        archivo<<t4<<"<td port=\"ant\" width=\"28\" height=\"36\" fixedsize=\"true\"></td>\n";
        archivo<<t4<<"<td port=\"data\" width=\"28\" height=\"36\" fixedsize=\"false\">"<<pTmp->m_Dato<<"</td>\n";
        archivo<<t4<<"<td port=\"sig\" width=\"28\" height=\"36\" fixedsize=\"true\"></td>\n";
        archivo<<"\t\t\t</tr> </table>> ];\n\n";
        pTmp = pTmp->m_pSig;
        i++;
      } while(pTmp);
      archivo<<"\t}\n";
      i-=1;
      for(int k=0; k<i; k++){
        archivo<<"\tnodo_"<<k<<":sig:c -> nodo_"<<k+1<<":data:n [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];\n";
      }
      for(int k=i; k>=1; k--){
        archivo<<"\tnodo_"<<k<<":ant:c -> nodo_"<<k-1<<":data:s [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];\n";
      }
      archivo<<"\tnull1 -> nodo_0:ant:c [arrowhead=dot, arrowtail=vee, dir=both, headclip=false];\n";
      archivo<<"\tnodo_"<<m_size-1<<":sig:c -> null2:w [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false];\n";
      archivo<<"}";//cerrar digraph
      archivo.close();
      system("dot -Tjpg archivoListaDoble.dot -o archivoListaDoble.jpg");
    }
};


#endif // DOUBLELINKEDLIST_H
