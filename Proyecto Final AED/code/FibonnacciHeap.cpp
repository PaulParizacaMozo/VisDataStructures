#include "iostream"
#include "stdlib.h"
#include "list"
#include "algorithm"
#include "queue"
#include "map"
#include "fstream"

using namespace std;

template <typename T>
class Nodo_Fibo
{
    typedef Nodo_Fibo<T> *pnodo;

public:
    T m_dato;
    pnodo m_pfather;
    int m_grade;
    list<pnodo> m_sons;
    bool m_visitado;
    bool m_color;

public:
    Nodo_Fibo(T d)
    {
        m_dato = d;
        m_pfather = nullptr;
        m_grade = 0;
        m_visitado=0;
        m_color=false;  //no estan de luto
    }
    ~Nodo_Fibo() {}
    void Add_sons(pnodo p)
    {
        m_sons.push_front(p);
    }
};

template <typename T>
class Fibo_heaps
{
    typedef Nodo_Fibo<T>* pnodo;
    typedef typename list<pnodo>::iterator Iterator;
    typedef typename map<int,Iterator>::iterator Iterator_map;

protected:
    list<pnodo> m_pHeads;
    Iterator p_min;
    int m_size;

public:
    Fibo_heaps()
    {
        p_min=m_pHeads.begin();
        m_size = 0;
    }
    ~Fibo_heaps() {}
    /*--------------Funciones----------------*/
    void insert_dato(T d)
    { // O(1)
        if (m_pHeads.empty())
        {
            pnodo p = new Nodo_Fibo<T>(d);
            m_pHeads.push_front(p);
            m_size++;
            (*p_min)=p;
        }
        else
        {
            pnodo q = new Nodo_Fibo<T>(d);
            Iterator it = m_pHeads.begin();
            if ((*it) == (*p_min))
            {
                m_pHeads.push_front(q);
                p_min = find_min();
                m_size++;
            }
            else
            {
                Iterator aux = rest_direc(p_min);
                pnodo p = (*aux);
                m_pHeads.push_front(p);
                aux = rest_direc(p_min);
                (*aux) = q;
                p_min = find_min();
                m_size++;
            }
        }
    }
    void insert_pnodo(pnodo p)
    { // O(1)
        if (m_pHeads.empty())
        {
            m_pHeads.push_front(p);
            m_size++;
            (*p_min)=p;
        }
        else if(find_bool(p->m_dato)==false)//cambio
        {
            Iterator it = m_pHeads.begin();
            if ((*it) == (*p_min))
            {
                m_pHeads.push_front(p);
                p_min = find_min();
                m_size++;
            }
            else
            {
                Iterator aux = rest_direc(p_min);
                pnodo q = (*aux);
                m_pHeads.push_front(q);
                aux=rest_direc(p_min);
                (*aux) = p;
                p_min = find_min();
                m_size++;
            }
        }
    }
    
    void delete_min()
    {
        if (m_pHeads.empty())
        {
            return;
        }
        else
        {
            if ((*p_min)->m_sons.empty())
            {
                m_pHeads.remove(*p_min);
                compactar();
                p_min=find_min();
            }
            else
            {
                Iterator it = ((*p_min)->m_sons).begin();
                for(;it!=(*p_min)->m_sons.end();it++)
                {
                    (*it)->m_pfather = nullptr;
                    insert_pnodo((*it));
                    it++;
                }
                m_pHeads.remove(*p_min);
                compactar();
                p_min=find_min();
            }
        }
    }
    void delete_general(T d){
        if (find_bool(d)==true)
        {
            decrease_key(d,1);
            delete_min();
        }
        else{cout<<"No existe ese dato"<<endl;}
    }

