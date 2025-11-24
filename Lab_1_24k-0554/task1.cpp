#include <iostream>
#include <cstring>
using namespace std;

class ResearchPaper {
private:
    char* authors;
    int numAuthors;
    
public:
    ResearchPaper() {
        authors = nullptr;
        numAuthors = 0;
        cout << "Default constructor called" << endl;
    }
    
    ResearchPaper(const char* authorList, int count) {
        numAuthors = count;
        authors = new char[strlen(authorList) + 1];
        strcpy(authors, authorList);
        cout << "Parameterized constructor called" << endl;
    }
    
    ResearchPaper(const ResearchPaper& other) {
        numAuthors = other.numAuthors;
        if (other.authors != nullptr) {
            authors = new char[strlen(other.authors) + 1];
            strcpy(authors, other.authors);
        } else {
            authors = nullptr;
        }
        cout << "Copy constructor called (Deep Copy)" << endl;
    }
    
    ResearchPaper& operator=(const ResearchPaper& other) {
        cout << "Assignment operator called (Deep Copy)" << endl;
        
        if (this == &other) {
            return *this;
        }
        
        if (authors != nullptr) {
            delete[] authors;
        }
        
        numAuthors = other.numAuthors;
        if (other.authors != nullptr) {
            authors = new char[strlen(other.authors) + 1];
            strcpy(authors, other.authors);
        } else {
            authors = nullptr;
        }
        
        return *this;
    }
    
    ~ResearchPaper() {
        if (authors != nullptr) {
            delete[] authors;
        }
        cout << "Destructor called" << endl;
    }
    
    void display() const {
        cout << "Authors: " << (authors ? authors : "None") << endl;
        cout << "Number of Authors: " << numAuthors << endl;
    }
    
    void setAuthors(const char* authorList, int count) {
        if (authors != nullptr) {
            delete[] authors;
        }
        numAuthors = count;
        authors = new char[strlen(authorList) + 1];
        strcpy(authors, authorList);
    }
};

int main() {
    cout << "=== Creating paper1 ===" << endl;
    ResearchPaper paper1("John, Alice, Bob", 3);
    paper1.display();
    
    cout << "\n=== Creating paper2 using copy constructor ===" << endl;
    ResearchPaper paper2 = paper1;
    paper2.display();
    
    cout << "\n=== Creating paper3 and using assignment operator ===" << endl;
    ResearchPaper paper3;
    paper3 = paper1;
    paper3.display();
    
    cout << "\n=== Modifying paper2 to show independent copies ===" << endl;
    paper2.setAuthors("David, Eve", 2);
    
    cout << "\nPaper1 (original):" << endl;
    paper1.display();
    
    cout << "\nPaper2 (modified):" << endl;
    paper2.display();
    
    cout << "\nPaper3 (copy of original):" << endl;
    paper3.display();
    
    cout << "\n=== Program ending - destructors will be called ===" << endl;
    
    return 0;
}