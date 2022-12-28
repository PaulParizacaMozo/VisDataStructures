#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

#define INF 99999;

template<class V, class A>
class EdgeG;

template<class V,class A>
class VertexG {
  public:
    V                   m_Dato;
    int                 m_Costo;
    bool                m_Visit;
    list<EdgeG<V,A> >    m_list_EdgeG;

  VertexG(V vertice) {
    m_Dato = vertice;
    m_Costo = INF;
    m_Visit = false;
  }

  bool operator==(const VertexG<V,A> & Ve)
  {
    return m_Dato == Ve.m_Dato;
  }
};

template<class V,class A>
class EdgeG {
  public:
  A                   m_Dato;
  VertexG<V,A> * m_pVertexGDestino;
  VertexG<V,A> * m_pVertexGOrigen;

  EdgeG(A a, VertexG<V,A> * p=0, VertexG<V,A> * q=0) {
    m_Dato = a;
    m_pVertexGOrigen = p; // Se añade ptr al VertexG origen
    m_pVertexGDestino = q;
  }

  bool operator==(const EdgeG<V,A> & Ar)
  {
    return m_Dato == Ar.m_Dato;
  }
};

template<class V, class A>
class compareEdgeGs{
  public:
    int operator() (const EdgeG<V,A>& e1, const EdgeG<V,A>& e2){
      return e1.m_Dato > e2.m_Dato;
    }
};

template<class V,class A>
class GraphX {
  typedef typename list< VertexG <V,A> >::iterator Iterator_VertexG;
  typedef typename list< EdgeG <V,A> >::iterator Iterator_EdgeG;
  public:
    list< VertexG <V,A> >   m_GraphX;
    int n_VertexG;
  public:
    GraphX(){n_VertexG = 0;};

    void Insert(V Vertice) {
      m_GraphX.push_back(VertexG<V,A>(Vertice));
      n_VertexG++;
    };
    void Insert_EdgeG(V v1, V v2, A a)
    {
      Iterator_VertexG p = find_VertexG(v1);
      Iterator_VertexG q = find_VertexG(v2);
      if(p!= m_GraphX.end() && q!= m_GraphX.end())
      {
        // ¿Qué ocurre si la arista y existe?
        VertexG<V,A>* pOrigen = &(*p);
        VertexG<V,A>* pDestino = &(*q);
        p->m_list_EdgeG.push_back(EdgeG<V,A>(a,pOrigen,pDestino));
      }
    }

    void Reset_GraphX() {
      Iterator_VertexG it = m_GraphX.begin();
      for(; it != m_GraphX.end();it++)
      {
        it->m_Visit = false;
      }
    }

    void DFS(){
      Reset_GraphX();
      stack< Iterator_VertexG > pila;
      pila.push( m_GraphX.begin());
      Iterator_VertexG it = pila.top();
      it->m_Visit = true;
      while(!pila.empty()) {
        it = pila.top();
        cout<<it->m_Dato<<endl;
        //cout<<"size pila ="<<pila.size()<<endl;
        pila.pop();
        Iterator_EdgeG it_e = it->m_list_EdgeG.begin(); //Recorre todos los vertices adyacentes
        for(; it_e != it->m_list_EdgeG.end();++it_e) {
          Iterator_VertexG it_d = find_VertexG(it_e->m_pVertexGDestino->m_Dato); // retorna iterator VertexG
          if((it_d != m_GraphX.end()) && it_d->m_Visit==false){ // si el nodo aun no fue visitado ?
            it_d->m_Visit = true;
            pila.push(it_d);
          }
        }
      }
    }

    void BFS(){
      Reset_GraphX();
      queue< Iterator_VertexG > cola;
      cola.push( m_GraphX.begin());
      Iterator_VertexG it = cola.front();
      it->m_Visit = true;
      while(!cola.empty()) {
        it = cola.front();
        cout<<it->m_Dato<<endl;
        //cout<<"size cola ="<<cola.size()<<endl;
        cola.pop();
        Iterator_EdgeG it_e = it->m_list_EdgeG.begin(); //Recorre todos los vertices adyacentes
        for(; it_e != it->m_list_EdgeG.end();++it_e) {
          Iterator_VertexG it_d = find_VertexG(it_e->m_pVertexGDestino->m_Dato); // retorna iterator VertexG
          if((it_d != m_GraphX.end()) && it_d->m_Visit==false){ // si el nodo aun no fue visitado ?
            it_d->m_Visit = true;
            cola.push(it_d);
          }
        }
      }
    }

