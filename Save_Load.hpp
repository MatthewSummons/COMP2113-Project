#ifndef SAVE_LOAD_HPP
#define SAVE_LOAD_HPP

#include <string>

void Start_Save_Load(const int game_mode, std::string &stage, std::string* inventory);
void Save(const std::string stage, std::string *inventory);

void update_save(struct Game_State game_status);
void load_save(struct Game_State &game_status);

#endif