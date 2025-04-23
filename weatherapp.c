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
//json_str = ist eigentlich der zeiger der schluss endlich unseren string an sich speichern wird
    

}


void init_string(struct string *str) {

    (*str).len = 0; // Initialierung von str auf die länge 0
    (*str).ptr = malloc(1); //Vom unserem str struct greifen wir nun auf den Zeiger ptr zu (welcher ja auf den char zeigte) (welcher schlusseendlich den responsetext trägt)
    (*str).ptr[0] = '\0'; // Gleichzusetzen mit c#: string name = ""; ('\0' = nullterminierung bzw. das Ende eines string oder der einfachhalt halber: "")
}

CURLcode api_call () { //eigene Funktion
    CURL *curl = curl_easy_init(); //Initialisierung einer CURL-Sitzung und speichert den Zeiger darauf in curl (CURL * = Zeiger auf CURL-Struktur)
    CURLcode res = CURLE_FAILED_INIT; //Variable res speichert den Rückgabewert von curl_easy_perform (wird hier initial mit Fehlerwert CURLE_FAILED_INIT gesetzt)
    if (curl) { //Prüfung ob die CURL-Sitzung erfolgreich intitialisiert wurde
        curl_easy_setopt(curl, CURLOPT_URL, "https://wttr.in/Krefeld?format=j1"); // Setzen der URL für die Wetter-API
        res = curl_easy_perform(curl); //Der API-Call wird ausgeführt und das Ergebnis in res gespeichert.
    }
    curl_easy_cleanup(curl); //Aufräumen der CURL-Sitzung und Freigabe der Ressourcen
    return res;
}

int main () { // Hauptfunktion

    CURLcode res = api_call(); // Aufruf meiner eigenen Funktion api_call, welche die API abfragt und das Resultat als Typ CURLcode zurückgibt und es in der Variable res abspeichert
    if (res == CURLE_OK) { // Überprüfung ob mein API-Call erforgreich war
    printf("API call war erfolgreich\n"); //Ausgabe einer Erfolgsnachricht
    } else { 
        printf("Der API call war nicht erfolgreich.\n"); // Ausgabe einer Fehlermeldung
    }

    const char *json_string = res; //Hier wird der Rückgabewert der API in einen String umgewandelt, damit er als JSON interpretiert werden kann

    //Parse JSON
    struct json_object *parsed_json;
    parsed_json = json_tokener_parse(json_string); //Hier wird der JSON-String geparsed und in parsed_json gespeichert
    struct json_object *weather_description;
    json_object_object_get_ex(parsed_json, "weather_description", &weather_description); //Hier wird das Wetter-Objekt aus dem JSON-String extrahiert und in weather_description gespeichert
    struct json_object *weather_description = json_object_array_get_idx(weather_description, 0); //Hier wird das erste Element des Wetter-Objekts extrahiert und in weather_description gespeichert
    struct json_object *value;
    json_object_object_get_ex(value, "value", &value); //Hier wird der Wert des Wetter-Objekts extrahiert und in value gespeichert
    printf("Wetterbeschreibung: %s\n", json_object_get_string(value)); //Hier wird die Wetterbeschreibung ausgegeben
}