#ifndef KNDBFILE_H
#define KNDBFILE_H

#include<fstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstddef>
#include"./CollumnTypes/KNDBCollumnObject.hpp"


class KNDBFile{
   
    private:

     std::fstream FILE;
     std::string FILE_PATH;
     static inline char MAGIC_NUMBER_ [4] = {'k','n','d','b'};
     static inline float VERSION_NUMBER = 0.1;
     int page_number;

    //Constructors    
    public: 
    //This constructor opens an instance of a KNDB file if there exists any , if not it will create a file with the specified name
    KNDBFile(char* filePath);

    //This constructor creates a KNDB file with a automatically generated random name 
    KNDBFile();



    private:

    void set_version(float versionNumber);



    bool is_file_empty();
    //generates an unique string using the pattern KNDB, current unix time stamp , .kndb


    std::string generate_unique_string();


    //writes the header in a file in binary mode
    void write_file_header();
  
    void set_version_number(float version);

    void setColumns(KNDBColumnObject collumnType);
};





#endif
