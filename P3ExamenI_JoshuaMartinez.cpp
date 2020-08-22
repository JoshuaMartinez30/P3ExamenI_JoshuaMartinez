#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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
            {
                for (int i = 0; i < lista.size(); i++){
                    cout<<i<<")"<<lista[i]->gethostname()<<endl;
                }
                cout<<endl;
                int posicion1, posicion;
                cout<<"Ingrese posicion: ";
                cin>>posicion1;
                char prueba='s';
                while (prueba=='s'){   
                    if (lista.empty()){
                        cout<<"No existen PC"<<endl;
                    }else{
                    posicion=posicion1;
                    cout<<endl;
                    string comando,comando1,comando2, comando3;
                    comando1=lista[posicion]->gethostname()+"#show";
                    comando3=lista[posicion]->gethostname()+"#exit";
                    cout<<lista[posicion]->gethostname()+"#";
                    cin>>comando;
                    comando2=lista[posicion]->gethostname()+"#"+comando;
                    if (comando2==comando3){
                        prueba='n';
                    }else if (comando2==comando1){
                        cout<<"IP: "<<lista[posicion]->getip()<<endl;
                        cout<<"Mascara: "<<lista[posicion]->getmascara()<<endl;
                        cout<<endl;
                    }else{
                        int centinela=0, centinela1=0;
                        string temporal="";
                        for (int i = 0; i < comando2.size(); i++){
                            if (comando2.at(i)=='_'){
                                centinela++;
                            }
                            if (centinela==1){
                                if (centinela1==1){
                                    temporal+=comando2.at(i);    
                                }
                                centinela1=1;
                            }
                        }
                        for (int i = 0; i < lista.size(); i++){
                            if (temporal==lista[i]->getip()){
                                string auxiliar_mask, IP_2;
                                auxiliar_mask = lista[i]->getmascara();
                                cout<<"IP_1: "<< temporal<< "  Mascara:   "<<auxiliar_mask<<endl;
                                cout<<"IP_2->";
                                cin>>IP_2;
                                string auxiliar_binario1="", auxiliar_binario2="", auxiliar_binario3=""; 
                                string binario_IP1="", binario_IP2, binario_mascara;
                                int binario1, binario2, binario3, contador_binario;
                                string conversion="";
                                for (int i = 0; i < temporal.size(); i++){//binario IP 1
                                    if (temporal.at(i)!='.'){
                                        conversion+=temporal.at(i);
                                    }else if (temporal.at(i)=='.'){
                                        binario1 = atoi(conversion.c_str());
                                        if (binario1==0){
                                            for (int i = 0; i < 8; i++){
                                                binario_IP1+="0";
                                            }
                                            binario_IP1+=".";    
                                        }else{
                                            while (binario1>0){
                                                if (binario1%2==0){
                                                    auxiliar_binario1+="0";
                                                }else{
                                                    auxiliar_binario1+="1";
                                                }
                                                binario1 = (int) binario1/2;
                                            }
                                            if (auxiliar_binario1.size()<8){
                                                contador_binario=8-auxiliar_binario1.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_IP1+="0";
                                                }
                                                binario_IP1+=auxiliar_binario1+".";
                                                auxiliar_binario1="";
                                            }else{
                                                binario_IP1+=auxiliar_binario1+".";
                                                auxiliar_binario1="";
                                            }
                                        
                                        }
                                        conversion="";
                                    }
                                    if (i==temporal.size()-1){
                                        binario1 = atoi(conversion.c_str());
                                        if (binario1==0){
                                            for (int i = 0; i < 8; i++){
                                                binario_IP1+="0";
                                            }
                                        }else{
                                            while (binario1>0){
                                                if (binario1%2==0){
                                                    auxiliar_binario1+="0";
                                                }else{
                                                    auxiliar_binario1+="1";
                                                }
                                                binario1 = (int) binario1/2;
                                            }
                                            if (auxiliar_binario1.size()<8){
                                                contador_binario=8-auxiliar_binario1.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_IP1+="0";
                                                }
                                                binario_IP1+=auxiliar_binario1;
                                                auxiliar_binario1="";
                                            }else{
                                                binario_IP1+=auxiliar_binario1;
                                                auxiliar_binario1="";
                                            }
                                        
                                        }
                                        conversion="";
                                    }
                                }//fin Binario IP 1
                                conversion="";
                                for (int i = 0; i < auxiliar_mask.size(); i++){//binario mascara
                                    if (auxiliar_mask.at(i)!='.'){
                                        conversion+=auxiliar_mask.at(i);
                                    }else if (auxiliar_mask.at(i)=='.'){
                                        binario2 = atoi(conversion.c_str());
                                        if (binario2==0){//
                                            for (int i = 0; i < 8; i++){
                                            binario_mascara+="0";
                                        }
                                        binario_mascara+=".";    
                                        }else{
                                            while (binario2>0){
                                                if (binario2%2==0){
                                                    auxiliar_binario2+="0";
                                                }else{
                                                    auxiliar_binario2+="1";
                                                }
                                                binario2 = (int) binario2/2;
                                            }
                                            if (auxiliar_binario2.size()<8){
                                                contador_binario=8-auxiliar_binario2.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_mascara+="0";
                                                }
                                                binario_mascara+=auxiliar_binario2+".";
                                                auxiliar_binario2="";
                                            }else{
                                                binario_mascara+=auxiliar_binario2+".";
                                                auxiliar_binario2="";
                                            }   
                                        }//
                                        conversion="";
                                    }
                                    if (i==auxiliar_mask.size()-1){
                                        binario2 = atoi(conversion.c_str());
                                        if (binario2==0){
                                            for (int i = 0; i < 8; i++){
                                                binario_mascara+="0";
                                            }
                                        }else{
                                            while (binario2>0){
                                                if (binario2%2==0){
                                                    auxiliar_binario2+="0";
                                                }else{
                                                    auxiliar_binario2+="1";
                                                }
                                                binario2 = (int) binario2/2;
                                            }
                                            if (auxiliar_binario2.size()<8){
                                                contador_binario=8-auxiliar_binario2.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_mascara+="0";
                                                }
                                                binario_mascara+=auxiliar_binario2;
                                                auxiliar_binario1="";
                                            }else{
                                                binario_mascara+=auxiliar_binario2;
                                                auxiliar_binario1="";
                                            }
                                        
                                        }
                                        conversion="";
                                    }
                                }//fin mascara

                                conversion="";
                                for (int i = 0; i < IP_2.size(); i++){//binario IP 2
                                    if (IP_2.at(i)!='.'){
                                        conversion+=IP_2.at(i);
                                    }else if (IP_2.at(i)=='.'){
                                        binario3 = atoi(conversion.c_str());
                                        if (binario3==0){
                                            for (int i = 0; i < 8; i++){
                                                binario_IP2+="0";
                                            }
                                            binario_IP2+=".";    
                                        }else{
                                            while (binario3>0){
                                                if (binario3%2==0){
                                                    auxiliar_binario3+="0";
                                                }else{
                                                    auxiliar_binario3+="1";
                                                }
                                                binario3 = (int) binario3/2;
                                            }
                                            if (auxiliar_binario3.size()<8){
                                                contador_binario=8-auxiliar_binario3.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_IP2+="0";
                                                }
                                                binario_IP2+=auxiliar_binario3+".";
                                                auxiliar_binario3="";
                                            }else{
                                                binario_IP2+=auxiliar_binario3+".";
                                                auxiliar_binario3="";
                                            }
                                        }
                                        conversion="";
                                    }
                                    if (i==IP_2.size()-1){
                                        binario3 = atoi(conversion.c_str());
                                        if (binario3==0){
                                            for (int i = 0; i < 8; i++){
                                                binario_IP2+="0";
                                            }
                                        }else{
                                            while (binario3>0){
                                                if (binario3%2==0){
                                                    auxiliar_binario3+="0";
                                                }else{
                                                    auxiliar_binario3+="1";
                                                }
                                                binario3 = (int) binario3/2;
                                            }
                                            if (auxiliar_binario3.size()<8){
                                                contador_binario=8-auxiliar_binario3.size();
                                                for (int i = 0; i < contador_binario; i++){
                                                    binario_IP2+="0";
                                                }
                                                binario_IP2+=auxiliar_binario3;
                                                auxiliar_binario3="";
                                            }else{
                                                binario_IP2+=auxiliar_binario3;
                                                auxiliar_binario3="";
                                            }
                                        }
                                        conversion="";
                                    }
                                }//fin Binario IP 2

                                //ojo
                                cout<<"IP1_banario: "<<binario_IP1<<endl;
                                cout<<"IP2_banario: "<<binario_IP2<<endl;
                                cout<<"mascara_banario: "<<binario_mascara<<endl;
                                int contador=0;
                                for ( i = 0; i < binario_mascara.size(); i++){
                                    if (binario_mascara.at(i)=='1'){
                                        contador++;
                                    }else if (binario_mascara.at(i)=='0'){
                                        i=binario_mascara.size();
                                    }  
                                }
                                int contador_ip1,contador_ip2;
                                contador_ip1=contador;
                                contador_ip2=contador;
                                string temporal_binario_IP1="";
                                for (int i = 0; i < contador_ip1; i++){
                                    temporal_binario_IP1+=binario_IP1.at(i);
                                    if (binario_IP1.at(i)=='.'){
                                        contador_ip1=contador_ip1+1;
                                    }
                                }
                                string temporal_binario_IP2="";
                                for (int i = 0; i < contador_ip2; i++){
                                    temporal_binario_IP2+=binario_IP2.at(i);
                                    if (binario_IP1.at(i)=='.'){
                                        contador_ip2=contador_ip2+1;
                                    }
                                }
                                cout<<endl;
                                cout<<"Comparar IP's:"<<endl;
                                cout<<"IP1: "<<temporal_binario_IP1<<endl;
                                cout<<"IP2: "<<temporal_binario_IP2<<endl;
                                cout<<endl;
                                if (temporal_binario_IP1==temporal_binario_IP2){
                                    cout<<"Pinging to "<<temporal <<" with 32 bytes of data: "<<endl;
                                    cout<<"Reply from "<< temporal<< ": bytes=32  time=37ms  TTL=46"<<endl;
                                    cout<<"Reply from "<< temporal<< ": bytes=32  time=37ms  TTL=46"<<endl;
                                    cout<<"Reply from "<< temporal<< ": bytes=32  time=37ms  TTL=46"<<endl;
                                    cout<<"Reply from "<< temporal<< ": bytes=32  time=37ms  TTL=46"<<endl;
                                    cout<<endl;
                                    cout<<"Ping statistics for "<<temporal<<":"<<endl;
                                    cout<<"    Packets: Sent = 4, Recieved = 4, Lost = 4(0% loss)"<<endl;
                                }else{
                                    cout<<"Pinging to "<<temporal <<" with 32 bytes of data: "<<endl;
                                    cout<<"Reply from "<< temporal<< ": Destination host unreachable"<<endl;
                                    cout<<"Reply from "<< temporal<< ": Destination host unreachable"<<endl;
                                    cout<<"Reply from "<< temporal<< ": Destination host unreachable"<<endl;
                                    cout<<"Reply from "<< temporal<< ": Destination host unreachable"<<endl;
                                    cout<<endl;
                                    cout<<"Ping statistics for "<<temporal<<":"<<endl;
                                    cout<<"    Packets: Sent = 4, Recieved = 4, Lost = 4(0% loss)"<<endl;
                                }
                            
                            }else{
                                cout<<"Pinging to "<<temporal <<" with 32 bytes of data: "<<endl;
                                cout<<"Request timed out"<<endl;
                                cout<<"Request timed out"<<endl;
                                cout<<"Request timed out"<<endl;
                                cout<<"Request timed out"<<endl;
                                cout<<endl;
                                cout<<"Ping statistics for "<<temporal<<":"<<endl;
                                cout<<"    Packets: Sent = 4, Recieved = 0, Lost = 4(100% loss)"<<endl;
                            }  
                        }
                    }
                }//else
            }//while
        }     
            break;
        
            case 0:
                return (0);
            break;
        }
    }
}
