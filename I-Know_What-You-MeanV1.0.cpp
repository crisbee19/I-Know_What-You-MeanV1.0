// ************************************************************************************************************************************************************************************************************

                                                                                             // I-Know-What-You-Mean
                                                                                             // Cristian Padilla Soto
                                                                                             // Alannis Rubianes Febo

// ************************************************************************************************************************************************************************************************************

#include <iostream>

#include <fstream> // "fstream" le brinda la funcionalidad de poder tener entrada y salida de archivos

#include <sstream> // es similar a la librería string solo que esta funciona construyendo, manipulando y extrayendo datos de cadena de carácteres.

#include <vector> // Los vectores dan varias herramientas como almacenar, acceder, insertar elementos de un amanera mas eficiente, en otras palabras, acceso dinamico.

#include <Windows.h>

#include <chrono>

#include <thread>

#include <string>

#include <ctime>

#include <cstdlib>

using namespace std;

// ************************************************************************************************************************************************************************************************************



// ********************************************************************************************* FUNCIONES *****************************************************************************************************



// Function to encode the original message into random words

string codificar(const string& msgOG) {
    stringstream msgcode;
    istringstream leer(msgOG);
    string word;
    while (leer >> word) {
        msgcode << word[0];
    }
    return msgcode.str();
}

// Function to decode the random words back into the original message

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

// Function to clear screen

void BorrarPantalla() {
    system("cls");
}

// This array contains the words that'll replace each letter in the user's message

const string wordArray[26][6] = { // Defined as a constant since the dimensions will never change

        {"Airplane", "Apple", "Anchor", "Ant", "Army", "Armor"},
        {"Bird", "Boat", "Bar", "Beach", "Brother", "Blanket"},
        {"Cat", "Chair", "Candle", "Clock", "Car", "Couch"},
        {"Door", "Dice", "Date", "Drum", "Doubt", "Deed"},
        {"Eat", "Earth", "Egg", "Elf", "Elephant", "Easy"},
        {"Fun", "Friend", "Forward", "Face", "Fall", "Farm"},
        {"Ghost", "Gear", "Game", "Gift", "Glass", "Gate"},
        {"Habit", "Hint", "Hope", "Heat", "Hero", "Honor"},
        {"Ice", "Ink", "Insect", "Iguana", "Internet", "Item"},
        {"Jacket", "Jade", "Japan", "Jet", "Job", "Jazz"},
        {"Kangaroo", "Karma", "Keyboard", "Kitten", "Kite", "Keeper"},
        {"Lake", "Lamp", "Llama", "Lock", "Leader", "Leather"},
        {"Modern", "Magic", "Marvel", "Manager", "Model", "Monitor"},
        {"Navy", "Notion", "Name", "Niece", "New", "Nothing"},
        {"Oasis", "Ocean", "Office", "Oath", "One", "Offer"},
        {"Patience", "Prize", "Play", "Praise", "Palace", "Pacific"},
        {"Quality", "Question", "Quiz", "Quarter", "Quick", "Quart"},
        {"Rat", "Rabbit", "Rent", "Rope", "Radar", "Run"},
        {"Sabotage", "Sail", "Serenity", "Sea", "Sense", "Secret"},
        {"Team", "Table", "Time", "Tent", "Together", "Tear"},
        {"Umbrella", "Universe", "Ultimatum", "Union", "Unit", "Uber"},
        {"Van", "Vase", "Valuable", "Visitor", "Vault", "Veil"},
        {"Weather", "Work", "Wallet", "Water", "Winner", "Web"},
        {"Xylophone", "Xenon", "Xmas", "Xray", "Xiaosaurus", "Xerography"},
        {"Yawn", "Yellow", "Yesterday", "Year", "Yard", "Yacht"},
        {"Zip", "Zag", "Zillion", "Zone", "Zoom", "Zenith"},
};

// Function that searches for words in the array that match with each letter in the user's input 

string searchWordWithLetter(char letter) {

    int index = toupper(letter) - 'A'; // basically converts the letter to uppercase and maps it to an index in the range from 0 to 25

    if (index >= 0 && index < 26) {
        srand(static_cast<unsigned int>(time(NULL)));
        int randomWord = rand() % 6; // ensures that when a letter is repeated the program selects different words from the array to give it some variety

        return wordArray[index][randomWord]; // returns the randomly selected word
    }
    return "";
}


// ************************************************************************************************************************************************************************************************************

int main() {

    cout << "************************************* \n";
    cout << "Welcome to I-Know-What-You-Mean! \n";
    cout << "************************************* \n";

    int decision;
    string mensaje;
    bool validez = false;
    while (!validez) {
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

    //***********************************************************************************************************************************

    string decodedMessage, translatedMessage;

    cout << "Enter a message to encode! \n";
    cin.ignore();
    getline(cin, decodedMessage);

    for (int i = 0; i < decodedMessage.length(); i++) { // loop iterates through EACH character in the user's input
        char letter_again = decodedMessage[i];

        if (isalpha(letter_again)) {
            // isalpha checks if each letter is alphabetic
            // it ignores any character that isn't a letter in the user input (i.e., a space)


            translatedMessage += searchWordWithLetter(letter_again) + " ";

            // The word searcher function is called to find a matching word for each letter,
            // then it appends the word match to the translatedMessage string.

            // The process repeats for every other letter in the input 
        }

    }

    cout << translatedMessage;
    return 0;
}