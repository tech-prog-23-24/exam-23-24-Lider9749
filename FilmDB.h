// FilmDB.h
#ifndef FILMDB_H
#define FILMDB_H

#include <string>
#include <vector>

#define DATABASE_FILE "movieDB.sqlite" // Имя файла базы данных

using namespace std;

class FilmDB {
public:
    FilmDB(); // Конструктор класса
    ~FilmDB(); // Деструктор класса

    // Методы для получения фильмов по различным критериям
    vector<string> get_good_films_of_genre(int rating, const string& genre);
    vector<string> get_films_of_genre_less_than(int time, const string& genre);
    vector<string> get_films_less_than(int time);
    int count_genre(const string& genre);

private:
    // Свойства класса
    struct Film {
        string name;
        string genre;
        int rating;
        int duration;
    };
    vector<Film> films;

    // Вспомогательные методы для работы с базой данных
    void load_db();
};

#endif // FILMDB_H
