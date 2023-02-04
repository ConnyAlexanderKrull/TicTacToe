#include <iostream>
#include <vector>


class TicTacToe2p
{
protected:
	uint16_t input_num;
	std::vector<char> field = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
	bool turns = true;
public:
	void print_field()
	{
		for (size_t i = 0; i < field.size(); i++)
		{
			std::cout << field[i] << " ";
			if (i == 2 || i == 5)
			{
				std::cout << "\n";
			}
		}
	}

	uint8_t vic_cond()
	{
		//Paths that don't cross mid
		if (field[0] == 'X' && field[1] == 'X' && field[2] == 'X') return 1;
		if (field[0] == 'X' && field[3] == 'X' && field[6] == 'X') return 1;
		if (field[8] == 'X' && field[5] == 'X' && field[2] == 'X') return 1;
		if (field[8] == 'X' && field[7] == 'X' && field[6] == 'X') return 1;
		if (field[0] == '0' && field[1] == '0' && field[2] == '0') return 2;
		if (field[0] == '0' && field[3] == '0' && field[6] == '0') return 2;
		if (field[8] == '0' && field[5] == '0' && field[2] == '0') return 2;
		if (field[8] == '0' && field[7] == '0' && field[6] == '0') return 2;
		//Paths that do cross mid
		if (field[4] == 'X' && field[0] == 'X' && field[8] == 'X') return 1;
		if (field[4] == 'X' && field[1] == 'X' && field[7] == 'X') return 1;
		if (field[4] == 'X' && field[2] == 'X' && field[6] == 'X') return 1;
		if (field[4] == 'X' && field[3] == 'X' && field[5] == 'X') return 1;
		if (field[4] == '0' && field[0] == '0' && field[8] == '0') return 2;
		if (field[4] == '0' && field[1] == '0' && field[7] == '0') return 2;
		if (field[4] == '0' && field[2] == '0' && field[6] == '0') return 2;
		if (field[4] == '0' && field[3] == '0' && field[5] == '0') return 2;

		return 0;
	}

	bool input_field()
	{
		for (size_t i = 0; i < field.size(); i++)
		{
			if (vic_cond() == 0)
			{
				print_field();
				std::cin >> input_num;
				if (field[input_num-1] == '-')
				{
					if (turns)
					{
						field[input_num-1] = 'X';
						turns = false;
					}
					else
					{
						field[input_num-1] = '0';
						turns = true;
					}
				}
				else
				{
					!turns;
				}
			}
			else if (vic_cond() == 1)
			{
				system("cls");
				std::cout << "X Won!\n";
				print_field();
				return true;
			}
			else
			{
				system("cls");
				std::cout << "0 Won!\n";
				print_field();
				return true;
			}
		}
		return false;
	}
};



int main()
{
	TicTacToe2p tic_tac_toe;
	if(tic_tac_toe.input_field() == false)
	{
		std::cout << "Error loading game, try again later\n";
	}
}
