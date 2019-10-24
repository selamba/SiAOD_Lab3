#include <iostream>
#include <random>
#include <functional>

std::default_random_engine generator;
std::uniform_int_distribution distribution(1, 9);
auto rnd = std::bind(distribution, generator);

int main()
{
	int n = 0, m = 0;
	unsigned short int non_null_rows = 0;

	std::cout << "Enter n and m: ";
	std::cin >> n >> m;

	int array[n][m];
	for (int i = 0; i < n; i++)
	{
		bool is_null = true;

		for (int j = 0; j < m; j++)
		{
			array[i][j] = rnd();
			if (array[i][j] != 0) is_null = false;
		}
		if (!is_null) non_null_rows++;
	}

	int array2[non_null_rows][m];
	for (int i = 0; i < n; i++)
	{
		static int num = 0;
		bool is_null = true;

		for (int j = 0; j < m; j++)
		{
			if (array[i][j] != 0) is_null = false;
		}

		if (!is_null)
		{
			for (int k = 0; k < m; k++)
				array2[num][k] = array[i][k];
			num++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << array[i][j];
			if (j != (m - 1)) std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < non_null_rows; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << array2[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}