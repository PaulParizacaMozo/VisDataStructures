#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#define INF 99999;

template<class V, class A>
class Edge;

template<class V,class A>
class Vertex
{
    public:
     V                   m_Dato;
     int                 m_Costo;
     bool                m_Visit; 
     list<Edge<V,A> >    m_list_Edge;
  
    Vertex(V vertice)
    {
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
class Edge
{
    public:
        A                   m_Dato;
        Vertex<V,A>  *      m_pVertex;

        Edge(A a, Vertex<V,A>  *q=0)
        {
            m_Dato = a;
            m_pVertex=q;
        }


    bool operator==(const Edge<V,A> & Ar)
    {
        return m_Dato == Ar.m_Dato;
    }

};



template<class V,class A>
class Graph
{
   typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
   typedef typename   list<  Edge  <V,A>>::iterator Iterator_Edge;  
   private:
      list< Vertex <V,A> >   m_Graph;
   public:
   Graph(){};

   void Insert(V Vertice)
   {
          m_Graph.push_back(Vertex<V,A>(Vertice));
   };
   void Insert_Edge(V v1, V v2, A a)
   {
         Iterator_Vertex p = find_Vertex(v1);
         Iterator_Vertex q = find_Vertex(v2);
         if(p!= m_Graph.end() && q!= m_Graph.end())
         { 
            // ¿Qué ocurre si la arista y existe?
            Vertex<V,A>* pDestino = &(*q); 
            p->m_list_Edge.push_back(Edge<V,A>(a, pDestino));
         }
          
   };

   void Reset_Graph()
   {
     Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          it->m_Visit = false;
       }
   }

   /*void DFS()
   {
       stack< Iterator_Vertex > pila;
       pila.push(m_Graph.begin());
       while (!pila.empty())
       {
           Iterator_Vertex it = pila.top();
           pila.pop();
           it->m_Visit=true;
           cout<<it->m_Dato<<endl;
           Iterator_Edge it_e = it->m_list_Edge.begin();
           for(; it_e != it->m_list_Edge.end();++it_e)
           {
               if(it_e->m_pVertex->m_Visit==false)
               {
                Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato);
                if(it_d != m_Graph.end())
                  pila.push(it_d);
               }
           }
       }
   }*/
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
          Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato); // retorna iterator vertex
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
          Iterator_Vertex it_d = find_Vertex(it_e->m_pVertex->m_Dato); // retorna iterator vertex
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
   void Print()
   {
       typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
       Iterator_Vertex it = m_Graph.begin();
       for(; it != m_Graph.end();it++)
       {
          cout<<"\n"<<it->m_Visit<<"\n";
          Iterator_Edge    it_e = it->m_list_Edge.begin();
          for(; it_e != it->m_list_Edge.end();++it_e) 
           { 
              cout<<it->m_Dato<<" ---> "<<it_e->m_Dato<<"---->"<<it_e->m_pVertex->m_Dato<<endl;
           }
          
       }

   };

};


void test1()
{
   Graph<string, int>  G;
   G.Insert("Arequipa");
   G.Insert("Lima");
   G.Insert("Cusco");
   G.Insert("Puno");
   G.Insert("Tacna");
   G.Insert("Ica");

   G.Insert_Edge("Arequipa","Cusco",100);
   G.Insert_Edge("Arequipa","Puno",160);
   G.Insert_Edge("Arequipa","Lima",1500);
   G.Insert_Edge("Puno","Ica",1500);
   G.Insert_Edge("Puno","Tacna",1070);
   G.Insert_Edge("Cusco","Puno",400);
   G.Insert_Edge("Cusco","Tacna",600);
   G.Insert_Edge("Tacna","Lima",600);
   G.Insert_Edge("Tacna","Arequipa",600);
   G.Insert_Edge("Lima","Puno",600);
   G.Insert_Edge("Ica","Arequipa",600);

   G.Print();
   cout<<"BFS\n"; G.BFS(); //correcto
   cout<<"-----------------\n";
   cout<<"DFS\n"; G.DFS();
        
}

int main()
{
  test1();
  return 0;
}