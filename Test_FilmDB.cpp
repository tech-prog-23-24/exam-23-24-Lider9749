// Test_FilmDB.cpp
#include <iostream>
#include <cassert>
#include "FilmDB.h"

using namespace std;

void test_get_films_of_genre_less_than() {
    FilmDB db; // Создание объекта для работы с базой данных

    // Тестовые значения (укажите корректные значения, исходя из вашего файла films.csv)
    vector<string> expected = {"Film1", "Film2"}; // Предполагаем, что эти фильмы есть в базе данных
    vector<string> result = db.get_films_of_genre_less_than(90, "Comedy");

    // Проверка соответствия результатов
    assert(result == expected);
    cout << "Test get_films_of_genre_less_than passed!" << endl;
}

int main() {
    test_get_films_of_genre_less_than(); // Запуск теста
    return 0;
}
