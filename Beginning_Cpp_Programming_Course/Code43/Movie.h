#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <iostream>

class Movie {
private:
    std::string name;
    std::string rating;
    int num_of_watching {0};

public:
    Movie(std::string M_name, std::string M_rating, int M_num_of_watching);
    Movie(std::string M_name, std::string M_rating);
    Movie(std::string M_name);
    Movie();
    ~Movie() = default;

    // Copy constructor
    Movie(const Movie& source);

    // Getters (const-correct)
    std::string get_M_name() const;
    std::string get_M_rating() const;
    int get_M_num_of_watching() const;

    // Setters
    void set_M_name(const std::string& M_name);
    void set_M_rating(const std::string& M_rating);
    void set_M_num_of_watching(int M_num_of_watching);

    // Methods
    void display_Movie() const;
    void increment_watched();
    void increment_watched(int num);
};

#endif
