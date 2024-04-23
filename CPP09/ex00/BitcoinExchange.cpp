 #include "BitcoinExchange.hpp"

//--------------------------------------------------------------------------//
//                      - CONSTRUCTORS & DESTRUCTORS -                      //
//--------------------------------------------------------------------------//

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

//--------------------------------------------------------------------------//
//                               - OPERATORS -                              //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - GETTERS & SETTERS -                          //
//--------------------------------------------------------------------------//



//--------------------------------------------------------------------------//
//                           - MEMBER FUNCTIONS -                           //
//--------------------------------------------------------------------------//

bool    isValidDate(std::string inputLine)
{
    int year = atoi(inputLine.substr(0, 4).c_str());
    int month = atoi(inputLine.substr(5, 2).c_str());
    int day = atoi(inputLine.substr(8, 2).c_str());
    if (year <= 2009 && month <= 1 && day < 2)
        return false;

    if (year < 2009 || year > 2050)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31 ||
        (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) ||
        (day > 29 && month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) ||
        (day > 28 && month == 2 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
        return false;
    return true;
}

void BitcoinExchange::printNearestDate(std::string input, std::map<std::string, long double> &btc, float value)
{
    std::map<std::string, long double>::iterator it = btc.lower_bound(input.substr(0, 10));
    it--;
    std::cout << it->first.substr(0, 10) << " => " << value << " = " << it->second * value << std::endl;
}

std::map<std::string, long double> BitcoinExchange::createBtcMap()
{
    std::ifstream file("./data.csv");
    std::map<std::string, long double> btc;

    if (file.is_open())
    {
        std::string tmp;
        getline(file, tmp);
        
        while (std::getline(file, tmp))
        {
            std::string date = tmp.substr(0, 10);

            char *end;
            long double rate = strtod(tmp.substr(11).c_str(), &end);
            btc.insert(std::make_pair(date, rate));
        }
        file.close();
        return (btc);
    }
    else
    {
        file.close();
        throw std::runtime_error("Error: Can' t open file data.csv, maybe it doesn' t exist ?\n");
    }
    file.close();
    return (btc);
}

void    BitcoinExchange::evaluateInputWithBtc(std::string inputLine, std::map<std::string, long double> &btc)
{
    regex_t     regex;

    const char  *pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2}");

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        throw std::runtime_error("Error: Regex compilation failed.");
    
    int status = regexec(&regex, inputLine.substr(0, 10).c_str(), 0, NULL, 0);

    regfree(&regex);
    if (status == REG_NOMATCH)
        throw std::runtime_error("Error: bad input " + inputLine + ".");

    if (!isValidDate(inputLine))
        throw std::runtime_error("Error: bad date format " + inputLine + ".");

    if (inputLine.substr(10, 3) != " | ")
        throw std::runtime_error("Error: bad delimiter " + inputLine + ".");

    int onlyOne = 0;
    for (size_t i = 13; i < inputLine.length(); i++)
    {
        if (inputLine[i] == '.')
            onlyOne++;
        if (onlyOne > 1)
            throw std::runtime_error("Error: bad input " + inputLine + ".");
        if (!isdigit(inputLine[13]) || !isdigit(inputLine[inputLine.length() - 1]))
            throw std::runtime_error("Error: bad input " + inputLine + ".");
        if ((inputLine[i] < '0' || inputLine[i] > '9') && inputLine[i] != '.')
            throw std::runtime_error("Error: bad input " + inputLine + ".");
    }
    
    float value = atof(inputLine.substr(13).c_str());
    if (value < 0)
        throw std::runtime_error("Error: not a positive number");
    else if (value > 1000)
        throw std::out_of_range("Error: Too large number.");
    
    std::map<std::string, long double>::const_iterator it = btc.find(inputLine.substr(0, 10).c_str());
    if (it != btc.end())
        std::cout << inputLine.substr(0, 10).c_str() << " => " << value << " = " << it->second * value << std::endl;
    else
        printNearestDate(inputLine, btc, value);
}

void    BitcoinExchange::exec(std::string input)
{
    std::map<std::string, long double> btc = createBtcMap();
    std::ifstream file(input.c_str());

    if (file.is_open())
    {
        std::string inputLine;

        getline(file, inputLine);
        if (inputLine != "date | value")
        {
            file.close();
            throw std::runtime_error("Error: Wrong header' s input, it should start exactly with \"date | value\".\n");
        }
        while(std::getline(file, inputLine))
        {
            try
            {
                evaluateInputWithBtc(inputLine, btc);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    else
    {
        file.close();
        throw std::runtime_error("Error: Can' t open file " + input + ", maybe it doesn' t exist ?\n");
    }
    file.close();
}