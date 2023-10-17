#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
#include <fstream>
#include<conio.h>
#include<stdlib.h>
#include "routers.h"

using namespace std;
routers r;
char ori;
vector<string> rut={""};
vector<int> cost= {90000000}; //-> ponemos un valor grande para que en la comparacion de los costos no genere problema
int j;

string leer(string nombre_archivo){
    string data;
    string texto;
    // Abre el archivo en modo lectura
    ifstream infile;
    string direccion="C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt";
    //direccion+=nombre_archivo;
    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    infile.open(direccion);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
        cout << "Error abriendo el archivo" << endl;
        exit(1);  //--> es para comparar si se abrio exitosamente el archivo
    }
    while(!infile.eof()){
        infile>>data;
        if (texto==""){
            texto= data;
        }
        else{
            texto= texto+ " " + data;
        }
    }

    infile.close();
    return texto;
}

void AgregarRouter(){

    /*esta funcion tiene como objetivo agragar todos los routers que el usuario desee agregar al
archivo donde se tienen guardadas las rutas*/

    string router;
    ofstream Guardar;
    Guardar.open("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt",ios::app);
    while (router!="-1") {

        cout<<"PORFAVOR INGRESELO DE LA FORMA "
                "<NUEVO><VIEJO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "<<endl<<"Y VISEVERSA "
                "<VIEJO><NUEVO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "
                ";EJEMPLO <AZ-9> Y <ZA-9>."<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL NUEVO ROUTER ASI         *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*      <ROUTER 1><ROUTER 2>-<COSTO>        *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O -1 PARA SALIR              *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;

        if(router!="-1"){
            router+=".";
            Guardar<<router<<endl;
            system("CLS");
        }
    }

    Guardar.close();

}

void AgregarRouter2(string doc){

    /*esta funcion tiene como objetivo agragar todos los routers que el usuario desee agregar al
archivo donde se tienen guardadas las rutas*/

    string router,k;
    ofstream Guardar;
    k="C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt";
    k+=doc;
    Guardar.open(k,ios::app);
    while (router!="-1") {

        cout<<"PORFAVOR INGRESELO DE LA FORMA "
                "<NUEVO><VIEJO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "<<endl<<"Y VISEVERSA "
                "<VIEJO><NUEVO>-<COSTO> (CON UN ENTER O SALTO DE LINEA) "
                ";EJEMPLO <AZ-9> Y <ZA-9>."<<endl;

        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL NUEVO ROUTER ASI         *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*      <ROUTER 1><ROUTER 2>-<COSTO>        *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O -1 PARA SALIR              *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;

        if(router!="-1"){
            router+=".";
            Guardar<<router<<endl;
            system("CLS");
        }
    }

    Guardar.close();

}

