#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Single_record_file.hpp"
class Files_operations
{
public:
	Files_operations();

	uint16_t load_from_settings(uint8_t row_number);
	void save_settings(uint16_t res, uint8_t vol, bool efect, bool music, uint8_t diff);
	std::string load_score(uint8_t row_number);
	std::string load_best_score();
	void save_score_reset();
	void sort_best_score();
	void delete_record(uint16_t index);
	uint16_t how_many_record_score();
	void record_ini();

private:
	uint16_t no_line;
	std::string name, data, score;
	std::vector<Single_record_file>records;
	std::vector<Single_record_file>temp_single_record;
	//struct single_record_struct
	//{
	//	std::string name;
	//	std::string data;
	//	std::string score;
	//};
	//std::vector<single_record_struct>score_record_struct;
	//std::string temp_string;
};

