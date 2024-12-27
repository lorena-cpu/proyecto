#include <iostream>
#include <vector>
#include <string>
using namespace std;
class SuperClase {
protected:
    string mensaje;
public:
    SuperClase(string msg = "Mensaje de la SuperClase") : mensaje(msg) {}
    virtual void mostrarMensaje() const {
        cout << "SuperClase: " << mensaje << endl;
    }

    friend class ClaseAmiga;
};

class Hija : public SuperClase {
public:
    Hija(string msg = "Mensaje de la Hija") : SuperClase(msg) {}

    void mostrarMensaje() const override {
        cout << "Hija: " << mensaje << endl;
    }
};

class ClaseAmiga {
public:
    void modificarMensaje(SuperClase &superClase, const string &nuevoMensaje) {
        superClase.mensaje = nuevoMensaje;
    }

    void mostrarMensaje(const SuperClase &superClase) const {
        cout << "ClaseAmiga mostrando: " << superClase.mensaje << endl;
    }
};
class Alumno {
private:
    string nombre;
    string numero;
    string dni;
    string colegio;

public:
    Alumno(string n, string num, string d, string col) 
        : nombre(n), numero(num), dni(d), colegio(col) {}

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero de telefono: " << numero << endl;
        cout << "DNI: " << dni << endl;
        cout << "Colegio: " << colegio << endl;
    }

    string getNombre() const {
        return nombre;
    }
};

class SistemaAlumnos {
private:
    vector<Alumno> alumnos;

public:
    void agregarAlumno() {
        string nombre, numero, dni, colegio;

        cout << "Ingrese los datos del alumno:" << endl;
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Numero de telefono: ";
        getline(cin, numero);
        cout << "DNI: ";
        getline(cin, dni);
        cout << "Colegio: ";
        getline(cin, colegio);

        Alumno nuevoAlumno(nombre, numero, dni, colegio);
        alumnos.push_back(nuevoAlumno);
cout << "Alumno agregado exitosamente!" << endl;
    }

    void mostrarAlumnos() const {
        cout << "\n--- Lista de Alumnos ---" << endl;
        for (const auto& alumno : alumnos) {
            alumno.mostrarDatos();
            cout << "------------------------" << endl;
        }
    }

    void buscarAlumno() const {
        string nombreBuscado;
        cout << "Ingrese el nombre del alumno a buscar: ";
        getline(cin, nombreBuscado);

        bool encontrado = false;
        for (const auto& alumno : alumnos) {
            if (alumno.getNombre() == nombreBuscado) {
                alumno.mostrarDatos();
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Alumno no encontrado." << endl;
        }
    }
    void bienvenida() const {
        cout << "Bienvenido " << endl;
        cout << "A continuacion, vamos a tomar sus datos. " << endl;
    }

    void menu() {
        int opcion;
        do {
            cout << "\n--- Menu ---" << endl;
            cout << "1. Agregar Alumno" << endl;
            cout << "2. Mostrar Alumnos" << endl;
            cout << "3. Buscar Alumno" << endl;
            cout << "4. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1:
                    agregarAlumno();
                    break;
                case 2:
                    mostrarAlumnos();
                    break;
                case 3:
                    buscarAlumno();
                    break;
                case 4:
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion inválida, intente de nuevo." << endl;
            }
        } while (opcion != 4);
    }
};
class Curso {
private:
    string nombre;

public:
    Curso(string n) : nombre(n) {}
    void mostrar() const {
        cout << nombre << endl;
    }
    string getNombre() const {
        return nombre;
    }
};
class CEPRE {
private:
    int ciclo;
    Curso* cursos[10]; 

public:
    CEPRE() {
        cursos[0] = new Curso("razonamiento matematico");
        cursos[1] = new Curso("Fisica ");
        cursos[2] = new Curso("razonamiento verbal");
        cursos[3] = new Curso("trigonometria");
        cursos[4] = new Curso("Quimica ");
        cursos[5] = new Curso("Biologia");
        cursos[6] = new Curso("humanidades");
        cursos[7] = new Curso("algebra");
        cursos[8] = new Curso("geometria");
        cursos[9] = new Curso("aritmetica");
    }
    ~CEPRE() {
        for (int i = 0; i < 10; ++i) {
            delete cursos[i]; 
        }
    }
    void mostrarCursos() const {
        cout << "\nCursos matriculados:" << endl;
        for (int i = 0; i < 10; ++i) {
            cout << i + 1 << ". ";
            cursos[i]->mostrar(); 
        }
    }