    Iterator_VertexG find_VertexG(V v)
    {
      return std::find(m_GraphX.begin(), m_GraphX.end(), VertexG<V,A>(v));
    }


    bool find_EdgeG(V v, A a)
    {
      Iterator_VertexG  p = find_VertexG(v);
      Iterator_EdgeG    q = std::find(p->m_list_EdgeG.begin(), p->m_list_EdgeG.end(), EdgeG<V,A>(a));
      if(q!=p->m_list_EdgeG.end())
        return true;
    }

    void Print() {
      typedef typename   list< VertexG <V,A>>::iterator Iterator_VertexG;
      Iterator_VertexG it = m_GraphX.begin();
      for(; it != m_GraphX.end();it++) {
        //cout<<"\n"<<it->m_Visit<<"\n";
        Iterator_EdgeG it_e = it->m_list_EdgeG.begin();
        for(; it_e != it->m_list_EdgeG.end();++it_e)
        {
          cout<<it->m_Dato<<" --- "<<it_e->m_Dato<<" --- "<<it_e->m_pVertexGDestino->m_Dato<<endl;
        }
      }
    }
    void Draw() {
      string nombreArchivo = "graph.dot";
      ofstream archivo;
      archivo.open(nombreArchivo.c_str(), fstream::out);
      archivo << "digraph grafo {node [style=filled];\n";

      typedef typename   list< VertexG <V,A>>::iterator Iterator_Vertex;
      Iterator_Vertex it = m_GraphX.begin();
      for(; it != m_GraphX.end();it++) {
        archivo<<it->m_Dato<<";";
        //cout<<"\n"<<it->m_Visit<<"\n";
        Iterator_EdgeG it_e = it->m_list_EdgeG.begin();
        for(; it_e != it->m_list_EdgeG.end();++it_e)
        {
          archivo<<it->m_Dato<<" -> "<<it_e->m_pVertexGDestino->m_Dato<<"[label = "<<it_e->m_Dato<<"];\n";
        }
      }
      archivo<<"}";
      archivo.close();

      system("dot -Tjpg graph.dot -o graph.jpg");
    }

  VertexG<V,A> * find_VertexGPtr(V v){ //busca y retorna la direccion donde se encuentra el vertice buscado.
    //Iterator_VertexG  it = find(m_GraphX.begin(), m_GraphX.end(), v);
    Iterator_VertexG  it = find(m_GraphX.begin(), m_GraphX.end(), VertexG<V,A>(v));
    if (it == m_GraphX.end()) {
      return nullptr;
    }
    return &(*it);
  }
  A valor_EdgeG(V v1, V v2){
    VertexG<V,A> * p = find_VertexGPtr(v1);
    Iterator_EdgeG it = p->m_list_EdgeG.begin();
    for(; it != p->m_list_EdgeG.end();it++){ //recorre la lista de aristas del vertice hasta encontrar uan con su valor
      if(it->m_pVertexGDestino == find_VertexGPtr(v2))
        return it->m_Dato;
    }
    return INT16_MAX;
  }


};

template<class V, class A>
V find_set(map<V,V>& link,V v){
  if(v==link.at(v))
    return v;
  return find_set<V,A> (link,link.at(v));
  //return link.at(v) = find_set<V,A> (link,link.at(v));
}

template<class V, class A>
void union_sets(map<V,V>& link, V v1,V v2){
  v1 = find_set<V,A>(link,v1);
  v2 = find_set<V,A>(link,v2);
  link.at(v2) = v1;
}

template<class V, class A>
bool hayCiclo(map <V,V>& conectados, EdgeG<V,A>& e){
  // Buscamos los padres de los vertices: Si son diferentes significa que son de dos subarboles distintos y hay q unirlos
  if(find_set<V,A>(conectados,e.m_pVertexGOrigen->m_Dato) != find_set<V,A>(conectados,e.m_pVertexGDestino->m_Dato)){
    union_sets<V,A>(conectados,e.m_pVertexGOrigen->m_Dato,e.m_pVertexGDestino->m_Dato);
    return false;
  }
  return true;
}

