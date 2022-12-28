#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define INF 99999;

template<class V, class A>
class Edge;

template<class V,class A>
class Vertex {
  public:
    V                   m_Dato;
    int                 m_Costo;
    bool                m_Visit; 
    list<Edge<V,A> >    m_list_Edge;

  Vertex(V vertice) {
    m_Dato = vertice;
    m_Costo = INF;
    m_Visit = false;
  }

  bool operator==(const Vertex<V,A> & Ve)
  {
    return m_Dato == Ve.m_Dato;
  }
};

template<class V,class A>
class Edge {
  public:
  A                   m_Dato;
  Vertex<V,A> * m_pVertexDestino;
  Vertex<V,A> * m_pVertexOrigen;

  Edge(A a, Vertex<V,A> * p=0, Vertex<V,A> * q=0) {
    m_Dato = a;
    m_pVertexOrigen = p; // Se añade ptr al Vertex origen
    m_pVertexDestino = q;
  }

  bool operator==(const Edge<V,A> & Ar)
  {
    return m_Dato == Ar.m_Dato;
  }
};

template<class V, class A>
class compareEdges{
  public:
    int operator() (const Edge<V,A>& e1, const Edge<V,A>& e2){
      return e1.m_Dato > e2.m_Dato;
    }
};

template<class V,class A>
class Graph {
  typedef typename list< Vertex <V,A> >::iterator Iterator_Vertex; 
  typedef typename list< Edge <V,A> >::iterator Iterator_Edge;  
  public:
    list< Vertex <V,A> >   m_Graph;
  public:
    Graph(){};

    void Insert(V Vertice) {
      m_Graph.push_back(Vertex<V,A>(Vertice));
    };
    void Insert_Edge(V v1, V v2, A a)
    {
      Iterator_Vertex p = find_Vertex(v1);
      Iterator_Vertex q = find_Vertex(v2);
      if(p!= m_Graph.end() && q!= m_Graph.end())
      { 
        // ¿Qué ocurre si la arista y existe?
        Vertex<V,A>* pOrigen = &(*p);
        Vertex<V,A>* pDestino = &(*q); 
        p->m_list_Edge.push_back(Edge<V,A>(a,pOrigen,pDestino));
      }    
    }

    void Reset_Graph() {
      Iterator_Vertex it = m_Graph.begin();
      for(; it != m_Graph.end();it++)
      {
        it->m_Visit = false;
      }
    }

    void DFS(){
      Reset_Graph();
      stack< Iterator_Vertex > pila;
      pila.push( m_Graph.begin());
      Iterator_Vertex it = pila.top();
      it->m_Visit = true;
      while(!pila.empty()) {
        it = pila.top();
        cout<<it->m_Dato<<endl;
        //cout<<"size pila ="<<pila.size()<<endl;
        pila.pop();
        Iterator_Edge it_e = it->m_list_Edge.begin(); //Recorre todos los vertices adyacentes
        for(; it_e != it->m_list_Edge.end();++it_e) { 
          Iterator_Vertex it_d = find_Vertex(it_e->m_pVertexDestino->m_Dato); // retorna iterator vertex
          if((it_d != m_Graph.end()) && it_d->m_Visit==false){ // si el nodo aun no fue visitado ?
            it_d->m_Visit = true;
            pila.push(it_d);
          }
        }
      }
    }

    void BFS(){
      Reset_Graph();
      queue< Iterator_Vertex > cola;
      cola.push( m_Graph.begin());
      Iterator_Vertex it = cola.front();
      it->m_Visit = true;
      while(!cola.empty()) {
        it = cola.front();
        cout<<it->m_Dato<<endl;
        //cout<<"size cola ="<<cola.size()<<endl;
        cola.pop();
        Iterator_Edge it_e = it->m_list_Edge.begin(); //Recorre todos los vertices adyacentes
        for(; it_e != it->m_list_Edge.end();++it_e) { 
          Iterator_Vertex it_d = find_Vertex(it_e->m_pVertexDestino->m_Dato); // retorna iterator vertex
          if((it_d != m_Graph.end()) && it_d->m_Visit==false){ // si el nodo aun no fue visitado ?
            it_d->m_Visit = true;
            cola.push(it_d);
          }
        }
      }
    }

    Iterator_Vertex find_Vertex(V v)
    {
      return std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
    } 
      
   
    bool find_edge(V v, A a)
    {
      Iterator_Vertex  p = find_Vertex(v);
      Iterator_Edge    q = std::find(p->m_list_Edge.begin(), p->m_list_Edge.end(), Edge<V,A>(a));
      if(q!=p->m_list_Edge.end())
        return true;   
    }

    void Print() {
      typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
      Iterator_Vertex it = m_Graph.begin();
      for(; it != m_Graph.end();it++) {
        //cout<<"\n"<<it->m_Visit<<"\n";
        Iterator_Edge it_e = it->m_list_Edge.begin();
        for(; it_e != it->m_list_Edge.end();++it_e) 
        { 
          cout<<it->m_Dato<<" --- "<<it_e->m_Dato<<" --- "<<it_e->m_pVertexDestino->m_Dato<<endl;
        }
      }
    }

    // Ya implementadas
    // void Insert(V Vertice)
    // void Insert_Edge(V v1, V v2, A a)
    // Iterator_Vertex find_Vertex(V v)
    // bool find_edge(V v, A a)
    // void DFS
    // void BFS
};

template<class V, class A>
bool hayCiclo(map <V,V>& conectados, Edge<V,A>& e){
  return true;
}

// Graph<string,int> 
template<class V,class A>
void Prim( Graph<V,A> G ){
  G.Reset_Graph();
  vector < Edge<V,A> > MST; // Guardara las aristas que forman parte del MST
  vector < Edge<V,A> > vectorEdges; // Almacenara Todas las aristas del Grafo 
}

void test1() {
  Graph<string, int>  G;
  G.Insert("A");
  G.Insert("B");
  G.Insert("C");
  G.Insert("D");
  G.Insert("E");
  G.Insert("F");
  G.Insert("G");
  G.Insert("H");
  G.Insert("I");

  G.Insert_Edge("A","B",4);
  G.Insert_Edge("A","D",3);
  G.Insert_Edge("B","D",5);
  G.Insert_Edge("A","H",15);
  G.Insert_Edge("D","C",4);
  G.Insert_Edge("B","C",5);
  G.Insert_Edge("C","E",6);
  G.Insert_Edge("C","G",3);
  G.Insert_Edge("G","F",9);
  G.Insert_Edge("E","F",8);
  G.Insert_Edge("D","F",12);
  G.Insert_Edge("H","I",7);
  G.Insert_Edge("G","I",13);
  G.Insert_Edge("F","I",11);
  cout<<"----- Print -----\n";
  G.Print();
  /*cout<<"BFS\n"; G.BFS(); //correcto
  cout<<"-----------------\n";
  cout<<"DFS\n"; G.DFS();*/
  cout<<"\n----- Prim -----\n";
  Prim<string,int>(G);
  cout<<"\n----- Fin";
}

int main()
{
  test1();
  return 0;
}