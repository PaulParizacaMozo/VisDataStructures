#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <iostream>
#include <list> // lista doble que tiene c++
#include <queue>
#include <fstream>
using namespace std;

template <typename T>
class Nodo_Binomial
{
  typedef Nodo_Binomial<T> *pNodo;

public:
  T m_Data;
  int m_Grade;
  pNodo m_pFather;
  bool m_visitado;
  list<pNodo> m_Sons;

public:
  Nodo_Binomial(T d)
  {
    m_Data = d;
    m_Grade = 0;
    m_pFather = 0;
    m_visitado = 0;
    // No tiene hijos
  }
  ~Nodo_Binomial() {}

  // Añadir un hijo al nodo en su lista de hijos
  void Add_Son(pNodo p)
  {
    m_Sons.push_front(p);
  }
};

template <typename T>
class Binomial_Heap
{
  typedef Nodo_Binomial<T> *pNodo; // solo declaramos un sinonimo
  typedef typename list<pNodo>::iterator Iterator;
  /*
  typename here is letting the compiler know that (iterator) is a type and not a static member of (list<pNodo>).
  the :: is the scope of the type. It is kind of like "is in" so iterator "is in" list<pNodo>. or can also be
  thought of as contains.
  */
private:
  list<pNodo> m_pHeads; // Lista de punteros que apuntan a las cabezas de un arbol binomial
  int m_size;           // Para saber cuántos nodos tenemos en el Binomial Heap
  Iterator p_max;

private: // funciones con la que no puede interactuar el usuario
  // Time complexity O(logn)
  void compact()
  {
    if (!m_pHeads.empty())
    {
      Iterator h = m_pHeads.begin();
      Iterator r = m_pHeads.begin();
      for (; h != m_pHeads.end(); ++h)
      {
        if (m_size != 1)
        {
          if ((*h)->m_Data == (*r)->m_Data)
          {
            // cout<<"Estan apuntando al mismo";
          }
          else if ((*h)->m_Grade == (*r)->m_Grade)
          {
            if ((*h)->m_Data > (*r)->m_Data)
            {
              (*h) = link((*r), (*h));
              (*r) = 0;
              m_pHeads.remove((*r));
              delete (*r);
              r = h;
              m_size--;
            }
            else
            {
              (*r) = link((*h), (*r));
              (*h) = 0;
              m_pHeads.remove((*h));
              // cout<<"Ya fueron unidos";
              delete (*h);
              h = r++;
              r--;
              m_size--;
            }
          }
        }
        else
        {
          return;
        }
      }
    }
    else
    {
      return;
    }
  }

  // time complexity O(1) porque solo mete a 1 hijo
  pNodo link(pNodo p, pNodo q)
  {
    if (p->m_Data > q->m_Data)
    {
      p->m_Sons.push_front(q);
      q->m_pFather = p;
      p->m_Grade++;
      return p;
    }
    q->m_Sons.push_front(p);
    p->m_pFather = q;
    q->m_Grade++;
    return q;
  }

  // Complexity Timely O(logn)
  Iterator find_max()
  { // encontrar al máximo
    // ITERATOR esta definido arriba como un typename
    Iterator it = m_pHeads.begin(); // ahora el iterador esta en el inicio
    // guardamos el mayor en otro iterator:
    Iterator Maxinum = it;
    for (; it != m_pHeads.end(); ++it) // para avanzar con el iterator it hasta end();
    {
      if ((*Maxinum)->m_Data < (*it)->m_Data)
      {
        Maxinum = it;
      }
    }
    return Maxinum;
  }

public:
  Binomial_Heap()
  {
    m_size = 0;
    p_max = m_pHeads.begin();
    // Aún no hay m_pheads
  }
  ~Binomial_Heap() {}