// GraphX<string,int>
template<class V,class A>
void Kruskal( GraphX<V,A> G ){
  G.Reset_GraphX();
  vector < EdgeG<V,A> > MST; // Guardara las aristas que forman parte del MST
  vector < EdgeG<V,A> > vectorEdgeGs; // Almacenara Todas las aristas del Grafo
  map < V, V > fathers; // A cada Vertice le asigna otro vertice que representa la raiz del subrbol al cual pertenece el vertice

  for (auto it=G.m_GraphX.begin(); it!= G.m_GraphX.end(); it++) {
    fathers.insert( pair<V,V>(it->m_Dato, it->m_Dato) ); // Inicializamos los fathers de los nodos A->A, B->B, C->C
  }


  for(auto it = G.m_GraphX.begin(); it != G.m_GraphX.end(); it++) {
    cout<<"aqui";
    for(auto it_e = it->m_list_EdgeG.begin(); it_e != it->m_list_EdgeG.end(); it_e++) {

      cout<<it_e->m_pVertexGOrigen<<" -- "<<it_e->m_pVertexGDestino<<endl;
      vectorEdgeGs.push_back(*it_e); // Inserta la arista al vector de Aristas
      //cout<<it->m_Dato<<" ---> "<<it_e->m_Dato<<"---->"<<it_e->m_pVertexG->m_Dato<<endl;
    }
  }
  // Min-Heap de los pesos de las aristas
  priority_queue< EdgeG<V,A>, vector<EdgeG<V,A>>, compareEdgeGs<V,A> > pq_minheap;
  for (auto it=vectorEdgeGs.begin(); it!=vectorEdgeGs.end(); it++) { // Se inserta las aristas al min heap
    pq_minheap.push(*it);
  }
  EdgeG<V,A> e = pq_minheap.top();
  while (MST.size()+1 < G.m_GraphX.size() || !pq_minheap.empty()){
    e = pq_minheap.top();
    pq_minheap.pop();
    if(!hayCiclo(fathers,e)){ // Si la nueva arista no forma un ciclo con las demas, insertamos al MST
      MST.push_back(e);
    }
  }
   cout<<"\n----- Fathers -----"<<endl;
  for (auto it=fathers.begin(); it!= fathers.end(); it++) {
    cout<<it->first<<" -> "<<it->second<<"\n";
  }
  for (auto it=MST.begin(); it!=MST.end(); it++){
    cout<<"["<<it->m_pVertexGOrigen->m_Dato<<" -- "<<it->m_Dato<<" -- "<<it->m_pVertexGDestino->m_Dato<<"]"<<endl;
  }

  //----------------draw Kruskal
  string nombreArchivo = "graph.dot";
  ofstream archivo;
  archivo.open(nombreArchivo.c_str(), fstream::out);
  archivo << "graph world {\nrankdir = LR;\nsubgraph cluster_0{";
  archivo << "label = \"GRAFO - MST KRUSKAL\";node [style=filled];";

  auto ite = G.m_GraphX.begin();
  for(; ite != G.m_GraphX.end();ite++) {
    //cout<<"\n"<<it->m_Visit<<"\n";
    auto it_e = ite->m_list_EdgeG.begin();
    for(; it_e != ite->m_list_EdgeG.end();++it_e)
    {

    archivo<<ite->m_Dato<<" -- "<<it_e->m_pVertexGDestino->m_Dato<<"[label = "<<it_e->m_Dato;
    for (auto it=MST.begin(); it!=MST.end(); it++){
      if(it->m_pVertexGOrigen->m_Dato == ite->m_Dato && it_e->m_pVertexGDestino->m_Dato == it->m_pVertexGDestino->m_Dato && it_e->m_Dato == it->m_Dato){
        archivo<<",color = blue";
        break;
      }

    }
    archivo<<"];\n";
    }
  }
  //for (auto it=MST.begin(); it!=MST.end(); it++){
  //  archivo<<it->m_pVertexGOrigen->m_Dato<<" -> "<<it->m_pVertexGDestino->m_Dato<<"[label = "<<it->m_Dato<<",color = blue];\n";
  //}

  archivo<<"}}";
  archivo.close();
  system("dot -Tjpg graph.dot -o graph.jpg");
}

