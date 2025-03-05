#include "recordtable.h"
#include <fstream>
#include <QDebug>

RecordTable::RecordTable() {}

void RecordTable::showRecordTable(){

}

void RecordTable::writeToRecordTable(const std::string& name, const unsigned int time_game){
    std::ofstream file;
    file.open(file_name_,std::ios::app);
    if(file.is_open()){
        std::string temp_str = name + '|' + std::to_string(time_game)+'\n';
        file << temp_str;
        file.close();
    }
}
