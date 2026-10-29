#include <iostream>
#include <clocale>
#include "file.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF-8");
    Movie* movie = nullptr;
    int choice;
    cout << "Выберите фильм:" << endl;
    cout << "1. Пин-код" << endl;
    cout << "2. Мультсериал Смешарики" << endl;
    cout << "3. Смешарики. Начало" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1)
        movie = new AnimatedMovie("Смешарики", 2003, 8.0, true, "Петербург");
    else if (choice == 2)
        movie = new Series("Смешарики", 2003, 8.5, true, "Петербург", 500);
    else if (choice == 3)
        movie = new FullLengthMovie("Смешарики. Начало", 2011, 7.0, true, "Петербург", 85);
    else
    {
        cout << "Неверный выбор." << endl;
        return 0;
    }

    cout << "\nРабота с Set и Get" << endl;
    movie->SetTitle("Смешарики");
    movie->SetYear(2003);
    movie->SetRating(8.5);
    movie->SetAvailable(true);
    cout << "Название: " << movie->GetTitle() << endl;
    cout << "Год: " << movie->GetYear() << endl;
    cout << "Рейтинг: " << movie->GetRating() << endl;
    cout << "Доступен: " << (movie->GetAvailable() ? "да" : "нет") << endl;
    cout << "\nПозднее связывание" << endl;
    cout << "Тип: " << movie->GetType() << endl;
    movie->PrintInfo();
    movie->Play();
    cout << "\nРаннее связывание" << endl;
    AnimatedMovie animated("Смешарики", 2003, 8.0, true, "Петербург");
    animated.SetStudio("Петербург");
    cout << "Студия: " << animated.GetStudio() << endl;
    animated.PrintInfo();
    animated.Play();
    Series series("Смешарики", 2003, 8.5, true, "Петербург", 500);
    series.SetEpisodes(500);
    cout << "Количество серий: " << series.GetEpisodes() << endl;
    series.PrintInfo();
    series.Play();
    FullLengthMovie fullLength("Смешарики. Начало", 2011, 7.0, true, "Петербург", 85);
    fullLength.SetDuration(85);
    cout << "Продолжительность: " << fullLength.GetDuration() << endl;
    fullLength.PrintInfo();
    fullLength.Play();
    cout << "\nРабота с сеансом" << endl;
    CinemaSession session(movie, 2, "18:30");
    session.SetRoom(3);
    session.SetTime("20:00");
    session.SetMovie(movie);
    cout << "Зал: " << session.GetRoom() << endl;
    cout << "Время: " << session.GetTime() << endl;
    session.GetMovie();
    session.PrintInfo();
    delete movie;
    cout << "\nПрограмма завершена." << endl;
    return 0;
}