#include "iostream"
#include "stdlib.h"
#include "list"
#include "algorithm"
#include "queue"
#include "map"

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

public:
    Nodo_Fibo(T d)
    {
        m_dato = d;
        m_pfather = nullptr;
        m_grade = 0;
        m_visitado=0;
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
                pnodo p = new Nodo_Fibo<T>((*aux)->m_dato);
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
        else
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
                pnodo q = new Nodo_Fibo<T>((*aux)->m_dato);
                m_pHeads.push_front(q);
                aux = rest_direc(p_min);
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
                Iterator it = (*p_min)->m_sons.begin();
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
    void delete_general();

    Iterator si_encuentro(map<int,Iterator> &map_grados,Iterator &it) //probable falla por no pasar por referencia o algo así, la dirección y ello
    {
        cout<<"it en si_encuentro: "<<(*it)->m_dato<<endl;
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
                    // cout<<"agregando grado1111: "<<(*it)->m_grade<<" del nodo "<<(*it)->m_dato<<endl;

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
    pnodo link(pnodo p, pnodo q)
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


    void decrease_key();
    void find();

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

    void print(); // BFS
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
    void print_2()
    { // Basado en BFS
        typedef typename list<pnodo>::iterator itSons;
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
                cout << it->m_dato << " ";          // Mostramos el primer elemento de la cola
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
                cout << "(sons:" << c << ") ";
                c = 0;
            }
            cout << "\n";
        }
        void draw();
    }
};

int main()
{
    Fibo_heaps<int> F;
    F.insert_dato(10);
    F.insert_dato(12);
    F.insert_dato(5);
    F.insert_dato(13);
    F.insert_dato(3);
    F.insert_dato(22);
    F.insert_dato(1);
    // F.insert_dato(19);
    F.print_heads();
    F.delete_min();
    // cout<<"ya pasó el delete min"<<endl;
    F.print_heads();
    F.print_2();
    F.print_heads();
    return 0;
}