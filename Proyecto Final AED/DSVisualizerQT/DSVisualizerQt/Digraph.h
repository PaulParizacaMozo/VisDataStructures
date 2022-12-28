#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int INF = INT16_MAX;

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
  A m_Dato;
  Vertex<V,A> * m_pVertexDestino;
  Vertex<V,A> * m_pVertexOrigen;

  Edge(A a, Vertex<V,A> * p=0, Vertex<V,A> * q=0) {
    m_Dato = a;
    //m_pVertexOrigen = p; // Se añade ptr al Vertex origen
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
    list < Vertex <V,A> > m_Graph;
    map < V, map <V,A> > m_MatrizAdyacencia;
    map < V, map <V,A> > m_MatrizCaminos; // Guarda 0 y 1 dependiendo si hay un camino
    map < V, map <V,A> > m_MCaminosEtiqu;
    int n_Vertex;
  public:

    Graph(){n_Vertex = 0;};


    void Insert(V Vertice) {
      m_Graph.push_back(Vertex<V,A>(Vertice));
      n_Vertex++;
      //m_MatrizAdyacencia.clear();
      for(auto it=m_Graph.begin();it!=m_Graph.end();it++){
        for(auto it2=m_Graph.begin();it2!=m_Graph.end();it2++){
          m_MatrizAdyacencia[it->m_Dato][it2->m_Dato] = INF;
          m_MatrizCaminos[it->m_Dato][it2->m_Dato] = 0;
        }
      }
    };

    void printMatrizAdyacencia(){
      for(auto it_i = m_MatrizAdyacencia.begin(); it_i != m_MatrizAdyacencia.end(); it_i++) {
        //cout<< it_i->first<<"\n";
        for(auto it_j=it_i->second.begin(); it_j!=it_i->second.end(); it_j++){
          if(it_j->second==INF) cout<<"INF\t";
          else cout<<it_j->second<<"\t";
          //cout<< it_j->first << " "<< it_j->second << endl;
        }
        cout<<"\n";
      }
    }

    void Warshal(){ // O(n3)
      V i,j,k;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          for(auto it_k=m_Graph.begin(); it_k!=m_Graph.end(); it_k++){
            i = it_i->m_Dato;
            j = it_j->m_Dato;
            k = it_k->m_Dato;
            if(m_MatrizCaminos[i][j] || (m_MatrizCaminos[i][k] && m_MatrizCaminos[k][j])){
              m_MatrizCaminos[i][j] = 1;
            }
          }
        }
      }
    }

    void PrintWarshall(){
      V i,j;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          i = it_i->m_Dato;
          j = it_j->m_Dato;
          cout<<m_MatrizCaminos[i][j]<<"\t";
        }
        cout<<"\n";
      }
    }


    void DrawWarshall(){
      string nombreArchivo = "archivoFloyd_Warshall.dot";
      ofstream archivo;
      archivo.open(nombreArchivo.c_str(), fstream::out);
      archivo << "digraph G {\n  fontname=\"Helvetica,Arial,sans-serif\" \nnode [fontname=\"Helvetica,Arial,sans-serif\"] \nedge [fontname=\"Helvetica,Arial,sans-serif\"]";
      archivo<<"a0 [shape=none label=<\n<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"#30110d\" gradientangle=\"315\">\n";
      V i,j;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        archivo<<"\n<TR>\n";
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          i = it_i->m_Dato;
          j = it_j->m_Dato;
          archivo<<"\t<TD bgcolor=\"#f2bc94\">"<<m_MatrizCaminos[i][j]<<"</TD>\n";
        }
        archivo<<"</TR>\n";
      }

      archivo<<"</TABLE>>];}";
      archivo.close();

      system("dot -Tjpg archivoFloyd_Warshall.dot -o archivoFloyd_Warshall.jpg");


    }



    void Floyd(){
      m_MCaminosEtiqu = m_MatrizAdyacencia;
      V i,j,k;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          for(auto it_k=m_Graph.begin(); it_k!=m_Graph.end(); it_k++){
            i = it_i->m_Dato;
            j = it_j->m_Dato;
            k = it_k->m_Dato;
            if(m_MCaminosEtiqu[i][j] > (m_MCaminosEtiqu[i][k] + m_MCaminosEtiqu[k][j])){
              m_MCaminosEtiqu[i][j] = m_MCaminosEtiqu[i][k] + m_MCaminosEtiqu[k][j];
            }
          }
        }
      }
    }

    void PrintFloyd(){
      V i,j;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          i = it_i->m_Dato;
          j = it_j->m_Dato;
          if(m_MCaminosEtiqu[i][j]==INF) cout<<"INF\t";
          else cout<<m_MCaminosEtiqu[i][j]<<"\t";
        }
        cout<<"\n";
      }
    }

    void DrawFloyd(){
      string nombreArchivo = "archivoFloyd_Warshall.dot";
      ofstream archivo;
      archivo.open(nombreArchivo.c_str(), fstream::out);
      archivo << "digraph G {\n  fontname=\"Helvetica,Arial,sans-serif\" \nnode [fontname=\"Helvetica,Arial,sans-serif\"] \nedge [fontname=\"Helvetica,Arial,sans-serif\"]";
      archivo<<"a0 [shape=none label=<\n<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"#30110d\" gradientangle=\"315\">\n";
      V i,j;
      for(auto it_i=m_Graph.begin(); it_i!=m_Graph.end(); it_i++){
        archivo<<"\n<TR>\n";
        for(auto it_j=m_Graph.begin(); it_j!=m_Graph.end(); it_j++){
          i = it_i->m_Dato;
          j = it_j->m_Dato;
          if(m_MCaminosEtiqu[i][j]==INF) archivo<<"\t<TD bgcolor=\"#f2bc94\">"<<"INF"<<"</TD>\n";
          else archivo<<"\t<TD bgcolor=\"#f2bc94\">"<<m_MCaminosEtiqu[i][j]<<"</TD>\n";
        }
        archivo<<"</TR>\n";
      }

      archivo<<"</TABLE>>];}";
      archivo.close();

      system("dot -Tjpg archivoFloyd_Warshall.dot -o archivoFloyd_Warshall.jpg");
    }

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
        m_MatrizAdyacencia[v1][v2] = a;
        m_MatrizCaminos[v1][v2] = 1;
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
  Vertex<V,A> * find_VertexPtr(V v){ //busca y retorna la direccion donde se encuentra el vertice buscado.
    //Iterator_Vertex  it = find(m_Graph.begin(), m_Graph.end(), v);
    Iterator_Vertex  it = find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
    if (it == m_Graph.end()) {
      return nullptr;
    }
    return &(*it);
  }

  A valor_edge(V v1, V v2){
    Vertex<V,A> * p = find_VertexPtr(v1);
    Iterator_Edge it = p->m_list_Edge.begin();
    for(; it != p->m_list_Edge.end();it++){ //recorre la lista de aristas del vertice hasta encontrar uan con su valor
      if(it->m_pVertexDestino == find_VertexPtr(v2))
        return it->m_Dato;
    }
    return INT16_MAX;
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

    void Draw() {
      ofstream limpiar, archivo;
      limpiar.open("archivoFloyd_Warshall.dot",ios::out); limpiar<<""; limpiar.close();
      archivo.open("archivoFloyd_Warshall.dot",ios::app);
      if(archivo.fail()){  cout<<"No se puede abrir archivo"<<endl; exit(1); }
      archivo << "digraph G {node [style=filled];\n";

      typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex;
      Iterator_Vertex it = m_Graph.begin();
      for(; it != m_Graph.end();it++) {
        archivo<<it->m_Dato<<";";
        //cout<<"\n"<<it->m_Visit<<"\n";
        Iterator_Edge it_e = it->m_list_Edge.begin();
        for(; it_e != it->m_list_Edge.end();++it_e)
        {
          archivo<<it->m_Dato<<" -> "<<it_e->m_pVertexDestino->m_Dato<<"[label = "<<it_e->m_Dato<<"];\n";
        }
      }

      archivo<<"}";//cerrar digraph
      archivo.close();
      system("dot -Tjpg archivoFloyd_Warshall.dot -o archivoFloyd_Warshall.jpg");
    }

  bool hayCeros(vector<int> &vec){
    typedef typename vector<int>::iterator it;
    it p = std::find (vec.begin(), vec.end(),0);
    return (p!=vec.end());
  }

  int getMenor(vector<int> &c, vector<int> &d){
    int V_min = INT16_MAX;
    int indice = INT16_MAX;
    for(int i=0; i<n_Vertex; i++){
      if(c[i] == 0){
        if(d[i] <= V_min){
          V_min = d[i];
          indice = i;
       }
      }
    }
    return indice;
  }

  int buscarIndice(vector<V> datos, V origen){
    for(int i=0; i<n_Vertex; i++){
      if(datos[i] == origen)
        return i;
    }
    return INT16_MAX;
  }
  V datoSegunIndice(vector<V> datos, int ind){
    for(int i=0; i<n_Vertex; i++){
      if(i == ind)
        return datos[i];
    }
    return 0;
  }

  //dijkstra
  vector<int> dijkstra (V origen){
    vector<V> datos(n_Vertex);
    vector<int> c(n_Vertex);
    vector<int> d(n_Vertex);

    Iterator_Vertex it = m_Graph.begin();
    int dato=0;
    for(; it != m_Graph.end();it++){ //recorre todos los vertices
      datos[dato] = it->m_Dato;
      dato++;
    }

    int inicial = buscarIndice(datos,origen);
    c[inicial] = 1;

    for(int i=0; i<n_Vertex; i++){
      d[i] = valor_edge(origen,datoSegunIndice(datos,i));
    }

    if(hayCeros(c)){
      cout<<"gaaa"<<endl;
    }
    while (hayCeros(c)) {
      int s = getMenor(c,d);
      c[s] = 1;
      for(int i=0; i<n_Vertex; i++){
        if(c[i] == 0){
          d[i] = min(d[i], d[s] + valor_edge(datoSegunIndice(datos,s),datoSegunIndice(datos,i)));
        }
      }

      cout<<"\nC -> ";
      for(int i=0; i<n_Vertex; i++){
        cout<<c[i]<<" - ";
      }
      cout<<"\nD -> ";
      for(int i=0; i<n_Vertex; i++){
        cout<<d[i]<<" - ";
      }
    }

    string nombreArchivo = "archivoFloyd_Warshall.dot";
    ofstream archivo;
    archivo.open(nombreArchivo.c_str(), fstream::out);
    archivo << "digraph grafo {\nsubgraph cluster_0{rankdir = LR;\n";
    archivo << "label = GRAFO;node [style=filled];";

    Iterator_Vertex ite = m_Graph.begin();
    for(; ite != m_Graph.end();ite++) {
      //cout<<"\n"<<it->m_Visit<<"\n";
      Iterator_Edge it_e = ite->m_list_Edge.begin();
      for(; it_e != ite->m_list_Edge.end();++it_e)
      {
        archivo<<ite->m_Dato<<" -> "<<it_e->m_pVertexDestino->m_Dato<<"[label = "<<it_e->m_Dato<<"];\n";
      }
    }
    archivo<<"}";

    archivo<<"subgraph cluster_1{ rankdir = LR;node [style=filled];\nlabel = \"Dijkstra\"\n";
    for(int i=0; i<n_Vertex; i++){
      archivo<<i<<"[label = "<<datoSegunIndice(datos,i)<<"];";
    }
    for(int i=0; i<n_Vertex; i++){
      if(d[i]< INT16_MAX){
       archivo<<0<<"->"<<i<<"[label="<<d[i]<<"];";
      }
      else{
        archivo<<0<<"->"<<i<<"[label=INF];";
      }
    }
    archivo<<"}\n";

    //DIJSKTRA


    archivo<<"}";
    archivo.close();

    system("dot -Tjpg archivoFloyd_Warshall.dot -o archivoFloyd_Warshall.jpg");
    return d;
  }
};