  // time: O(logn)
  void Insert(T d)
  {
    if (m_pHeads.empty())
    {
      pNodo pNew = new Nodo_Binomial<T>(d);
      m_pHeads.push_front(pNew);
      p_max = find_max();
      m_size++;
    }
    else
    {
      pNodo pNew = new Nodo_Binomial<T>(d);
      m_pHeads.push_front(pNew);
      p_max = find_max();
      m_size++;
      compact();
      p_max = find_max();
    }
  }
  void Extract_Max()
  {
    // 1. find max
    Iterator pMax = find_max();
    // 2. Subir los hijos con sus respectivas hojas
    Iterator it = (*pMax)->m_Sons.begin();
    for (; it != (*pMax)->m_Sons.end(); it++)
    {
      m_pHeads.push_front(*it);
    }
    // 3.Eliminamos el pMax
    m_pHeads.erase(pMax);
    // 4. Compactamos
    compact();
  }

  void Delete(pNodo p)
  { // pasamos el puntero al nodo que eliminaremos
    Increase_key(p, 10000000);
    Extract_Max();
  }

  pNodo Get_Max()
  { // nos dará el nodo al máximo
    Iterator pMax = find_max();
    return (*pMax);
  }

  // time complexity O(logn)
  void Increase_key(pNodo p, T d)
  {
    // recibimos el puntero al nodo que le incrementaremos el Key y cuánto le incrementaremos
    if (p->m_Data > d)
      return;      // verificamos que exista un increase
    p->m_Data = d; // cambiamos dato
    while (p->m_pFather && p->m_pFather->m_Data < p->m_Data)
    {
      swap(p->m_Data, p->m_pFather->m_Data); // hacemos swap entre 2 datos
      // reubicamos p:
      p = p->m_pFather;
    }
  }
  Iterator sumar_direc(Iterator it)
  {
    it++;
    return it;
  }

  Iterator rest_direc(Iterator it)
  {
    it--;
    return it;
  }

  void Print()
  { // Basado en BFS
    typedef typename list<pNodo>::iterator itSons;
    if (m_pHeads.empty())
      return;
    auto itheads = m_pHeads.begin();
    auto it2 = (*itheads)->m_Sons.begin();
    queue<pNodo> cola;
    for (; itheads != m_pHeads.end(); itheads++)
    { // Recorre heads y imprime las cabezas
      cout << "[head] ";
      cola.push(*itheads);     // Inserta primer nodo
      pNodo it = cola.front(); // it es el 1er elemento de la cola
      it->m_visitado = true;   // lo marcamos como visitado
      while (!cola.empty())
      {
        it = cola.front();
        cout << it->m_Data << " ";          // Mostramos el primer elemento de la cola
        cola.pop();                         // Eliminamos el elemento ya mostrado
        itSons itsons = it->m_Sons.begin(); // Consultamos los hijos del nodo it actual;
        int c = 0;
        for (; itsons != it->m_Sons.end(); itsons++)
        {
          if ((*itsons)->m_visitado == false)
          { // Si aun no fue visitado lo agregamos a la cola
            (*itsons)->m_visitado == true;
            cola.push(*itsons);
          }
          c++;
        }
        cout << "(sons:" << c << ") ";
        c = 0;
      }
      cout << "\n";
    }
    /*cout<<endl;
    typedef typename list<pNodo>::iterator itListNodos;
    list<pNodo> print = res;
    for(auto it3 = print.begin(); it3!=print.end(); it3++){
      cout<<(*it3)->m_Data<<" ";
    }*/
  }

  void printNelzon()
  {
    if (!m_pHeads.empty())
    {
      Iterator it = m_pHeads.begin();
      for (; it != m_pHeads.end(); it++)
      {
        BFS((*it));
      }
    }
    else
    {
      cout << "No hay elementos en la lista" << endl;
    }
  }

  void BFS(pNodo q)
  { // recursiva
    cout << q->m_Data;
    if (!q->m_Sons.empty())
    {
      cout << "( ";
      Iterator son = q->m_Sons.begin();
      for (; son != q->m_Sons.end(); son++)
      {
        BFS((*son));
      }
      cout << ") ";
    }
    else
    {
      cout << " ---- ";
    }
  }

