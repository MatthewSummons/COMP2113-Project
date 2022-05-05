#include <unistd.h> // For implementing ...
#include <chrono>   // a .. delay ..
#include <thread>   // when printing stuff

#include <iostream>   // For prinitng stuff
#include <string>     // For C++ strings

using namespace std;

#include "Story.hpp"
#include "Save_Load.hpp"    // For Saving Files
#include "Minigames.hpp"    // For Minigames
#include "End_Screen.hpp"   // For End Screen

// Originally in SaveLoad.cpp
std::string stages_alias[] = {
  "Introduction",
  "Monster 1",
  "Monster 2",
  "Monster 3",
  "Monster 4",
  "Final Battle"
};

// ! write func to update inventory (Add/ Remove)
struct Choice {
  // Choice Presented to the Player
  string line;
  // End Screen line if incorrect choice made
  string end_screen;

  // Constructor for Struct
  Choice(std::string line, std::string end_screen = "You made the wrong choice") {
    this -> line = line;
    this -> end_screen = end_screen;
  }

  // The function which offers the choice to the player
  void Decide(int delay = 35, bool isEndLine = true) {
    print(this -> line, delay, isEndLine);
    std::string response;
    std::cin >> response;

    if (response == "Y" || response == "y")
      return;
    
    // Show End Screen for selecting the wrong choice
    End_Screen(this -> end_screen);
    
  }
};

typedef struct Choice Choice;


void print(string str, int delay, bool isEndLine) {
  int len = str.length();
  for (int i = 0; i < len; i++) {
    cout << str[i] << flush;
    this_thread::sleep_for(chrono::milliseconds(delay));
  }

  this_thread::sleep_for(chrono::milliseconds(delay + 100));

  if (isEndLine) {
    cout << endl;
  }
}


// Select stage based on load from save file; If new game, play from Introduction
void Play_Stage(string &stage, string *inventory) {
  if (stage == "Introduction")
    Introduction(inventory);
  else if (stage == "Monster 1")
    Monster_1(inventory);
  else if (stage == "Monster 2")
    Monster_2(inventory);
  else if (stage == "Monster 3")
    Monster_3(inventory);
  else if (stage == "Monster 4")
    Monster_4(inventory);
  else if (stage == "Final Battle") {
    Final_Battle(inventory);
    print("Thanks for playing!");
    return;
  }
  
  else {
    cout << "Save File corrupted" << endl;
    exit(1);
  }

  // Ask to save each time
  Ask_Save(stage, inventory);

  // Ask if the player would like to continue playing
  print("Would you like to continue playing? [Y/n]");
  string response;
  cin >> response;

  // Quit out of game
  if ((response == "n") || (response == "Y")) {
    print("Thanks for playing! Come back around again!", 50);
    exit(1);
  }
}

// Ask to save before continuing chpater, save if player wants to
void Ask_Save(const string stage, string *inventory) {
  // Lower the text
  for (int i = 0; i < 3; i++) {
    cout << endl;
  } 

  print("Would you like to save before continuing? [Y/n]");
  
  string response;
  cin >> response;

  // Save if the players want to save
  if (response == "Y" || response == "y") {
    Save(stage, inventory);
  }
}

// After completing a stage, move to the next stage
void Update_Stage(string &stage) {
  // 5 Stages
  string next_stage = "Corrupted";
  for (int i = 0; i < 5; i++) {
    if (stage == stages_alias[i])
      next_stage = stages_alias[i + 1];
  }
  stage = next_stage;
}

