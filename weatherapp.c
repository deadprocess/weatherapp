#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <json-c/json.h>


struct string { // Struktur für den String, der die Antwort der API speichert
    char *ptr; // ptr ist ein zeiger der auf char zeigt.
    size_t len; // size_t = spezieller Datentyp in C welcher dazu verwendet wird die Größe einer variable und/oder Länge in Bytes abzuspeichern; len = Länge des Strings
};

size_t writejsonfunction(void *ptr, size_t size, size_t number_of_elements, struct string *json_str) { 

// *ptr = zeiger eines TEILS des json strings
//size = Die Größe unserer Json-Daten in Bytes
//numer_of_elements = Anzahl der Elemente in unseren json string
//json_str = ist eigentlich der zeiger der schluss endlich unseren string anzeigt
    
size_t new_len = (*json_str).len + size * number_of_elements; // Neue Länge = aktuelle Länge + Größe der neuen JSON-Daten in Bytes multipliziert mit der Anzahl der Elemente
(*json_str).ptr = realloc((*json_str).ptr, new_len + 1); // Der JSON-String wird mit der funktion realloc (speichererweiterung) vergrößert um die neue Länge + 1 Byte
memcpy((*json_str).ptr + (*json_str).len, ptr, size * number_of_elements); //memcpy = kopiert daten: kopiert den teil unseres json string + die länge sowie unsere teil des json strings multipliziert mit der neuen größe
(*json_str).ptr[new_len] = '\0'; // Nullterminierung des Strings (Beendet den String) Wir erinnern uns: '\0' = "";

// writejsonfunction = Diese Funktion wird aufgerufen um die JSON-Daten zu verarbeiten und darauf einen String zu basteln
// Zunächst wird die neue Länge des string in der Variable new_len abgespeichert.
//Anschließend wird der Zeiger unseres JSON-Chunks oder JSON-Stücks vergrößert um die neue Länge + 1 Byte damit man da auch die restlichen Daten reinpackt, quasi Chunk für Chunk.
// Am Ende werden die Daten in den Zeiger kopiert (der string)
//Gannz zum schluss wird der string mit '\0' nullterminiert bzw gesagt '"'->Ende des String.

}


void init_string(struct string *str) {

    (*str).len = 0; // Initialierung von str auf die länge 0
    (*str).ptr = malloc(1); //Vom unserem str struct greifen wir nun auf den Zeiger ptr zu (welcher ja auf den char zeigte) (welcher schlussendlich den responsetext trägt)
    (*str).ptr[0] = '\0'; // Gleichzusetzen mit c#: string name = ""; ('\0' = nullterminierung bzw. das Ende eines string oder der einfachhalt halber: "")
}

char *api_call () { //eigene Funktion
    struct string json_str;
    init_string(&json_str); //initiiert den String json_str

    
    
    CURL *curl = curl_easy_init(); //Initialisierung einer CURL-Sitzung und speichert den Zeiger darauf in curl (CURL * = Zeiger auf CURL-Struktur)
    CURLcode res = CURLE_FAILED_INIT; //Variable res speichert den Rückgabewert von curl_easy_perform (wird hier initial mit Fehlerwert CURLE_FAILED_INIT gesetzt)
    if (curl) { //Prüfung ob die CURL-Sitzung erfolgreich intitialisiert wurde
        curl_easy_setopt(curl, CURLOPT_URL, "https://wttr.in/Krefeld?format=j1"); // Setzen der URL für die Wetter-API
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writejsonfunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &json_str);

        res = curl_easy_perform(curl); //Der API-Call wird ausgeführt und das Ergebnis in res gespeichert.
    }
    curl_easy_cleanup(curl); //Aufräumen der CURL-Sitzung und Freigabe der Ressourcen
    return json_str.ptr;
}

int main () { // Hauptfunktion

    char *json_response = api_call(); // Aufruf meiner eigenen Funktion api_call, welche die API abfragt und das Resultat als Zeiger des Inhalts zurückgibt und es in der Variable json_response abspeichert
    printf("Antwort: %s\n", json_response);
    
    //Parse JSON
    struct json_object *parsed_json;
    parsed_json = json_tokener_parse(json_response); //Hier wird der JSON-String geparsed und in parsed_json gespeichert
    struct json_object *weatherDesc;
    json_object_object_get_ex(parsed_json, "weatherDesc", &weatherDesc); //Hier wird das Wetter-Objekt aus dem JSON-String extrahiert und in weatherDesc gespeichert
    
    struct json_object *value;
    json_object_object_get_ex(weatherDesc, "value", &value); // Hier wird der Wert des Wetter-Objekts aus weather_description extrahiert
    printf("Wetterbeschreibung: %s\n", json_object_get_string(value)); // Hier wird die Wetterbeschreibung ausgegeben
}