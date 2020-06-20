#include "Files_operations.hpp"

Files_operations::Files_operations()
{
}

int Files_operations::load_from_settings(int row_number)
{
	int no_line = 1;
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
	return 0;
}

void Files_operations::save_settings(int res, int vol, bool efect, bool music, int diff)
{
    std::fstream file;
    std::cout << res << " ---------------- " << diff << "\n";
    
    file.open("settings.ini", std::ios::out | std::ios::trunc);
    file << res << std::endl;
    file << vol << std::endl;
    file << efect << std::endl;
    file << music << std::endl;
    file << diff << std::endl;
    file.close();
}



