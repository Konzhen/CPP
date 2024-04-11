#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Parameters are 'File', 's1', 's2'" << std::endl;
		return (1);
	}
    if (!argv[2][0])
    {
 		std::cout << "Empty text to replace." << std::endl;
		return (1);       
    }
    std::ifstream sourceFile(argv[1]);
    if (!sourceFile.is_open()) {
        std::cerr << "Unable to open source file." << std::endl;
        return (1);
    }

	std::string	nfile(argv[1]);

    nfile += ".replace";
    std::ofstream destFile(nfile.c_str());
    if (!destFile.is_open()) {
        std::cerr << "Unable to open destination file." << std::endl;
        return (1);
    }

    std::string cpy;
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    size_t      pos;

    getline(sourceFile, cpy, '\0');
    if (cpy.empty())
    {
        std::cerr << "Source file is empty" << std::endl;        
        return 1;
    }
    pos = cpy.find(s1);
    while (cpy.npos != pos)
    {
        cpy.erase(pos, s1.length());
        cpy.insert(pos, s2);
        pos = cpy.find(s1, pos + s2.length());
    }

    destFile << cpy;
    
    sourceFile.close();
    destFile.close();
}