    void ingresarCiclo() {
        cout << "\nPor favor, ingresa el ciclo que deseas matricularte: ";
        cin>>ciclo;  
    }
    void mostrarCiclo() const {
        if (ciclo == 1){
            cout<<"te matriculaste en el ciclo 1, vas a tomar 3 examenes 2 examenes valen 30% y el ultimo vale 40% ";
        } else if(ciclo == 2){
            cout<<"te matriculaste en el ciclo 2, vas a tomar 4 examenes 3 examens velen 20% y el ultimo vale 40%";
        }else if (ciclo == 3){
            cout<<"te matriculaste en el ciclo 2, vas a tomar 4 examenes 3 examens velen 20% y el ultimo vale 40% ";
        } else 
            cout<<"solo puede elegir de 1 al 3 ";
        
    }
    void bienvenida() const {
        cout << "Bienvenido a la CEPRE-UNAS 2024 " << endl;
        cout << "A continuacion, veras las opciones a elegir. " << endl;
    }
   void menu() {
       int opcion;
        do {
            cout << "\n--- Menu ---" << endl;
            cout << "1. matricularse en el ciclo correspondiente " << endl;
            cout << "2. cursos que se van a dictar " << endl;
            cout << "3. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1:
                   ingresarCiclo();
                   mostrarCiclo();
                    break;
                case 2:
                    mostrarCursos();
                    break;
                case 3:
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opcion inválida, intente de nuevo." << endl;
            }
        } while (opcion != 3);
    };
};
class Estudiante {
private:
    vector<float> notas;
    float promedio;
   
public:
   
    void ciclo1() {
        cout << "Introduce las 3 notas del curso:" << endl;
        notas.clear(); 
        for (int i = 0; i < 3; i++) {
            float nota;
            cout << "Nota " << i + 1 << ": ";
            cin >> nota;
            notas.push_back(nota);
        }
        calcularPromedio();
    }
    void ciclo2y3() {
        cout << "Introduce las 4 notas del curso:" << endl;
        notas.clear(); 
        for (int i = 0; i < 4; i++) {
            float nota;
            cout << "Nota " << i + 1 << ": ";
            cin >> nota;
            notas.push_back(nota);
        }
        calcularPromedio();
    }
    void calcularPromedio() {
        promedio = 0;
        for (float nota : notas) {
            promedio += nota;
        }
        promedio /= notas.size();
    }
    void mostrarPromedio() const {
        cout << "Tu promedio es: " << promedio << endl;
        if (promedio >= 10.5) {
            cout << "Felicidades Has aprobado." << endl;
        } else {
            cout << "Lo siento, no has aprobado." << endl;
        }
    }
};
void mostrarBienvenida() {
    cout << "vamos a realizar una simulacion " << endl;
}
void mostrarMenu(Estudiante &estudiante) {
    int opcion;
    do {
        cout << "ingrese el ciclo matriculado " << endl;
        cout << "1. si es ciclo I" << endl;
        cout << "2. si es ciclo II" << endl;
        cout << "3. si es ciclo III" << endl;
        cout << "4. Ver promedio" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                estudiante.ciclo1();
                break;
            case 2:
                estudiante.ciclo2y3();
                break;
            case 3:
                estudiante.ciclo2y3();
                break;
            case 4:
                estudiante.mostrarPromedio();
                break;
            case 5:
                cout << "Gracias por usar el sistema. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elige una opción válida." << endl;
        }
    } while (opcion != 4);
}
int main() {
    SistemaAlumnos sistema;
    sistema.bienvenida();
    sistema.menu();
    CEPRE cepre;
    cepre.bienvenida();
    cepre.menu();
    Estudiante estudiante;
    mostrarBienvenida();
    mostrarMenu(estudiante);
    return 0;
}
