#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante 
{
    string nombre;
    int identificador;
    int calificacion;
    //int &calif = calificacion;
};
int Menu();
int Menu()
 {
    int respuesta;
    cout<<"Ingrese una opcion para continuar"<<endl;
    cout<<""<<endl;
    cout<<"1. Agregar estudiante"<<endl;
    cout<<"2. Actualizar calificaciones de un estudiante"<<endl;
    cout<<"3. Buscar estudiantes por su identificador"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>respuesta;
    return respuesta;
}

vector<Estudiante> estudiantes;
void agregarEstudiante() 
{
    Estudiante estudiante;
    cout << "Escriba el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Escriba un identificador del estudiante: (numero) ";
    cin >> estudiante.identificador;
    cout << "Escriba una calificación para el estudiante: ";
    cin >> estudiante.calificacion;
    
    estudiantes.push_back(estudiante);
    cout << "El estudiante " << estudiante.nombre << " ha sido agregado." << endl;
}

void actualizarCalificacion() 
{
    int identificador;

    cout << "Lista de estudiantes:" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        cout << "Identificador: " << estudiante.identificador
             << ", Nombre: " << estudiante.nombre
             << ", Calificacion: " << estudiante.calificacion << endl;
    }
    
    cout << "Ingrese el identificador del estudiante: ";
    cin >> identificador;
    bool encontrado = false;
    for (auto& estudiante : estudiantes) 
	{
        if (estudiante.identificador == identificador) 
		{
            cout << "Ingrese la nueva calificación del estudiante: ";
            int &calif=estudiante.calificacion;
            cin >> calif;
            cout << "La calificación del estudiante " << estudiante.nombre << " se actualizo." << endl;
            encontrado = true;
        }
    }
    if (!encontrado) 
	{
        cout << "No se encontró estudiante con ese identificador." << endl;
    }
}
void buscarEstudiante()
{
    int identificador_buscado;
                bool encontrado = false;
                cout << "Ingresa el identificador del estudiante a buscar: ";
                cin >> identificador_buscado;
                for (auto& estudiante : estudiantes) 
				{
                    if (estudiante.identificador == identificador_buscado) 
					{
                        encontrado = true;
                        Estudiante* ptr_estudiante = &estudiante;
                        cout << "Estudiante encontrado: " << endl;
                        cout << "Nombre: " << ptr_estudiante->nombre << endl;
                        cout << "Identificador: " << ptr_estudiante->identificador << endl;
                        cout << "Calificación: " << ptr_estudiante->calificacion << endl;
                    break;
                    }
                }
                if (!encontrado) 
				{
                    cout << "No se encontro estudiante " << endl;
                }
}
int main()
{
int opcion;
    do 
	{
        opcion = Menu();
        switch (opcion) 
		{
            case 1:
                agregarEstudiante();
                break;
            case 2:
                actualizarCalificacion();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Vuelva a intentar." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}