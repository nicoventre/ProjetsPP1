#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MaxAlumnos = 100;
typedef struct {
    string fecha;
    string nombre;
    string apellido;
    int estado;
} tRegistro;

typedef tRegistro tArray[MaxAlumnos];
typedef struct {
    tArray registro;
    int contador;
} tLista;

tLista lista;

void cargar();
void seleccion(int op);
void agregar();
void marcar();
void mostrar();
void mostrar_todo();
void guardar();
int main (void){
    int op;
    cargar();

    do
    {
        cout<<"Ingrese la opcion deseada: "<<endl;
        cout<<"1: Agregar alumno"<<endl;
        cout<<"2: Marcar asistencia o ausencia"<<endl;
        cout<<"3: Mostrar los alumnos ausentes"<<endl;
        cout<<"4: Mostrar toda la lista"<<endl;
        cout<<"0: Salir"<<endl;
        cin>>op;
        seleccion(op);
    }
    while (op!=0);
    guardar();

}

void cargar(){
    ifstream archivo;
    int i = 0;
    archivo.open("asistencia.txt");

    if (archivo.is_open())
    {
        do{
            archivo >> lista.registro[i].fecha >> lista.registro[i].nombre >> lista.registro[i].apellido >> lista.registro[i].estado;
            i++;
        }
        while (!archivo.eof());
        lista.contador = i-1;
    }
    else
        cout<<"No se encontró el archivo"<<endl;
    archivo.close();
    return;
}
void seleccion(int op){

    switch (op){
        case 1: agregar();
        break;
        case 2: marcar();
        break;
        case 3: mostrar();
        break;
        case 4: mostrar_todo();
        break;
        }
    return;
}

void agregar(){
    cout<<"Ingrese el nombre del nuevo alumno: "<<endl; cin>>lista.registro[lista.contador].nombre;
    cout<<"Ingrese el apellido del nuevo alumno: "<<endl; cin>>lista.registro[lista.contador].apellido;
    cout<<"Ingrese la fecha (DD/MM/AAAA): "<<endl; cin>>lista.registro[lista.contador].fecha;
    lista.registro[lista.contador].estado = 1;
    lista.contador++;
    return;
}
void marcar(){
    cout<<"A continuaicion se muestran los alumnos de la lista..."<<endl;
    cout<<"Ingrese 1 junto al alumno para registrar presente"<<endl;
    cout<<"Ingrese 0 junto al alumno para registrar ausente"<<endl;
    for (int i=0; i<lista.contador; i++)
    {
        cout<<lista.registro[i].fecha<<" || "<<lista.registro[i].nombre<<" "<<lista.registro[i].apellido<<": "; cin>>lista.registro[i].estado;
    }
    return;
}

void mostrar(){
    cout<<"Los alumnos ausentes son: "<<endl;
    for (int i = 0; i<lista.contador; i++){
        if (lista.registro[i].estado==0)
            cout<<lista.registro[i].fecha<<" || "<<lista.registro[i].nombre<<" "<<lista.registro[i].apellido<<endl;
    }
    return;
}

void mostrar_todo(){
    cout<<"Lista de alumnos"<<endl;
    for (int i=0; i<lista.contador; i++)
        cout<<lista.registro[i].fecha<<" || "<<lista.registro[i].nombre<<" "<<lista.registro[i].apellido<<endl;
    return;
}

void guardar()
{
    ofstream archivo;
    archivo.open("asistencia.txt");

    for (int i = 0; i<lista.contador; i++)
        {
            archivo<<lista.registro[i].fecha<<" "<<lista.registro[i].nombre<<" "<<lista.registro[i].apellido<<" "<<lista.registro[i].estado<<endl;
        }
    archivo.close();
    return;
}

