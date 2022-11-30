#include <string> //LIFO
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class NodoP {
  public:
    T m_Dato;
    NodoP<T> *m_pAnt;

    NodoP(T d) {
      m_Dato = d;
      m_pAnt = 0;
    }
};

template <class T>
class Pila {
  private:
    NodoP<T> * m_pTope; // ultimo insertado
  public:
    Pila() {
      m_pTope = 0;
    }
    bool IsEmpty() {
      return m_pTope==0;         
    }

    void push(T d) {
      NodoP<T> * pNuevo = new NodoP<T>(d); 
      if(!m_pTope)  // si esta vacio inserta 1er NodoP
        m_pTope =  pNuevo;
      else {
        pNuevo->m_pAnt = m_pTope; 
        m_pTope = pNuevo; // ahora tope apunta al ultimo elemento de encima
      }
    }
    
    void pop() {
      if(!m_pTope) return; // si esta vacio retorna
      NodoP<T> * tmp = m_pTope; 
      m_pTope = m_pTope->m_pAnt; // tope ahora es el penultimo 
      delete tmp; // liberamos el ultimo
    }

    T Top() {
      if(!IsEmpty())  
          return (m_pTope->m_Dato);
      return 0;
    }

    void dibujar(){
      if(!m_pTope) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoPila.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoPila.dot",ios::app); 
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape=box]\n";

      if(!(m_pTope->m_pAnt)){
        archivo<<"\t"<<m_pTope->m_Dato;
        archivo<<"\n}";
        archivo.close();
        system("dot -Tpdf archivoPila.dot -o archivoPila.pdf");
        system("zathura archivoPila.pdf &");
        return;
      } else {
        NodoP<T>* pTmp = m_pTope;
        //NodoP<T>* pTmpSig;
        while(pTmp) { // mientras existe pTmp
          //pTmpSig = pTmp;
          if(pTmp->m_pAnt!=nullptr) 
            archivo<<"\t"<<pTmp->m_Dato<<" -> ";
          pTmp = pTmp->m_pAnt;
          if(pTmp) 
            archivo<<pTmp->m_Dato<<"\n";
        }
        archivo<<"\n}";
        archivo.close(); //importante cerrar el archivo
      }
      //system("dot -Tjpg archivoPila.dot -o archivoPila.jpg");
      system("dot -Tpdf archivoPila.dot -o archivoPila.pdf");
      system("zathura archivoPila.pdf &");
    }
};
/*
int main(){
  Pila<int> A;
  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Push\t[2] Pop\t\t[3] Print"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A.push(dato);
    } else if( op==2 ){
      A.pop();
    } else if( op==3 ){
      A.dibujar(); cout<<endl;
    } else break;
  }
  return 0;
}*/
