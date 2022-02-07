#include "IOVector.h"
#include "Vector.h"

int main()
{
	Vector* vector = new Vector;

	PrintVectorMenu(*vector);

	delete vector;

	return 0;
}