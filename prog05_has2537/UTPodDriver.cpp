/* UTPod_driver.cpp
Demo Driver for the UTPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UTPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    //make Ut Pod without parameters
    UTPod t;

    //Add 10 songs to test AddSongs method alone and Song functions.
    cout <<"Add 10 songs, all valid. To no param UTPod" << endl;

    int result;
    Song s1("Beatles", "Hey Jude3", 6);
    result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s2("Beatles", "Hey Jude4", 7);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    Song s3("Beatles", "Hey Jude5", 241);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Imagine Dragons", "Thunder",50);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Kelly Clarkson", "Champions", 3);
    result = t.addSong(s5);
    cout << "result = " << result << endl;

    Song s6("LMFAO", "Party Rock", 1);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    Song s7("Britney Spears", "Scream", 1);
    result = t.addSong(s7);
    cout << "result = " << result << endl;

    Song s8("DJ", "High Hopes", 5);
    result = t.addSong (s8);
    cout << "result = " << result << endl;

    Song s9("Taylor Swift", "Shake it off", 20);
    result = t.addSong (s9);
    cout << "result = " << result << endl;

    Song s10("Taylor Swift", "Bad and Beautiful", 20);
    result = t.addSong (s10);
    cout << "result = " << result << endl;

    t.showSongList(); //verify all songs are there in proper form.
    cout<<"Remaining Memory= " << t.getRemainingMemory()<<endl;
    cout<<"Expected Remaining Memory= " << 512-(6+7+241+50+3+1+1+5+20+20)<<endl;
    cout<<"Total memory= " <<t.getTotalMemory()<<endl;
    cout<<"\n";

    //Test shuffle method
    cout<<"Shuffle List above Test" <<endl;
    t.shuffle();
    //verify it is randomly shuffled well
    t.showSongList();

    //Remove indicated songs and verify results.
    cout<<"Removing Songs. Jude3, Jude4, Jude5, High Hopes, Shake It Off."<<endl;
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s9);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s8);
    cout << "delete result = " << result << endl;

    //verify remove function results.
    t.showSongList();
    cout <<"Remaining memory = " << t.getRemainingMemory() << endl;
    cout <<"Expected Remaining memory = " << 512-(6+7+241+50+3+1+1+5+20+20)+20+5+241+6+7<< endl;

    //clear memory and Test
    cout<<"Clear UtPod" <<endl;
    t.clearMemory();
    t.showSongList();
    cout<<"Total Memory: "<<t.getTotalMemory()<<endl;
    cout<<"Remaining memory= "<<t.getRemainingMemory()<<endl;
    cout <<"Expected Remaining memory = " <<512<< endl;
    cout<<"\n\n";

    cout<<"Checking Sort function: "<<endl;
    Song p1("Lil wayne","New Freezer",50);
    t.addSong(p1);
    Song p2("Lil wayne","Amilli",100);
    t.addSong(p2);
    Song p3("Lil wayne","Amilli",50);
    t.addSong(p3);
    Song p4("Kendrick Lamar","New Freezer",100);
    t.addSong(p4);

    cout<<"New List of Songs: "<<endl;
    t.showSongList();
    t.sortSongList();
    cout<<"Sorted list:"<<endl;
    t.showSongList();
}