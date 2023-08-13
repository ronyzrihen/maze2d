#include "file.h"


file::file(vector<int>& maze ,string name ,filesystem::path dir): f_dir(dir), f_name(name){
    string Path = dir.string() + name +".txt";
fstream newFile;
newFile.open(Path, ios::out);
for(int num : maze){
    newFile << num;
}

newFile.close();

    f_size = filesystem::file_size(Path);
}