template<class V,class A>
void Prim(GraphX<V,A> G,V inicio){

  G.Reset_GraphX();
  vector < EdgeG<V,A> > MST; // Guardara las aristas que forman parte del MST
  vector < EdgeG<V,A> > MSTfinal; // Guardara las aristas que forman parte del MST
  //Parte de la opcion 1
  vector < EdgeG<V,A> > vectorEdgeGs; // Almacenara Todas las aristas del Grafo

  cout<<"aqui";
  for(auto it = G.m_GraphX.begin(); it != G.m_GraphX.end(); it++) {
    for(auto it_e = it->m_list_EdgeG.begin(); it_e != it->m_list_EdgeG.end(); it_e++) {
      cout<<it_e->m_pVertexGOrigen->m_Dato<<" -- "<<it_e->m_pVertexGDestino->m_Dato<<endl;
      vectorEdgeGs.push_back(*it_e);// Inserta la arista al vector de Aristas
      EdgeG<V,A> aux2(it_e->m_Dato,it_e->m_pVertexGDestino,it_e->m_pVertexGOrigen);
      vectorEdgeGs.push_back(aux2);
    }
  }

  //--------------
  map < V, bool > visitados; // A cada Vertice le asigna otro vertice que representa la raiz del subrbol al cual pertenece el vertice

  for (auto it=G.m_GraphX.begin(); it!= G.m_GraphX.end(); it++) {
    visitados.insert( pair<V,bool>(it->m_Dato, false) ); // Inicializamos los fathers de los nodos A->A, B->B, C->C
  }

  //--------------
    priority_queue< EdgeG<V,A>, vector<EdgeG<V,A>>, compareEdgeGs<V,A> > pq_minheap;
    VertexG<V,A> * vert = G.find_VertexGPtr(inicio);
    V ori = vert->m_Dato;//opcion 1
    EdgeG<V,A> ini(0,vert,vert);
    pq_minheap.push(ini);

    while (!pq_minheap.empty()) {
      EdgeG<V,A> aux = pq_minheap.top();
      cout<<"si entro"<<endl;

      pq_minheap.pop();
      vert = aux.m_pVertexGDestino;
      auto it = visitados.find(vert->m_Dato);
      if(it->second == true){
        continue;
      }


      cout<<aux.m_pVertexGOrigen->m_Dato<<" -- "<<aux.m_Dato<<" -- "<<aux.m_pVertexGDestino->m_Dato<<endl;
      MST.push_back(aux);
      it->second = true;

      //opcion 1
      for(auto ite = vectorEdgeGs.begin(); ite !=vectorEdgeGs.end(); ite++){
        if(vert->m_Dato == ite->m_pVertexGOrigen->m_Dato){
          //cout<<"gaa"<<endl;
          //cout<<ite->m_pVertexGOrigen<<" -- "<<ite->m_pVertexGDestino<<endl;
          pq_minheap.push(*ite); // Inserta la arista al vector de Aristas
        }
      }

      //opcion 2
      //for(auto it_e = vert->m_list_EdgeG.begin(); it_e != vert->m_list_EdgeG.end(); it_e++) {
      //  //cout<<it_e->m_pVertexGOrigen->m_Dato<<" -- "<<it_e->m_Dato<<" -- "<<it_e->m_pVertexGDestino->m_Dato<<endl;
      //  EdgeG<V,A> aux2(it_e->m_Dato,it_e->m_pVertexGDestino,it_e->m_pVertexGOrigen);
      //  pq_minheap.push(aux2);
      //  pq_minheap.push(*it_e);
      //}
      cout<<"-----------------------------------------------"<<endl;
    }

  for (auto it=MST.begin(); it!=MST.end(); it++){
    EdgeG<V,A> auxiliar(it->m_Dato,it->m_pVertexGDestino, it->m_pVertexGOrigen);
    MSTfinal.push_back(auxiliar);
    cout<<"["<<it->m_pVertexGOrigen->m_Dato<<" -- "<<it->m_Dato<<" -- "<<it->m_pVertexGDestino->m_Dato<<"]"<<endl;
  }

  //----------------draw Kruskal
  string nombreArchivo = "graph.dot";
  ofstream archivo;
  archivo.open(nombreArchivo.c_str(), fstream::out);
  archivo << "graph world {\nrankdir = LR;\nsubgraph cluster_0{";
  archivo << "label = \"GRAFO - MST PRIM\";node [style=filled];";

  auto ite = G.m_GraphX.begin();
  for(; ite != G.m_GraphX.end();ite++) {
    //cout<<"\n"<<it->m_Visit<<"\n";
    auto it_e = ite->m_list_EdgeG.begin();
    for(; it_e != ite->m_list_EdgeG.end();++it_e)
    {
    archivo<<ite->m_Dato<<" -- "<<it_e->m_pVertexGDestino->m_Dato<<"[label = "<<it_e->m_Dato;
    for (auto it=MST.begin(); it!=MST.end(); it++){
      //if(it->m_pVertexGOrigen->m_Dato == it->m_pVertexGDestino->m_Dato){
      //  continue;
      //}
      if(it->m_pVertexGOrigen->m_Dato == ite->m_Dato && it_e->m_pVertexGDestino->m_Dato == it->m_pVertexGDestino->m_Dato && it_e->m_Dato == it->m_Dato){
        cout<<"si inserta"<<endl;
        archivo<<",color = blue";
        break;
      }
    }
    for (auto it=MSTfinal.begin(); it!=MSTfinal.end(); it++){
      //if(it->m_pVertexGOrigen->m_Dato == it->m_pVertexGDestino->m_Dato){
      //  continue;
      //}
      if(it->m_pVertexGOrigen->m_Dato == ite->m_Dato && it_e->m_pVertexGDestino->m_Dato == it->m_pVertexGDestino->m_Dato && it_e->m_Dato == it->m_Dato){
        cout<<"si inserta"<<endl;
        archivo<<",color = blue";
        break;
      }
    }
    archivo<<"];\n";
    }
  }
  //for (auto it=MST.begin(); it!=MST.end(); it++){
  //  archivo<<it->m_pVertexGOrigen->m_Dato<<" -> "<<it->m_pVertexGDestino->m_Dato<<"[label = "<<it->m_Dato<<",color = blue];\n";
  //}

  archivo<<"}}";
  archivo.close();
  system("dot -Tjpg graph.dot -o graph.jpg");
}

