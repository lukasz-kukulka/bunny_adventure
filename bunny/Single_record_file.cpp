#include "Single_record_file.hpp"

Single_record_file::Single_record_file(std::string name, std::string data, std::string score)
{
	this->name = name;
	this->data = data;
	this->score = score;
}

std::string Single_record_file::name_out()
{
	return name;
}

std::string Single_record_file::data_out()
{
	return data;
}

std::string Single_record_file::score_out()
{
	return score;
}