void Introduction(string *inventory) {
  system("clear");

  print("Introduction");
  print("");
  print("Once upon a time, there was a little girl. Her name was Hera.");
  print("She lived with her father, her step-mother and her sister in a small village called Snowland.");
  print("She also had a loyal husky friend named Lucky that her father has gifted to her.");
  print("One day, the girl's father died of an unknown illness.");
  print("He was the most important person for her and she loved him with all her heart.");
  print("The girl mourned day and night for her father.");
  print("Suddenly, out of the darkness emerged a creature that called itself the spirit of Frost who called himself Moroz.");
  print("The Spirit of Frost appears to all the dead.");
  print("He looked at the girl appearing to be in deep thoughts.");
  print("Soon the spirit spoke up:");
  print("");
  print("* Do you want to bring your father back to life?");
  print("* Yes, for all I have. But why are you asking me that? It's impossible.");
  print("* Girl, what if I said that it is possible?");
  print("  But everything comes with a price.");
  print("  I will tell you the way.");
  print("  You need magic crystals that will revive your father.");
  print("  Crystals are held by evil Baba Yaga, Koshchei the Immortal, Zmey Gorynych and the Snow Queen.");
  print("  If you manage to collect these crystals, you can make a magic flower by combing them. ");
  print("  This flower is very unusual, as it contains the magical power of all its current owners.");
  print("  The one who takes a possession of this flower can translate all their conceivable and inconceivable desires into reality.");
  print("  This will be more than enough to revive your father.");
  print("  I am a kind spirit, so I will help you take possession of these crystals.");
  print("");
  print("Choice:");
  print("- Agree");
  print("- Disagree");

  // CHOICE 1
  // If pick "- Agree":
    //RANDOM CHOICE OF THE NEXT EVENT

  // If pick "- Disagree":
    print("* You seemed to be a sensible child until now. You disappointed me.");
    print("  Useless girl, since you foolishly declined my generous offer, I will kill you.");
    print("");
    // GAME OVER

  // R"()" for raw strings.
  // print()
}


void Monster_1 (string *inventory) {
  system("clear");
  
  print("Hut of the Baba Yaga");
  print("");
  print("As promised, the spirit accompanied the girl to the land of Baba Yaga and disappeared once reaching the destination.");
  print("Hera saw an old wooden hut before her eyes. Curiosity took over her and she opened the creaky door.");  
  print("An old woman was found to be sweeping the wooden floor with the broom made out of silver birch and a mortar.");
  print("Seeing the girl, Baba Yaga was delighted and thought to herself, “Hehe. Today I will not be left hungry.");
  print("So she began to prepare the ingredients for her upcoming dinner. Time cannot be wasted.");
  print("She kindled a fire, put water in the cauldron, and spoke to the girl:");
  print("* Come in, girl, why are you standing halfway there. You must be hungry. I have some food waiting for you.");
  print("  Why don't you have a taste?");
  print("");
  print("Choice:");
  print("- Come into Baba Yaga's hut");
  print("- Don't come into the hut");
  print("");

  // CHOICE 2
  // If pick "- Come into Baba Yaga's hut":
    print("* Would it be really okay? I don't want to inconvenience the person I first met.");
    print("* You are asking? Come here and can call me grandma.");
    print("* Thank you, grandma.");
    print("When the girl approached Baba Yaga, pointed to the dusty stove next to her:");
    print("* For your hunger, there's a baked potato in the oven. Take it.");
    print("When the girl was about to reach to the stove, Hera understood Baba Yaga's true intention.");
    print("She was trying to cook her alive by closing the lid of the stove if she will look inside.");
    print("In an urgent situation, the girl started thinking of the way to get out and decided to go for the trick:");
    print("* I can't reach the cauldron with potatoes. You have long arms, grandma, help me get it.");
    print("  Then Baba Yaga decided to look into the stove.");
    print("  At that moment, the girl pushed Baba Yaga into the stove with a kindled fire and closed the lid of the stove.");
    print("  Baba Yaga began to scream for help. Then the girl said:");
    print("* I'll help you if you give me your precious crystal.");
    print("  I don't think that it is more precious than your life. Think quick.");
    print("Baba Yaga had no choice but to agree to give her crystal.");
    print("");
    print("(FIRST CRYSTAL PIECE OBTAINED)");

    // INVENTORY UPDATE

    // RANDOM CHOICE OF THE NEXT EVENT

  // CHOICE 2
  // If pick "- Don't come into the hut":
    print("* Well, if you want it to be the bad way, so be it.");
    print("Baba Yaga puts Hera behind bars in shackles to drain her energy and eat afterwards.");
    print("");
    // GAME OVER

  // minigame_1();
}

