#include "Movie.h"

// Constructor definitions
Movie::Movie(std::string M_name, std::string M_rating, int M_num_of_watching)
    : name{M_name}, rating{M_rating}, num_of_watching{M_num_of_watching} {}

Movie::Movie(const Movie& source)
    : Movie{source.name, source.rating, source.num_of_watching} {}

void Movie::display_Movie() const {
    std::cout << name << " ," << rating << " ," << num_of_watching << std::endl;
}

void Movie::increment_watched() {
    num_of_watching++;
}

void Movie::increment_watched(int num) {
    num_of_watching += num;
}
