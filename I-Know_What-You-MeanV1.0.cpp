// ************************************************************************************************************************************************************************************************************

                                                                                             // I-Know-What-You-Mean
                                                                                             // Cristian Padilla Soto
                                                                                             // Alannis Rubianes Febo

// ************************************************************************************************************************************************************************************************************

#include <iostream>

#include <fstream> // "fstream" gives you the functionality of being able to have files input and output

#include <sstream> //It is similar to the string library only that it works by constructing, manipulating and extracting character string data. 

#include <vector> // Vectors give various tools like storing, accessing, inserting elements in a more efficient way, in other words, dynamic access.

#include <Windows.h> // Provides the functionality of the "sleep" function

#include <chrono> // Provides the timing ffunctionality in the sleep function.

#include <string> //Provides operations for creating and manipulating strings

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
    }/*
     the loop extracts the first character of each word and
     returns it to msgcode
     */
    return msgcode.str();
}

// Function to decode the random words back into the original message

string decodificar(const string& mensajeCodificado) {
    stringstream decodedMessage;
    istringstream leer(mensajeCodificado);
    //This allows to read the encoded message word by word
    string letra;
    while (leer >> letra) {
        decodedMessage << letra << " ";
        //This loop reads the characters from "leer" and sends it to letra
        //Each letter gets added to decodedMessage and gets appended 
    }
    return decodedMessage.str();
    //The function finally returns the decoded messagr
}

// Function to write encoded message to a text file

void escribirArchivo(const string& mensajeCodificado) {
    ofstream outfile("mensaje_codificado.txt");
    if (outfile.is_open()) {
        outfile << mensajeCodificado;
        outfile.close();
        //A file is created and it gives us the function to write on t
    }
    else {
        cerr << "File cannot be opened, try again later";
        //If the file can't be opened it gives an error message
    }
}

// Function to read encoded message from a text file

string leerArchivo() {
    ifstream infile("mensaje_codificado.txt"); //reads the data from the file
    stringstream buffer;
    buffer << infile.rdbuf();
    return buffer.str();
}//The contents of the infile are "placed 4" into the buffer function where it's returned

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

    int decision;
    string mensaje;
    bool validez = false; //It's used to check if the user input is correct
    while (!validez) {
        cout << endl;
        cout << "************************************* \n";
        cout << "Welcome to I-Know-What-You-Mean! \n";
        cout << "************************************* \n";

        cout << endl;
        cout << "Tip: Think carefully of the word's initials ... \n";
        cout << "Please enter 1 to type in your secret phrase, later your secret message will be shown!! \n";
        cout << endl;
        cout << "Or..";
        cout << "Press 2 for a more fun method!!";
        cout << endl;
        cin >> decision;
        cin.ignore();
        if (decision == 1 || decision == 2) {
            validez = true;
        }
        else {

            BorrarPantalla();
            cout << endl;
            cerr << "ERROR, number has to be 1 or 2! \n";
            Sleep(2000);
        }
    }
    if (decision == 1) {
        cout << "Please enter the phrase you want to decode: \n";
        getline(cin, mensaje); //the phrase gets stored
        string codificado = codificar(mensaje);
        escribirArchivo(codificado);
        cout << endl;
        cout << "The decodified message has been saved in a file!" << endl;
        string msgOG = leerArchivo(); //the contents on the file are saved into the function
        string msgcode = decodificar(msgOG); //Tge saved content is decodified and saved  into a new variable
        cout << endl;
        cout << "The hidden message is... : " << msgcode << endl;
    }
    else {
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
        cout << endl;
        cout << "The secret message is: " << translatedMessage;
        cout << endl;
        cout << "Wonder what that means... ";
    }
    return 0;
}