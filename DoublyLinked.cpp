#include <iostream>
#include <string>

using namespace std;

struct PodcastNode {
    string title;
    int duration; // dalam menit
    string category; // "Wawancara", "Berita", "Tips Mahasiswa"
    PodcastNode* next;
    PodcastNode* prev;

    PodcastNode(string t, int d, string c) : title(t), duration(d), category(c), next(nullptr), prev(nullptr) {}
};

class PodcastPlaylist {
private:
    PodcastNode* head;
    PodcastNode* tail;

public:
    PodcastPlaylist() : head(nullptr), tail(nullptr) {}

    // Menambahkan podcast di akhir playlist
    void addPodcast(string title, int duration, string category) {
        PodcastNode* newPodcast = new PodcastNode(title, duration, category);
        if (!head) {
            head = tail = newPodcast;
        } else {
            tail->next = newPodcast;
            newPodcast->prev = tail;
            tail = newPodcast;
        }
    }

    // Menyisipkan podcast di tengah playlist setelah judul tertentu
    void insertAfter(string afterTitle, string title, int duration, string category) {
        PodcastNode* current = head;
        while (current) {
            if (current->title == afterTitle) {
                PodcastNode* newPodcast = new PodcastNode(title, duration, category);
                newPodcast->next = current->next;
                newPodcast->prev = current;

                if (current->next) {
                    current->next->prev = newPodcast;
                } else {
                    tail = newPodcast; // update tail jika di akhir
                }
                current->next = newPodcast;
                return;
            }
            current = current->next;
        }
        cout << "Podcast dengan judul " << afterTitle << " tidak ditemukan." << endl;
    }

    // Menampilkan playlist dari depan
    void displayForward() {
        PodcastNode* current = head;
        while (current) {
            cout << "Judul: " << current->title 
                 << ", Durasi: " << current->duration 
                 << " menit, Kategori: " << current->category << endl;
            current = current->next;
        }
    }

    // Menampilkan playlist dari belakang
    void displayBackward() {
        PodcastNode* current = tail;
        while (current) {
            cout << "Judul: " << current->title 
                 << ", Durasi: " << current->duration 
                 << " menit, Kategori: " << current->category << endl;
            current = current->prev;
        }
    }

    // Menghapus podcast berdasarkan judul
    void removePodcast(string title) {
        PodcastNode* current = head;
        while (current) {
            if (current->title == title) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next; // Jika node yang dihapus adalah head
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev; // Jika node yang dihapus adalah tail
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Podcast dengan judul " << title << " tidak ditemukan." << endl;
    }

    ~PodcastPlaylist() {
        while (head) {
            PodcastNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PodcastPlaylist playlist;

    // Menambahkan beberapa podcast
    playlist.addPodcast("Podcast 1", 30, "Wawancara");
    playlist.addPodcast("Podcast 2", 45, "Berita");
    playlist.addPodcast("Podcast 3", 20, "Tips Mahasiswa");

    cout << "Playlist dari depan:" << endl;
    playlist.displayForward();

    cout << "\nMenambahkan Podcast 4 setelah Podcast 1:" << endl;
    playlist.insertAfter("Podcast 1", "Podcast 4", 25, "Wawancara");
    playlist.displayForward();

    cout << "\nPlaylist dari belakang:" << endl;
    playlist.displayBackward();

    cout << "\nMenghapus Podcast 2:" << endl;
    playlist.removePodcast("Podcast 2");
    playlist.displayForward();

    return 0;
}