#pragma once
#include <fstream>
#include <iostream>
#include <string>
class Files_operations
{
public:
	Files_operations();

	int load_from_settings(int row_number);
	void save_settings(struct settings* settings_save);

private:

};