/*



void test1() {
  GraphX<string, int>  G;
  G.Insert("A");
  G.Insert("B");
  G.Insert("C");
  G.Insert("D");
  G.Insert("E");
  G.Insert("F");
  G.Insert("G");
  G.Insert("H");
  G.Insert("I");

  G.Insert_EdgeG("A","B",4);
  G.Insert_EdgeG("A","D",3);
  G.Insert_EdgeG("B","D",5);
  G.Insert_EdgeG("A","H",15);
  G.Insert_EdgeG("D","C",4);
  G.Insert_EdgeG("B","C",5);
  G.Insert_EdgeG("C","E",6);
  G.Insert_EdgeG("C","G",3);
  G.Insert_EdgeG("G","F",9);
  G.Insert_EdgeG("E","F",8);
  G.Insert_EdgeG("D","F",12);
  G.Insert_EdgeG("H","I",7);
  G.Insert_EdgeG("G","I",13);
  G.Insert_EdgeG("F","I",11);
  cout<<"----- Print -----\n";
  G.Print();
  //cout<<"BFS\n"; G.BFS(); //correcto
  //cout<<"-----------------\n";
  //cout<<"DFS\n"; G.DFS();
  //cout<<"\n----- Kruskal -----\n";

  //Kruskal<string,int>(G);
  //G.dijkstra("D");
  cout<<"\n----- Fin";
  Prim<string,int>(G,"I");
  //G.Draw();
}

int main()
{
  test1();
  //int option;
  //bool salir = false;
  //string aux;
  //GraphX<string, int>  G;
  //string vertice;
  //int valorArista;

  //while(salir == false){
  //  cout<<"Menu"<<endl;
  //  cout<<" 1.- insertar vertice\n 2.- insertar arista\n 3.-Dijkstra\n 4.-Kruskal\n";
  //  cin>>option;

  //  switch (option) {
  //    case 1:
  //      cout<<"Ingrese el valor del vertice ->";
  //      cin>>vertice;
  //      G.Insert(vertice);
  //      break;
  //    case 2:{
  //      string origen, destino;
  //      cout<<"Ingrese el vertice origen  ->";
  //      cin>>origen;
  //      cout<<"Ingrese el vertice destino  ->";
  //      cin>>destino;
  //      cout<<"Ingrese el valor de la arista  ->";
  //      cin>>valorArista;
  //      G.Insert_EdgeG(origen,destino,valorArista);
  //      break;
  //    }
  //    case 3:
  //      cout<<"Ingrese el vertice inicial ->";
  //      cin>>aux;
  //      G.dijkstra(aux);
  //      break;

  //    case 10:
  //      G.Draw();
  //      break;

  //    case 0:
  //      salir = true;
  //      break;
  //  }
  //}

  //
  //return 0;
}
*/
#endif // GRAPH_H
