#include <iostream>
#include <fstream>
#include <queue>
#include <list>
using namespace std;

template <class T>
class NodoE {
public:
  T m_Dato;
  int m_row;
  int m_col;
  NodoE<T> *m_pNextRow;
  NodoE<T> *m_pNextCol;

  NodoE(T d, int row, int col){
    m_Dato = d;
    m_row = row;
    m_col = col;
    m_pNextRow = m_pNextCol = nullptr;
  }
};

template <class T, int row_size = 5, int col_size = 5>
class Matrix {
private:
  NodoE<T> *m_Row[row_size];
  NodoE<T> *m_Col[col_size];

public:
  Matrix() {
    for (int i = 0; i < row_size; i++)
        m_Row[i] = nullptr;
    for (int j = 0; j < col_size; j++)
        m_Col[j] = nullptr;
  }

  void Insert(T d, int row, int col){
    NodoE<T> ** p, ** q;
    bool r = find_row(row, col, p);
    bool c = find_col(row, col, q);
    if(!r || !c) {
      NodoE<T>* pNew = new NodoE<T>(d,row,col);
      pNew->m_pNextRow = *p;
      (*p) = pNew;
      pNew->m_pNextCol = *q;
      (*q) = pNew;
    }
    (*p)->m_Dato = d;
  }

  bool find_row(int row, int col, NodoE<T>**& p) {
    p = &m_Col[col];
    while(*p) {
      if((*p)->m_row == row)
        return true;
      if((*p)->m_row > row)
        return false;
      p = &((*p)->m_pNextRow);
    }
    return false;
  }

  bool find_col(int row, int col, NodoE<T>**& q){
    q = &m_Row[row];
    while(*q) {
      if ((*q)->m_col == col) return true;
      if ((*q)->m_col > col) return false;
      q = &((*q)->m_pNextCol);
    }
    return false;
  }

  void Delete_Cell(int row, int col){
    NodoE<T> ** p, ** q;
    bool r = find_row(row, col, p);
    bool c = find_col(row, col, q);
    //cout<<"\tp = "<<(*p)->m_Dato<<endl;
    //cout<<"\tq = "<<(*q)->m_Dato<<endl;
    //cout<<"\tpNextRow = "<<(*p)->m_pNextRow->m_Dato<<endl;
    // cout<<"\tpNextCol = "<<(*q)->m_pNextCol->m_Dato<<endl;
    if(r || q) {
      delete (*p);
      (*p) = (*p)->m_pNextRow;
      (*q) = (*q)->m_pNextCol;
    }
  }
  void Delete_Row(int row){
    NodoE<T> ** p;
    for(int j=0; j<col_size; j++){
      if(find_row(row,j,p))
        Delete_Cell(row,j);
    }
  }
  void Delete_Col(int col){
    NodoE<T> ** q;
    for(int i=0; i<row_size; i++){
      if(find_row(i,col,q))
        Delete_Cell(i,col);
    }
  }

  T Max_Row(int row) {
    NodoE<T>** p = &m_Row[row];
    T max = (*p)->m_Dato;
    while(*p){
      if((*p)->m_Dato > max)
        max = (*p)->m_Dato;
      p = &((*p)->m_pNextCol);
    }
    return max;
  }
  T Min_Row(int row) {
    NodoE<T>** p = &m_Row[row];
    T min = (*p)->m_Dato;
    while(*p){
      if((*p)->m_Dato < min)
        min = (*p)->m_Dato;
      p = &((*p)->m_pNextCol);
    }
    return min;
  }

  T Max_Col(int col) {
    NodoE<T>** q = &m_Col[col];
    T max = (*q)->m_Dato;
    while(*q){
      if((*q)->m_Dato > max)
        max = (*q)->m_Dato;
      q = &((*q)->m_pNextRow);
    }
    return max;
  }
  T Min_Col(int col) {
    NodoE<T>** q = &m_Col[col];
    T min = (*q)->m_Dato;
    while(*q){
      if((*q)->m_Dato < min)
        min = (*q)->m_Dato;
      q = &((*q)->m_pNextRow);
    }
    return min;
  }

