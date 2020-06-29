#pragma once

#include <SFML/Graphics.hpp>

class Single_record_file
{
public:
	Single_record_file(std::string name, std::string data, std::string score);
	std::string name_out();
	std::string data_out();
	std::string score_out();

private:
	std::string name, data, score;
};

