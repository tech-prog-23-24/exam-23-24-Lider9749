// main.cpp
#include <iostream>
#include "FilmDB.h"

using namespace std;

int main() {
    FilmDB db; // Создание объекта для работы с базой данных

    // Демонстрация работы метода get_good_films_of_genre
    vector<string> good_films = db.get_good_films_of_genre(8, "Action");
    cout << "Good Action Films with rating >= 8:" << endl;
    for (const string& film : good_films) {
        cout << film << endl;
    }

    // Демонстрация работы метода get_films_of_genre_less_than
    vector<string> short_comedies = db.get_films_of_genre_less_than(90, "Comedy");
    cout << "\nComedies with duration <= 120 minutes:" << endl;
    for (const string& film : short_comedies) {
        cout << film << endl;
    }

    // Демонстрация работы метода get_films_less_than
    vector<string> short_films = db.get_films_less_than(100);
    cout << "\nFilms with duration <= 100 minutes:" << endl;
    cout << "" ;
    for (const string& film : short_films) {
        cout << film << endl;
    }

    // Демонстрация работы метода count_genre
    int count_action = db.count_genre("Action");
    cout << "\nNumber of Action films: " << count_action << endl;

    return 0;
}
