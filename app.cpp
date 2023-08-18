#include <iostream> 
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int opciones(vector<int> user);
int agregar();


void promedioVector(const char* valor);
void modaVector(const char* valor); 
void contarElem(const char* valor);

int main(int argc, char *argv[]){
    int opcion;
    int seleccionada;
    string usuario;
    const char* valor;
    while ((opcion = getopt(argc, argv, "u:v:")) != -1) {
        switch (opcion) {
            case 'u':
                usuario = optarg;
                break;
            case 'v':
                valor = optarg;
                break;
            default:
                cerr << "Uso: " << argv[0] << " -u usuario -v valor" << endl;
                return 1;
        }
    }

    ifstream file("basededatos.txt");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    bool encontrarUsuario = false;
    string line;
    vector<int> numeros;
    while (getline(file, line)) {
        size_t pos = line.find(usuario);
        if (pos != string::npos) {
                string numerosStr = line.substr(pos + usuario.length() + 1); 
                istringstream numerosStream(numerosStr);
                int numero;

                while (numerosStream >> numero) {
                    numeros.push_back(numero);
                    char coma;
                    numerosStream >> coma; 
                }

                encontrarUsuario = true;
                break; 
            }
        }

    if (encontrarUsuario) {
        cout << "Usuario encontrado en el archivo." << endl;
    } else {
        cout << "Usuario no registrado en la base de datos." << endl;
        return 1;
    }
    
 
    seleccionada = opciones(numeros);
    
    file.close();

    if(seleccionada == 1){
        promedioVector(valor);
        return 1;
    }
    else if( seleccionada == 2){
        modaVector(valor);
        return 1;
    }
     else if( seleccionada == 3){
        contarElem(valor);
        return 1;
    }
     else if( seleccionada == 4){
       agregar();
       return 1;
    }


    return 0;
    }

int opciones(vector<int> user) { 
    int n;
    
    bool opc1 = false;
    bool opc2 = false;
    bool opc3 = false;
    bool opc4 = false;

    for (int i = 0; i < user.size(); i++) {
        if (user[i] == 1) {
            cout << "1) realizar promedio del vector" << endl;
            opc1 = true;
        }
        if (user[i] == 2) {
            cout << "2) realizar moda del vector" << endl;
            opc2 = true;
        }
        if (user[i] == 3) {
            cout << "3) contar elementos del vector" << endl;
            opc3 = true;
        }
        if (user[i] == 4) {
            cout << "4) Agregar usuario" << endl;
            opc4 = true;
        }
    }

    cin >> n;
    while(n>=5 || n <= 0 || (opc1 && n == 1) || (!opc2 && n == 2) || (!opc3 && n == 3) || (!opc4 && n == 4)){
        cout << "Opcion no existente, intentelo denuevo: ";
        cin >> n;
    }
    return n;
}




void promedioVector(const char* valor){
    int sum = 0;
    int count = 0;

    int numInicio = 0;
    for (int i = 0; valor[i] != '\0'; ++i) {
        if (valor[i] == ',') {
            int num = stoi(string(valor + numInicio, i - numInicio));
            sum += num;
            numInicio = i + 1;
            count++;
        }
    }
    
    int num = stoi(string(valor + numInicio));
    sum += num;
    count++;

    if (count > 0) {
        float promedio = static_cast<float>(sum) / count;
        cout << "El promedio es: " << promedio << endl;
    } else {
        cout << "No se encontraron números en la cadena." << endl;
    }
}
void modaVector(const char* valor ){
    
    map<int, int> frecuencia; 

    int numInicio = 0;
    for (int i = 0; valor[i] != '\0'; ++i) {
        if (valor[i] == ',') {
            int num = stoi(string(valor + numInicio, i - numInicio));
            frecuencia[num]++;
            numInicio = i + 1;
        }
    }
    
    int num = stoi(string(valor + numInicio));
    frecuencia[num]++;

    int moda = 0;  
    int maxfrecuencia = 0;

    for (const auto& pair : frecuencia) {
        if (pair.second > maxfrecuencia) {
            maxfrecuencia = pair.second;
            moda = pair.first;
        }
    }

    if (maxfrecuencia > 1) {
        cout << "La moda es: " << moda << endl;
    } else {
        cout << "No hay moda en los números." << endl;
    }


}

void contarElem(const char* valor){
    int cont = 1;
    for(int i = 0; i < strlen(valor);i++){
        if(valor[i] == ',')
            cont++;
    }

    cout << "Se ingresaron " << cont << " elementos" << endl;
}


int agregar() {

    string username;
    cout << "Ingrese el nombre de usuario(recuerde darle permisos desde 1 al 4 separados por una coma y que termine en ;): ";
    cin >> username;

    ofstream file("basededatos.txt", ios::app); 
    if (!file.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    file << username << "\n"; 

    cout << "Usuario agregado exitosamente." << endl;

    file.close();

    return 0;
}

//Ejecucion, app -u juanito -v 1,2,3,4,5
