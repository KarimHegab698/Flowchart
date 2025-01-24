
#include "HelperFn.h"

bool IsValue(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if ((input[i] >= 48 && input[i] <= 57) || (input[0] == 45) || (input[i] == 46))
		{
			for (int i = 1; i < input.size(); i++)
			{
				if (input[i] == 45)
				{
					return false;
				}
				for (int i = 0; i < input.size(); i++)
				{
					if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function

	return false;
}

bool IsVariable(string input)
{
	if (input.size() != 0 && ((input[0] >= 65 && input[0] <= 90) || (input[0] >= 97 && input[0] <= 122) || input[0] == 95))
	{
		for (int i = 1; i < input.size(); i++)
		{
			if (!((input[i] >= 48 && input[i] <= 57) || (input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)))
			{
				return false;
			}
		}
		return true;
	}
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function

	return false;
}

OpType ValueOrVariable(string input)
{
	if (IsValue(input))
	{
		return VALUE_OP;
	}
	else if (IsVariable(input))
	{
		return VARIABLE_OP;
	}
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	return INVALID_OP;
}
