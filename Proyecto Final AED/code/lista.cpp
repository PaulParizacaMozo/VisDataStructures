#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

template<class T>
class NodoL {
  public:
    T m_Dato;
    NodoL<T> *m_pSig;

    NodoL(T d) {
      m_Dato = d;
      m_pSig = nullptr;
    }
};

template<class T>
class List{
  private:
    NodoL<T>* m_pHead;
    int m_Size;
  public:
    List(){
      m_pHead = nullptr;
      m_Size = 0;
    }
    ~List(){}

    void Push_Front(T d){ //Iterativo
      NodoL<T>* pNew = new NodoL<T>(d);
      if(!m_pHead){ // si head no tiene nada 
        m_pHead = pNew; // inserto primer nodo
        m_Size++;
        return;
      } else {
        pNew->m_pSig = m_pHead;
        m_pHead = pNew;
      }
      m_Size++;
    }

    void Push_Back(T d){ //Iterativo
      NodoL<T>* pTmp = m_pHead;
      if(!m_pHead){ // si head no tiene nada 
        m_pHead = new NodoL<T>(d); // inserto primer nodo
        m_Size++;
        return;
      } else if(!m_pHead->m_pSig) {
        m_pHead->m_pSig = new NodoL<T>(d);
        m_Size++;
        return;
      }
      while(true){
        pTmp = pTmp->m_pSig;
        if (!pTmp->m_pSig) break; // si el sig apunta a nada significa que pTmp apunta al ultimo nodo
      }
      pTmp->m_pSig = new NodoL<T>(d); m_Size++;
    }

    void InsertPorIndice(int indice,T d){
      if(indice>=0 && indice<=m_Size-1){
        if(indice==0){ Push_Front(d); return;}
        else{
          NodoL<T>* pCurrent = m_pHead;
          NodoL<T>* pPrev;
          int contador = 0;
          while(true){
            pPrev = pCurrent; // pPrev siempre apunta una posicion antes que pCurrent
            pCurrent = pCurrent->m_pSig;
            contador++;
            if (contador==indice) break; // si el sig apunta a nada significa que pTmp apunta al ultimo nodo
          }
          pPrev->m_pSig = new NodoL<T>(d);
          pPrev->m_pSig->m_pSig = pCurrent;
          m_Size++;
        }
      }
    }

    void Pop_Front() { // Iterativo
      NodoL<T>* pCurrent = m_pHead;
      if(!m_pHead) return; //Si esta vacia retorna
      if(!m_pHead->m_pSig){
        m_pHead = m_pHead->m_pSig;
        delete pCurrent; //si tiene un nodo
        m_Size--;
        return;
      } 
      m_pHead = m_pHead->m_pSig; //head apunta al 2do nodo
      pCurrent->m_pSig = 0;
      delete pCurrent;
      m_Size--;
    }

    void Pop_Last() { //Iterativo
      NodoL<T>* pCurrent = m_pHead;
      NodoL<T>* pPrev = nullptr;
      if(!m_pHead) return; //Si esta vacia retorna
      if(!m_pHead->m_pSig){
        m_pHead = m_pHead->m_pSig;
        delete pCurrent; //si tiene un nodo
        m_Size--;
        return;
      }  
      while(true){
        pPrev = pCurrent; // pPrev siempre apunta una posicion antes que pCurrent
        pCurrent = pCurrent->m_pSig;
        if (!pCurrent->m_pSig) break; // si el sig apunta a nada significa que pTmp apunta al ultimo nodo
      }
      pPrev->m_pSig = 0;
      delete pCurrent;
      m_Size--;
    }

    bool Find(T d) { // Iterativo
      NodoL<T>* pTmp = m_pHead;
      if(!m_pHead) return false; //Si esta vacio retorna
      while(pTmp) { // mientras existe pTmp
        if(pTmp->m_Dato == d)
          return true;
        pTmp = pTmp->m_pSig;
      }
      return false;
    }

    T getMax() { // valor maximo de la lista - iterativo
      NodoL<T>* pTmp = m_pHead;
      T max = pTmp->m_Dato;
      if(!m_pHead->m_pSig) return max;
      pTmp = pTmp->m_pSig;
      while(true){
        if(pTmp->m_Dato > max){
          max = pTmp->m_Dato;
        }
        pTmp = pTmp->m_pSig;
        if (!pTmp->m_pSig) break;
      }
      return max;
    }


    void Print() { // Iterativo
      NodoL<T>* pTmp = m_pHead;
      if(!m_pHead) return; //Si esta vacio sale
      while(pTmp) { // mientras existe pTmp
        cout<<pTmp->m_Dato<<" --> ";
        pTmp = pTmp->m_pSig;
      }
    }