void BorrarRouter(){

    /*esta funciÃ³n tiene el propÃ³sito de eliminar el Ruter elegido por el usuario,
se hace siguiendo estos pasos:

1) extraer los enlaces y ubicarlos en un mapa (estos para poder manippular los ruters con mayor facilidad)

2) buscar con ayuda de un iterador si el Reuter que dio el usuario estÃ¡ en el mapa (por que no puedes eliminar algo que no existe)
en la parte de key en la cual estÃ¡n los nombres de los Reuters conectados, y si se encuentra el Reuter se elimina dicho componente del mapa

3)se agrega a un archivo temporal la informaciÃ³n editada para poder hacer la actualizacion y se renombra despues este archivo y se elimina el anterior
 (Cosa que me hubiera gustado aprender o saber donde buscar para el lab 3 :Â´D )*/


    int x=0,pos,posinicio=0,posaux1=0,posaux2;
    string temp1,temp2,txtau,neu,temporal,txtguia;char router,ru=' ';

    ofstream Guardar;
    ofstream temp_txt;

    Guardar.open("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt",ios::app);
    temp_txt.open("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/temporal.txt",ios::app);

    map<string,short> enlaces;
    map<string,short>::iterator it;

    string sacado=leer("rutas.txt");

    pos =sacado.find_first_of('.');

    for(unsigned int i=0;i<sacado.length();i++){
        if(i<pos){
            txtguia+=sacado.at(i);
        }

    }
    txtguia+=".";
    temp_txt<<txtguia<<endl;

    //guardamos el archivo dentro del string para mejor manipulacion de la informacion

    while(true){
        for(int i=posinicio;i < pos;i++){
            if(posinicio==0){
                for(unsigned int i=0;i<sacado.length();i++){
                    if(i>pos){
                        temp2+=sacado.at(i);
                    }

                }sacado=temp2;
                temp2="";
                pos=0;
                break;
            }
            else if(sacado.at(i)!=' '){
                temp1+=sacado.at(i);
            }
        }

        //separamos los ruters nada mas por el . y quitamos los endl

        if (temp1!=""){
            posaux1=temp1.find_first_of("-");
            for(unsigned int i=0;i<temp1.length();i++){
                if(i>posaux1){
                    temp2+=temp1.at(i);
                }else if(temp1.at(i)!='-'){
                    txtau+=temp1.at(i);
                }
            }
            double num_double = std::stod(temp2);
            enlaces[txtau]=num_double; //--> guardamos en el mapa
        }

        posinicio=pos+1;

        for(unsigned int i=0;i<sacado.length();i++){
            if(i>pos){
                neu+=sacado.at(i);
            }

        }

        //separamos la ruta de su costo de envio en dos variables diferentes para poder buscar mejor

        posaux2=neu.find_first_of('.');
        pos +=posaux2+1;
        neu="";
        temp2="";
        temp1="";
        txtau="";
        if(posaux2==-1){
            break;
        }
    }

    while (router!='1') {

        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL ROUTER A ELIMINAR        *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*                <ROUTER>                  *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O 1 PARA SALIR               *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;

        if(router!='1'){
            if(ru!=router){
                for(it=enlaces.begin();it!=enlaces.end();it++){
                    if(it->first[0]==router || it->first[1]==router){}
                    else{temporal+=it->first+"-" + to_string(it->second)+".";
                        temp_txt<<temporal<<endl;
                        temporal="";
                    }

                }

            }

            //Buscamos dentro del mapa en ambas posiciones el router a eliminar para asegurarnos de eliminar todas las conecciones

            ru=router;
            temp_txt.close();
            Guardar.close();
            remove("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt");
            rename("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/temporal.txt","C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt");
            cout<<"EL ROUTER "<<router<<" fue eliminado"<<endl;

            //Actualizamos los archivos para guardar la informacion que no se borro

            _sleep(3500); //---> permite un tiempo de espera en la pantalla antes de ejecutar el siguiente comando
            system("CLS");
        }
    }
}

