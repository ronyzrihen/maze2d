#include "file.h"


file::file(vector<int>& maze ,string name ,string dir): f_dir(dir),f_name(name) {
    save(maze);
}

vector<int>  file::load(){
    vector<int> convertedFile;
    fstream aFile;
    aFile.open(f_dir + f_name , ios::in);
    if( aFile.is_open()){
        string content;
        getline(aFile,content);
        aFile.close();

        for(int i = 0 ; i < content.size() ; i++){
            if(content[i] == '-'){
                convertedFile.push_back(-1);
                i++;
                continue;
            }
            int convertedLetter = content[i] - '0';
            convertedFile.push_back(convertedLetter);
    }
        return convertedFile;
}
    throw open_failed();

}

void file::save(vector<int> maze) {

    string Path = f_dir + f_name;
    fstream newFile;
    newFile.open(Path, ios::out);
    if (newFile.is_open()) {

        for (int num: maze) {
            newFile << num;
        }
        newFile.close();
        f_size = filesystem::file_size(Path);
    }
}