    Iterator si_encuentro(map<int,Iterator> &map_grados,Iterator &it) //probable falla por no pasar por referencia o algo así, la dirección y ello
    {
        // cout<<"it en si_encuentro: "<<(*it)->m_dato<<endl;
        if (find_grado(map_grados,(*it)->m_grade,it) == true)
        { 
            Iterator grado_it=map_grados[(*it)->m_grade];//pnodo que esta junto al grado repetido
            // cout<<"grado it apunta a 12: "<<(*grado_it)->m_dato<<endl;
            // Iterator grado_it=((map_grados.at((*it)->m_grade)));//pnodo que esta junto al grado repetido
            // Iterator grado_it=((map_grados.find((*it)->m_grade)->second));//pnodo que esta junto al grado repetido
            // cout<<"contenido de grado it: "<<(*grado_it)->m_dato<<endl;
            // (map_grados.find(0)->second)->m_dato//para mostrar dato encontrado
            
            if ( (((*grado_it)->m_dato) > ((*it)->m_dato)) )
            {
                // cout<<"El dato de grado_it: "<<(((*grado_it)->m_dato))<<" es mayor que el de it: "<<((*it)->m_dato)<<endl;
                (*it) = link((*grado_it), (*it));
                map_grados.erase((*grado_it)->m_grade);//movemos el grado del map de grados
                // cout<<"borrando grado1: "<<(*grado_it)->m_grade<<" del nodo "<<(*grado_it)->m_dato<<endl;
                m_pHeads.remove(*grado_it);
                it=si_encuentro(map_grados,it);
                // map_grados.insert(pair<int,Iterator>((*it)->m_grade,it));
                // cout<<"agregando grado222: "<<(*it)->m_grade<<" del nodo "<<(*it)->m_dato<<endl;
                return it;
            }
            else
            {
                // cout<<"El dato de grado_it: "<<((*grado_it)->m_dato)<<" es menor que el de it: "<<((*it)->m_dato)<<endl;
                //--------------------------------------------
                (*grado_it) = link((*grado_it), (*it));
                map_grados.erase((*it)->m_grade);//movemos el grado del map de grados
                // cout<<"borrando grado2: "<<(*it)->m_grade<<" del nodo "<<(*grado_it)->m_dato<<endl;
                m_pHeads.remove(*it);

                grado_it=si_encuentro(map_grados,grado_it);
                // if(find_grado(map_grados,(*grado_it)->m_grade,grado_it)== true){

                // }
                // map_grados.insert(pair<int,Iterator>((*grado_it)->m_grade,grado_it));
                // cout<<"agregando grado333: "<<(*grado_it)->m_grade<<" del nodo "<<(*grado_it)->m_dato<<endl;
                return grado_it;
            }
        }
        else if (find_grado(map_grados, (*it)->m_grade,it) != true || map_grados.empty()==true){
            map_grados.insert(pair<int,Iterator>((*it)->m_grade,it));
            // cout<<"agregando grado444: "<<(*it)->m_grade<<" del nodo "<<(*it)->m_dato<<endl;
            return it;
        }

    }
    Iterator sumar_direc(Iterator it){
        it++;
        return it;
    }

    Iterator rest_direc(Iterator it){
        it--;
        return it;
    }
    
    void compactar()
    {
        // cout<<"compactar"<<endl;
        if (!m_pHeads.empty())
        {
            Iterator it = m_pHeads.begin();
            map<int,Iterator> map_grados;
            for(;it!=m_pHeads.end();it++){
                if (map_grados.empty()==true)
                {
                    map_grados.insert(pair<int,Iterator>((*it)->m_grade,it));

                }
                else{
                    it=si_encuentro(map_grados,it);
                }
            }
        }
    }

    bool find_grado(map<int,Iterator> m, int g, Iterator it_head)
    {
        if (m.empty())
        {
            return false;
        }
        else
        {
            Iterator_map it;
            it = m.find(g);
            if (it != m.end() && ((*(m.find((*it_head)->m_grade)->second))->m_grade)==g)
                return true;
            else
                return false;
        }
    }

    // time complexity O(1) porque solo mete a 1 hijo
    pnodo link(pnodo &p, pnodo &q)
    {
        if (p->m_dato < q->m_dato)
        {
            p->m_sons.push_front(q);
            q->m_pfather = p;
            p->m_grade++;
            return p;
        }
        q->m_sons.push_front(p);
        p->m_pfather = q;
        q->m_grade++;
        return q;
    }

    void padre_luto(pnodo &r)
    {
        if (r->m_color == true)
        {
            pnodo s = r->m_pfather;
            s->m_sons.remove(r);
            r->m_pfather = nullptr;
            r->m_color = false;
            insert_pnodo(r);
            padre_luto(s);
        }
        // else{
        //     r->m_color=true;
        // }
    }

