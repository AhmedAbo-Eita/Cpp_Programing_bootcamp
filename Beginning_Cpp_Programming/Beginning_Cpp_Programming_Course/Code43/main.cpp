#include "Movie.h"
#include <vector>

void display(const std::vector<Movie>& obj);
void add_movie(std::vector<Movie>& obj, const std::string& name, const std::string& rating, int num);

int main() {
    std::vector<Movie> my_movies;
    
    display(my_movies);

    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);

    display(my_movies);

    add_movie(my_movies, "Ice Age", "PG", 12);
    display(my_movies);

    return 0;
}

void display(const std::vector<Movie>& obj) {
    for (const auto& movie : obj) {
        movie.display_Movie();
    }
}

void add_movie(std::vector<Movie>& obj, const std::string& name, const std::string& rating, int num) {
    obj.push_back(Movie(name, rating, num));
}
