//
// Created by Hasna Sharif on 10/25/20.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class Song {

private:
    char* songName;
    char* artist;
    int size;

public:

    //Default Constructor
    Song();
    //First we need a constructor - Song can have no default constructor as it has to have a songName and artist name
    //per the instruction, so this is a constructor with songname, artist name, and size.
    Song(char[], char[], int);


    //Getter and Setter functions to return song private member variables

    //size functions
    int getSize() const;
    void setSize(int sz);

    //name functions
    char* getName() const;
    void setName(char name[]);

    //artists functions
    char* getArtist() const;
    void setArtist(char artist[]);


    //Overload operators to compare songs
    bool operator != (Song const &rhs);
    bool operator == (Song const &rhs);
    bool operator > (Song const &rhs);
    bool operator < (Song const &rhs);

    //destructor
    ~Song();
};


#endif //UTPOD_SONG_H