    void decrease_key(T d, T d2){
        pnodo p=find_return_nodo(d);
        // cout<<"puntero al dato conseguido:"<<p->m_dato<<endl;
        p->m_dato=d2;
        pnodo q=p->m_pfather;//q es padre de p
        if (p->m_pfather==nullptr)  //caso de tener un nodo en head
        {
            p_min=find_min();
            //aquí como algo extra que se puede poner de ser el caso de que ponga un dato mucho mayor al que se tenga
        }
        else if (p->m_dato < q->m_dato) //q es padre
        {
            if (q->m_color==true)
            {
                //primero saca al elemento escogido
                q->m_sons.remove(p);
                p->m_pfather=nullptr;
                p->m_color=false;//cambiamos a blanco si estaba negro
                insert_pnodo(p);//el insert ya tiene el find p_min
                // cout<<"dato a insertar:"<<p->m_dato<<endl;


                //como su padre ya estaba de luto también lo extraemos
                pnodo r=q->m_pfather;
                r->m_sons.remove(q);
                q->m_pfather=nullptr;
                q->m_color=false;
                insert_pnodo(q);
                padre_luto(r);           
            }
            else{
                q->m_color=true;
                q->m_sons.remove(p);
                // cout<<"gaa"<<endl;
                p->m_pfather=nullptr;
                p->m_color=false;//cambiamos a blanco si estaba negro
                // if (q->m_pfather!=nullptr)
                // {
                //     cout<<"El padre de q es: "<<(q->m_pfather)->m_dato<<endl;
                // }
                insert_pnodo(p);//el insert ya tiene el find p_min
            }
        }
        cout<<"todo bien"<<endl;
    }

    void find_general(T d)
    { // Basado en BFS

        typedef typename list<pnodo>::iterator itSons;
        if (!m_pHeads.empty())
        {
            auto itheads = m_pHeads.begin();
            auto it2 = (*itheads)->m_sons.begin();
            queue<pnodo> cola;
            for (; itheads != m_pHeads.end(); itheads++)
            { // Recorre heads y imprime las cabezas
                // cout << "[head] ";
                cola.push(*itheads);     // Inserta primer nodo
                pnodo it = cola.front(); // it es el 1er elemento de la cola
                it->m_visitado = true;   // lo marcamos como visitado
                while (!cola.empty())
                {
                    it = cola.front();
                    // cout << it->m_dato << " ";
                    if (it->m_dato == d)
                    {
                        cout << "Dato encontrado" << endl;
                        break;
                    }
                    cola.pop();                         // Eliminamos el elemento ya mostrado
                    itSons itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                    int c = 0;
                    for (; itsons != it->m_sons.end(); itsons++)
                    {
                        if ((*itsons)->m_visitado == false)
                        { // Si aun no fue visitado lo agregamos a la cola
                            (*itsons)->m_visitado == true;
                            cola.push(*itsons);
                        }
                        c++;
                    }
                    // cout << "(sons:" << c << ") ";
                    c = 0;
                }
                // cout << "\n";
            }
        }
    }

    bool find_bool(T d)
    { // Basado en BFS

        typedef typename list<pnodo>::iterator itSons;
        if (!m_pHeads.empty())
        {
            auto itheads = m_pHeads.begin();
            auto it2 = (*itheads)->m_sons.begin();
            queue<pnodo> cola;
            for (; itheads != m_pHeads.end(); itheads++)
            { // Recorre heads y imprime las cabezas
                // cout << "[head] ";
                cola.push(*itheads);     // Inserta primer nodo
                pnodo it = cola.front(); // it es el 1er elemento de la cola
                it->m_visitado = true;   // lo marcamos como visitado
                while (!cola.empty())
                {
                    it = cola.front();
                    // cout << it->m_dato << " ";
                    if (it->m_dato == d)
                    {
                        return true;
                    }
                    cola.pop();                         // Eliminamos el elemento ya mostrado
                    itSons itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                    int c = 0;
                    for (; itsons != it->m_sons.end(); itsons++)
                    {
                        if ((*itsons)->m_visitado == false)
                        { // Si aun no fue visitado lo agregamos a la cola
                            (*itsons)->m_visitado == true;
                            cola.push(*itsons);
                        }
                        c++;
                    }
                    // cout << "(sons:" << c << ") ";
                    c = 0;
                }
                // return false;
                // cout << "\n";
            }
        }
    }