void BorrarRouter2(string doc){

    /*esta funciÃ³n tiene el propÃ³sito de eliminar el Ruter elegido por el usuario,
se hace siguiendo estos pasos:

1) extraer los enlaces y ubicarlos en un mapa (estos para poder manippular los ruters con mayor facilidad)

2) buscar con ayuda de un iterador si el Reuter que dio el usuario estÃ¡ en el mapa (por que no puedes eliminar algo que no existe)
en la parte de key en la cual estÃ¡n los nombres de los Reuters conectados, y si se encuentra el Reuter se elimina dicho componente del mapa

3)se agrega a un archivo temporal la informaciÃ³n editada para poder hacer la actualizacion y se renombra despues este archivo y se elimina el anterior
 (Cosa que me hubiera gustado aprender o saber donde buscar para el lab 3 :Â´D )*/


    int x=0,pos,posinicio=0,posaux1=0,posaux2;
    string temp1,temp2,txtau,neu,temporal,txtguia,k;char router,ru=' ';

    ofstream Guardar;
    ofstream temp_txt;

    k="C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/rutas.txt";
    k+=doc;
    Guardar.open(k,ios::app);
    temp_txt.open("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/temporal.txt",ios::app);

    map<string,short> enlaces;
    map<string,short>::iterator it;

    string sacado=leer(doc);

    pos =sacado.find_first_of('.');

    for(unsigned int i=0;i<sacado.length();i++){
        if(i<pos){
            txtguia+=sacado.at(i);
        }

    }
    txtguia+=".";
    temp_txt<<txtguia<<endl;
    while(true){
        for(int i=posinicio;i < pos;i++){
            if(posinicio==0){
                for(unsigned int i=0;i<sacado.length();i++){
                    if(i>pos){
                        temp2+=sacado.at(i);
                    }

                }sacado=temp2;
                temp2="";
                pos=0;
                break;
            }
            else if(sacado.at(i)!=' '){
                temp1+=sacado.at(i);
            }
        }
        if (temp1!=""){
            posaux1=temp1.find_first_of(",");
            for(unsigned int i=0;i<temp1.length();i++){
                if(i>posaux1){
                    temp2+=temp1.at(i);
                }else if(temp1.at(i)!='-'){
                    txtau+=temp1.at(i);
                }
            }
            double num_double = std::stod(temp2);
            enlaces[txtau]=num_double;  //-> guardamos en el mapa
        }

        posinicio=pos+1;

        //Como en la funcion anterior se pasa la informacion a un string para poder manipularla mejor y guardarla mejor en el mapa

        for(unsigned int i=0;i<sacado.length();i++){
            if(i>pos){
                neu+=sacado.at(i);
            }

        }
        posaux2=neu.find_first_of('.');
        pos +=posaux2+1;
        neu="";
        temp2="";
        temp1="";
        txtau="";
        if(posaux2==-1){
            break;
        }
    }
    while (router!='1') {

        cout<<"********************************************"<<endl;
        cout<<"*      INGRESE EL ROUTER A ELIMINAR        *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"*                <ROUTER>                  *"<<endl;
        cout<<"*                                          *"<<endl;
        cout<<"********************************************"<<endl;
        cout<<"*             O 1 PARA SALIR               *"<<endl;
        cout<<"********************************************"<<endl;
        cin>>router;

        if(router!='1'){
            if(ru!=router){
                for(it=enlaces.begin();it!=enlaces.end();it++){
                    if(it->first[0]==router || it->first[1]==router){}
                    else{temporal+=it->first+"-" + to_string(it->second)+".";
                        temp_txt<<temporal<<endl;
                        temporal="";
                    }

                }

            }

            //Como en el proceso anterior se guar la informacion que no se borro en un archivo auxiliar para luego renombrarlo y guardar la informacion

            ru=router;
            temp_txt.close();
            Guardar.close();
            remove("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/topologia.txt");
            rename("C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/temporal.txt","C:/Users/maria/OneDrive/Documentos/INFO2-REPOSITORIO/Practica4-qt/Practica4/rutas/topologia.txt");
            cout<<"EL ROUTER "<<router<<" fue eliminado"<<endl;

            _sleep(3500);
            system("CLS");
        }
    }
}

void fu(char origen,char destino,map<string,short> enlaces,string ruta,short costo,routers r){

    /* LA FUNCION MAS GRANDE DE LA HISTORIA :D

    Esta funcion es la que hace posible la comparacion de las rutas con el costo de envio, siempre buscando la mas corta y la menos costosa!
    */


    map<string,short>::iterator it1;
    string rutaa;
    for (it1=enlaces.begin();it1!=enlaces.end();it1++){
        if(it1->first[0]==origen){
            if(ruta.find(it1->first[1])==-1){
                ruta+=it1->first;
                costo+=it1->second;
                if(it1->first[1]==destino){
                    if(cost[0]>costo){
                        rut[0]="";
                        rut[0]=ruta;
                        cost[0]=costo;
                        ruta="";
                        costo=0;

                        origen=ori;
                        return;
                    }
                }else{
                    if(ruta[ruta.size()-1]==origen){

                    }else{origen=it1->first[1];
                        fu(origen, destino, enlaces,ruta,costo,r);
                        origen=ruta[ruta.size()-2];
                        for(unsigned int i=0;i<ruta.size();i++){
                            if(i<ruta.size()-2){
                                rutaa+=ruta.at(i);
                            }

                        }
                        costo-=it1->second;
                        ruta=rutaa;
                    }


                }
            }

        }

    }
}

