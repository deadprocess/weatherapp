# WeatherApp

## 📖 Beschreibung (Deutsch)

Die **WeatherApp** ist ein kleines C-Programm, das aktuelle Wetterdaten von der API [wttr.in](https://wttr.in) abruft. Es verwendet die `libcurl`-Bibliothek, um HTTP-Anfragen zu senden, und `json-c`, um die JSON-Antwort zu parsen. Das Programm zeigt die Wetterbeschreibung für eine bestimmte Stadt (standardmäßig `Krefeld`) an.

### 🛠️ Voraussetzungen

Um das Programm zu kompilieren und auszuführen, müssen folgende Abhängigkeiten installiert sein:

1. **libcurl**: Eine Bibliothek für HTTP-Anfragen.
   - Installation (Linux):  
     ```bash
     sudo apt-get install libcurl4-openssl-dev
     ```
2. **json-c**: Eine Bibliothek zum Parsen von JSON-Daten.
   - Installation (Linux):  
     ```bash
     sudo apt-get install libjson-c-dev
     ```

### 🚀 Kompilieren und Ausführen

1. **Kompilieren**:
   Verwende den folgenden Befehl, um das Programm zu kompilieren:
   ```bash
   gcc -o weatherapp weatherapp.c -lcurl -ljson-c

2. **Ausführen**:
    Starte das Programm mit
    ```bash
    ./weatherapp


## ⚠️ Hinweise
Stelle sicher, dass du eine aktive Internetverbindung hast, da das Programm Wetterdaten von der API abruft.
Die Standardstadt ist Krefeld. Du kannst die URL in der Funktion api_call anpassen, um Wetterdaten für eine andere Stadt abzurufen.    


# WeatherApp

## 📖 Description (English)

The **WeatherApp** is a small C program that fetches current weather data from the [wttr.in](https://wttr.in) API. It uses the `libcurl` library to send HTTP requests and `json-c` to parse the JSON response. The program displays the weather description for a specific city (default: `Krefeld`).

### 🛠️ Requirements

To compile and run the program, the following dependencies must be installed:

1. **libcurl**: A library for HTTP requests.
   - Installation (Linux):  
     ```bash
     sudo apt-get install libcurl4-openssl-dev
     ```
2. **json-c**: A library for parsing JSON data.
   - Installation (Linux):  
     ```bash
     sudo apt-get install libjson-c-dev
     ```

### 🚀 Compile and Run

1. **Compile**:
   Use the following command to compile the program:
   ```bash
   gcc -o weatherapp weatherapp.c -lcurl -ljson-c
   ```

2. **Run**:
   Start the program with:
   ```bash
   ./weatherapp
   ```

### ⚠️ Notes

- Ensure you have an active internet connection, as the program fetches weather data from the API.
- The default city is `Krefeld`. You can modify the URL in the `api_call` function to fetch weather data for a different city.