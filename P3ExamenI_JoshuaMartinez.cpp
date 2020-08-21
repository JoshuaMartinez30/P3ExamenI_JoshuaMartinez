#include <iostream>
#include <vector>
#include "PC.cpp"
using namespace std;
int main(){
    int opcion;
    char respuesta='s';
    vector <PC *> lista;
    while (respuesta=='s' || respuesta=='S'){
        cout<<"1. Agregar PC"<<endl;
        cout<<"2. Ingresar a PC"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese opcion: ";
        cin>>opcion;
        switch (opcion){
            case 1:
            {
                string ip, mascara, hostname;
                cout<<"Ingrese IP: ";
                cin>>ip;
                cout<<"Ingrese Mascara: ";
                cin>>mascara;
                cout<<"Ingrese Hostname: ";
                cin>>hostname;
                PC* p = new PC(ip, mascara, hostname);
                lista.push_back(p);
            }
            break;
        
            case 2:
            if (lista.empty()){
                cout<<"No existen PC"<<endl;
            }else{
                for (int i = 0; i < lista.size(); i++){
                cout<<i<<")"<<lista[i]->gethostname()<<endl;
            }
            cout<<endl;
                int posicion;
                cout<<"Ingrese posicion: ";
                cin>>posicion;
                cout<<endl;
                string comando,comando1,comando2;
                comando1=lista[posicion]->gethostname()+"#show";
                cout<<lista[posicion]->gethostname()+"#";
                cin>>comando;
                comando2=lista[posicion]->gethostname()+"#"+comando;
                if (comando2==comando1){
                   cout<<"IP: "<<lista[posicion]->getip()<<endl;
                   cout<<"Mascara: "<<lista[posicion]->getmascara()<<endl;
                   cout<<endl;
                }else{
                    for (int i = 0; i < ; i++)
                    {
                        /* code */
                    }
                    
                }
                
            }     
            break;
        
            case 0:
                return (0);
            break;
        }
    }
}
