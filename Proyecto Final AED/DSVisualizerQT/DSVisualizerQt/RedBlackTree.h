#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

template<class T>
class NodoRB{
  public:
    T m_Dato;
    NodoRB<T> * m_pSon[2];
    string color;
    NodoRB<T>* m_pParent;

    NodoRB(T d){
      m_Dato = d;
      m_pSon[0] = nullptr;
      m_pSon[1] = nullptr;
      m_pParent = nullptr;
      color = "rojo";
    }
};

template<class T>
class RedBlackTree{
  private:
    NodoRB<T>* m_pRoot;
    NodoRB<T>* pCurrent;
  public:
    RedBlackTree() {
      m_pRoot = nullptr;
    }

    void Insert_i(T d){
      NodoRB<T>* p = m_pRoot;
      NodoRB<T>* pTmpFather;
      if(!p) {
        m_pRoot = new NodoRB<T>(d);
        p = m_pRoot;
        p->m_pParent = nullptr;
        insercion_case1(p);
        return;
      }
      while(p){
        if(p->m_Dato == d) return;
        if(p->m_pSon[p->m_Dato < d]==nullptr){
          pTmpFather = p;
          break;
        }
        p = p->m_pSon[p->m_Dato < d];
      }
      p->m_pSon[p->m_Dato < d] = new NodoRB<T>(d);
      p = p->m_pSon[p->m_Dato < d];
      p->m_pParent = pTmpFather;
      insercion_case1(p);
    }

    void Transplant(NodoRB<T>* u, NodoRB<T>* v){
      if(u->m_pParent == nullptr){
        m_pRoot = v;
      } else if (u == u->m_pParent->m_pSon[0]){ // si u esta a la izq de su padre
        u->m_pParent->m_pSon[0] = v;
      } else { // si u esta a la der de su padre
        u->m_pParent->m_pSon[1] = v;
      }
      cout<<"----- Llega aqui"<<endl;
      v->m_pParent = u->m_pParent; // asignamos como padre de v al padre de u
    }

    /*void Delete_Fixup(NodoRB<T>* x){
      NodoRB<T>* s; //sibling
      while(x!=m_pRoot && x->color == "negro"){
        if(x==x->m_pParent->m_pSon[0]){
          s = x->m_pParent->m_pSon[1];
          if(s->color == "rojo"){ // Tipo 1
            s->color == "negro";
            x->m_pParent->color == "rojo";
            RI(x->m_pParent);
            s = x->m_pParent->m_pSon[1];
          }
          if(s->m_pSon[0]->color=="negro" && s->m_pSon[1]->color=="negro"){ // Tipo 2
            s->color =="rojo";
            x = x->m_pParent;
          } else {
            if(s->m_pSon[1]->color == "negro"){ // Tipo 3
              s->m_pSon[0]->color = "negro";
              s->color = "rojo";
              RD(s);
              s = x->m_pParent->m_pSon[1];
            }
            s->color = x->m_pParent->color; // Tipo 4
            x->m_pParent->color = "negro";
            s->m_pSon[1]->color = "negro";
            RI(x->m_pParent);
            x = m_pRoot;
          }
        } else {
          s = x->m_pParent->m_pSon[0];
          if(s->color=="rojo"){
            s->color = "negro";
            x->m_pParent->color = "rojo";
            RD(x->m_pParent);
            s = x->m_pParent->m_pSon[0];
          }
          if(s->m_pSon[1]->color == "negro" && s->m_pSon[1]->color == "negro"){ // Tipo 2
            s->color =="rojo";
            x = x->m_pParent;
          } else {
            if(s->m_pSon[0]->color == "negro"){ // Tipo 3
              s->m_pSon[1]->color = "negro";
              s->color = "rojo";
              RI(s);
              s = x->m_pParent->m_pSon[0];
            }
            s->color = x->m_pParent->color;
            x->m_pParent->color = "negro";
            s->m_pSon[0]->color = "negro";
            RD(x->m_pParent);
            x = m_pRoot;
          }
        }
      }
      x->color = "negro";
    }
    */

