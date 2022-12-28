#include <string> //FIFO
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class NodoC {
  public:
    T m_Dato;
    NodoC<T> * m_pSig;

    NodoC(T d) {
      m_Dato = d;
      m_pSig = nullptr;
    }
};

template<class T>
class Cola { //primero que entra primero que sale
  private:
    NodoC<T> * m_pFirst;
    NodoC<T> * m_pLast;
    int m_Size;
    
  public:
    Cola() {
      m_pFirst = 0;
      m_pLast = 0;
      m_Size = 0; 
    }

    bool IsEmpty() {
      return (m_pFirst == nullptr);         
    }

    void Push(T d) { //push
      NodoC<T> * pNuevo = new NodoC<T>(d); 
      if(!m_pFirst){  // si esta vacio inserta 1er NodoC
        m_pFirst = pNuevo;
        m_pLast = m_pFirst;
      } else {
        m_pLast->m_pSig = pNuevo; // insertamos despues de pLast
        m_pLast = pNuevo; //Ahora pLast es el ultimo NodoC
      }
      m_Size++;
    }

    void Pop() { //pop
      if(!m_pFirst) return; //Si esta vacia retorna
      NodoC<T>* pCurrent = m_pFirst;
      if(!m_pFirst->m_pSig){
        m_pFirst = m_pFirst->m_pSig;
        delete pCurrent; //si tiene un NodoC
        m_Size--;
        return;
      }
      m_pFirst = m_pFirst->m_pSig; //First apunta al 2do NodoC
      pCurrent->m_pSig = 0;
      delete pCurrent;
      m_Size--;
    }
    
    T Front() {
      return m_pFirst->m_Dato;
    }

    T Back() {
      return m_pLast->m_Dato;
    }
    
    void Print() { // Iterativo
      NodoC<T>* pTmp = m_pFirst;
      if(!m_pFirst) return; //Si esta vacio sale
      while(pTmp) { // mientras existe pTmp
        cout<<pTmp->m_Dato<<" --> ";
        pTmp = pTmp->m_pSig;
      }
    }

    void draw(){
      //if(!m_pFirst) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoCola.dot",ios::out); limpiar<<""; limpiar.close();
      archivo.open("archivoCola.dot",ios::app); 
      if(archivo.fail()){  cout<<"No se puede abrir archivo"<<endl; exit(1); }
      NodoC<T>* pTmp = m_pFirst;
      archivo<<"digraph G{\n";
      if(!m_pFirst){
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n";
        archivo<<"\tnull[label=\"NULL\" shape=\"none\"];\n";
        archivo<<"\ttail [label=\"tail\" shape=\"rect\"];\n";
        archivo<<"\thead -> null [dir=\"both\" arrowtail=none];\n";
        archivo<<"\tnull -> tail [dir=\"both\" arrowhead=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoCola.dot -o archivoCola.jpg"); return;
      }
      
      if(m_Size==1){
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n\trankdir=LR;\n";
        archivo<<"\tnodo_0[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\" shape=\"record\" style=\"filled\" fillcolor=\"gray80\"];\n";
        archivo<<"\ttail [label=\"tail\" shape=\"rect\"];\n";
        archivo<<"\thead -> nodo_0 [dir=\"both\" arrowtail=none];\n";
        archivo<<"\tnodo_0 -> tail [dir=\"both\" arrowhead=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoCola.dot -o archivoCola.jpg"); return;
      }
      
      archivo<<"\thead [label=\"head\" shape=\"rect\"]\n";
      archivo<<"\trankdir=\"LR\"\n";
      archivo<<"\tedge[tailclip=false,arrowtail=dot,dir=both];\n";
      archivo<<"\tsubgraph clust0 {\n";
      archivo<<"\t\tstyle=filled;\n";
      archivo<<"\t\tcolor=white;\n\t\tnode [style=filled];\n\t\tnode[shape=record]\n";

      int i = 0;
      do{
        archivo<<"\t\tnodo_"<<i<<"[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\"];\n";
        pTmp = pTmp->m_pSig;
        i++;
      }while(pTmp);
      i-=1;
      for(int k=0; k<i; k++){
        archivo<<"\t\tnodo_"<<k<<":sig:c -> nodo_"<<k+1<<":dato;\n";
      }
      archivo<<"\n\t}\n"; // cerrar cluster_0
      archivo<<"\tsubgraph clust1 {\n\t\tnode[shape=record];\n";
      archivo<<"\t\tnode[shape=\"point\" height=\"0\"]\n";
      for(int k=0; k<i; k++){
        archivo<<"\t\tp"<<k<<"\n";
      }
      archivo<<"\n\t\tedge[arrowtail=none, arrowhead=none, color=\"transparent\"];\n";
      i-=1;
      for(int k=0; k<i; k++){
        archivo<<"\t\tp"<<k<<" -> p"<<k+1<<"\n";
        if((k+1)==i) break;
      }
      archivo<<"\n\t}\n"; // cerrar cluster_1
      archivo<<"\ttail [label=\"tail\" shape=\"rect\"]\n";
      archivo<<"\tp"<<i<<" -> tail [arrowtail=none, arrowhead=none, color=\"transparent\"];\n";
      archivo<<"}";
      archivo.close();
      system("dot -Tjpg archivoCola.dot -o archivoCola.jpg");
    }
};


int main() {
  Cola<int> A;

  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Push\t[2] Pop\t\t[3] Print"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A.Push(dato);
      A.draw();
    } else if( op==2 ){
      A.Pop();
      A.draw();
    } else if( op==3 ){
      A.Print(); cout<<endl;
      A.draw();
      //system("dot -Tjpg archivo.dot -o archivo.jpg");
    } else break;
  }
  
  return 0;
}
