#pragma once
#include <fstream>
#include <iostream>
#include <string>
class Files_operations
{
public:
	Files_operations();

	int load_from_settings(int row_number);
	void save_settings(int res, int vol, bool efect, bool music, int diff);
	std::string load_score(int row_number);
	int how_many_record_score();

private:
	
};

