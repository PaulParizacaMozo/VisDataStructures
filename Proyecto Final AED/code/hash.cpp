#include <iostream>
#include <fstream>
#include <list>
#include <iterator>

using namespace std;

template <class Obj, int (*fd)(string, int), int size = 11>
class Hash {
  private:
    list<Obj> m_Tablal[size];

  public:
    Hash(){};
    
    void Insert(string key, Obj obj){
      int pos = fd(key, size);
      //cout << "Lugar de insercion : " << pos << endl;
      m_Tablal[pos].push_back(obj);
    }

    void Print(){
      typedef typename list<Obj>::iterator ITERADOR;

      for (int i = 0; i < size; i++) {
        ITERADOR it = m_Tablal[i].begin();
        cout << "[" << i << "]";
        for (; it != m_Tablal[i].end(); ++it)
          cout << *it << "-->";
        cout << endl;
      }
    }

    void Draw(){
      //if(m_Tablal->empty()) return;
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede añadir datos donde se quedo el cursor
      limpiar.open("archivoHash.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      archivo.open("archivoHash.dot",ios::app); 
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\trankdir = LR\n";
      archivo<<"\tnode [shape=record, width=0.1, height=0.1]\n";
      archivo<<"\ttabla [label = \"";
      for (int i=0; i<size; i++) {
        archivo<<"<"<<i<<"> "<<i;
        if(i+1 != size){
          archivo<<" | ";
        }
      }
      archivo<<"\", height = 5, fillcolor = \"#76F6FA\" style=filled, fontcolor=\"#000000\"];\n";
      archivo<<"\tnode[ width=0.8 ];\n";
      // --- Construccion de nodos
      typedef typename list<Obj>::iterator ITERADOR;
      int contador = 0;
      for (int i = 0; i < size; i++) {
        ITERADOR it = m_Tablal[i].begin();
        contador = 0;
        for (; it != m_Tablal[i].end(); ++it){
          archivo<<"\tnode"<<i<<"_"<<contador<<" [label = \"{<e> "<<contador<<" | "<<*it<<"}\" ]\n";
          contador++;
        }
      }
      // --- Construccion de enlaces de la tabla Hash
      typedef typename list<Obj>::iterator ITERADOR;
      contador = 0;
      for (int i = 0; i < size; i++) {
        ITERADOR it = m_Tablal[i].begin();
        contador = 0;
        if(!m_Tablal[i].empty()){
          archivo<<"\ttabla:"<<i<<" -> node"<<i<<"_0"<<";\n";
        }
        ++it; // importante
        for (; it != m_Tablal[i].end(); ++it){
          archivo<<"\tnode"<<i<<"_"<<contador<<" -> ";
          archivo<<"node"<<i<<"_"<<contador+1<<" \n";
          contador++;
        }
      }
      archivo<<"\n}";
      archivo.close();
      system("dot -Tjpg archivoHash.dot -o archivoHash.jpg");
      //system("zathura archivoCola.pdf &");
    }
};

// Estas son funciones de disperción creadas por el usuario
int FD1(string key, int size) {
  char *p = (char *)key.c_str();
  int s = 0;
  while (*p) {
    s += *p;
    p++;
  }
  return s % size;
}

int FD2(string key, int size) {
  int s = key.size();
  if (s < 2)
    return (key[0] * key[0]) % size;
  return (key[s / 2] * key[s / 2 + 1]) % size;
}



int main() {
  Hash<int, FD2> A;
  A.Insert("cuatro", 4);
  A.Insert("ocho", 34);
  A.Insert("nueve", 44);
  A.Insert("treitaitres", 54);
  A.Insert("noventa", 64);
  A.Insert("xxxx", 774);
  A.Insert("xxxx", 11);
  A.Insert("xxxx", 22);
  A.Insert("xxxx", 33);
  A.Insert("trece", 44);
  A.Insert("doce", 111);
  A.Print();
  A.Draw();

  int op, dato;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Insert\t[2] Delete\t\t[3] Dibujar"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese dato => "; cin>>dato;
      A.Insert("ocho", dato);
    } else if( op==2 ){
      cout<<"Se elimino dato"<<endl;
    } else if( op==3 ){
      A.Print();
      A.Draw();
      //cout<<A<<endl;
      system("dot -Tjpg archivo.dot -o archivo.jpg");
    } else break;
  }
}