    /*void Delete(T d){
      NodoRB<T>* p = m_pRoot;
      NodoRB<T>* z=nullptr, * x, * y;
      while(p != nullptr){
        if(p->m_Dato == d)
          z = p;
        p = p->m_pSon[p->m_Dato < d];
      }
      if(z==nullptr){ cout<<"No found"<<endl; return; }
      y = z;
      string y_color_original = y->color;
      if(z->m_pSon[0] == nullptr){
        x = z->m_pSon[1];
        Transplant(z,z->m_pSon[1]);
      } else if (z->m_pSon[1] == nullptr){
        x = z->m_pSon[0];
        Transplant(z,z->m_pSon[0]);
      }else {
        y = Minimum(z->m_pSon[1]);
        y_color_original = y->color;
        x = y->m_pSon[1];
        if(y->m_pParent == z)
          x->m_pParent = y;
        else{
          Transplant(y,y->m_pSon[1]);
          y->m_pSon[1] = z->m_pSon[1];
          y->m_pSon[1]->m_pParent = y;
        }
        Transplant(z,y);
        y->m_pSon[0] = z->m_pSon[0];
        y->m_pSon[0]->m_pParent = y;
        y->color = z->color;
      }

      delete z;
      if(y_color_original == "negro"){ Delete_Fixup(x); }
    }*/

    NodoRB<T>* Minimum(NodoRB<T>* NodoRB) {
      while (NodoRB->m_pSon[0] != nullptr)
        NodoRB = NodoRB->m_pSon[0];
      return NodoRB;
    }

    NodoRB<T>* Maximum(NodoRB<T>* NodoRB) {
      while (NodoRB->m_pSon[1] != nullptr)
        NodoRB = NodoRB->m_pSon[1];
      return NodoRB;
    }

    void insercion_case1(NodoRB<T>*& n){   // Si es raiz, cambia a negro
      if(n->m_pParent == nullptr)
        n->color = "negro";
      else
        insercion_case2(n);
    }

    void insercion_case2(NodoRB<T>*& n){   //verificar que el padre sea negro
      if(n->m_pParent->color == "negro")
        return; // Arbol valido
      else
        insercion_case3(n);
    }

    void insercion_case3(NodoRB<T>*& n){   //caso tio rojo
      NodoRB<T>* t = getUncle_i(n);
      NodoRB<T>* a;
      if((t!=nullptr) && (t->color == "rojo")){
        n->m_pParent->color = "negro";
        t->color = "negro";
        a = getGrandFather_i(n);
        a->color = "rojo";
        insercion_case1(a);
      } else {
        insercion_case4(n);
      }
    }

    void insercion_case4(NodoRB<T>*& n){
      NodoRB<T>* f = n->m_pParent;
      NodoRB<T>* a = getGrandFather_i(n);
      if((n == n->m_pParent->m_pSon[1]) && (n->m_pParent == a->m_pSon[0])) {
        //cout<<"ejecutando RI del caso 4"<<endl;
        RI(f);
        n = n->m_pSon[0];
      } else if((n == n->m_pParent->m_pSon[0]) && (n->m_pParent == a->m_pSon[1])){
        //cout<<"ejecutando RD del caso 4"<<endl;
        RD(f);
        n = n->m_pSon[1];
      }
      insercion_case5(n);
    }

    void insercion_case5(NodoRB<T>*& n){
      NodoRB<T>* a = getGrandFather_i(n);
      //cout<<"a = "<<a->m_Dato<<endl;
      n->m_pParent->color = "negro";
      a->color = "rojo";
      if((n == n->m_pParent->m_pSon[0]) && (n->m_pParent == a->m_pSon[0])){
        //cout<<"Ejecutando RD en caso 5"<<endl;
        RD(a);
      } else {
        //cout<<"Ejecutando RI en caso 5"<<endl;
        RI(a);
      }
    }
    void RI(NodoRB<T>*& x){
      NodoRB<T>* y = x->m_pSon[1];
      x->m_pSon[1] = y->m_pSon[0];
      if(y->m_pSon[0] != nullptr)
        y->m_pSon[0]->m_pParent = x;
      y->m_pParent = x->m_pParent;
      if(x->m_pParent == nullptr)
        m_pRoot = y;
      else if(x == x->m_pParent->m_pSon[0])
        x->m_pParent->m_pSon[0] = y;
      else
        x->m_pParent->m_pSon[1] = y;
      y->m_pSon[0] = x;
      x->m_pParent = y;
    }

