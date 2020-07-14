#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef int64_t ll;  

vector<ll> arre;
vector<pii> zonas;
int k;


//calcula la cantidad de fotos en una sección
ll calculaEntrada(int i, int j){
    ll suma = 0;
    for(pii p: zonas)
        suma+= 1000 - abs(p.first - i) - abs(p.second - j);
    return suma;
}

//te dice si se puede con k rollos con f fotos
bool sePuedeRollo(ll f){ // f es med
    ll necesito = 0;
    ll sumaActual = 0;
    // [a1, a2, a3, a4]
    for(ll entrada : arre){
        //me voy a pasar si la tomo
        //entonces hay de dos
        if(sumaActual + entrada > f){    
            //esta nueva entrada no cabe ni en un rollo
            if(entrada > f)
                return false;
            //o empiezo un nuevo rollo
            ++necesito;
            sumaActual = entrada;
        }
        //si no me paso solo la sumo
        else
            sumaActual += entrada;
    }
    //como solo conte cuando cortaba, me falta contar el ultimo rollo 
    //que no se corta nunca
    ++necesito;
    
    //shortcut para
    // if(necesito <= k) return true
    // else return false
    // lo que hace es regresar si esa afirmacion es verdadera o no
    return necesito<=k;
}
 

ll busquedaBinaria(ll l, ll r){
    
    ll med;
    while(l < r){
        //en este caso usamos la mitad "de la izquierda"
        med = (l+r)/2;
        if(sePuedeRollo(med))
            r = med;
        else
            l = med+1;
    }

    return l; 
}

int main(){
    
    //leemos las zonas con avistamientos
    int r, c;
    cin>>r>>c>>k;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            char aux;
            cin>>aux;
            if(aux == '*')
                zonas.push_back(pii(i, j));
        }
    }
    

    /*
    -------->
    <--------
    -------->
    <--------
    [arre1, arre2]
    */

    //creo arreglo (de tamanio r*c)
    for(int i = 0; i < r; ++i){
        //recorro normal
        if(i%2 == 0){
            for(int j = 0; j < c; ++j)
                arre.push_back(calculaEntrada(i, j));
        }
        //recorro al reves
        else{
            for(int j = c-1; j >= 0; --j)
                arre.push_back(calculaEntrada(i, j));
        }
    }

    
    
    // hacemos busqueda binaria con cotas
    ll resp = busquedaBinaria(0, 2*1e10);
    
    cout<<resp<<"\n";
}