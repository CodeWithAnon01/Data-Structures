#include <iostream>
#include <string>
using namespace std;

class SongNode {
public:
    string songTitle;
    string artist;
    SongNode* next;
    
    SongNode(string title, string artistName) {
        songTitle = title;
        artist = artistName;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    SongNode* head;
    SongNode* currentSong;
    int totalSongs;

public:
    MusicPlaylist() {
        head = nullptr;
        currentSong = nullptr;
        totalSongs = 0;
    }

    ~MusicPlaylist() {
        if (head != nullptr) {
            SongNode* current = head;
            do {
                SongNode* temp = current;
                current = current->next;
                delete temp;
            } while (current != head);
        }
    }

    void addSong(string title, string artist) {
        SongNode* newSong = new SongNode(title, artist);
        
        if (head == nullptr) {
            head = newSong;
            currentSong = newSong;
            newSong->next = newSong;
        } else {
            SongNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newSong;
            newSong->next = head;
        }
        totalSongs++;
        cout << "Added: '" << title << "' by " << artist << endl;
    }

    void playNext() {
        if (currentSong == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        currentSong = currentSong->next;
        cout << "Now playing: '" << currentSong->songTitle << "' by " << currentSong->artist << endl;
    }

    void playPrevious() {
        if (currentSong == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        
        SongNode* prev = head;
        while (prev->next != currentSong) {
            prev = prev->next;
        }
        currentSong = prev;
        cout << "Now playing: '" << currentSong->songTitle << "' by " << currentSong->artist << endl;
    }

    void removeSong(string title) {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        if (totalSongs == 1 && head->songTitle == title) {
            delete head;
            head = nullptr;
            currentSong = nullptr;
            totalSongs = 0;
            cout << "Removed: '" << title << "' - Playlist is now empty" << endl;
            return;
        }

        SongNode* current = head;
        SongNode* prev = nullptr;
        
        do {
            if (current->songTitle == title) {
                if (current == head) {
                    SongNode* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    if (currentSong == current) {
                        currentSong = head;
                    }
                } else {
                    prev->next = current->next;
                    if (currentSong == current) {
                        currentSong = current->next;
                    }
                }
                delete current;
                totalSongs--;
                cout << "Removed: '" << title << "'" << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        
        cout << "Song '" << title << "' not found in playlist!" << endl;
    }

    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        
        cout << "\n=== PLAYLIST ===" << endl;
        SongNode* current = head;
        int position = 1;
        
        do {
            cout << position << ". '" << current->songTitle << "' by " << current->artist;
            if (current == currentSong) {
                cout << " [CURRENTLY PLAYING]";
            }
            cout << endl;
            current = current->next;
            position++;
        } while (current != head);
        
        cout << "Total songs: " << totalSongs << endl << endl;
    }

    void getCurrentSong() {
        if (currentSong == nullptr) {
            cout << "No song is currently playing!" << endl;
        } else {
            cout << "Currently playing: '" << currentSong->songTitle << "' by " << currentSong->artist << endl;
        }
    }

    void playFromBeginning() {
        if (head != nullptr) {
            currentSong = head;
            cout << "Starting playlist from beginning..." << endl;
            getCurrentSong();
        } else {
            cout << "Playlist is empty!" << endl;
        }
    }

    void shufflePlay() {
        if (totalSongs == 0) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        
        int randomSteps = rand() % totalSongs;
        SongNode* shuffled = head;
        
        for (int i = 0; i < randomSteps; i++) {
            shuffled = shuffled->next;
        }
        
        currentSong = shuffled;
        cout << "Shuffled to: '" << currentSong->songTitle << "' by " << currentSong->artist << endl;
    }
};

int main() {
    MusicPlaylist playlist;
    
    playlist.addSong("Bohemian Rhapsody", "Queen");
    playlist.addSong("Hotel California", "Eagles");
    playlist.addSong("Stairway to Heaven", "Led Zeppelin");
    playlist.addSong("Imagine", "John Lennon");
    playlist.addSong("Sweet Child O' Mine", "Guns N' Roses");
    
    playlist.displayPlaylist();
    
    playlist.getCurrentSong();
    
    playlist.playNext();
    playlist.playNext();
    playlist.displayPlaylist();
    
    playlist.playPrevious();
    playlist.getCurrentSong();
    
    playlist.removeSong("Hotel California");
    playlist.displayPlaylist();
    
    playlist.playFromBeginning();
    
    playlist.shufflePlay();
    
    cout << "\nContinuous play demonstration:" << endl;
    for (int i = 0; i < 8; i++) {
        playlist.playNext();
    }
    
    return 0;
}