    void RD(NodoRB<T>*& x){
      NodoRB<T>* y = x->m_pSon[0];
      x->m_pSon[0] = y->m_pSon[1];
      if(y->m_pSon[1] != nullptr)
        y->m_pSon[1]->m_pParent = x;
      y->m_pParent = x->m_pParent;
      if(x->m_pParent == nullptr)
        m_pRoot = y;
      else if(x == x->m_pParent->m_pSon[1])
        x->m_pParent->m_pSon[1] = y;
      else
        x->m_pParent->m_pSon[0] = y;
      y->m_pSon[1] = x;
      x->m_pParent = y;
    }

    NodoRB<T>* getFather_i(NodoRB<T>* d) {
      NodoRB<T>* aux = m_pRoot;
      if(!m_pRoot) return 0;
      while(aux->m_pSon[aux->m_Dato < d->m_Dato] != nullptr){
        if(aux->m_pSon[aux->m_Dato < d->m_Dato]->m_Dato == d->m_Dato)
          return aux;
        aux = aux->m_pSon[aux->m_Dato < d->m_Dato];
      }
      return 0;
    }

    NodoRB<T>* getSibling(NodoRB<T>* d) { //getBrother
      NodoRB<T>* pTmpPadre = getFather_i(d);
      if (pTmpPadre == nullptr) return 0;
      if((pTmpPadre->m_pSon[0] == nullptr) && (pTmpPadre->m_pSon[1] != nullptr))
        return 0;
      else if((pTmpPadre->m_pSon[1] == nullptr) && (pTmpPadre->m_pSon[0] != nullptr))
        return 0;
      if(pTmpPadre->m_pSon[0]->m_Dato == d->m_Dato)
        return pTmpPadre->m_pSon[1];
      else if (pTmpPadre->m_pSon[1]->m_Dato == d->m_Dato)
        return pTmpPadre->m_pSon[0];
      else
        return 0;
    }

    NodoRB<T>* getUncle_i(NodoRB<T>* d){
      NodoRB<T>* pTmpPadre = getFather_i(d);
      if(!pTmpPadre) return 0;
      NodoRB<T>* pTmpTio = getSibling(pTmpPadre);
      return pTmpTio ? pTmpTio : 0;
    }

    NodoRB<T>* getGrandFather_i(NodoRB<T>* d) {
      NodoRB<T>* tmpFather = getFather_i(d);
      if(tmpFather==nullptr) return 0;
      NodoRB<T>* aux = getFather_i(tmpFather);
      return aux ? aux : 0;
    }

    RedBlackTree<T> & operator<<(T d) {
      Insert_i(d); // Insert_r(d);
      return *this;
    }
    friend ostream & operator<< (ostream & os , RedBlackTree<T>& arb) {
      arb.In_Order();
      return os;
    }

    void In_Order(NodoRB<T>* p){ // [1] subarbol Izq [2] Raiz [3] subarbol Der
      if(p) {
        In_Order(p->m_pSon[0]);
        cout<<"[ "<<p->m_Dato<<" ("<<p->color<<") - Padre: ";
        if(getFather_i(p)) cout<<getFather_i(p)->m_Dato<<") ] \n";
        else cout<<" nullptr ]\n";
        In_Order(p->m_pSon[1]);
      }else return;
    }
    void In_Order(){
      In_Order(m_pRoot);
    }

