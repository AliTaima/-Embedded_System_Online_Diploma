/*
 * keypad.c
 *
 * Created: 12/23/2023 1:51:34 PM
 *  Author: Ali Mohamed Taima
 */
#include "keypad.h"

void KEYPAD_Init(void)
{
	// Directions of rows and columns
	KEYPAD_Dir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3)); // Make rows as i/p
	KEYPAD_Dir |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));	// Make columns as o/p
	// Initial values
	KEYPAD_Port = 0xFF;
}
char KEYPAD_Get_Char(void)
{
	uint8_t i, j;
	uint8_t KeyPad_Rows[] = {R0, R1, R2, R3};
	uint8_t KeyPad_Cols[] = {C0, C1, C2, C3};
	for (i = 0; i < 4; i++)
	{
		KEYPAD_Port |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3)); // Write high on columns
		KEYPAD_Port &= ~(1 << KeyPad_Cols[i]);
		for (j = 0; j < 4; j++)
		{
			if (!((KEYPAD_Pin & (1 << KeyPad_Rows[j])) >> KeyPad_Rows[j]))
			{
				while (!((KEYPAD_Pin & (1 << KeyPad_Rows[j])) >> KeyPad_Rows[j]))
					;
				switch (j)
				{
				case 0:
					if (i == 0)
						return '7';
					else if (i == 1)
						return '8';
					else if (i == 2)
						return '9';
					else if (i == 3)
						return '/';
					break;
				case 1:
					if (i == 0)
						return '4';
					else if (i == 1)
						return '5';
					else if (i == 2)
						return '6';
					else if (i == 3)
						return '*';
					break;
				case 2:
					if (i == 0)
						return '1';
					else if (i == 1)
						return '2';
					else if (i == 2)
						return '3';
					else if (i == 3)
						return '-';
					break;
				case 3:
					if (i == 0)
						return '?';
					else if (i == 1)
						return '0';
					else if (i == 2)
						return '=';
					else if (i == 3)
						return '+';
					break;					
				}
			}
		}
	}
	return 'N';//to discard nothing
}