  void Draw()
  {
    if (!m_pHeads.empty())
    {
      ofstream limpiar, archivo;
      // ios::in -> al abrir escribe desde 0 el archivo
      // ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
      limpiar.open("BinoHeap.dot", ios::out);
      limpiar << "";
      limpiar.close();
      archivo.open("BinoHeap.dot", ios::app);
      if (archivo.fail())
      {
        cout << "No se puede abrir archivo" << endl;
        exit(1);
      }
      archivo << "digraph G{\n";

      // mínimo apuntando
      archivo << "\t Máximo ->" << (*p_max)->m_Data << "\n";
      archivo << "\t Máximo[fillcolor=springgreen,style=filled,shape = octagon,fixedsize = true] edge[color=springgreen]\n";

      // heads:
      auto aux = m_pHeads.begin();
      archivo << "\t";
      while (aux != m_pHeads.end())
      {
        archivo << (*aux)->m_Data;
        if (sumar_direc(aux) != m_pHeads.end())
        {
          archivo << " -> ";
        }
        aux++;
      }
      archivo << "\n";
      auto aux2 = m_pHeads.begin();
      archivo << "\t{rank=same;";
      while (aux2 != m_pHeads.end())
      {
        archivo << (*aux2)->m_Data;
        if (sumar_direc(aux2) != m_pHeads.end())
        {
          archivo << ";";
        }
        aux2++;
      }
      archivo << "}\n";

      /*auto it=m_pHeads.begin();
      int i=0;
      for(;it!=m_pHeads.end();it++){ //-------------- nodos padre
        archivo<<"\tnodo_"<<i<<"[label=\""<<(*it)->m_Data<<"\"]\n";
        i++;
      }
      for(int k=0; k<i-1; k++){ // ----- enlace entre padres
        archivo<<"\tnodo_"<<k<<" -> nodo_"<<k+1<<";\n";
      }
      it = m_pHeads.begin();
      archivo<<"\t{ rank=same;"; // rank=same -------------
      for(int k=0; k<i; k++){
        archivo<<"nodo_"<<k<<"; ";
      }
      archivo<<"}\n"; // -------------------------------
      */

      list<pNodo> res;
      typedef typename list<pNodo>::iterator itSons;
      if (m_pHeads.empty())
        return;
      auto itheads = m_pHeads.begin();
      auto it2 = (*itheads)->m_Sons.begin();
      queue<pNodo> cola;
      for (; itheads != m_pHeads.end(); itheads++)
      { // Recorre heads y imprime las cabezas
        // cout<<"[head] ";
        cola.push(*itheads);     // Inserta primer nodo
        pNodo it = cola.front(); // it es el 1er elemento de la cola
        it->m_visitado = true;   // lo marcamos como visitado
        while (!cola.empty())
        {
          it = cola.front();
          // cout<<it->m_Data<<" "; // Mostramos el primer elemento de la cola
          res.push_back(it);
          cola.pop();                         // Eliminamos el elemento ya mostrado
          itSons itsons = it->m_Sons.begin(); // Consultamos los hijos del nodo it actual;
          for (; itsons != it->m_Sons.end(); itsons++)
          {
            if ((*itsons)->m_visitado == false)
            { // Si aun no fue visitado lo agregamos a la cola
              (*itsons)->m_visitado == true;
              cola.push(*itsons);
            }
          }
        }
      }

      // typedef typename list<pNodo>::iterator itListNodos;
      list<pNodo> print = res;
      for (auto it3 = print.begin(); it3 != print.end(); it3++)
      {
        // cout<<(*it3)->m_Data<<" ";
        for (auto it4 = (*it3)->m_Sons.begin(); it4 != ((*it3)->m_Sons.end()); it4++)
        {
          archivo << "\t" << (*it3)->m_Data << " -> " << (*it4)->m_Data << "\n";
        }
      }

      archivo << "\n}";
      archivo.close();
      system("dot -Tjpg BinoHeap.dot -o BinoHeap.jpg");
    }
    else
    {
      return;
    }
  }
};
#endif // BINOMIALHEAP_H
