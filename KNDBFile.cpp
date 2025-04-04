#include<fstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstddef>
#include"KNDBFile.hpp"
#include"./CollumnTypes/KNDBCollumnObject.hpp"


//Constructors    
//This constructor opens an instance of a KNDB file if there exists any , if not it will create a file with the specified name

KNDBFile::KNDBFile(char* filePath){
    this -> FILE_PATH = filePath;
    this -> FILE.open(this -> FILE_PATH.c_str(), std::ios_base::binary | std::ios_base::in| std::ios_base::out );
}


//This constructor creates a KNDB file with a automatically generated random name 
KNDBFile::KNDBFile(){

    this -> FILE_PATH = this -> generate_unique_string();
    this -> FILE.open(FILE_PATH.c_str() , std::ios_base::out | std::ios_base::in | std::ios_base::binary);
    this -> write_file_header();
    std::cout << FILE_PATH;
}




void KNDBFile::set_version(float versionNumber){
    if (versionNumber == NULL){
        this -> VERSION_NUMBER = 0.1;
    }
    this -> VERSION_NUMBER = versionNumber;
}




bool KNDBFile::is_file_empty(){
    if (!this -> FILE.is_open()){
        std::cerr << "There is no file in this file path";
    }
    this -> FILE.gcount();
    return true;
}

//generates an unique string using the pattern KNDB, current unix time stamp , .kndb
std::string KNDBFile::generate_unique_string(){
    std::time_t time_now = std::time(nullptr);
    std::stringstream ss;     
    ss<<"KNDB" <<time_now <<".kndb";
    return ss.str();
} 
//writes the header in a file in binary mode
void KNDBFile::write_file_header(){
    FILE.write("KNDB",4);
    FILE.write(reinterpret_cast<char*>(&VERSION_NUMBER), sizeof(VERSION_NUMBER));
    FILE.write(reinterpret_cast<char*>(&page_number),sizeof(page_number));
}

void KNDBFile::set_version_number(float version){
    this->VERSION_NUMBER = version; 
}

void KNDBFile::setColumns(KNDBCollumnObject collumnType){
}



