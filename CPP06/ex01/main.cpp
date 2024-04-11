#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	*data = new Data();
	Data	*serData;

	std::cout << "a, b, c : " << data->a << ", " << data->b << ", " << data->c << std::endl;

	serData = Serializer::deserialize(Serializer::serialize(data));
	std::cout << data << std::endl;
	std::cout << serData << std::endl;
	std::cout << Serializer::serialize(data) << std::endl;
	std::cout << Serializer::serialize(serData) << std::endl;

	std::cout << "a, b, c : " << serData->a << ", " << serData->b << ", " << serData->c << std::endl;

	delete(data);

	std::cout << std::endl;
}