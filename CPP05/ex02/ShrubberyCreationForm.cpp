#include "ShrubberyCreationForm.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, std::string target) : AForm(137, 145, name), _target(target)
{
    std::cout << "Shrubbery Creation form: " << getName() << " as been adopted, Sign grade: " << getSignGrade() << ", Exec grade:" << getExecGrade() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberycreationform) : AForm(shrubberycreationform)
{
    *this = shrubberycreationform;
    std::cout << "Shrubbery Creation form: " << getName() << " as been copied." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Creation form: " << getName() << " as been dismissed." << std::endl;
}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &f)
{
    _target = f._target;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//

std::string         ShrubberyCreationForm::getTarget() const
{
    return _target;
}

//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool                ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (getIsSigned())
    {
        if (executor.getGrade() < getExecGrade())
        {
            std::string fName = _target + "_shrubbery";
            std::ofstream file(fName.c_str());
            if (!file.is_open())
                throw std::runtime_error("Can' t open file shrubbery");
            file << "               ,@@@@@@@,\n";
            file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
            file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888'\'88/8o\n";
            file << "   ,%&'\'%&&%&&%,@@@'\'@@@/@@@88'\'88888/88'\n";
            file << "   %&&%&%&/%&&%@@'\'@@/ /@@@88888'\'88888'\n";
            file << "   %&&%/ %&%%&&@@'\' V /@@' `88'\'8 `/88'\n";
            file << "   `&%'\' ` /%&'    |.|        '\' '|8'\n";
            file << "       |o|        | |         | |'\n";
            file << "       |.|        | |         | |'\n";
            file << "    _'\'/ ._'\'/__/__/  ,'\'_/____'\'/.  '\'_/___/_\n";
            file.close();
            return (true);
        }
        else
            throw Bureaucrat::GradeTooLowException(); 
    }
    else
        throw AForm::NotSignedException();
    return (false);
}