/*
int main(){
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

  G.Print();
  G.printMatrizAdyacencia(); cout<<endl;
  G.Warshal();
  G.PrintWarshall(); cout<<endl;
  //G.DrawWarshall();
  G.Floyd();
  G.PrintFloyd();
  //G.DrawFloyd();
  G.dijkstra("A");

  int op, dato, pesoA;
  string vert, vertF;
  while(1){
    cout<<"Ingrese Opcion: "<<endl;
    cout<<"[1] Insertar Vertice \t[2] Insertar Arista\t[3] Print\t[4] Warshall\t[5] Floyd\n";
    cout<<"[6] Draw\t\t[7] Salir"<<endl;
    cin>>op;
    if ( op==1 ) {
      cout<<"Ingrese Vertice => "; cin>>vert;
      G.Insert(vert);
      //A.Print(); cout<<endl;
    } else if( op==2 ){
      cout<<"Ingrese Vertice Inicio => "; cin>>vert;
      cout<<"Ingrese Vertice LLegada => "; cin>>vertF;
      cout<<"Ingrese Peso de Arista => "; cin>>pesoA;
      G.Insert_Edge(vert,vertF,pesoA);
      //A.Print(); cout<<endl;
    } else if( op==3 ){
      G.Print();
      cout<<endl;
    } else if( op==4 ){
      G.Warshal();
      G.PrintWarshall();
      cout<<endl;
    } else if( op==5 ){
      G.Floyd();
      G.PrintFloyd();
      cout<<endl;
    } else if( op==6 ){
      G.Draw();
      cout<<endl;
    } else break;
  }

  return 0;
}
*/
#endif // DIGRAPH_H