void Monster_2 (string *inventory) {
  system("clear");
  print("Koshchei the Immortal");
  print("");
  print("With the guidance of the spirit, the girl went to the lifeless lands of Koshchei the immortal.");
  print("She already knew what to do when seeing a spooky castle nearby.");
  print("The girl came into Koshchei's castle. Koschei sitting in his bone throne has long seen her and finally said:");
  print("* You deserve a punishment for barging into my territory without my permission, little girl.");
  print("  But I am merciful and fair ruler, therefore I will give you a choice so that you choose your fate yourself.");
  print("  I haven't been using my magic in a while. It wouldn't be bad to train it on you by turning you into something.");
  print("  Now, who do you want to become: a stone statue, mindless zombie or an animal? ");
  print("");
  print("Choice:");
  print("- Become a stone");
  print("- Become a zombie");
  print("- Become an animal");

  // CHOICE 3
  // If pick "- Become a stone":
    print("* My choice is to become an animal.");
    print("That doesn't seem to be a bad choice. But I am a bit afraid and uncertain of it.");
    print("  I want to understand how you do it. As my last wish, show me first doing it on yourself.");
    print("* You are causing me trouble, child, but I'm still a merciful king. I will fulfil your last wish.");
    print("Koschei turns into a cat. Lucky grabs the cat and puts it in his mouth, and brings it to Hera. ");
    print("Koschei pleaded:");
    print("* Do not let your dog eat me. I will give you my most precious possession: a mana crystal.");
    print("");
    print("(SECOND CRYSTAL PIECE OBTAINED)");
    // INVENTORY UPDATE

    // RANDOM CHOICE OF THE NEXT EVENT

  // CHOICE 3
  // If pick "- Become a zombie":
    print("Hera turned into one of Koschei's obedient followers forever. She lost her mind and will to him.");
    // GAME OVER

  // CHOICE 3
  // If pick "- Become a stone":
    print("Hera soon became a stone statue and fell over breaking into pieces.");
    print("There is no way back to turn her into a living person again.");
    // GAME OVER

  // minigame_2();
}

void Monster_3 (string *inventory) {
  system("clear");
  print("Three-headed dragon Gorynych");
  print("");
  print("The girl next prepared to take an adventure to the land of the three-headed dragon Gorynych. Moroz led the way for her.");
  print("Once arriving to the place, the three-headed dragon smelled the girl's scent and found her right after.");
  print("First head mightily spoke:");
  print("* We're not going to let you live. You are our prisoner. We will burn you.");
  print("Second head disappointed:");
  print("* Weren't we going to trample her over with our weight? It's fun.");
  print("Third head angrily:");
  print("* I am hungry. Let's eat her!");
  print("First head:");
  print("* Okay, let's not argue. Let the girl choose how she wants to die.");
  print("");
  print("Choice:");
  print("- Get burned");
  print("- Get trampled over");
  print("- Get eaten");

  // CHOICE 4
  // If pick "- Get burned":
    print("Hera gets burned by the dragon in an instant.");
    // GAME OVER

  // CHOICE 4
  // If pick "- Get trampled over":
    print("Without any hesitation, Hera gets trampled over by the dragon.");
    // GAME OVER

  // CHOICE 4
  // If pick "- Get eaten":
    print("* Fine, I'll choose to be eaten. But how are you going to eat me at the same time since there are three of you?");
    print("  And I want a quick and painless death. That is why I pick to get eaten by one with sharpest teeth.");
    print("  Can each of you show me your teeth? I'll be the judge.");
    print("Dragon bows his heads down for a better look and the girl jumps on the neck.");
    print("A spirit appears and gives Hera a magic sword.");
    // INVENTORY UPDATE
    print("Having picked up the sword, she threatens the dragon:");
    print("* I won't kill you if you give me your crystal. Otherwise, I will cut off your heads.");
    print("");


  cout << "MONSTER 3" << endl;
}

void Monster_4 (string *inventory) {
  system("clear");

  cout << "MONSTER 4" << endl;
}

void Final_Battle(string *inventory) {
  system("clear");

  cout << "FINALE" << endl;
}