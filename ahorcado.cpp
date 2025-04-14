#include <iostream>
using namespace std;

// Muestra el estado actual de la palabra
void mostrarPalabra(string palabra, string progreso) {
    for (int i = 0; palabra[i] != '\0'; i++) {
        if (progreso[i] == '_') {
            cout << "_ ";
        } else {
            cout << progreso[i] << " ";
        }
    }
    cout << endl;
}

// Muestra las partes del cuerpo según errores
void mostrarCuerpo(int errores) {
    cout << "\nPartes del cuerpo perdidas (" << errores << "/6):\n";
    if (errores >= 1) cout << "- Cabeza\n";
    if (errores >= 2) cout << "- Tronco\n";
    if (errores >= 3) cout << "- Brazo izquierdo\n";
    if (errores >= 4) cout << "- Brazo derecho\n";
    if (errores >= 5) cout << "- Pierna izquierda\n";
    if (errores == 6) cout << "- Pierna derecha\n";
}

// Actualiza el progreso si la letra es correcta, devuelve si acertó o no
bool actualizarProgreso(char letra, string palabra, string &progreso) {
    bool acierto = false;
    for (int i = 0; palabra[i] != '\0'; i++) {
        if (palabra[i] == letra && progreso[i] == '_') {
            progreso[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}

// Verifica si la palabra fue completamente adivinada
bool palabraCompleta(string progreso) {
    for (int i = 0; progreso[i] != '\0'; i++) {
        if (progreso[i] == '_') {
            return false;
        }
    }
    return true;
}

int main() {
    string palabra, progreso = "";
    char letra;
    int errores = 0;

    cout << "=== Juego del Ahorcado ===\n";
    cout << "Jugador 1, ingresa la palabra secreta (sin espacios): ";
    cin >> palabra;

    // Inicializar el progreso con guiones bajos
    for (int i = 0; palabra[i] != '\0'; i++) {
        progreso += "_";
    }

    system("clear || cls"); // Limpia pantalla para ocultar la palabra

    while (errores < 6) {
        cout << "\nPalabra: ";
        mostrarPalabra(palabra, progreso);
        mostrarCuerpo(errores);

        cout << "Ingresa una letra: ";
        cin >> letra;

        if (!actualizarProgreso(letra, palabra, progreso)) {
            errores++;
        }

        if (palabraCompleta(progreso)) {
            cout << "\n¡Felicidades! Adivinaste la palabra: " << palabra << endl;
            return 0;
        }
    }

    // Si el jugador llega aquí, ha perdido
    mostrarCuerpo(errores);
    cout << "\nHas perdido. La palabra era: " << palabra << endl;

    return 0;
}
