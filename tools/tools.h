#pragma once
#pragma warning (disable:4996)
#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <codecvt>

using namespace std;

string GetTime();
void PrintConsoleBottomRight(string str);
void wait(string text = "╭─────────────────────────────────────╮ \n│ Нажмите любую кнопку чтобы продол-  │ \n│ жить...                             │ \n╰─────────────────────────────────────╯ \n");
void waitForEsc(string text = "");
void printTitle(string title, bool seamless = true);
bool acceptQuery(string query, bool custom = false);
