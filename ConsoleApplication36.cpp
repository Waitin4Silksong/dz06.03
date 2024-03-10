#include <iostream>
#include <string>
#include <fstream>

class FileManager
{
private:
	std::string name;
public:
	FileManager(std::string& name) : name{ name } {}
	bool exists(const std::string& filename)
	{
		std::ifstream file(filename);
		return file.good();
	}
	void create_file(std::string& content)
	{
		std::ofstream file(name);
		try
		{
			file.open(name);
			if (exists(name))
			{
				throw std::runtime_error("File with that name already exists");
			}
			if (!file.is_open())
			{
				throw std::runtime_error("Failed to open the file");
			}
			file << content;
			file.close();
			std::cout << "File created successfuly" << std::endl;
		}
		catch (std::exception& ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
		}
	}
	void rename_file(std::string& new_name)
	{
		try
		{
			if (name == new_name)
			{
				throw std::runtime_error("You cannot rename file on itself");
			}
			if (std::rename(name.c_str(), new_name.c_str()) != 0)
			{
				throw std::runtime_error("Failed to rename the file");
			}
			std::cout << "File renamed successfuly" << std::endl;
			name = new_name;
		}
		catch (std::exception& ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
		}
	}
	void delete_file()
	{
		try {
			if (!exists(name))
			{
				throw std::runtime_error("File with that name does not exists");
			}
			if (std::remove(name.c_str()) != 0)
			{
				throw std::runtime_error("Failed to delete file");
			}
			std::cout << "File deleted successfuly";
		}
		catch (std::exception& ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
		}
	}
	class Copy
	{
	public:

		void copy_file(std::string& source, std::string& destination)
		{
			std::ifstream src(source);
			std::ofstream dest(destination);
			try
			{
				if (!src.is_open())
				{
					throw std::runtime_error("Failed to open source file");
				}
				if (!dest.is_open())
				{
					throw std::runtime_error("Failed to open destination file");
				}
				dest << src.rdbuf();
				std::cout << "Content copied successfuly";
			}
			catch (std::exception& ex)
			{
				std::cerr << "Error: " << ex.what() << std::endl;
			}
		}
	};
};

int main()
{

}
