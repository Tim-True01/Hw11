#include "file.h"
#include <iostream>

using namespace std;

Movie::Movie()
{
    cout << "[Отладка] Movie()" << endl;
    title = new string("Без названия");
    year = new int(0);
    rating = new double(0);
    available = new bool(false);
}

Movie::Movie(string t, int y, double r, bool a)
{
    cout << "[Отладка] Movie(string, int, double, bool)" << endl;
    title = new string(t);
    year = new int(y);
    rating = new double(r);
    available = new bool(a);
}

Movie::~Movie()
{
    cout << "[Отладка] ~Movie()" << endl;
    delete title;
    delete year;
    delete rating;
    delete available;
}

void Movie::SetTitle(string t)
{
    cout << "[Отладка] SetTitle()" << endl;
    *title = t;
}

void Movie::SetYear(int y)
{
    cout << "[Отладка] SetYear()" << endl;
    *year = y;
}

void Movie::SetRating(double r)
{
    cout << "[Отладка] SetRating()" << endl;
    *rating = r;
}

void Movie::SetAvailable(bool a)
{
    cout << "[Отладка] SetAvailable()" << endl;
    *available = a;
}

string Movie::GetTitle()
{
    cout << "[Отладка] GetTitle()" << endl;
    return *title;
}

int Movie::GetYear()
{
    cout << "[Отладка] GetYear()" << endl;
    return *year;
}

double Movie::GetRating()
{
    cout << "[Отладка] GetRating()" << endl;
    return *rating;
}

bool Movie::GetAvailable()
{
    cout << "[Отладка] GetAvailable()" << endl;
    return *available;
}

AnimatedMovie::AnimatedMovie(string t, int y, double r, bool a, string s)
    : Movie(t, y, r, a)
{
    cout << "[Отладка] AnimatedMovie()" << endl;
    studio = new string(s);
}

AnimatedMovie::~AnimatedMovie()
{
    cout << "[Отладка] ~AnimatedMovie()" << endl;
    delete studio;
}

void AnimatedMovie::SetStudio(string s)
{
    cout << "[Отладка] SetStudio()" << endl;
    *studio = s;
}

string AnimatedMovie::GetStudio()
{
    cout << "[Отладка] GetStudio()" << endl;
    return *studio;
}

void AnimatedMovie::Play()
{
    cout << "[Отладка] AnimatedMovie::Play()" << endl;
    cout << "Воспроизводится мультфильм" << endl;
}

void AnimatedMovie::PrintInfo()
{
    cout << "[Отладка] AnimatedMovie::PrintInfo()" << endl;
    cout << "Название: " << GetTitle() << endl;
    cout << "Год: " << GetYear() << endl;
    cout << "Рейтинг: " << GetRating() << endl;
    cout << "Доступен: " << (GetAvailable() ? "да" : "нет") << endl;
    cout << "Студия: " << GetStudio() << endl;
}

string AnimatedMovie::GetType()
{
    cout << "[Отладка] AnimatedMovie::GetType()" << endl;
    return "Мультфильм";
}

Series::Series(string t, int y, double r, bool a, string s, int e)
    : AnimatedMovie(t, y, r, a, s)
{
    cout << "[Отладка] Series()" << endl;
    episodes = new int(e);
}

Series::~Series()
{
    cout << "[Отладка] ~Series()" << endl;
    delete episodes;
}

void Series::SetEpisodes(int e)
{
    cout << "[Отладка] SetEpisodes()" << endl;
    *episodes = e;
}

int Series::GetEpisodes()
{
    cout << "[Отладка] GetEpisodes()" << endl;
    return *episodes;
}

void Series::Play()
{
    cout << "[Отладка] Series::Play()" << endl;
    cout << "Воспроизводится мультсериал" << endl;
}

void Series::PrintInfo()
{
    cout << "[Отладка] Series::PrintInfo()" << endl;
    AnimatedMovie::PrintInfo();
    cout << "Количество серий: " << GetEpisodes() << endl;
}

string Series::GetType()
{
    cout << "[Отладка] Series::GetType()" << endl;
    return "Мультсериал";
}

FullLengthMovie::FullLengthMovie(string t, int y, double r, bool a,
    string s, int d) : AnimatedMovie(t, y, r, a, s)
{
    cout << "[Отладка] FullLengthMovie()" << endl;
    duration = new int(d);
}

FullLengthMovie::~FullLengthMovie()
{
    cout << "[Отладка] ~FullLengthMovie()" << endl;
    delete duration;
}

void FullLengthMovie::SetDuration(int d)
{
    cout << "[Отладка] SetDuration()" << endl;
    *duration = d;
}

int FullLengthMovie::GetDuration()
{
    cout << "[Отладка] GetDuration()" << endl;
    return *duration;
}

void FullLengthMovie::Play()
{
    cout << "[Отладка] FullLengthMovie::Play()" << endl;
    cout << "Воспроизводится полнометражный мультфильм" << endl;
}

void FullLengthMovie::PrintInfo()
{
    cout<< "[Отладка] FullLengthMovie::PrintInfo()" << endl;
    AnimatedMovie::PrintInfo();
    cout << "Продолжительность: " << GetDuration() << " минут" << endl;
}

string FullLengthMovie::GetType()
{
    cout << "[Отладка] FullLengthMovie::GetType()" << endl;
    return "Полнометражный мультфильм";
}

CinemaSession::CinemaSession(Movie* m, int r, string t)
{
    cout << "[Отладка] CinemaSession()" << endl;
    movie = new Movie * (m);
    room = new int(r);
    time = new string(t);
}

CinemaSession::~CinemaSession()
{
    cout << "[Отладка] ~CinemaSession()" << endl;
    delete movie;
    delete room;
    delete time;
}

void CinemaSession::SetMovie(Movie* m)
{
    cout << "[Отладка] SetMovie()" << endl;
    *movie = m;
}

void CinemaSession::SetRoom(int r)
{
    cout << "[Отладка] SetRoom()" << endl;
    *room = r;
}

void CinemaSession::SetTime(string t)
{
    cout << "[Отладка] SetTime()" << endl;
    *time = t;
}

Movie* CinemaSession::GetMovie()
{
    cout << "[Отладка] GetMovie()" << endl;
    return *movie;
}

int CinemaSession::GetRoom()
{
    cout << "[Отладка] GetRoom()" << endl;
    return *room;
}

string CinemaSession::GetTime()
{
    cout << "[Отладка] GetTime()" << endl;
    return *time;
}

void CinemaSession::PrintInfo()
{
    cout << "[Отладка] CinemaSession::PrintInfo()" << endl;
    cout << "Номер зала: " << GetRoom() << endl;
    cout << "Время: " << GetTime() << endl;

    if (GetMovie() != nullptr)
    {
        cout << "Тип: " << GetMovie()->GetType() << endl;
        GetMovie()->PrintInfo();
    }
}





