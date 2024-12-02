#include <iostream>

int main()
{
    float startA, endA;
    float startB, endB;
    float number;

    std::cin >> startA >> endA >> startB >> endB >> number;

    bool isInSetA = startA <= number && number <= endA;
    bool isInSetB = startB <= number && number <= endB;

    bool inUnion        = isInSetA || isInSetB;
    bool inIntersection = isInSetA && isInSetB;
    bool inDifference   = isInSetA && !isInSetB;
    bool inSingleSet    = (isInSetA && !isInSetB) || (!isInSetA && isInSetB);

    std::cout << std::boolalpha;
    std::cout << "Is in union: " << inUnion << std::endl;
    std::cout << "Is in intersection: " << inIntersection << std::endl;
    std::cout << "Is in difference: " << inDifference << std::endl;
    std::cout << "Is in only one set: " << inSingleSet << std::endl;
}