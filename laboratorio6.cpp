#include <iostream>
#include <cstring>  
using namespace std;

struct Direccion {
    char calle[50];
    int numero;
    char ciudad[50];
};

struct Estudiante {
    char nombre[50];
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante *estudiantes, int &cantidad);
void mostrarEstudiantes(Estudiante * estudiantes, int cantidad);
int buscarEstudiante(Estudiante * estudiantes, int cantidad, const char * nombreBuscado);
void modificarEstudiante(Estudiante *estudiantes, int cantidad);

int main() {
    const int MAX_ESTUDIANTES = 100;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad = 0;
    int opcion;

    do {
        cout << "=== MENU DE GESTION DE ESTUDIANTES ===" << endl;
        cout << "1. Ingresar estudiante " << endl;
        cout << "2. Mostrar estudiantes " << endl;
        cout << "3. Buscar estudiante " << endl;
        cout << "4. Modificar estudiante " << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            ingresarEstudiantes(estudiantes, cantidad);
            break;

        case 2:
            if (cantidad > 0)
                mostrarEstudiantes(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados.";
            break;

        case 3:
            if (cantidad > 0) {
                char nombreBuscado[60];
                cout << "Ingrese el nombre del estudiante a buscar: ";
                cin.getline(nombreBuscado, 60);
                int pos = buscarEstudiante(estudiantes, cantidad, nombreBuscado);
                if (pos != -1) {
                    cout << "--- Estudiante encontrado ---";
                    cout << "Nombre: " << estudiantes[pos]. nombre << endl;
                    cout << "Edad: " << estudiantes[pos].edad << endl;
                    cout << "Direccion: " << estudiantes[pos].direccion.calle << " "
                         << estudiantes[pos].direccion.numero << ", "
                         << estudiantes[pos].direccion.ciudad << endl;
                    cout << "Calificaciones: ";
                    for (int i = 0; i < 5; i++)
                        cout << estudiantes[pos].calificaciones[i] << " ";
                    cout << endl;
                } else {
                    cout << "Estudiante no encontrado.";
                }
            } else {
                cout << "No hay estudiantes registrados.";
            }
            break;

        case 4:
            if (cantidad > 0)
                modificarEstudiante(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados.";
            break;

        case 5:
            cout << "Saliendo del programa.";
            break;

        default:
            cout << "Opcion no valida.";
        }

    } while (opcion != 5);

    return 0;
}

void ingresarEstudiantes(Estudiante *estudiantes, int &cantidad) {
    cout << "=== Ingresar nuevo estudiante ===" << endl;
    cout << "Nombre: ";
    cin.getline(estudiantes[cantidad]. nombre, 50);

    cout << "Edad: ";
    cin >> estudiantes[cantidad].edad;

    cout << "Ingrese las 5 calificaciones:";
    for (int j = 0; j < 5; j++) {
        cout << "Calificacion " << j + 1 << ": ";
        cin >> estudiantes[cantidad].calificaciones[j];
    }
    cin.ignore();

    cout << "Calle: ";
    cin.getline(estudiantes[cantidad].direccion.calle, 50);
    cout << "Numero: ";
    cin >> estudiantes[cantidad].direccion.numero;
    cin.ignore();

    cout << "Ciudad: ";
    cin.getline(estudiantes[cantidad].direccion.ciudad, 50);

    cantidad++;
    cout << "Estudiante agregado correctamente.";
}

void mostrarEstudiantes(Estudiante *estudiantes, int cantidad) {
    cout << "=== LISTA DE ESTUDIANTES ===";
    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante #" << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i]. nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Direccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++)
            cout << estudiantes[i].calificaciones[j] << " ";
        cout << endl;
    }
}


int buscarEstudiante(Estudiante *estudiantes, int cantidad, const char * nombreBuscado) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(estudiantes[i]. 
        nombre, nombreBuscado) == 0)
            return i;
    }
    return 0;
}

void modificarEstudiante(Estudiante *estudiantes, int cantidad) {
    char nombreBuscado[50];
    cout << "Ingrese el nombre del estudiante a modificar: ";
    cin.ignore();
    cin.getline(nombreBuscado, 50);

    int pos = buscarEstudiante(estudiantes, cantidad, nombreBuscado);
    if (pos != -1) {
        cout << "--- Modificando datos del estudiante ---";

        cout << "Nuevo nombre: ";
        cin.getline(estudiantes[pos].nombre, 50);

        cout << "Nueva edad: ";
        cin >> estudiantes[pos].edad;

        cout << "Nuevas calificaciones:";
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> estudiantes[pos].calificaciones[j];
        }

        cin.ignore();
        cout << "Nueva calle: ";
        cin.getline(estudiantes[pos].direccion.calle, 50);

        cout << "Nuevo numero: ";
        cin >> estudiantes[pos].direccion.numero;
        cin.ignore();

        cout << "Nueva ciudad: ";
        cin.getline(estudiantes[pos].direccion.ciudad, 50);

        cout << "Datos modificados correctamente.";
    } else {
        cout << "Estudiante no encontrado.";
    }
}
