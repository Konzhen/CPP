#include "ScalarConverter.hpp"

//--------------------------------------------------------------------------//
//	 	             - CONSTRUCTORS & DESTRUCTORS -							//
//--------------------------------------------------------------------------//

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const &scalarconverter)
{
    *this = scalarconverter;
}

ScalarConverter::~ScalarConverter()
{

}


//--------------------------------------------------------------------------//
//	 	                      - OPERATORS -	    						    //
//--------------------------------------------------------------------------//

ScalarConverter    &ScalarConverter::operator=(ScalarConverter const &scalarconverter)
{
    (void)scalarconverter;
    return (*this);
}


//--------------------------------------------------------------------------//
//	 					  - GETTERS & SETTERS -							    //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//	 					  - MEMBER FUNCTIONS -							    //
//--------------------------------------------------------------------------//

bool      ScalarConverter::isInt(const char *p)
{
    regex_t     regex;

    const char  *pattern("^[+-]?[0-9]+$");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Regex compilation failed.");
    
    int status = regexec(&regex, p, 0, NULL, 0);

    regfree(&regex);
    if (!status)
        return (true);
    else if (status == REG_NOMATCH)
        return (false);
    else
        throw std::runtime_error("Regex execution failed");
}

bool      ScalarConverter::isFloat(const char *p)
{
    if (!strcmp(p, "-inff") || !strcmp(p, "+inff") || !strcmp(p, "nanf"))
        return (true);
    regex_t     regex;

    const char  *pattern("^[+-]?[0-9]+\\.[0-9]+f$");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Regex compilation failed.");
    
    int status = regexec(&regex, p, 0, NULL, 0);

    regfree(&regex);
    if (!status)
        return (true);
    else if (status == REG_NOMATCH)
        return (false);
    else
        throw std::runtime_error("Regex execution failed");
}

bool      ScalarConverter::isChar(const char *p)
{
    regex_t     regex;

    const char  *pattern("^[^0-9]$");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Regex compilation failed.");

    int status = regexec(&regex, p, 0, NULL, 0);

    regfree(&regex);
    if (!status)
        return (true);
    else if (status == REG_NOMATCH)
        return (false);
    else
        throw std::runtime_error("Regex execution failed");
}

bool      ScalarConverter::isDouble(const char *p)
{
    if (!strcmp(p, "-inf") || !strcmp(p, "+inf") || !strcmp(p, "nan"))
        return (true);

    regex_t     regex;

    const char  *pattern("^[+-]?[0-9]+\\.[0-9]+$");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Regex compilation failed.");
    
    int status = regexec(&regex, p, 0, NULL, 0);

    regfree(&regex);
    if (!status)
    {
        return (true);
    }
    else if (status == REG_NOMATCH)
        return (false);
    else
        throw std::runtime_error("Regex execution failed");
}

int    ScalarConverter::findType(const char *p)
{
    if (isInt(p))
        return (INT);
    else if (isFloat(p))
        return (FLOAT);
    else if (isChar(p))
        return (CHAR);
    else if (isDouble(p))
        return (DOUBLE);
    else
        return (NONDISPLAYABLE);
}

std::string         ScalarConverter::convertToInt(std::string p, int src)
{
    std::stringstream   s(p);
    std::stringstream   tmp;
    int                 i;

    if (src == CHAR)
    {
        char    c;

        s >> c;
        i = static_cast<int>(c);

        tmp << i;
        return (tmp.str());        
    }
    if (s >> i && !s.fail())
    {
        tmp << i;
        return (tmp.str());
    }
    return ("impossible");
}

std::string        ScalarConverter::convertToFloat(std::string p, int src)
{
    std::stringstream   s(p);
    std::stringstream   tmp;
    float               f;

    if (src == FLOAT)
        if (!strcmp(p.c_str(), "+inff") || !strcmp(p.c_str(), "-inff") || !strcmp(p.c_str(), "nanf"))
            return (p);
    if (src == CHAR)
    {
        char    c;
        int     i;

        s >> c;
        i = static_cast<int>(c);

        tmp << i << ".0f";
        return (tmp.str());        
    }
    else if (src == DOUBLE)
    {
        if (!strcmp(p.c_str(), "+inf"))
            return ("+inff");
        else if (!strcmp(p.c_str(), "-inf"))
            return ("-inff");
        else if (!strcmp(p.c_str(), "nan"))
            return ("nanf");
        float          fd;

        if (s >> fd && !s.fail())
        {
            float           cmp;
            long long int   i;

            i = static_cast<long long int>(fd);
            cmp = static_cast<double>(i);
            f = static_cast<float>(fd);
            if (fd > cmp)
                tmp << f << "f";
            else
                tmp << f << ".0f";
            return (tmp.str());
        }
    }
    else
    {
        if (s >> f && !s.fail())
        {
            if (src == FLOAT)
            {
                if (p[0] == '+')
                   return (p.erase(0, 1)); 
                return (p);
            }
            else
                tmp << f << ".0f";
            return (tmp.str());
        }
    }
    return ("impossible");
}

