#ifndef RECORDTABLE_H
#define RECORDTABLE_H
#include <string>
class RecordTable
{
    public:
        RecordTable();
        void showRecordTable();
        void writeToRecordTable(const std::string& name, const unsigned int time_game);

    private:
        const std::string file_name_{"./table_of_record.txt"};

};

#endif // RECORDTABLE_H
