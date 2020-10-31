#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct FileData
{
    string name;// Nombre del archivo
    long size;// El tamaño en bytes
};
FileData files[1000];
int numberOfFiles=0;// Número de archivos que ya tenemos
int i;// Para bucles
int option;// La option del menu que elija el usuario

string tempText;// Para pedir datos al usuario
int tempNumber;

void cargar();
void guardar();

int main()
{
    //FileData* files = new FileData[1000];
    cargar();

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;

        cin >> option;

        // Hacemos una cosa u otra según la opción escogida
        switch(option)
        {
            case 1: // Añadir un dato nuevo
                if (numberOfFiles < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del archivo: ";
                    cin.sync();
                    getline(cin, files[numberOfFiles].name);
                    cout << "Introduce el tamaño en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;  // Y tenemos una ficha más
                }
                else   // Si no hay hueco para más archivos, avisamos
                    cout << "¡Máximo de archivos alcanzado (1000)!" << endl;
                break;

            case 2: // Mostrar todos
                for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tamaño: " << files[i].size
                        << "Kb" << endl;
                break;

            case 3: // Mostrar según el tamaño
                cout << "¿A partir de que tamaño quieres que te muestre? ";
                cin >> tempNumber;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;

            case 4: // Ver todos los datos (pocos) de un archivo
                cout << "¿De qué archivo quieres ver todos los datos?";
                cin >> tempText;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;

            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opción: no válida
                cout << "¡Opción desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opción es 5, terminamos

    guardar();
    return 0;
}

void cargar(){
    ifstream archivo;
    int i = 0;
    archivo.open("FilesData.txt");

    if (archivo.is_open())
    {
        do{

            archivo >> files[i].size;
            getline(archivo, files[i].name);
            cout<<"Cargando"<<endl;
            i++;
        }
        while (!archivo.eof());

        numberOfFiles = i;
    }
    else
        cout<<"No se encontró el archivo"<<endl;
    archivo.close();
    return;
}

void guardar()
{
    ofstream archivo;
    archivo.open("FilesData.txt");

    for (int i = 0; i<numberOfFiles; i++)
        {
            archivo<<files[i].size<<" "<<files[i].name<<endl;
        }
    archivo.close();
    return;
}