  T Max(){
    T max = Max_Row(0);
    T temp;
    for(int i=0; i<row_size; i++){
      temp = Max_Row(i);
      if(temp > max)
        max = temp;
    }
    return max;
  }
  T Min(){
    T min = Min_Row(0);
    T temp;
    for(int i=0; i<row_size; i++){
      temp = Min_Row(i);
      if(temp < min)
        min = temp;
    }
    return min;
  }

  T Sum_Row(int row) {
    NodoE<T>** p = &m_Row[row];
    T suma = 0;
    while(*p){
      suma = suma + (*p)->m_Dato;
      p = &((*p)->m_pNextCol);
    }
    return suma;
  }

  T Sum_Col(int col) {
    NodoE<T>** q = &m_Col[col];
    T suma = 0;
    while(*q){
      suma = suma + (*q)->m_Dato;
      q = &((*q)->m_pNextRow);
    }
    return suma;
  }

  T Sum_Row(int row, int begin_col, int end_col){
    NodoE<T>** q;
    bool c = find_col(row, begin_col, q);
    T suma = 0;
    while(*q) {
      suma = suma + (*q)->m_Dato;
      if ((*q)->m_col == end_col)
        break;
      q = &((*q)->m_pNextCol);
    }
    return suma;
  }

  T Sum_Col(int col, int begin_row, int end_row){ // 4 1 3
    NodoE<T>** p;
    bool r = find_row(begin_row, col, p);
    T suma = 0;
    while(*p){
      suma = suma + (*p)->m_Dato;
      if((*p)->m_row == end_row)
        break;
      p = &((*p)->m_pNextRow);
    }
    return suma;
  }

  void Rows_Enchange(int row_1, int row_2){
    for(int j=0; j<col_size; j++){
      Swap(row_1,j,row_2,j);
    }
  }
  void Cols_Enchange(int col_1, int col_2){
    for(int i=0; i<row_size; i++){
      Swap(i,col_1,i,col_2);
    }
  } 

  void Transpose(){
    cout<<"\nTranspose"<<endl;
    NodoE<T> ** p;
    const int row_sizeT = col_size;
    const int col_sizeT = row_size;
    Matrix<T,row_sizeT,col_sizeT> Transp;
    for(int i=0; i<row_sizeT; i++){
      for(int j=0; j<col_sizeT; j++){
        if(find_col(j,i,p))
          Transp.Insert((*p)->m_Dato,i,j);
      }
    }
    Transp.Print();
  }

  void Sort_Row(int row){
    NodoE<T>** p;
    list<int> posColumnas;
    list<T> datos;
    for (int i=0; i<col_size; i++){
      if(find_col(row,i,p)){
        posColumnas.push_back((*p)->m_col);
        datos.push_back((*p)->m_Dato);
      }
    }
    datos.sort();
    Delete_Row(row);
    while(!posColumnas.empty() && !datos.empty()){
      Insert(datos.front(),row,posColumnas.front());
      datos.pop_front();
      posColumnas.pop_front();
    }
  }

  void Sort_Col(int col){
    NodoE<T>** q;
    list<int> posRows;
    list<T> datos;
    for (int i=0; i<row_size; i++){
      if(find_col(i,col,q)){
        posRows.push_back((*q)->m_row);
        datos.push_back((*q)->m_Dato);
      }
    }
    datos.sort();
    Delete_Col(col);
    while(!posRows.empty() && !datos.empty()){
      Insert(datos.front(),posRows.front(),col);
      datos.pop_front();
      posRows.pop_front();
    }
  }

  void Swap(int row1,int col1,int row2,int col2){
    NodoE<T> ** p1, ** q1, ** p2, **q2;
    T temp;
    bool r1 = find_row(row1, col1, p1);
    bool c1 = find_col(row1, col1, q1);
    bool r2 = find_row(row2, col2, p2);
    bool c2 = find_col(row2, col2, q2);
    if (*p1 && *q1 && *p2 && *q2){// si ambos nodos existen
      temp = (*p1)->m_Dato;
      (*p1)->m_Dato = (*p2)->m_Dato;
      (*p2)->m_Dato = temp;
    } else if((*p1 && *q1) && !(*p2 && *q2)){ //si solo existe el 1ro
      Insert((*p1)->m_Dato,row2,col2);
      Delete_Cell(row1,col1);
    } else if(!(*p1 && *q1) && (*p2 && *q2)){ //si solo existe el 2do
      Insert((*p2)->m_Dato,row1,col1);
      Delete_Cell(row2,col2);
    }
  }