    bool find_element(T d){   //Similar al Binario Trees
      NodoRB<T>* pTmp = m_pRoot;
      if(pTmp == nullptr) return false;
      while (pTmp) {
        if(pTmp->m_Dato == d)
          //cout<<"Encontrado :)"<<endl;
          return true;
        pTmp = pTmp->m_pSon[pTmp->m_Dato < d];
      }
      return false;
    }

    void Draw(){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoRB.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoRB.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";


      // Asigna colores

      stack<NodoRB<T>*> pila0;
      pCurrent = m_pRoot;
      while(!pila0.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila0.push(pCurrent);
          archivo<<"\t"<<pCurrent->m_Dato<<" [fillcolor=\"";
          if(pCurrent->color == "rojo")
            archivo<<"#FF1B1B\", style=filled, fontcolor=\"#000000\"pad=50.0]"; // color rojo
          else
            archivo<<"#000000\", style=filled, fontcolor=\"#FFFFFF\",pad=50.0]"; // color negro
          archivo<<"\n";
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila0.top();
          pila0.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      archivo<<"\n";

      // Asigna enlaces -------------------
      stack<NodoRB<T>*> pila;
      pCurrent = m_pRoot;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[0]->m_Dato<<"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[1]->m_Dato<<"\n";
          pCurrent = pCurrent->m_pSon[0];
        }
        else {
          pCurrent = pila.top();
          pila.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }

      archivo<<"\n}";
      archivo.close();

      system("dot -Tjpg archivoRB.dot -o archivoRB.jpg");
    }

    void Find_Draw_RB(T d){
      if(!m_pRoot) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("archivoRB.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoRB.dot",ios::app);
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape = circle]\n";
      archivo<<"\tnode[style = filled]\n";


      // Asigna colores

      stack<NodoRB<T>*> pila0;
      pCurrent = m_pRoot;
      while(!pila0.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila0.push(pCurrent);
          archivo<<"\t"<<pCurrent->m_Dato<<" [fillcolor=\"";
          if(pCurrent->color == "rojo")
            archivo<<"#FF1B1B\", style=filled, fontcolor=\"#000000\"]"; // color rojo
          else
            archivo<<"#000000\", style=filled, fontcolor=\"#FFFFFF\"]"; // color negro
          archivo<<"\n";
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila0.top();
          pila0.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      archivo<<"\n";

      // Asigna enlaces -------------------
      stack<NodoRB<T>*> pila;
      pCurrent = m_pRoot;
      while(!pila.empty() || pCurrent != nullptr) {
        if(pCurrent != nullptr) {
          pila.push(pCurrent);
          if(pCurrent->m_pSon[0])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[0]->m_Dato<<"\n";
          if(pCurrent->m_pSon[1])
            archivo<<"\t"<<pCurrent->m_Dato<<" -> "<<pCurrent->m_pSon[1]->m_Dato<<"\n";
          pCurrent = pCurrent->m_pSon[0];
        } else {
          pCurrent = pila.top();
          pila.pop();
          pCurrent = pCurrent->m_pSon[1];
        }
      }
      /*ENCONTRAR*/
      if(find_element(d))
        archivo<<"\t"<<d<<"[fillcolor = \"#EEE111\"]\n";

      archivo<<"\n}";
      archivo.close();

      system("dot -Tpdf archivoRB.dot -o archivoRB.pdf");
      system("zathura archivoRB.pdf &");
    }

    void menu()
    {
      RedBlackTree<int> A;
      int op, dato;
      while (1)
      {
        cout << "Ingrese Opcion: " << endl;
        cout << "[1] Insert\t[2] Delete\t\t[3] Dibujar" << endl;
        cin >> op;
        if (op == 1)
        {
          cout << "Ingrese dato => ";
          cin >> dato;
          A << dato;
        }
        else if (op == 2)
        {
          cout << "Se elimino dato" << endl;
        }
        else if (op == 3)
        {
          cout << A << endl;
          A.Draw();
        }
        else
          break;
      }
    }
};



#endif // REDBLACKTREE_H
