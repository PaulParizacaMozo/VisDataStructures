#include <string> //FIFO
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class NodoC {
  public:
    T m_Dato;
    NodoC<T> *m_pSig;

    NodoC(T d) {
      m_Dato = d;
      m_pSig = 0;
    }
};

template<class T>
class Cola { //primero que entra primero que sale
  private:
    NodoC<T> * m_pFirst;
    NodoC<T> * m_pLast;
    
  public:
    Cola() {
      m_pFirst = 0;
      m_pLast = 0;
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
    }

    void Pop() { //pop
      if(!m_pFirst) return; //Si esta vacia retorna
      NodoC<T>* pCurrent = m_pFirst;
      if(!m_pFirst->m_pSig){
        m_pFirst = m_pFirst->m_pSig;
        delete pCurrent; //si tiene un NodoC
        return;
      }
      m_pFirst = m_pFirst->m_pSig; //First apunta al 2do NodoC
      pCurrent->m_pSig = 0;
      delete pCurrent;
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

    void dibujar(){
      if(!m_pFirst) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoCola.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoCola.dot",ios::app); 
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\trankdir = \"LR\"\n";
      archivo<<"\tnode[shape=box]\n";

      if(!m_pFirst->m_pSig){
        archivo<<"\t"<<m_pFirst->m_Dato;
        archivo<<"\n}";
        archivo.close();
        system("dot -Tpdf archivoCola.dot -o archivoCola.pdf");
        system("zathura archivoCola.pdf &");
        return;
      } else {
        NodoC<T>* pTmp = m_pFirst;
        //NodoC<T>* pTmpSig;
        while(pTmp) { // mientras existe pTmp
          //pTmpSig = pTmp;
          if(pTmp!=m_pLast) 
            archivo<<"\t"<<pTmp->m_Dato<<" -> ";
          pTmp = pTmp->m_pSig;
          if(pTmp) 
            archivo<<pTmp->m_Dato<<"\n";
        }
        archivo<<"\n}";
        archivo.close(); //importante cerrar el archivo
      }
      system("dot -Tpdf archivoCola.dot -o archivoCola.pdf");
      system("zathura archivoCola.pdf &");
    }
};

/*
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
    } else if( op==2 ){
      A.Pop();
    } else if( op==3 ){
      A.Print(); cout<<endl;
      //system("dot -Tjpg archivo.dot -o archivo.jpg");
    } else break;
  }
  
  return 0;
}*/
