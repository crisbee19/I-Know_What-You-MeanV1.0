//Cristian Padilla Soto
//Alannis Rubianes Febo
#include <iostream>
#include <fstream>
/*
"fstream" le brinda la funcionalidad de poder
tener entrada y salida de archivos
*/
#include <sstream>
/*
"sstream" es similar a la librería string  solo que esta funciona
construyendo, manipulando y extrayendo datos de cadena de carácteres.
*/
#include <vector>
/*/
"Los vectores dan varias herramientas como almacenar, acceder, insertar elementos
de un amanera mas eficiente, en otras palabras, acceso dinamico.
*/
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;

// Function to encode the original message into random words
/*
Esta función codifica el mensaje que es entrado por el usuario y es convertido en
*/
string codificar(const string& msgOG) {
    stringstream msgcode;
    istringstream leer(msgOG);
    //
    string word;
    while (leer >> word) {
        msgcode << word[0];
    }
    return msgcode.str();
}

// Function to decode the random words back into the original message
/*
Esta función decodifica las palabras aleatorias que fueron randomizadas en la
función anterior
*/
string decodificar(const string& mensajeCodificado) {
    stringstream decodedMessage;
    istringstream leer(mensajeCodificado);
    string letra;
    while (leer >> letra) {
        decodedMessage << letra << " ";
    }
    return decodedMessage.str();
}

// Function to write encoded message to a text file
void escribirArchivo(const string& mensajeCodificado) {
    ofstream outfile("mensaje_codificado.txt");
    if (outfile.is_open()) {
        outfile << mensajeCodificado;
        outfile.close();
    }
    else {
        cerr << "No se puede abrir el archivo, intente de nuevo.";
    }
}

// Function to read encoded message from a text file
string leerArchivo() {
    ifstream infile("mensaje_codificado.txt");
    stringstream buffer;
    buffer << infile.rdbuf();
    return buffer.str();
}

void BorrarPantalla() {
    system("cls");
}

int main() {
    int decision;
    string mensaje;
    bool validez = false;
    while (!validez) {
        cout << "\n";
        cout << "¡Bienvenido a I-Know-What-You-Mean! \n";
        cout << endl;
        cout << "******************************************** \n";
        cout << endl;
        cout << "Por favor entre el 1 para entrar su frase secreta o el 2 para revelar su significado oculto:  \n";
        cin >> decision;
        cin.ignore();
        if (decision == 1) {
            validez = true;
        }
        else {

            BorrarPantalla();
            cout << endl;
            cerr << "ERROR, numero tiene que ser 1 o 2! \n";
            Sleep(2000);
        }
    }
    if (decision == 1) {
        cout << "Por favor entre el mensaje que quiere codificar: ";
        getline(cin, mensaje);
        string codificado = codificar(mensaje);
        escribirArchivo(codificado);
        cout << "El mensaje codificado ha sido guardado!" << endl;
        string msgOG = leerArchivo();
        string msgcode = decodificar(msgOG);
        cout << "El mensaje oculto es : " << msgcode << endl;
    }

    return 0;
}