    void Draw(){
      //if(!m_pFirst) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoLista.dot",ios::out); limpiar<<""; limpiar.close();
      archivo.open("archivoLista.dot",ios::app); 
      if(archivo.fail()){  cout<<"No se puede abrir archivo"<<endl; exit(1); }
      NodoL<T>* pTmp = m_pHead;
      archivo<<"digraph G{\n";
      if(!m_pHead){
        archivo<<"\trankdir=LR\n";
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n";
        archivo<<"\tnull[label=\"NULL\" shape=\"none\"];\n";
        archivo<<"\thead -> null [dir=\"both\" arrowtail=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoLista.dot -o archivoLista.jpg"); return;
      }
      
      if(m_Size==1){
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n\trankdir=LR;\n";
        archivo<<"\tnodo_0[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\" shape=\"record\" style=\"filled\" fillcolor=\"gray80\"];\n";
        archivo<<"\thead -> nodo_0 [dir=\"both\" arrowtail=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoLista.dot -o archivoLista.jpg"); return;
      }
      
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
      archivo<<"\t\thead [label=\"head\" shape=\"rect\"]\n";
      archivo<<"\n\t}\n"; // cerrar cluster_1
      archivo<<"}";
      archivo.close();
      system("dot -Tjpg archivoLista.dot -o archivoLista.jpg");
    }

    void Find_Draw(T dato){
      //if(!m_pFirst) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoLista.dot",ios::out); limpiar<<""; limpiar.close();
      archivo.open("archivoLista.dot",ios::app); 
      if(archivo.fail()){  cout<<"No se puede abrir archivo"<<endl; exit(1); }
      NodoL<T>* pTmp = m_pHead;
      archivo<<"digraph G{\n";
      if(!m_pHead){ //Si no hay nada
        archivo<<"\trankdir=LR\n";
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n";
        archivo<<"\tnull[label=\"NULL\" shape=\"none\"];\n";
        archivo<<"\thead -> null [dir=\"both\" arrowtail=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoLista.dot -o archivoLista.jpg"); return;
      }
      
      if(m_Size==1){ // si hay un elemento;
        archivo<<"\thead [label=\"head\" shape=\"rect\"];\n\trankdir=LR;\n";
        archivo<<"\tnodo_0[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\" shape=\"record\" style=\"filled\" fillcolor=\"gray80\"];\n";
        archivo<<"\thead -> nodo_0 [dir=\"both\" arrowtail=none];\n";
        archivo<<"}";
        archivo.close();
        system("dot -Tjpg archivoLista.dot -o archivoLista.jpg"); return;
      }
      archivo<<"\trankdir=\"LR\"\n";
      archivo<<"\tedge[tailclip=false,arrowtail=dot,dir=both];\n";
      archivo<<"\tsubgraph clust0 {\n";
      archivo<<"\t\tstyle=filled;\n";
      archivo<<"\t\tcolor=white;\n\t\tnode [style=filled];\n\t\tnode[shape=record]\n";

      int i = 0;
      do{
        archivo<<"\t\tnodo_"<<i<<"[label=\"{<dato> "<<pTmp->m_Dato<<"| <sig>}\" ";
        if(pTmp->m_Dato == dato)
          archivo<<"fillcolor=\"skyblue\"];\n";
        else
          archivo<<"];\n";
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
      archivo<<"\t\thead [label=\"head\" shape=\"rect\"]\n";
      archivo<<"\n\t}\n"; // cerrar cluster_1
      archivo<<"}";
      archivo.close();
      system("dot -Tjpg archivoLista.dot -o archivoLista.jpg");
    }
};


int main(){
  List<int> A;
  int op, dato, ind;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] PushBack\t[2] PushFront\t[3] InsertPorIndice\t[4] PopBack\t[5] PopFront"<<endl;
    cout<<"[6] Draw\t\t[7] Find"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A.Push_Back(dato);
      A.Print(); cout<<endl;
    } else if( op==2 ){
      cout<<"Ingrese dato => "; cin>>dato;
      A.Push_Front(dato);
      A.Print(); cout<<endl;
    } else if( op==3 ){
      cout<<"Ingrese dato => "; cin>>dato;
      cout<<"Ingrese indice => "; cin>>ind;
      A.InsertPorIndice(ind,dato);
      A.Print(); cout<<endl;
    } else if( op==4 ){
      A.Pop_Last();
      A.Print(); cout<<endl;
    } else if( op==5 ){
      A.Pop_Front();
      A.Print(); cout<<endl;
    } else if( op==6 ){
      A.Print(); cout<<endl;
      A.Draw();
    } else if( op==7 ){
      cout<<"Ingrese dato => "; cin>>dato;
      A.Find_Draw(dato);
    } else break;
  }

  return 0;
}
