#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define INF 99999;

template<class V, class A>
class Edge;

template<class V,class A>
class Vertex {
  public:
    V m_Dato;
    int m_Costo;
    bool m_Visit; 
    list< Edge<V,A> > m_list_Edge;

    Vertex(V vertice) {
      m_Dato = vertice;
      m_Costo = INF;
      m_Visit = false;
    }

    bool operator==(const Vertex<V,A> & Ve) {
      return m_Dato == Ve.m_Dato;
    }
};



template<class V,class A>
class Edge {
  public:
    A m_Weight;
    Vertex<V,A> * m_pVertex;

    Edge(A a, Vertex<V,A>  *q=0) {
      m_Weight = a;
      m_pVertex=q;
    }

    bool operator==(const Edge<V,A> & Ar) {
      return m_Weight == Ar.m_Weight;
    }
};

template<class V,class A>
class NDGraph {
  typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
  typedef typename   list<  Edge  <V,A>>::iterator Iterator_Edge;
  private:
    list< Vertex <V,A> > m_Graph; // Lista de vertices
  public:
    NDGraph(){};

    void Insert(V Vertice) {
      m_Graph.push_back(Vertex<V,A>(Vertice));
    };

    void Insert_Edge(V v1, V v2, A a) { // No dirigido
      Iterator_Vertex p = find_Vertex(v1);
      Iterator_Vertex q = find_Vertex(v2);
      if(p!= m_Graph.end() && q!= m_Graph.end()) { // si los vertices existen: insertar edge
        Vertex<V,A>* ptrV2 = &(*q);
        Vertex<V,A>* ptrV1 = &(*p);
        p->m_list_Edge.push_back(Edge<V,A>(a, ptrV2));
        q->m_list_Edge.push_back(Edge<V,A>(a, ptrV1));
      }      
    };

    void Reset_Graph() {
      //Iterator_Vertex it = m_Graph.begin();
      for(auto it = m_Graph.begin(); it != m_Graph.end(); it++) {
        it->m_Visit = false;
      }
    }

    Iterator_Vertex find_Vertex(V v) {
      return std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
    } 

    bool find_edge(V v, A a) {
      Iterator_Vertex p = find_Vertex(v);
      Iterator_Edge   q = std::find(p->m_list_Edge.begin(), p->m_list_Edge.end(), Edge<V,A>(a));
      if(q!=p->m_list_Edge.end())
        return true;   
    }

    list<int> Prim() {
      list<int> A;
      A.push_back(10);
      A.push_back(20);
      A.push_back(30);
      A.push_back(40);
      A.push_back(50);
      return A;
    }

    void Print() {
      Iterator_Vertex it = m_Graph.begin();
      for(; it != m_Graph.end(); it++) {
        //cout<<"\n"<<it->m_Visit<<"\n";
        Iterator_Edge    it_e = it->m_list_Edge.begin();
        for(; it_e != it->m_list_Edge.end(); it_e++) { 
          cout<<it->m_Dato<<" ---> "<<it_e->m_Weight<<" ---> "<<it_e->m_pVertex->m_Dato<<endl;
        }
      }
    }
};

int main(){
  NDGraph<string, int>  G;
  G.Insert("A");
  G.Insert("B");
  G.Insert("C");
  G.Insert("D");
  G.Insert("E");
  G.Insert("F");
  G.Insert("G");

  G.Insert_Edge("A","B",7);
  G.Insert_Edge("B","C",8);
  G.Insert_Edge("A","D",5);
  G.Insert_Edge("D","B",9);
  G.Insert_Edge("D","F",6);
  G.Insert_Edge("D","E",15);
  G.Insert_Edge("B","E",7);
  G.Insert_Edge("C","E",5);
  G.Insert_Edge("E","G",9);
  G.Insert_Edge("F","G",11);
  G.Insert_Edge("F","E",8);
  
  //G.Print();
  return 0;
}


