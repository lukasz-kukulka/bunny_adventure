#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Single_record_file.hpp"
class Files_operations
{
public:
	Files_operations();

	int load_from_settings(int row_number);
	void save_settings(int res, int vol, bool efect, bool music, int diff);
	std::string load_score(int row_number);
	void save_score_reset();
	void delete_record(int index);
	int how_many_record_score();
	void record_ini();

private:
	int no_line;
	std::string name, data, score;
	std::vector<Single_record_file>records;
};

