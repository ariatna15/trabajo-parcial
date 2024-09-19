#pragma once
#include "iostream"
using namespace System;
using namespace std;



//Funcion provisional para pasar colores en forma de parametros si es que es necesario
//void color(int c)
//{
//    switch (c)
//    {
//    case 1: Console::ForegroundColor = ConsoleColor::Black; break;
//    case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
//    case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
//    case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
//    case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
//    case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
//    case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
//    case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
//    case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
//    case 10: Console::ForegroundColor = ConsoleColor::Green; break;
//    case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
//    case 12: Console::ForegroundColor = ConsoleColor::Red; break;
//    case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
//    case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
//    case 15: Console::ForegroundColor = ConsoleColor::White; break;
//    }
//}



void instrucciones() {
    system("cls");
    Console::SetCursorPosition(40, 12); cout << "\t   INSTRUCCIONES";
    Console::SetCursorPosition(40, 13); cout << "\t   -------------";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(20, 15); cout << "\t1. Utiliza las teclas direccionales para jugar.";
    Console::SetCursorPosition(20, 16); cout << "\t2. Muevete por todo el mapa para recoger los recursos.";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(20, 17); cout << "\t3. Tienes un limite de tres vidas.";
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(20, 18); cout << "\t4. Para ganar tines que recoger un 70% de los recursos :)";
    Console::SetCursorPosition(20, 18); cout << "\t5. Pierdes si el tiempo se te acaba.";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(20, 21); cout << "\tPresiona cualquier tecla para regresar";

}

void game_over() {
    system("cls");
    int x = 40;
    int y = 10;
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(x, y); cout << "  ____    _    __  __ _____    _____     _______ ____       __";
    Console::SetCursorPosition(x, y + 1); cout << " / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\   _ / /";
    Console::SetCursorPosition(x, y + 2); cout << "| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) | (_) | ";
    Console::SetCursorPosition(x, y + 3); cout << "| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ <   _| | ";
    Console::SetCursorPosition(x, y + 4); cout << " \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_\\ (_) | ";
    Console::SetCursorPosition(x, y + 5); cout << "                                                           \\_\\";

}
void you_win() {
    system("cls");
    int x = 40;
    int y = 10;
    Console::ForegroundColor = ConsoleColor::DarkMagenta;
    Console::SetCursorPosition(x, y); cout << " __   _____  _   _  __        _____ _   _";
    Console::SetCursorPosition(x, y + 1); cout << " \\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | |";
    Console::SetCursorPosition(x, y + 2); cout << "  \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| |";
    Console::SetCursorPosition(x, y + 3); cout << "   | || |_| | |_| |   \\ V  V /  | || |\\  |";
    Console::SetCursorPosition(x, y + 4); cout << "   |_| \\___ /\\___ /    \\_/\\_/  |___|_| \\_|";

}

void creditos() {
    system("cls");
    int x = 40;
    int y = 5;
    Console::ForegroundColor = ConsoleColor::DarkMagenta;
    Console::SetCursorPosition(x, y); cout << "  ____       __     _   _            ";
    Console::SetCursorPosition(x, y + 1); cout << " / ___|_ __ /_/  __| (_) |_ ___   ___ ";
    Console::SetCursorPosition(x, y + 2); cout << "| |   | '__/ _ \\/ _` | | __/  \\/ __|";
    Console::SetCursorPosition(x, y + 3); cout << "| |___| | |  __/ (_|_| | || (_) \\__ \\";
    Console::SetCursorPosition(x, y + 4); cout << " \\____|_|  \\___|\\__,_|_|\\__\\___/|___/";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(x, y + 7); cout << " UPC - SEDE MONTERRICO";
    Console::SetCursorPosition(x, y + 8); cout << "=======================";
    Console::SetCursorPosition(x, y + 10); cout << "ALGORITMOS - CC22";
    Console::SetCursorPosition(x, y + 11); cout << "Programadores:";
    Console::SetCursorPosition(x, y + 13); cout << "-Ryan Mateo Zavaleta Jave ";
    Console::SetCursorPosition(x, y + 15); cout << "-Ariatna Ximena Bravo Torres ";
    Console::SetCursorPosition(x, y + 17); cout << "-Josue Froilan Laurente Castrejon ";

}



