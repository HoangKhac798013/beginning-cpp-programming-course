/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"


 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::find_movie_by_name(std::string movie_name, size_t& i) const {
    for (i; i < movies.size(); i++) {
        if(movies.at(i).get_name() == movie_name) {
            return true;
        }
    }
    return false;
}
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // you implement this method
    size_t index{0};
    if(!find_movie_by_name(name, index)) {
        Movie temp_object {name, rating, watched};
        movies.push_back(temp_object);
        return true;
    }
    else {
        return false;
    }
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
    // you implement this method
    size_t index {0};
    if (find_movie_by_name(name, index)) {
        movies.at(index).increment_watched();
        return true;
    }
   return false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
   // You implement this method
    std::cout << "Dispaying movies" << std::endl;
    for (auto i: movies) {
        i.display();
    }
}