#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

// Handles the title screen ouput and input, decides the game mode as well
void Title_Screen(int & game_mode);

void delayed_print(std::string str, bool isEndline);
void print_title_screen(bool save_status);
bool isSaved();

int ask_game_mode(bool save_status);

#endif