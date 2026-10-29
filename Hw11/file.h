#pragma once
#include <string>

class Movie
{
private:
    std::string* title;
    int* year;
    double* rating;
    bool* available;

public:
    Movie();
    Movie(std::string t, int y, double r, bool a);
    virtual ~Movie();

    void SetTitle(std::string t);
    void SetYear(int y);
    void SetRating(double r);
    void SetAvailable(bool a);

    std::string GetTitle();
    int GetYear();
    double GetRating();
    bool GetAvailable();

    virtual void Play() = 0;
    virtual void PrintInfo() = 0;
    virtual std::string GetType() = 0;
};

class AnimatedMovie : public Movie
{
private:
    std::string* studio;

public:
    AnimatedMovie(std::string t, int y, double r, bool a, std::string s);
    ~AnimatedMovie();

    void SetStudio(std::string s);
    std::string GetStudio();

    void Play() override;
    void PrintInfo() override;
    std::string GetType() override;
};

class Series : public AnimatedMovie
{
private:
    int* episodes;

public:
    Series(std::string t, int y, double r, bool a, std::string s, int e);
    ~Series();

    void SetEpisodes(int e);
    int GetEpisodes();

    void Play() override;
    void PrintInfo() override;
    std::string GetType() override;
};

class FullLengthMovie : public AnimatedMovie
{
private:
    int* duration;

public:
    FullLengthMovie(std::string t, int y, double r, bool a, std::string s, int d);
    ~FullLengthMovie();

    void SetDuration(int d);
    int GetDuration();

    void Play() override;
    void PrintInfo() override;
    std::string GetType() override;
};

class CinemaSession
{
private:
    Movie** movie;
    int* room;
    std::string* time;

public:
    CinemaSession(Movie* m, int r, std::string t);
    ~CinemaSession();

    void SetMovie(Movie* m);
    void SetRoom(int r);
    void SetTime(std::string t);

    Movie* GetMovie();
    int GetRoom();
    std::string GetTime();

    void PrintInfo();
};