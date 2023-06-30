#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}
// rangedbaseloop

void Harl::complain( std::string level )
{
	int index = 0;
	// functionPtr[0] = &Harl::debug;
	// functionPtr[1] = &Harl::info;
	// functionPtr[2] = &Harl::warning;
	// functionPtr[3] = &Harl::error;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (; index <= 4 && level.compare(levels[index]); ++index)
	{}
	switch (index)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
	}

}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << "I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}