#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

constexpr size_t FSIZE = 100;

void create_file(const std::string& fileName);
void concat_files(const std::string& fileName1, const std::string& fileName2, const std::string& fileName3);
void read_file(const std::string& fileName, char** p);
bool find_word(const std::string& fileName, const std::string& word);

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    if(argc != 6)
    {
        std::cerr << "Error! Incorrect command line arguments, please input three file names." << std::endl;
        exit(EXIT_FAILURE);
    }

    // ---------#1---------
    create_file(argv[1]);
    create_file(argv[2]);

    // ---------#2---------
    concat_files(argv[1], argv[2], argv[3]);

    // ---------#3---------
    std::cout << std::boolalpha << find_word(argv[4], argv[5]) << std::endl;

    exit(EXIT_SUCCESS);
}

void create_file(const std::string& fileName)
{
    std::ofstream out(fileName);
    if(out.is_open())
    {
        for(size_t i = 0; i < FSIZE; ++i)
        {
            out << (char)(65 + rand() % (90 - 65 + 1));
        }
        out.close();
    }
    else
    {
        std::cerr << "Can't open file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
}

void concat_files(const std::string& fileName1, const std::string& fileName2, const std::string& fileName3)
{
    std::ofstream out(fileName3);
    if (!out.is_open())
    {
        std::cerr << "Can't open file: " << fileName3 << std::endl;
        exit(EXIT_FAILURE);
    }

    char* p = nullptr;
    read_file(fileName1, &p);
    out << p;
    delete [] p;
    p = nullptr;

    read_file(fileName2, &p);
    out << p;
    delete [] p;
    p = nullptr;
}

void read_file(const std::string& fileName, char** p)
{
    std::ifstream in(fileName);
    if (in.is_open())
    {
        std::streampos pos = 0;
        pos = in.tellg();
        in.seekg(0, std::ios::end);
        size_t size = in.tellg() - pos;
        in.seekg(0, std::ios::beg);
        *p = new char[size];
        in >> *p;
        in.close();
    }
    else
    {
        std::cerr << "Can't open file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool find_word(const std::string& fileName, const std::string& word)
{
    std::ifstream in(fileName);
    if (in.is_open())
    {
        std::string part;
        while(in >> part)
        {
            if (part.find(word) != std::string::npos)
            {
                in.close();
                return true;
            }
        }
    }
    else
    {
        std::cerr << "Can't open file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    in.close();
    return false;
}
