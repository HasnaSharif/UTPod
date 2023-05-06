//
// Created by Hasna Sharif on 10/25/20.
//

#include "Song.h"


//Default Constructor
Song::Song() {
    songName= new char[100];
    artist=new char[100];
    size=0;
}


//Definition for Constructor for Song
Song::Song(char art[], char sname[], int s) {
    songName = new char[strlen(sname)+1];
    artist = new char[strlen(art)+1];
    if( !(strlen(sname)==0 || strlen(art)==0)){
        strcpy(songName,sname);
        strcpy(artist,art);
    }
    else{
        cout<<"Cannot make song with empty Name or Artist. So default will be made for you.\n";
        Song();
    }
    if(s>0){
        size=s;
    }
    else{
        cout<<"Size must be greater than 0 for a Song. So default song will be made for you.\n";
        Song();
    }


}

int Song::getSize() const {
    return size;
}

void Song::setSize(int sz) {
    size=sz;
}

void Song::setName(char name[]) {
    strcpy(songName,name);
}

char *Song::getName() const {
    return songName;
}

char *Song::getArtist() const {
    return artist;
}

void Song::setArtist(char artist[]) {
    strcpy(this->artist,artist);
}

//Song Operators to compare

bool Song::operator != (Song const &rhs){
    string song = songName; string arti= artist; string name = rhs.getName(); string art = rhs.getArtist();
    if(songName!=name)
        return true;
    else if(artist!=art)
        return true;
    else if (size!=rhs.getSize())
        return true;
    else
        return false;
}

bool Song::operator == (Song const &rhs) {
    return !(this->operator!=(rhs));
}

bool Song::operator>(Song const &rhs) {
    string song = songName; string arti= artist; string name = rhs.getName(); string art = rhs.getArtist();
    if(arti>art){
        return true;
    }
    else if(arti==art){
        if(song>name){
            return true;
        }
        else if(song==name){
            if(size>rhs.getSize()){
                return true;
            }
            else
                return false;
        }
    }
    else
        return false;
}

bool Song::operator<(Song const &rhs) {
    return (!this->operator==(rhs) && !this->operator>(rhs));
}


Song::~Song() {
    delete [] songName;
    delete [] artist;
}
