//
// Created by Hasna Sharif on 10/25/20.
//

#include "Song.h"
#include "UTPod.h"

//Definition for default constructor
UTPod::UTPod() {
    podMemSize = MAX_MEMORY;
    songs = new SongNode;
    songs->next=NULL;
    currentTime = (unsigned)time(0);
    srand(currentTime);
}

//definition for constructor with size specified in parameter.
UTPod::UTPod(int size) {
    if(size>=MAX_MEMORY || size<=0){
        podMemSize=MAX_MEMORY;

    }
    else {
        podMemSize = size;
    }
    songs = new SongNode;
    songs->next=NULL;
    currentTime = (unsigned)time(0);
    srand(currentTime);
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/
int UTPod::addSong(Song const &s) {

    //See if song can fit
    int songSize = s.getSize();
    if(getRemainingMemory()<songSize){
        return NO_MEMORY;
    }

    //If song can fit. Find last song in list, add the song to the list, and than add another empty SongNode.
    SongNode* temp = songs;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    //Update Song of last SongNode in list
    temp->s.setSize(songSize);
    temp->s.setName(s.getName());
    temp->s.setArtist(s.getArtist());
    //Add extra SongNode with a Null Pointer at end.
    temp->next= new SongNode;
    temp->next->next=NULL;

    //return success
    return SUCCESS;
}

/* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed


       input parms -

       output parms -
    */
int UTPod::removeSong(Song const &s) {

    //Loop through list to find the first instance of Song to remove.
    SongNode* previous = songs;
    SongNode* temp = previous->next;

    //check to see if first Song in list is the match
    if(previous->s.operator!=(s)){
        //do nothing and continue
    }
    else{
        songs=temp; //set head of list pointer to next element and remove free memory for previous
        free(previous);
        return SUCCESS; //Song found and removed
    }
    while(temp->next!=NULL) {
        if(temp->s.operator!=(s)){
            previous=previous->next;
            temp=temp->next;
            continue;
        }
        else{
            previous->next=temp->next;
            free(temp);
            return SUCCESS;
        }
    }
    return NOT_FOUND;
}

int UTPod::getRemainingMemory() {
    int memoryLeft = podMemSize;
    SongNode* temp = songs;
    while(temp->next!=NULL){
        memoryLeft -= temp->s.getSize();
        temp = temp->next;
    }
    return memoryLeft;
}

/* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */
void UTPod::shuffle() {

    //Check for only two songs using i.
    if(getNumSongs()<2){
        return;
    }

    //
    int random = rand()%10+5;
    for (int j = 0; j < random; ++j) {
        SongNode* previous = songs;
        SongNode* temp=previous->next;

        int numSongs = getNumSongs();
        int random2 = rand()%(numSongs-1);
        if(random2<numSongs){
            int k =0;
            while(k!=random2){
                k++;
                previous=previous->next;
                temp=temp->next;
            }
            //Move random indexed song in list to beginning random number of times.
            previous->next=temp->next;
            temp->next=songs;
            songs=temp;
        }

    }
}

int UTPod::getNumSongs() {
    int i=0;
    SongNode* temp = songs;
    while(temp->next!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}

void UTPod::showSongList() {

    SongNode* temp = songs;
    while(temp->next!=NULL){
        cout<<"The Song is: "<<temp->s.getName();
        cout<<"----The Artist is: "<<temp->s.getArtist();
        cout<<"----The size is: " <<temp->s.getSize() << endl;
        temp=temp->next;
    }
    cout<<"\n";
}

void UTPod::clearMemory() {
    SongNode* temp = songs;
    while(temp->next!=NULL){
        removeSong(temp->s);
        temp=songs;
    }
}

UTPod::~UTPod() {
    clearMemory();
    delete songs;
}


/* FUNCTION - void sortSongList
    *  sorts the songs in ascending order
       o will do nothing if there are less than two songs in the current list

      input parms -

      output parms -
*/
void UTPod::sortSongList() {
    //check for less than 2 songs
    if(getNumSongs()<2)
        return;

    //Start Sorting using by adding smallest song in list to new list first.
    //Than remove it from original list, and repeat. adding each smallest song to newList than set song to newList
    //Head
    SongNode* previousHead = songs;
    SongNode* newHead = new SongNode;
    SongNode* newHeadIncrement = newHead;
    while(previousHead->next!=NULL){
        SongNode* temp = previousHead;
        Song minSong = temp->s;
        while(temp->next!=NULL){
            if(minSong.operator>(temp->s)){
                minSong = temp->s;
            }
            temp=temp->next;
        }
        this->removeSong(minSong); //will change songs by itself and will also clear original list memory
        newHeadIncrement->s=minSong;
        newHeadIncrement->next= new SongNode;
        newHeadIncrement=newHeadIncrement->next;
        newHeadIncrement->next=NULL;
        previousHead = songs;
    }

    songs=newHead;

}