std::string         ScalarConverter::convertToChar(std::string p, int src)
{
    std::stringstream s(p);
    int  i;

    if (src == CHAR)
        return (s.str());
    else if (src == DOUBLE || src == FLOAT)
    {
        double  d;
        double  cmp;

        s >> d;
        i = static_cast<int>(d);
        cmp = static_cast<double>(i);

        if (d > cmp)
            return ("Non displayable");
        else
        {
            if (i < 33 || i > 126)
                return ("Non displayable");
            std::stringstream   tmp;
            char c;

            c = i;
            tmp << "\'" << c << "\'";
            return (tmp.str());
        }
    }
    if (s >> i && !s.fail())
    {
        if (i < 33 || i > 126)
            return ("Non displayable");
        std::stringstream   tmp;
        char c;

        c = i;
        tmp << "\'" << c << "\'";
        return (tmp.str());
    }
    return ("Non displayable");
}

std::string       ScalarConverter::convertToDouble(std::string p, int src)
{
    std::stringstream   s(p);
    std::stringstream   tmp;
    double              d;

    if (src == DOUBLE)
        if (!strcmp(p.c_str(), "+inf") || !strcmp(p.c_str(), "-inf") || !strcmp(p.c_str(), "nan"))
            return (p);
    if (src == CHAR)
    {
        char    c;
        int     i;

        s >> c;
        i = static_cast<int>(c);

        tmp << i << ".0";
        return (tmp.str());   
    }
    else if (src == FLOAT)
    {
        if (!strcmp(p.c_str(), "+inff"))
            return ("+inf");
        else if (!strcmp(p.c_str(), "-inff"))
            return ("-inf");
        else if (!strcmp(p.c_str(), "nanf"))
            return ("nan");
        double          dd;

        if (s >> dd && !s.fail())
        {
            double           cmp;
            long long int    i;

            i = static_cast<long long int>(dd);
            cmp = static_cast<double>(i);
            d = static_cast<double>(dd);
            if (dd > cmp) 
                tmp << d;
            else
                tmp << d << ".0";
            return (tmp.str());
        }        
    }
    {
        if (s >> d && !s.fail())
        {
            std::stringstream   tmp;

            if (src != FLOAT && src != DOUBLE)
                tmp << d << ".0";
            else
                tmp << d;
            return (tmp.str());
        }
    }
    return ("impossible");
}

void    ScalarConverter::convert(std::string const &p)
{
    int type = findType(p.c_str());

    switch (type)
    {
        case 0:
        {
            std::cout << "char: " << convertToChar(p, INT) << std::endl;
            std::cout << "int: " << convertToInt(p, INT) << std::endl;
            std::cout << "float: " << convertToFloat(p, INT) << std::endl;
            std::cout << "double: " << convertToDouble(p, INT) << std::endl;
            break;
        } 
        case 1:
        {
            std::cout << "char: " << convertToChar(p, FLOAT) << std::endl;
            std::cout << "int: " << convertToInt(p, FLOAT) << std::endl;
            std::cout << "float: " << convertToFloat(p, FLOAT) << std::endl;
            std::cout << "double: " << convertToDouble(p, FLOAT) << std::endl;
            break;
        } 
        case 2:
        {
            std::cout << "char: " << convertToChar(p, CHAR) << std::endl;
            std::cout << "int: " << convertToInt(p, CHAR) << std::endl;
            std::cout << "float: " << convertToFloat(p, CHAR) << std::endl;
            std::cout << "double: " << convertToDouble(p, CHAR) << std::endl;
            break;
        } 
        case 3:
        {
            std::cout << "char: " << convertToChar(p, DOUBLE) << std::endl;
            std::cout << "int: " << convertToInt(p, DOUBLE) << std::endl;
            std::cout << "float: " << convertToFloat(p, DOUBLE) << std::endl;
            std::cout << "double: " << convertToDouble(p, DOUBLE) << std::endl;
            break;
        }   
        default:
        {
            std::cout << "char: " << "Non displayable" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << "impossible" << std::endl;
            std::cout << "double: " << "impossible" << std::endl;
            break;
        }
    }
}