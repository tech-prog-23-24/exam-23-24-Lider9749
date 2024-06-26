// FilmDB.cpp
#include "FilmDB.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

FilmDB::FilmDB() {
    load_db(); // Загрузка базы данных при создании объекта
}

FilmDB::~FilmDB() {
    // Нет необходимости в специальной очистке
}

void FilmDB::load_db() {
    // Загрузка базы данных из файла
    ifstream file(DATABASE_FILE);
    if (!file.is_open()) {
        cerr << "Не получилось открыть бд: " << DATABASE_FILE << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Film film;
        if (iss >> quoted(film.name) >> quoted(film.genre) >> film.rating >> film.duration) {
            films.push_back(film);
        }
    }
}

vector<string> FilmDB::get_good_films_of_genre(int rating, const string& genre) {
    // Получение фильмов по жанру с рейтингом не меньше заданного
    vector<string> result;
    for (const auto& film : films) {
        if (film.genre == genre && film.rating >= rating) {
            result.push_back(film.name);
        }
    }
    return result;
}

vector<string> FilmDB::get_films_of_genre_less_than(int time, const string& genre) {
    // Получение фильмов по жанру с длительностью не больше заданного времени
    vector<string> result;
    for (const auto& film : films) {
        if (film.genre == genre && film.duration <= time) {
            result.push_back(film.name);
        }
    }
    return result;
}

vector<string> FilmDB::get_films_less_than(int time) {
    // Получение фильмов с длительностью не больше заданного времени
    vector<string> result;
    for (const auto& film : films) {
        if (film.duration <= time) {
            result.push_back(film.name);
        }
    }
    return result;
}

int FilmDB::count_genre(const string& genre) {
    // Подсчет количества фильмов по жанру
    int count = 0;
    for (const auto& film : films) {
        if (film.genre == genre) {
            count++;
        }
    }
    return count;
}
