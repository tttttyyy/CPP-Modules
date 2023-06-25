#include "replace.hpp"

Replace::Replace(std::string argv1, std::string argv2, std::string argv3)
{
	m_filename = argv1;
	s1 = argv2;
	s2 = argv3;
}

void	Replace::replaceStrings()
{
	std::string		tmp;
	std::ifstream	infile (m_filename);
	size_t			pos;
	size_t			index = 0;

	if (!infile.is_open())
	{
		std::cerr << "\033[31m" << "[ERROR] NO SUCH FILE !" << "\033[30m" << std::endl;
		exit(1);
	}
	if (!getline(infile, tmp, '\0'))
	{
		std::cerr << "\033[31m" << "[ERROR] FILE IS EMPTY !" << "\033[30m" << std::endl;
		infile.close();
		exit(2);
	}
	std::ofstream outfile(m_filename + ".replace");
	pos = tmp.find(s1);
	while (pos != std::string::npos)
	{
		outfile << tmp.substr(index, pos - index);
		outfile << s2;
		index = pos + s1.length();
		pos = tmp.find(s1, pos + s1.length() + 1);
	}
	outfile << tmp.substr(index);
	outfile.close();
	infile.close();
}