void BusquedaRutas(){

    /*EMPIEZA LA MAGIA!!!*/

    char origen,destino;
    string c,ruta;short costo;

    cout<<"********************************************"<<endl;
    cout<<"*      INGRESE DE LA DIGUIENTE FORMA       *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*          <ROUTER 1><ROUTER 1>            *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*             O -1 PARA SALIR               *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>c;

    if (c!="-1"){
        origen=c[0];destino=c[1];ori=c[0];
        int x=0,pos,posinicio=0,posaux1=0,posaux2;
        string temp1,temp2,txtau,neu;
        map<string,short> enlaces;
        string sacado=leer("rutas.txt");
        pos =sacado.find_first_of('.');
        while(true){
            for(int i=posinicio;i < pos;i++){
                if(posinicio==0){
                    for(unsigned int i=0;i<sacado.length();i++){
                        if(i>pos){
                            temp2+=sacado.at(i);
                        }

                    }sacado=temp2;
                    temp2="";
                    pos=0;
                    break;
                }
                else if(sacado.at(i)!=' '){
                    temp1+=sacado.at(i);
                }
            }
            if (temp1!=""){
                posaux1=temp1.find_first_of("-");
                for(unsigned int i=0;i<temp1.length();i++){
                    if(i>posaux1){
                        temp2+=temp1.at(i);
                    }else if(temp1.at(i)!='-'){
                        txtau+=temp1.at(i);
                    }
                }
                double num_double = std::stod(temp2);
                enlaces[txtau]=num_double;
            }

            posinicio=pos+1;

            for(unsigned int i=0;i<sacado.length();i++){
                if(i>pos){
                    neu+=sacado.at(i);
                }

            }
            posaux2=neu.find_first_of('.');
            pos +=posaux2+1;
            neu="";
            temp2="";
            temp1="";
            txtau="";
            if(posaux2==-1){
                break;
            }

        }
        map<string,short>::iterator it1;


        /*ATENCION!!!! PON MUCHO CUIDADO!!!!

    Dependiendo de lo que el usuario quiera buscar, ya sea el costo de envio o la ruta mas eficiente,
    la decicion se toma con -> J; el costo minimo se toma por la ruta mas
    eficiente de envio y la ruta mas corta por el menor costo de envio :D , genial no? */


        fu(origen, destino, enlaces,ruta,costo,r); //-> con la funcion fu calculamos las rutas mas cortas y comparamos constantemente para escoger la correcta
        if(j==0){
            cout<<"el costo minimo es: "<<cost[0]<<endl;
        }else if(j==1){
            cout<<"la ruta minima es: "<<rut[0]<<endl;
        }
    }
}

void BusquedaRutas2(string doc){

    /*EMPIEZA LA MAGIA!!!*/

    char origen,destino;
    string c,ruta;short costo;

    cout<<"********************************************"<<endl;
    cout<<"*      INGRESE DE LA DIGUIENTE FORMA       *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*          <ROUTER 1><ROUTER 1>            *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*             O -1 PARA SALIR               *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>c;

    if (c!="-1"){

        origen=c[0];destino=c[1];ori=c[0];
        int x=0,pos,posinicio=0,posaux1=0,posaux2;

        string temp1,temp2,txtau,neu;

        map<string,short> enlaces;

        string sacado=leer(doc);

        pos =sacado.find_first_of('.');

        while(true){
            for(int i=posinicio;i < pos;i++){
                if(posinicio==0){
                    for(unsigned int i=0;i<sacado.length();i++){
                        if(i>pos){
                            temp2+=sacado.at(i);
                        }

                    }sacado=temp2;
                    temp2="";
                    pos=0;
                    break;
                }
                else if(sacado.at(i)!=' '){
                    temp1+=sacado.at(i);
                }
            }
            if (temp1!=""){
                posaux1=temp1.find_first_of("-");
                for(unsigned int i=0;i<temp1.length();i++){
                    if(i>posaux1){
                        temp2+=temp1.at(i);
                    }else if(temp1.at(i)!=','){
                        txtau+=temp1.at(i);
                    }
                }
                double num_double = std::stod(temp2);
                enlaces[txtau]=num_double;
            }

            posinicio=pos+1;

            for(unsigned int i=0;i<sacado.length();i++){
                if(i>pos){
                    neu+=sacado.at(i);
                }

            }
            posaux2=neu.find_first_of('.');
            pos +=posaux2+1;
            neu="";
            temp2="";
            temp1="";
            txtau="";
            if(posaux2==-1){
                break;
            }

        }
        map<string,short>::iterator it1;

        /*ATENCION!!!! PON MUCHO CUIDADO!!!!

        Dependiendo de lo que el usuario quiera buscar, ya sea el costo de envio o la ruta mas eficiente,
        la decicion se toma con -> J; el costo minimo se toma por la ruta mas
        eficiente de envio y la ruta mas corta por el menor costo de envio :D , genial no? */

        fu(origen, destino, enlaces,ruta,costo,r); //-> con la funcion fu calculamos las rutas mas cortas y comparamos constantemente para escoger la correcta
        if(j==0){
            cout<<"el costo minimo es: "<<cost[0]<<endl;
        }else if(j==1){
            cout<<"la ruta minima es: "<<rut[0]<<endl;
        }
    }
}

