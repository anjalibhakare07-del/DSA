#include <iostream
>
#include <string
>
using namespace std;
class Node {
public:
string songTitle;
string artistName;
Node* prev;
Node* next;
Node(string title, string artist) {
songTitle = title;
artistName = artist;
prev = nullptr;
next = nullptr; }
};
class MusicPlaylist {
private:
Node* head;
Node* current;
public:
MusicPlaylist() {
head = nullptr;
current = nullptr; }
void addSong(string title, string artist) {
Node* p = new Node(title, artist);
if (head == nullptr) {
head = p;
current = head;
cout << "Song added successfully.\n";
return; }
Node* q = head;
while (q-
>next != nullptr)
q = q-
>next;
q-
>next = p;
p-
>prev = q;
cout << "Song added successfully.\n"; }
void deleteSong(string title) {
if (head == nullptr) {
cout << "Playlist is empty.\n";
return; }
Node* q = head;
while (q != nullptr && q-
>songTitle != title)
q = q-
>next;
if (q == nullptr) {
cout << "Song not found in playlist.\n";
return; }
Node* p = q;
if (p == head) {
head = head-
>next;
if (head != nullptr)
head-
>prev = nullptr;
if (current == p)
current = head;
delete p;
cout << "Song deleted successfully.\n";
return; }
if (p-
>prev != nullptr)
p-
>prev-
>next = p-
>next;
if (p-
>next != nullptr)
p-
>next-
>prev = p-
>prev;
if (current == p) {
if (p-
>next != nullptr)
current = p-
>next;
else
current = p-
>prev;
}
delete p;
cout << "Song deleted successfully.\n"; }
void displayPlaylist() {
if (head == nullptr) {
cout << "Playlist is empty.\n";
return; }
Node* q = head;
int count = 1;
while (q != nullptr) {
cout << count << ". " << q-
>songTitle
<< " - " << q-
>artistName;
if (q == current)
cout << " [CURRENT]";
cout << endl;
q = q-
>next;
count++; }}
void displayReverse() {
if (head == nullptr) {
cout << "Playlist is empty.\n";
return; }
Node* q = head;
while (q-
>next != nullptr)
q = q-
>next;
while (q != nullptr) {
cout << q-
>songTitle
<< " - " << q-
>artistName << endl;
q = q-
>prev;
}}
void showCurrentSong() {
if (current == nullptr)
cout << "No song is currently selected.\n";
else
cout << "Current Song: " << current-
>songTitle
<< " - " << current-
>artistName << endl;
}
void playCurrentSong() {
if (current == nullptr)
cout << "No song available to play.\n";
else
cout << "Now Playing: " << current-
>songTitle
<< " - " << current-
>artistName << endl;
}
void nextSong() {
if (current == nullptr)
cout << "Playlist is empty.\n";
else if (current-
>next == nullptr)
cout << "Already at the last song.\n";
else {
current = current-
>next;
playCurrentSong(); }
}
void previousSong() {
if (current == nullptr)
cout << "Playlist is empty.\n";
else if (current->prev == nullptr)
cout << "Already at the first song.\n";
else {
current = current->prev;
playCurrentSong();
}
}
void playCompletePlaylist() {
Node* q = head;
if (q == nullptr) {
cout << "Playlist is empty.\n";
return;
}
while (q != nullptr) {
cout << "Now Playing: " << q->songTitle
<< " - " << q->artistName << endl;
q = q->next;
}
}
void repeatAll(int repetitions) {
if (head == nullptr) {
cout << "Playlist is empty.\n";
return;
}
for (int i = 1; i <= repetitions; i++) {
Node* q = head;
cout << "\n--- Playlist Round " << i << " ---\n";

while (q != nullptr) {
cout << "Playing: " << q->songTitle
<< " - " << q->artistName << endl;
q = q->next;
}
}
}
};
int main() {
MusicPlaylist playlist;
int choice, repetitions;
string title, artist;
do {
cout << "\n========== MUSIC PLAYLIST MANAGER ==========\n";
cout << "1. Add Song\n2. Delete Song\n";
cout << "3. Display Playlist\n4. Display Playlist in Reverse\n";
cout << "5. Play Current Song\n6. Play Next Song\n";
cout << "7. Play Previous Song\n8. Play Complete Playlist\n";
cout << "9. Repeat All\n10. Show Current Song\n11. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cin.ignore();
cout << "Enter song title: ";
getline(cin, title);
cout << "Enter artist name: ";
getline(cin, artist);
playlist.addSong(title, artist);
break;
case 2:
cin.ignore();
cout << "Enter song title to delete: ";
getline(cin, title);
playlist.deleteSong(title);
break;
case 3:
playlist.displayPlaylist();
break;
case 4:
playlist.displayReverse();
break;
case 5:
playlist.playCurrentSong();
break;
case 6:
playlist.nextSong();
break;
case 7:
playlist.previousSong();
break;
case 8:
playlist.playCompletePlaylist();
break;
case 9:
cout << "Enter number of repetitions: ";
cin >> repetitions;
playlist.repeatAll(repetitions);
break;
case 10:
playlist.showCurrentSong();
break;
case 11:
cout << "Exiting Music Playlist Manager...\n";
break;
default:
cout << "Invalid choice.\n";
}
} while (choice != 11);
return 0;
}
