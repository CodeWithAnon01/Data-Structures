#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct FileItem {
    string name;
    int sizekb;
    bool isFolder;
    vector<FileItem*> kids;
};

int getFolderSize(FileItem* item) {
    if (!item->isFolder)
        return item->sizekb;
    int total = 0;
    for (auto kid : item->kids)
        total += getFolderSize(kid);
    return total;
}

int main() {
    FileItem* root = new FileItem{"root", 0, true, {}};

    FileItem* docs = new FileItem{"docs", 0, true, {}};
    FileItem* f1 = new FileItem{"resume.pdf", 120, false, {}};
    FileItem* f2 = new FileItem{"notes.txt", 50, false, {}};
    docs->kids.push_back(f1);
    docs->kids.push_back(f2);

    FileItem* imgs = new FileItem{"images", 0, true, {}};
    FileItem* f3 = new FileItem{"photo.jpg", 300, false, {}};
    FileItem* f4 = new FileItem{"bg.png", 200, false, {}};
    imgs->kids.push_back(f3);
    imgs->kids.push_back(f4);

    root->kids.push_back(docs);
    root->kids.push_back(imgs);

    FileItem* f5 = new FileItem{"main.cpp", 10, false, {}};
    root->kids.push_back(f5);

    int totalSize = getFolderSize(root);
    cout << "total folder size: " << totalSize << " KB" << endl;
    cout << "docs folder size: " << getFolderSize(docs) << " KB" << endl;
    cout << "images folder size: " << getFolderSize(imgs) << " KB" << endl;

    return 0;
}
