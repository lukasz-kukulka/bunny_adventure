#include "Files_operations.hpp"

Files_operations::Files_operations()
{
    this->no_line = 1;
    //std::cout << records.size() << "\n";
}

int Files_operations::load_from_settings(int row_number)
{
	no_line = 1;
	std::string line;
	std::fstream file;
	file.open("settings.ini", std::ios::in);
	if (file.good() == false)
	{
		std::cout << "File not exist" << std::endl;
		exit(0);
	}
	while (getline(file, line))
	{
        if (no_line == row_number)
        {
            switch (row_number)
            {

            case 1:
            {
                return std::atoi(line.c_str());
            }

            case 2:
            {
                return std::atoi(line.c_str());
            }

            case 3:
            {
                return std::atoi(line.c_str());
            }

            case 4:
            {
                return std::atoi(line.c_str());
            }

            case 5:
            {
                return std::atoi(line.c_str());
            }

            default:
                return 0;
            }
        }
        no_line++;
	}
    file.close();
	return 0;
}

void Files_operations::save_settings(int res, int vol, bool efect, bool music, int diff)
{
    std::fstream file;
    file.open("settings.ini", std::ios::out | std::ios::trunc);
    file << res << std::endl;
    file << vol << std::endl;
    file << efect << std::endl;
    file << music << std::endl;
    file << diff << std::endl;
    file.close();
}

std::string Files_operations::load_score(int row_number)
{
    no_line = 1;
    std::string line;
    std::fstream file;
    file.open("score.txt", std::ios::in);
    if (file.good() == false)
    {
        std::cout << "File not exist" << std::endl;
        exit(0);
    }
    while (getline(file, line))
    {
        if (no_line == row_number)
        {
            return line;
        }
        no_line++;
    }
    file.close();
    return "cos";
}

void Files_operations::save_score_reset()
{
    std::fstream file;
    file.open("score.txt", std::ios::out | std::ios::trunc);
    for (int i = 0; i < records.size(); i++)
    {
        file << records[i].name_out() << std::endl;
        file << records[i].data_out() << std::endl;
        file << records[i].score_out() << std::endl;
    }
    std::cout << records.size() << " II in save \n";
    file.close();
}

void Files_operations::delete_record(int index)
{
    this->record_ini();
    this->records.erase(records.begin() + index);
    std::cout << records.size() << "in delete \n";
    this->save_score_reset();
    this->records.erase(records.begin(), records.end());
}

int Files_operations::how_many_record_score()
{
    this->record_ini();
    int record_size = records.size();
    records.erase(records.begin(), records.end());
    return record_size;
    
}

void Files_operations::record_ini()
{
    no_line = 1;
	std::string line;
	std::fstream file;
	file.open("score.txt", std::ios::in);
	if (file.good() == false)
	{
		std::cout << "File not exist" << std::endl;
		exit(0);
	}
	while (getline(file, line))
	{
		if (no_line % 3 == 1)
		{
            this->name = line;
		}
		else if (no_line % 3 == 2)
		{
            this->data = line;
		}
		else if (no_line % 3 == 0)
		{
            this->score = line;
            records.push_back(Single_record_file(name, data, score));
		}

		no_line++;
	}
    
	file.close();
}
