#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <cstdint>

#pragma pack(push, 1)
struct FileHeader {
    char signature[4];
    uint16_t version;
    uint32_t student_count;
};
#pragma pack(pop)

//forward declaration
class Student;

using namespace std;

class FileManager {
private:
    static constexpr const char* DEFAULT_SIGNATURE = "GRD";
    static constexpr uint16_t CURRENT_VERSION = 1;

public:
    static bool save_to_file(const string& filename,
        const vector<Student*>& students,
        const vector<double>& allGrades);
    static bool load_from_file(const string& filename,
        vector<Student*>& students,
        vector<double>& allGrades);
    static bool check_signature(const string& filename);
    
    //inline метод
    inline static size_t get_header_size() {
        return sizeof(FileHeader);
    }
};

#endif