bool Menu()//Este menu es para cuando las rutas deben ser ingresadas manualmente por el usuario
{
    int opcion;
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.AGREGAR ROUTER                       *"<<endl;
    cout<<"*   2.BORRAR ROUTER                        *"<<endl;
    cout<<"*   3.COSTO ENVIO <R1-R2>                  *"<<endl;
    cout<<"*   4.RUTA ENVIO <Ri-R2>                   *"<<endl;
    cout<<"*   5.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;

    switch (opcion) {

    case 1:
        system("CLS");
        AgregarRouter();
        break;

    case 2:
        system("CLS");
        BorrarRouter();
        break;

    case 3:
        system("CLS");
        j=0;
        BusquedaRutas();
        _sleep(2000);
        return true;

    case 4:
        system("CLS");
        j=1;
        BusquedaRutas();
        _sleep(2000);
        return true;

    case 5:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;

    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADAÂ¡            *"<<endl;
                cout<<"********************************************"<<endl;
        break;
    }

}

bool Menu2() //Este menu es para cuando las rutas se extraen de un txt
{
    int opcion;
    string doc;
    cout<<"INGRESE NOMBRE DEL DOCUMENTO TERMINADO EN .TXT"<<endl;
    cin>>doc;
    system("CLS");

    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.AGREGAR ROUTER                       *"<<endl;
    cout<<"*   2.BORRAR ROUTER                        *"<<endl;
    cout<<"*   3.COSTO ENVIO <R1-R2>                  *"<<endl;
    cout<<"*   4.RUTA ENVIO <Ri-R2>                   *"<<endl;
    cout<<"*   5.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;

    switch (opcion) {

    case 1:
        system("CLS");
        AgregarRouter2(doc);
        break;

    case 2:
        system("CLS");
        cout<<"INGRESE NOMBRE DEL DOCUMENTO ";
        cin>>doc;
        BorrarRouter2(doc);
        break;

    case 3:
        system("CLS");
        j=0;
        BusquedaRutas2(doc);
        _sleep(2000);
        return true;

    case 4:
        system("CLS");
        j=1;
        BusquedaRutas2(doc);
        _sleep(2000);
        return true;

    case 5:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;

    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADAÂ¡            *"<<endl;
                cout<<"********************************************"<<endl;
        break;
    }

}

bool Menu_()//Este es el menu principal, con el cual se escoge con cual de los dos menus anteriores se quiere trabajar
    //Este tambien es el que se invoca en el main!
{
    int opcion;
    bool x;
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.TRABAJAR CON RUTAS.TXT               *"<<endl;
    cout<<"*   2.CARGAR DOCUMENTO                     *"<<endl;
    cout<<"*   3.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;

    switch (opcion) {

    case 1:
        system("CLS");
        x=Menu();
        return x;

    case 2:
        system("CLS");
        x=Menu2();
        return x;

    case 3:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        return false;

    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADAÂ¡            *"<<endl;
                cout<<"********************************************"<<endl;
        break;
    }
}