    pnodo find_return_nodo(T d)
    { // Basado en BFS

        typedef typename list<pnodo>::iterator itSons;
        if (!m_pHeads.empty())
        {
            auto itheads = m_pHeads.begin();
            auto it2 = (*itheads)->m_sons.begin();
            queue<pnodo> cola;
            for (; itheads != m_pHeads.end(); itheads++)
            { // Recorre heads y imprime las cabezas
                // cout << "[head] ";
                cola.push(*itheads);     // Inserta primer nodo
                pnodo it = cola.front(); // it es el 1er elemento de la cola
                it->m_visitado = true;   // lo marcamos como visitado
                while (!cola.empty())
                {
                    it = cola.front();
                    // cout << it->m_dato << " ";
                    if (it->m_dato == d)
                    {
                        // cout<<"Dato encontrado"<<endl;
                        return it;
                        break;
                    }
                    cola.pop();                         // Eliminamos el elemento ya mostrado
                    itSons itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                    int c = 0;
                    for (; itsons != it->m_sons.end(); itsons++)
                    {
                        if ((*itsons)->m_visitado == false)
                        { // Si aun no fue visitado lo agregamos a la cola
                            (*itsons)->m_visitado == true;
                            cola.push(*itsons);
                        }
                        c++;
                    }
                    // cout << "(sons:" << c << ") ";
                    c = 0;
                }
                // cout << "\n";
            }
        }
    }

    Iterator find_min(){
        Iterator it=m_pHeads.begin();
        Iterator min=m_pHeads.begin();
        for(;it!=m_pHeads.end();it++){
            if (((*it)->m_dato)<((*min)->m_dato))
            {
                min=it;
            }
        }
        return min;
    }

    void print_heads()
    {
        Iterator it = m_pHeads.begin();
        while (it != m_pHeads.end())
        {
            cout << (*it)->m_dato << " --> ";
            it++;
        }
        cout<<endl;
        cout<<"Dato minimo: "<<(*p_min)->m_dato<<endl;
    }

