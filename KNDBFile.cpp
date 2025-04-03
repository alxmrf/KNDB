#include<fstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstddef>


class KNDBFile{
    private: std::fstream FILE;
    private: std::string FILE_PATH;
    private: char MAGIC_NUMBER_ [4] = {'k','n','d','b'};
    private: float VERSION_NUMBER = 0.1;
    private: int page_number = 1;





    public: 
    
    KNDBFile(char* filePath){
        this -> FILE_PATH = filePath;
        this -> FILE.open(this -> FILE_PATH.c_str(), std::ios_base::binary | std::ios_base::in| std::ios_base::out );
    }

    KNDBFile(){

        this -> FILE_PATH = this -> generate_unique_string();
        this -> FILE.open(FILE_PATH.c_str() , std::ios_base::out | std::ios_base::in | std::ios_base::binary);
        this -> write_file_header();
        std::cout << FILE_PATH;
    }
    

    private:

    bool is_file_empty(){
        if (!this -> FILE.is_open()){
            std::cerr << "There is no file in this file path";
        }
        this -> FILE.gcount();
        return true;
    }

    void set_version(float versionNumber){
        if (versionNumber == NULL){
            this -> VERSION_NUMBER = 0.1;
        }
        this -> VERSION_NUMBER = versionNumber;
    }

    std::string generate_unique_string(){
        std::time_t time_now = std::time(nullptr);
        std::stringstream ss;     
        ss<<"KNDB" <<time_now <<".kndb";
        return ss.str();
    } 

    void write_file_header(){
        FILE.write("KNDB",4);
        FILE.write(reinterpret_cast<char*>(&VERSION_NUMBER), sizeof(VERSION_NUMBER));
        FILE.write(reinterpret_cast<char*>(&page_number),sizeof(page_number));

    }

    void set_version_number(float version){
        this->VERSION_NUMBER = version; 
    }
};

int main (){
    KNDBFile teste;
    return 0;
}