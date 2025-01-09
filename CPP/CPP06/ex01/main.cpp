#include "Serializer.hpp"

int main()
{
    std::cout << "=== TEST 1 ===\nChecking pointer integrity after serialization/deserialization.\n";

    Data originalData;
    originalData.name = "John Doe";
    originalData.age = 30;

    std::cout << "Original Data - Name: " << originalData.name << ", Age: " << originalData.age << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized address: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data - Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;

    if (deserializedData == &originalData)
    {
        std::cout << "Test Passed: Pointers match!" << std::endl;
    }
    else
    {
        std::cout << "Test Failed: Pointers do not match!" << std::endl;
    }

    return 0;
}
