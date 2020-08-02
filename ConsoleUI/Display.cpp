#include "Displays.h"
#include "Graphics.h"
#include "Enums.h"
#include <conio.h>

void DrawRectangle(RECTANGLE rectangle, char getChar, Color textColor, Color bgColor)
{
	RECTANGLE rect = rectangle;

	for (int i = 0; i < rect.size.height; i++)
	{
		for (int j = 0; j < rect.size.width; j++)
		{
			if (i == 0 || j == 0 || i == rect.size.height - 1 || j == rect.size.width - 1 || j == 1 || j == rect.size.width - 2)
			{
				SetTextColor(textColor);
				GoToXY(rect.location.x, rect.location.y);
				if (i == 0 && j == 0)
				{
					cout << getChar;
				}
				else if (i == 0 && j == rect.size.width - 1)
				{
					cout << getChar;
				}
				else if (i == rect.size.height - 1 && j == 0)
				{
					cout << getChar;
				}
				else if (i == rect.size.height - 1 && j == rect.size.width - 1)
				{
					cout << getChar;
				}
				else if (i == 0 || i == rect.size.height - 1)
				{
					cout << getChar;
				}
				else if (j == 0 || j == rect.size.width - 1)
				{
					cout << getChar;
				}
				else if (j == 1 || j == rect.size.width - 2)
				{
					cout << getChar;
				}
			}
			else if (true)
			{
				SetBGColor(bgColor);
				GoToXY(rect.location.x, rect.location.y);
				cout << " ";
			}
			else
			{
				SetBGColor(bgColor); // set color bg
				cout << " ";
			}
			rect.location.x++;
		}
		rect.location.x = rectangle.location.x;
		rect.location.y++;
	}
}

void DrawButton(RECTANGLE rectangle, string text, char getChar, Color textColor, Color bgColor)
{
	RECTANGLE rect = rectangle;

	for (int i = 0; i < rect.size.height; i++)
	{
		for (int j = 0; j < rect.size.width; j++)
		{
			SetTextColor(bgColor);
			GoToXY(rect.location.x, rect.location.y);
			cout << getChar;
			rect.location.x++;
		}
		rect.location.x = rectangle.location.x;
		rect.location.y++;
	}
	if (rect.size.height == 1)
	{
		GoToXY(rect.location.x + rect.size.width / 2 - text.size() / 2, rect.location.y - 1);
		if (text.size() % 2 != 0) GoToXY(WhereX() - 1, WhereY());
		SetTextColor(textColor);
		SetBGColor(bgColor);
		cout << text;
	}
	else
	{
		GoToXY(rect.location.x + rect.size.width / 2 - text.size() / 2, rect.location.y - ((rect.size.height - 1) / 2) - 1);
		SetTextColor(textColor);
		SetBGColor(bgColor);
		cout << text;
	}
}
void DrawMessageBox(MYPOINT point, string text, string& inputText, bool& isEnter, bool& isCancel, char getChar, Color textColor, Color bgColor, Color bgButtonColor)
{
	RECTANGLE rect = RECTANGLE(point, { 40, 8 });;
	for (int i = 0; i < rect.size.height; i++)
	{

		if (i == 0)
		{
			SetTextColor(Color::Yellow);
			GoToXY(rect.location.x, rect.location.y);
			cout << std::string(rect.size.width, getChar);
		}
		else
		{
			SetTextColor(bgColor);
			GoToXY(rect.location.x, rect.location.y);
			cout << std::string(rect.size.width, getChar);
		}

		rect.location.x++;
		rect.location.x = point.x;
		rect.location.y++;
	}
	for (int i = 3; i < (rect.size.width - 3); i++)
	{
		GoToXY(point.x + i, point.y + rect.size.height / 2);
		SetTextColor(TEXT_INPUT_COLOR);
		SetBGColor(BG_COLOR);
		cout << " ";
	}

	RECTANGLE noBox = RECTANGLE({ point.x + 16, point.y + 6 }, { 8, 1 });

	DrawButton(noBox, "CANCEL", 219, textColor, bgButtonColor);

	GoToXY(point.x + 4, point.y + rect.size.height / 2);
	int flag = 1;
	char inputKey = NULL;
	char inputKey1 = NULL;

	while (1)
	{
		if (flag == 1)
		{
			DrawButton(noBox, "CANCEL", 219, textColor, bgButtonColor);
			GoToXY(point.x + 4, point.y + rect.size.height / 2);
			ShowPointer();
			//getline(cin, inputText);
			if (1)
			{
				do
				{
					Sleep(100);
					inputKey = _getch();
					//GoToXY(point.x + 4, point.y + rect.size.height / 2);
					if (inputKey == 0 || inputKey == -32)
					{
						inputKey = _getch();
					}

					if (inputKey == Key::ENTER && flag == 1)
					{
						isEnter = true;
						return;
						//cout << inputText;
					}
					else if ((inputKey == Key::UP && flag == 1) || (inputKey == Key::DOWN && flag == 1))
					{
						DrawButton(noBox, "CANCEL", 219, textColor, bgButtonColor);

						flag = 2;
						HidePointer();
						break;
					}
					else if (isalnum(inputKey) || inputKey == ' ')
					{
						inputText += inputKey;
						cout << inputKey;
					}
					else if (inputKey == Key::BACKSPACE)
					{
						auto end = inputText.end();
						inputText.erase(std::remove(end - 1, end, inputText[inputText.length() - 1]));
						GoToXY(WhereX() - 1, WhereY());
						std::cout << std::string(1, ' ');
						GoToXY(WhereX() - 1, WhereY());
					}
				} while (!_kbhit());
			}
		}
		else if (flag == 2)
		{

			DrawButton(noBox, "CANCEL", 219, textColor, Color::Blue);
			HidePointer();
			do
			{
				Sleep(100);
				char inputKey1 = _getch();
				if (inputKey1 == 0 || inputKey1 == -32)
				{
					inputKey1 = _getch();
				}
				if (inputKey1 == Key::ENTER && flag == 2)
				{
					isCancel = true;
					return;
				}
				else if ((inputKey1 == Key::UP && flag == 2) || (inputKey1 == Key::DOWN && flag == 2))
				{
					GoToXY(point.x + 4, point.y + rect.size.height / 2);
					flag = 1;
					break;
				}
			} while (!_kbhit());
		}
	}
}