void salir() {
    system("cls");
    int x = 20;
    int y = 10;
    Console::ForegroundColor = ConsoleColor::Yellow;

    Console::SetCursorPosition(x, y); cout << "    8eeeee eeeee  eeeee eeee e  eeeee eeeee    eeeee eeeee eeeee  \n";
    Console::SetCursorPosition(x, y + 1); cout << "\t8e     8   8  8   8 8  8 8  8   8 8   e    8   8 8  88 8   8  \n";
    Console::SetCursorPosition(x, y + 2); cout << "\t88  ee 8eee8e 8eee8 8e   8e 8eee8 8eeee    8eee8 8   8 8eee8e \n";
    Console::SetCursorPosition(x, y + 3); cout << "\t88   8 88   8 88  8 88   88 88  8    88    88    8   8 88   8 \n";
    Console::SetCursorPosition(x, y + 4); cout << "\t88eee8 88   8 88  8 88e8 88 88  8 8ee88    88    8eee8 88   8 \n";
    Console::SetCursorPosition(x, y + 5); cout << "\t                                                              \n";
    Console::SetCursorPosition(x, y + 6); cout << "\t                                                              \n";
    Console::SetCursorPosition(x, y + 7); cout << "\t       e  e   e eeeee eeeee eeeee                              \n";
    Console::SetCursorPosition(x, y + 8); cout << "\t       8  8   8 8     8   8 8   8                              \n";
    Console::SetCursorPosition(x, y + 9); cout << "\t       8e 8e  8 8\"88  8eee8 8eee8e                             \n";
    Console::SetCursorPosition(x, y + 10); cout << "\t    e  88 88  8 8   8 88  8 88   8                             \n";
    Console::SetCursorPosition(x, y + 11); cout << "\t    8ee88 88ee8 88ee8 88  8 88   8                             \n";

    Console::SetCursorPosition(x, y + 13); cout << "Gracias por jugar!\n";

    system("pause>0");
    exit(0);
}
int menu() {
    int opcion;
    /*bool continuar = true;*/ // Variable para controlar el bucle del menú
    system("cls");
    /*Consola();*/ // Dibujar la consola en cada iteración del menú
    Console::ForegroundColor = ConsoleColor::Magenta;
    Console::SetCursorPosition(40, 3); cout << " _______        _           _       ";
    Console::SetCursorPosition(40, 4); cout << "|__   __|      | |         (_)      ";
    Console::SetCursorPosition(40, 5); cout << "   | |_ __ __ _| |__   __ _ _  ___  ";
    Console::SetCursorPosition(40, 6); cout << "   | | '__/ _` | '_ \\ / _` | |/ _ \\ ";
    Console::SetCursorPosition(40, 7); cout << "   | | | | (_| | |_) | (_| | | (_) |";
    Console::SetCursorPosition(40, 8); cout << "   |_|_|  \\__,_|_.__/ \\__,_| |\\___/ ";
    Console::SetCursorPosition(40, 9); cout << "                          _/ |      ";
    Console::SetCursorPosition(40, 10); cout << "                         |__/       ";
    Console::SetCursorPosition(43, 11); cout << " _____               _       _ ";
    Console::SetCursorPosition(43, 12); cout << "|  __ \\             (_)     | |";
    Console::SetCursorPosition(43, 13); cout << "| |__) |_ _ _ __ ___ _  __ _| |";
    Console::SetCursorPosition(43, 14); cout << "|  ___/ _` | '__/ __| |/ _` | |";
    Console::SetCursorPosition(43, 15); cout << "| |  | (_| | | | (__| | (_| | |";
    Console::SetCursorPosition(43, 16); cout << "|_|   \\__,_|_|  \\___|_|\\__,_|_|";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(50, 19); cout << "[1]JUGAR";
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(50, 20); cout << "[2]CREDITOS";
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(50, 21); cout << "[3]INSTRUCCIONES";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(50, 22); cout << "[4]SALIR";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(50, 25); cout << "ELEGIR OPCION: "; cin >> opcion;

    return opcion;
}

void cuadro() {
    int ancho = 120;  // Ancho del rectángulo
    int alto = 35;    // Alto del rectángulo
    int posX = 0;    // Desplazamiento horizontal (espacios en blanco)
    int posY = 5;    // Desplazamiento vertical (nuevas líneas)

    for (int i = 0; i < posY; i++) {
        cout << endl;
    }
    // Bucle para crear solo los bordes del rectángulo
    for (int i = 0; i < alto; i++) {
        // (posX)
        for (int j = 0; j < posX; j++) {
            cout << " ";
        }

        // Dibujar los bordes: 
        for (int j = 0; j < ancho; j++) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                cout << char(219);
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }


}
void cargando() {
    system("cls");
    Console::SetCursorPosition(55, 20); cout << "CARGANDO..";
    for (int i = 40; i <= 76; i++) {
        Console::SetCursorPosition(i, 23); printf("%c", 177);
    }
    for (int i = 40; i <= 76; i++) {
        Console::SetCursorPosition(i, 23); printf("%c", 219);
        _sleep(35);
    }
    system("cls");


}