    void reset_visitados(){
        typedef typename list<pnodo>::iterator itSons;
        if (m_pHeads.empty())
            return;
        auto itheads = m_pHeads.begin();
        auto it2 = (*itheads)->m_sons.begin();
        queue<pnodo> cola;
        for (; itheads != m_pHeads.end(); itheads++)
        { // Recorre heads y imprime las cabezas
            // cout << "[head] ";
            cola.push(*itheads);     // Inserta primer nodo
            pnodo it = cola.front(); // it es el 1er elemento de la cola
            // it->m_visitado = true;   // lo marcamos como visitado
            while (!cola.empty())
            {
                it = cola.front();
                // cout << it->m_dato << " ";        // Mostramos el primer elemento de la cola
                cola.pop();                         // Eliminamos el elemento ya mostrado
                itSons itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                int c = 0;
                for (; itsons != it->m_sons.end(); itsons++)
                {
                    // if ((*itsons)->m_visitado == false)
                    // { // Si aun no fue visitado lo agregamos a la cola
                    //     (*itsons)->m_visitado == true;
                    cola.push(*itsons);
                    // }
                    c++;
                }
                // cout << "(sons:" << c << ") ";
                c = 0;
            }
            // cout << "\n";
        }
    }
    void print_2()
    { // Basado en BFS
        // reset_visitados();  
        Iterator itSons;
        if (m_pHeads.empty())
            return;
        auto itheads = m_pHeads.begin();
        auto it2 = (*itheads)->m_sons.begin();
        queue<pnodo> cola;
        for (; itheads != m_pHeads.end(); itheads++)
        { // Recorre heads y imprime las cabezas
            cout << "[head] ";
            cola.push(*itheads);     // Inserta primer nodo
            pnodo it = cola.front(); // it es el 1er elemento de la cola
            it->m_visitado = true;   // lo marcamos como visitado
            while (!cola.empty())
            {
                it = cola.front();
                cout << it->m_dato << " ";        // Mostramos el primer elemento de la cola
                cola.pop();                         // Eliminamos el elemento ya mostrado
                Iterator itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                int c = 0;
                for (; itsons!= it->m_sons.end(); itsons++)
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
    void Draw()
    {
        // reset_visitados();
        if (!m_pHeads.empty())
        {
            ofstream limpiar, archivo;
            // ios::in -> al abrir escribe desde 0 el archivo
            // ios::app -> abrir archivo de modo en que puede aÃ±adir datos donde se quedo el cursor
            limpiar.open("FiboHeap.dot", ios::out);
            limpiar << "";
            limpiar.close();
            archivo.open("FiboHeap.dot", ios::app);
            if (archivo.fail())
            {
                cout << "No se puede abrir archivo" << endl;
                exit(1);
            }
            archivo << "digraph G{\n";

            // mínimo apuntando
            archivo << "\t Mínimo ->" << (*p_min)->m_dato << "\n";
            archivo << "\t Mínimo[fillcolor=springgreen,style=filled,shape = octagon,fixedsize = true] edge[color=springgreen]\n";

            // heads:
            auto aux = m_pHeads.begin();
            archivo << "\t";
            while (aux != m_pHeads.end())
            {
                archivo << (*aux)->m_dato;
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
                archivo << (*aux2)->m_dato;
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

            list<pnodo> res;
            if (m_pHeads.empty())
                return;
            auto itheads = m_pHeads.begin();
            auto it2 = (*itheads)->m_sons.begin();
            queue<pnodo> cola;
            for (; itheads != m_pHeads.end(); itheads++)
            { // Recorre heads y imprime las cabezas
                // cout<<"[head] ";
                cola.push(*itheads);     // Inserta primer nodo
                pnodo it = cola.front(); // it es el 1er elemento de la cola
                it->m_visitado = true;   // lo marcamos como visitado
                while (!cola.empty())
                {
                    it = cola.front();
                    // cout<<it->m_dato<<" "; // Mostramos el primer elemento de la cola
                    res.push_back(it);
                    cola.pop();                         // Eliminamos el elemento ya mostrado
                    Iterator itsons = it->m_sons.begin(); // Consultamos los hijos del nodo it actual;
                    for (; itsons != it->m_sons.end(); itsons++)
                    {
                        if ((*itsons)->m_visitado == false)
                        { // Si aun no fue visitado lo agregamos a la cola
                            (*itsons)->m_visitado == true;
                            cola.push(*itsons);
                        }
                    }
                }
            }

            // typedef typename list<pnodo>::iterator itListNodos;
            list<pnodo> print = res;
            for (auto it3 = print.begin(); it3 != print.end(); it3++)
            {
                // cout<<(*it3)->m_dato<<" ";
                for (auto it4 = (*it3)->m_sons.begin(); it4 != ((*it3)->m_sons.end()); it4++)
                {
                    archivo << "\t" << (*it3)->m_dato << " -> " << (*it4)->m_dato << "\n";
                }
            }

            archivo << "\n}";
            archivo.close();
            system("dot -Tjpg FiboHeap.dot -o FiboHeap.jpg");
        }
        else
        {
            return;
        }
    }

    void menuFibonnacci()
    {
        Fibo_heaps<int> Fibo;
        bool salir = false;
        int opt;
        int aux;
        int aux2;
        while (salir == false)
        {
            cout << "\n***MENU DE FIBONNACCI HEAPS***" << endl;
            cout << " 1.- Insertar\n 2.- Eliminar dato mínimo\n 3.- Eliminar dato\n 4.- Modificar dato\n 5.- Mostrar\n 6.- SALIR" << endl;
            cout << " Ingrese una opcion -> ";
            cin >> opt;
            switch (opt)
            {
            case 1:
                cout << "  Ingrese el dato a insertar -> ";
                cin >> aux;
                insert_dato(aux);
                print_2();
                Draw();
                break;
            case 2:
                cout << "  Eliminando el dato mínimo y compactando..."; 
                delete_min();
                print_2();
                Draw();
                break;
            case 3:
                cout << "  Ingrese el dato a eliminar -> "; 
                cin >> aux;
                delete_general(aux);
                print_2();
                Draw();
                break;
            case 4:
                cout << "  Ingrese el dato a modificar -> "; 
                cin >> aux;
                if(find_bool(aux)){
                    cout << "  Ingrese el dato a ingresar -> "; 
                    cin >> aux2;
                    decrease_key(aux,aux2);
                    print_2();
                    Draw();
                    break;
                }
                else{
                    cout<<"dato no encontrado"<<endl;
                    break;
                }
            case 5:
                print_2();
                Draw();
                break;
            case 6:
                salir = true;
                break;

            }
        }
    }
};

int main()
{
    Fibo_heaps<int> F;
    F.insert_dato(5);
    F.insert_dato(13);
    F.insert_dato(78);
    F.insert_dato(2);
    F.insert_dato(3);
    F.insert_dato(22);
    // F.insert_dato(2);
    F.insert_dato(19);
    F.insert_dato(100);
    // F.insert_dato(9);
    F.delete_min();
    F.print_heads();
    F.print_2();
    F.Draw();
    // cout<<"Dato encontrado??: "<<F.find_bool(13)<<endl;
    // cout<<"----- "<<endl;
    // F.find_general(13);
    // F.decrease_key(78,56);
    // F.print_heads();
    // F.print_2();
    // F.Draw();
    // F.menuFibonnacci();
    return 0;
}