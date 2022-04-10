// Game Abstraction


void Game()
{
  // Print the title screen to the console
  Title_Screen();
  
  // Start New Game or Continue from a Save
  bool new_game = false, quit_flag = false;
  Choose_Play_Mode(bool& new_game, bool& quit_flag);

  if (quit_flag)
    Quit_Game();
  else if (new_game)
    New_Game();
  else
    Continue_Game();
  
  // Play the game
  

}