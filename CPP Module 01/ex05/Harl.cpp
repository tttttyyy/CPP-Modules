#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}
// rangedbaseloop

void Harl::complain( std::string level )
{
	int index = 0;

	void	(Harl::*functionPtr[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (; index <= 4 && level.compare(levels[index]); ++index)
	{
		if (index == 4)
		{
			std::cerr << "\033[31m" << "[ERROR] INCORRECT COMMAND !" << "\033[0m" << std::endl;
			return ;
		}
	}
	(this->*functionPtr[index])();
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << "I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}