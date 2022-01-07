#include "../include/LoadData.h"

std::vector<float> read_csv(const std::string file_name)
{
    std::vector<float> values;
    std::ifstream myFile;
    std::string file_path = "db/" + file_name;
    std::string word;

    try
    {
        myFile.open(file_path);
        while (myFile.good())
        {
            std::getline(myFile, word, ',');
            values.push_back(std::stof(word));
        }
    }
    catch (const std::ios_base::failure &fail)
    {
        std::cerr << fail.what() << '\n';
    }

    myFile.close();
    return values;
}