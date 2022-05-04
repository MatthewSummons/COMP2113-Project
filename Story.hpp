#ifndef STORY_HPP
#define STORY_HPP

// For printing stuff character by chracter
void print(std::string line, int delay = 35, bool isEndLine = true);

// Call the apprpriate stage function
void Play_Stage(std::string &stage, std::string *inventory);

// Ask to save after chapter concluded
void Ask_Save(const string stage, string *inventory);
// Update Stage after completing a stage
void Update_Stage(std::string &stage);

// Print the story for the respective stage
void Introduction(string *inventory);

void Monster_1(string *inventory);
void Monster_2(string *inventory);
void Monster_3(string *inventory);
void Monster_4(string *inventory);

void Final_Battle(string *inventory);

#endif