  void Print(){
    NodoE<T> ** p;
    for(int i=0; i<row_size; i++){
      for(int j=0; j<col_size; j++){
        if(find_col(i,j,p))
          cout<<(*p)->m_Dato<<"\t";
        else 
          cout<<"0\t";
      }
      cout<<"\n";
    }
  }

  void dibujar(){
      ofstream limpiar, archivo;
      //ios::in -> al abrir escribe desde 0 el archivo
      //ios::app -> abrir archivo de modo en que puede añadir datos donde se quedo el cursor
      limpiar.open("esparzadot.dot",ios::out);
      limpiar<<"";
      limpiar.close();

      //editar el archivo
      archivo.open("esparzadot.dot",ios::app); 
      if(archivo.fail()){
        cout<<"No se puede abrir archivo"<<endl; exit(1);
      }
      archivo<<"digraph G{\n";
      archivo<<"\tnode[shape=box fillcolor=\"#F54AEA\" style=filled]\n";
      archivo<<"\tsubgraph M_Espar{\n";
      archivo<<"\t\tlabel = \"MATRIZ ESPARZA\"\n";
      archivo<<"\t\traiz[label = \"0,0\"]\n";
      archivo<<"\t\tedge[dir = \"forward\"]\n";
      archivo<<"\n";

      //  Estructura inicial completa
      
      /*-------------------------------------------------*/
      //
      /*Crearemos las cabeceras de las filas*/
      for (int i = 0; i<row_size; i++)
      {
        archivo<<"\t\tFila"<<i<<"[label=\""<<i<<"\",group=0];\n";
      }
      archivo<<"\n";

      /*Aquí enlazamos los nodos de las filas*/
      for (size_t i = 0; i < row_size; i++)
      {
        archivo<<"\t\tFila"<<i<<"->Fila"<<i+1<<";\n";
      }
      archivo<<"\n";

      /*Aquí enlazamos los nodos de las columnas*/
      for (int i =0; i <col_size; i++)
      {
        archivo<<"\t\tColumna"<<i<<"[label=\""<<i<<"\",group="<<i<<",fillcolor=\"#F54AEA\"];\n";
      }
      archivo<<"\n";

      /*
        Aquí enlazaremos los nodos de las cabeceras
        de las columnas
      */
      for (size_t i = 0; i < col_size; i++)
      {
        archivo<<"\t\tColumna"<<i<<"->Columna"<<i+1<<";\n";
      }
      archivo<<"\n";
      /*
        Aquí vamos aunir la raiz a las filas 
        y a las columnas
      */
      archivo<<"\t\traiz->Fila0\n\t\traiz->Columna0\n";
      archivo<<"\n";
      
      /*Alineamos*/
      archivo<<"\t\t{rank=same;raiz;";
      for (int i = 0; i <= col_size; i++)
      {
        archivo<<"Columna"<<i<<";";
      }
      archivo<<"}\n";
      archivo<<"\n";

      //LISTAS de ROW Y COLUMNA LISTOS
      /*------------------------------------------------*/

      /*AQUI ALINEAMOS CADA NODO CABECERA DE
        LAS COLUMNAS*/
      NodoE<T> ** p;
      for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
          if(find_col(i,j,p))
            //cout<<(*p)->m_Dato<<"\t";
            /*--------------------*/
            archivo<<"\t\tnodo"<<i<<"_"<<j<<"[label=\""<<(*p)->m_Dato<<"\",fillcolor=\"#76FAA6\",group="<<j<<"];\n";
            /*--------------------*/
        }
      }
      archivo<<"\n";

      /*Enlazamos FILA POR FILA*/

      for (int i = 0; i < row_size; i++)
      {
        NodoE<T>*p=m_Row[i];
        if (p)
        {
          archivo<<"\t\tFila"<<i<<"->nodo"<<p->m_row<<"_"<<p->m_col<<";\n";
          while (p->m_pNextCol)
          {
            archivo<<"\t\tnodo"<<p->m_row<<"_"<<p->m_col<<"->nodo"<<p->m_pNextCol->m_row<<"_"<<p->m_pNextCol->m_col<<";\n";
            archivo<<"\t\t{rank=same;Fila"<<i<<";nodo"<<p->m_row<<"_"<<p->m_col<<"}\n";
            p=p->m_pNextCol;
          }
          archivo<<"\t\t{rank=same;Fila"<<i<<";nodo"<<p->m_row<<"_"<<p->m_col<<"}\n"; 

        }
        
      }
      

      /*Enlazamos las columnas con los datos*/
      for (int i = 0; i < col_size; i++)
      {
        NodoE<T>*p=m_Col[i];
        if (p)
        {
          archivo<<"\t\tColumna"<<i<<"->nodo"<<p->m_row<<"_"<<p->m_col<<";\n";
          while (p->m_pNextRow)
          {
            archivo<<"\t\tnodo"<<p->m_row<<"_"<<p->m_col<<"->nodo"<<p->m_pNextRow->m_row<<"_"<<p->m_pNextRow->m_col<<";\n";
            p=p->m_pNextRow;
          }

        }
        
      }
      /*-------------------------------------------------*/

      //  Parte Final de la estructura
      archivo<<"\n\t\t}";
      archivo<<"\n}";
      archivo.close(); //importante cerrar el archivo
      
      system("dot -Tpdf esparzadot.dot -o esparzadot.pdf");
      system("zathura esparzadot.pdf &");
  }

};
/*
int main(){
  Matrix<int,5,6> M;
  // for(int i=0; i<5; i++){
  //   M.Insert(i+1,i,i);
  // }
  M.Insert(118,3,3);
  M.Insert(11,3,4);
  M.Insert(50,3,2);
  M.Insert(46,1,2);
  M.Insert(22,2,2);

    
  M.Insert(38,1,3);
  M.Insert(25,1,2);
  M.Insert(33,1,4);
  M.Insert(75,1,0);
  M.Insert(96,4,2);
  M.Insert(99,2,3);
  M.Insert(105,2,4);
  M.Insert(66,2,0);

  M.Delete_Cell(2,3);
  M.Delete_Row(2);

  M.Print();
  // //cout<<"Max_Row: "<<M.Max_Row(1)<<endl;
  // //cout<<"Min_Row: "<<M.Min_Row(1)<<endl;
  // //cout<<"Max_Col: "<<M.Max_Col(2)<<endl;
  // //cout<<"Min_Col: "<<M.Min_Col(2)<<endl;
  // //cout<<"Max: "<<M.Max()<<endl;
  // //cout<<"Min: "<<M.Min()<<endl;
  // cout<<"Sum_Row: "<<M.Sum_Row(1)<<endl;
  // cout<<"Sum_Col: "<<M.Sum_Col(2)<<endl;
  // //M.Delete_Cell(2,2);
  // M.Insert(77,3,2);
  // M.Print(); cout<<endl;
  // M.Delete_Row(2); cout<<endl;
  // //M.Insert(44,2,3);
  // //M.Delete_Col(2);
  // M.Insert(14,2,1);
  // //M.Insert(7,4,3);
  // //M.Insert(57,4,1);
  // M.Print();
  // cout<<"SumRow 1 de col 1 a col 3: "<<M.Sum_Row(1,1,3)<<endl;
  // cout<<"SumCol 4 de row 1 a row 4: "<<M.Sum_Col(4,1,4)<<endl;
  // // M.Swap(1,1,4,1); //caso existen los 2
  // // M.Swap(1,3,4,0); //caso exista solo el 1ro
  // // M.Swap(0,1,0,4); //caso exista solo el 2do
  // M.Insert(44,2,5);
  // M.Insert(88,4,5);
  // M.Rows_Enchange(0,3);
  // cout<<"Despues de Cambiar filas"<<endl;
  // M.Print(); 
  // M.Cols_Enchange(2,4);
  // cout<<"Despues de Cambiar columnas"<<endl;
  // M.Print();
  // //M.Transpose();
  // M.Sort_Row(1);
  // cout<<"Despues de Sort_Row(1)"<<endl;
  // M.Print();
  // M.Sort_Col(4);
  // cout<<"Despues de Sort_Col(4)"<<endl;
  // M.Print();
  // cout<<"termina la ejecucion"<<endl;
  M.dibujar();
  return 0;
}*/
