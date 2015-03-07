#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "hpp/game.hpp"
#include "hpp/factory.hpp"
#include "hpp/menu.hpp"
#include <map>
#define SIZE_CELL 40
using namespace std;

enum MENU{
  MENU_GAME,
  MENU_SCORES,
  MENU_QUIT
};

void high_scores(ostream &o){
  fstream file("save/save.txt",ios::in);
  string content;
  if(file){
    while(getline(file,content)){
      o<<content<<endl;
    }
    file.close();
  }else{
    cerr<<"Unable to open save file"<<endl;
  }
  o<<endl;
}

string concat(string text,int integer){
  stringstream tmp;
  string txt=text;
  tmp.str( string() );
  tmp.clear();
  tmp<<integer;
  txt+=tmp.str();
  return txt;
}

void init(){
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
}

void quit(){
  TTF_Quit();
  SDL_Quit();
}

void key_management(Game & g,Sound & game_sound,Factory & f){
  int x,y;
  Uint8 * keys = SDL_GetKeyState(NULL);
  Uint8 mouse = SDL_GetMouseState(&x,&y);
  AbstractShape * tmp;

  if(mouse & SDL_BUTTON(SDL_BUTTON_LEFT)){
    if(x <= g.getCurrentpiece()->x_left_bloc()){
      if(!g.colision('l')){
	g.getCurrentpiece()->move_left(SIZE_CELL);
	game_sound.play_sound("move");
      }
    }else if(x >= g.getCurrentpiece()->x_right_bloc()){
      if(!g.colision('r')){
	g.getCurrentpiece()->move_right(SIZE_CELL);
	game_sound.play_sound("move");
      }
    }
  }

  if(mouse & SDL_BUTTON(SDL_BUTTON_MIDDLE)){
    if(g.getCurrentpiece()->y_down_bloc()+SIZE_CELL*g.getCurrentlevel()<g.getGridHeight()*SIZE_CELL && !g.colision('d')){
      g.getCurrentpiece()->move_down(g.getCurrentlevel()*SIZE_CELL);
    }
  }

  if(mouse & SDL_BUTTON(SDL_BUTTON_RIGHT)){
    if(x <= g.getCurrentpiece()->x_left_bloc()){
      if(!g.colision('l')){
	g.getCurrentpiece()->move_left(SIZE_CELL);
	game_sound.play_sound("move");
      }
    }else if(x >= g.getCurrentpiece()->x_right_bloc()){
      if(!g.colision('r')){
	g.getCurrentpiece()->move_right(SIZE_CELL);
	game_sound.play_sound("move");
      }
    }
  }

  if(keys[SDLK_LEFT]){
    if(!g.colision('l')){
      g.getCurrentpiece()->move_left(SIZE_CELL);
      game_sound.play_sound("move");
    }
  }

  if(keys[SDLK_KP_PLUS]){
    game_sound.up_Volume();
  }

  if(keys[SDLK_KP_MINUS]){
    game_sound.down_Volume();
  }

  if(keys[SDLK_RIGHT]){
    if(!g.colision('r')){
      g.getCurrentpiece()->move_right(SIZE_CELL);
      game_sound.play_sound("move");
    }
  }

  if(keys[SDLK_DOWN]){
    if(g.getCurrentpiece()->y_down_bloc()+SIZE_CELL<g.getGridHeight()*SIZE_CELL && !g.colision('d')){
      g.getCurrentpiece()->move_down(SIZE_CELL);
    }
  }
    
  if(keys[SDLK_s]){
    game_sound.stop_music();
  }

  if(keys[SDLK_p]){
    if(game_sound.is_music_paused()){
      game_sound.resume_music();
    }
  }
    
  if(keys[SDLK_KP1]){
    tmp=f.create(concat("shape",g.getCurrentpiece()->previous()),g.getCurrentpiece()->new_shape().first,g.getCurrentpiece()->new_shape().second,SIZE_CELL);
    if(!g.rotation_colision(tmp)){
      g.setCurrentpiece(tmp);
      game_sound.play_sound("turn");
    }
  }
}

bool play(string playername){
  SDL_Event event;
  bool go=true;
  string windowname;
  Factory f;
  int last_time = 0, actual_time = 0;
  int interval = 100;
  SDL_Color color = {255, 255, 255};
  string sound_folder="sounds/";
  string font_folder="font/";
  string img_folder="image/";

  string env="SDL_VIDEO_CENTERED=1";
  putenv((char *)env.c_str());

  // factory registering
  Factory::Register("shape0",new Shape0);
  Factory::Register("shape1",new Shape1);
  Factory::Register("shape2",new Shape2);
  Factory::Register("shape3",new Shape3);
  Factory::Register("shape4",new Shape4);
  Factory::Register("shape5",new Shape5);
  Factory::Register("shape6",new Shape6);
  Factory::Register("shape7",new Shape7);
  Factory::Register("shape8",new Shape8);
  Factory::Register("shape9",new Shape9);
  Factory::Register("shape10",new Shape10);
  Factory::Register("shape11",new Shape11);
  Factory::Register("shape12",new Shape12);
  Factory::Register("shape13",new Shape13);
  Factory::Register("shape14",new Shape14);
  Factory::Register("shape15",new Shape15);
  Factory::Register("shape16",new Shape16);
  Factory::Register("shape17",new Shape17);
  Factory::Register("shape18",new Shape18);

  //sounds registering
  map<string,string> sounds;
  sounds["level_up"]=sound_folder+"level_up.wav";
  sounds["erase_line"]=sound_folder+"erase_line.wav";
  sounds["shape_drop"]=sound_folder+"shape_drop.wav";
  sounds["turn"]=sound_folder+"turn.wav";
  sounds["move"]=sound_folder+"move.wav";

  Game g(playername,1,22,10,SIZE_CELL);
  g.setCurrentpiece(f.create_random_shape(((g.getGridWidth()/2)-1)*SIZE_CELL,0,SIZE_CELL));
  g.setNextpiece(f.create_random_shape(((g.getGridWidth()/2)-1)*SIZE_CELL,0,SIZE_CELL));
  screen screen_display(SIZE_CELL*g.getGridWidth(),SIZE_CELL*g.getGridHeight(),img_folder+"window_icone.bmp",img_folder+"background.bmp");
  Sound game_sound(sound_folder+"tetris.mp3",sound_folder+"game_over.wav",sounds);
  game_sound.play_music(-1); // play game music


  while(go){

    windowname=concat("Tetris  level ",g.getCurrentlevel());
    windowname+=" (player : ";
    windowname+=g.getPlayer()->getName();
    windowname+=" Score : ";
    windowname=concat(windowname,g.getPlayer()->getScore());
    windowname+=")";
    SDL_WM_SetCaption(windowname.c_str(), NULL); // dynamic window name with player name and score
    AbstractShape * tmp;

    while (SDL_PollEvent(&event)){
      switch(event.type)
	{
	case SDL_QUIT:
	  return false;
	case SDL_MOUSEMOTION:{
	  screen_display.setXcursor(event.motion.x);
	  screen_display.setYcursor(event.motion.y);
	  break;}
	case SDL_MOUSEBUTTONDOWN:{
	  switch(event.button.button){
	  case SDL_BUTTON_WHEELUP:{
	    tmp =f.create(concat("shape",g.getCurrentpiece()->next()),g.getCurrentpiece()->new_shape().first,g.getCurrentpiece()->new_shape().second,SIZE_CELL);
	    if(!g.rotation_colision(tmp)){
	      g.setCurrentpiece(tmp);
	      game_sound.play_sound("turn");
	    }
	    break;}
	  case SDL_BUTTON_WHEELDOWN:{
	    tmp=f.create(concat("shape",g.getCurrentpiece()->previous()),g.getCurrentpiece()->new_shape().first,g.getCurrentpiece()->new_shape().second,SIZE_CELL);
	    if(!g.rotation_colision(tmp)){
	      g.setCurrentpiece(tmp);
	      game_sound.play_sound("turn");
	    }
	    
	    break;}
	  }
	  break;}

	case SDL_KEYDOWN:{
	  switch(event.key.keysym.sym){
	  case SDLK_ESCAPE:{
	    go=false;	 
	    break;}
	  case SDLK_UP:{
	    tmp=f.create(concat("shape",g.getCurrentpiece()->next()),g.getCurrentpiece()->new_shape().first,g.getCurrentpiece()->new_shape().second,SIZE_CELL);
	    if(!g.rotation_colision(tmp)){
	      g.setCurrentpiece(tmp);
	    }
	    break;}
	  }
	  break;} 
	}
    }

    key_management(g,game_sound,f);

    if(!g.colision('d')){ // moving the shape down
      g.getCurrentpiece()->move_down(20);
    }else{ // put the shape on the floor or on another shape
      game_sound.play_sound("shape_drop");
      g.add_shape(g.getCurrentpiece());

      if(g.getNbblocs()%10==0){ // level up
	g.resetNbblocs();
	g.levelup();
	interval-=10;
	game_sound.play_sound("level_up");
      }

      for(int cpt=g.getCurrentpiece()->match_line_up();cpt<=g.getCurrentpiece()->match_line()-1;cpt++){
	if(g.check_line(cpt)){
	  g.delete_line(cpt);
	  g.getPlayer()->updateScore(400*g.getCurrentlevel());
	  game_sound.play_sound("erase_line");
	  g.add_line();
	}
      }

      if(g.getCurrentpiece()->y_up_bloc()<=0 && g.colision('d')){
	game_sound.play_game_over();
	screen_display.write_text("Game Over !",color,10,screen_display.getHeight()/2.2-SIZE_CELL/2,SIZE_CELL*1.5,font_folder+"ocraext.ttf");
	screen_display.flip();
	SDL_Event pause;
	while(SDL_WaitEvent(&pause)){
	  switch(pause.type){
	  case SDL_QUIT:
	    return false;
	  case SDL_KEYDOWN:
	    switch(pause.key.keysym.sym){
	    case SDLK_ESCAPE:
	      return false;
	    }
	  }
	}
	go=false;
      }else{
	g.getPlayer()->updateScore(g.getCurrentlevel()*10);
	g.setCurrentpiece(g.getNextpiece());
	g.setNextpiece(f.create_random_shape(((g.getGridWidth()/2)-1)*SIZE_CELL,0,SIZE_CELL));
      }
    }

    screen_display<<g;
    screen_display.blit();

    screen_display.write_text(concat("Score : ",g.getPlayer()->getScore()),color,screen_display.getWidth()+30,screen_display.getHeight()/4+screen_display.getHeight()/12,SIZE_CELL/2,font_folder+"ocraext.ttf");
    screen_display.write_text(concat("Level : ",g.getCurrentlevel()),color,screen_display.getWidth()+30,screen_display.getHeight()/4+screen_display.getHeight()/12+SIZE_CELL,SIZE_CELL/2,font_folder+"ocraext.ttf");
    screen_display.write_text(concat("Lines : ",g.get_lines()),color,screen_display.getWidth()+30,screen_display.getHeight()/4+screen_display.getHeight()/12+2*SIZE_CELL,SIZE_CELL/2,font_folder+"ocraext.ttf");

    screen_display.flip();
    screen_display.empty();
      

    if(actual_time - last_time < interval){ // timer for display
      SDL_Delay(interval - (actual_time - last_time));
    }
    last_time = actual_time;   
  }
  return EXIT_SUCCESS;
}

/*int main(){
  init();
  int choice;
  string playername;
  do{
    cout<<"Menu :"<<endl<<"(1) High Scores"<<endl<<"(2) Start Game"<<endl;
    cin>>choice;
    if(choice==1){
      high_scores(cout);
    }else{
      cout<<"Quel est votre nom ?"<<endl;
      cin>>playername;
    }
  }while(choice!=2);
  play(playername);
  quit();
  return 0;
}*/

int main(){
  init();
  SDL_Color hover = {26,62,137};
  SDL_Color normal = {150,150,150};
  SDL_Event event;

  int last_time = 0, actual_time = 0;
  int interval = 100;

  string env="SDL_VIDEO_CENTERED=1";
  putenv((char *)env.c_str());

  Menu m(22,"font/ocraext.ttf","image/window_icone.bmp","image/menu.bmp",hover,normal,640,480);
  m.add_element("New Game");
  m.add_element("High Scores");
  m.add_element("Quit");
  bool go = true;
  int choice;
  string playername;

  while(go){
    while(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	go = false;
	break;
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym){

	case SDLK_UP:
	  m.move_up();
	  break;
      
	case SDLK_DOWN:
	  m.move_down();
	  break;
      
	case SDLK_RETURN:
	  choice=m.getCurrentIndex();
	  go=false;
	  break;

	case SDLK_ESCAPE:
	  go = false;
	  break;
	}
	break;
      }
    }
    m.display();
    m.flip();
    if(actual_time - last_time < interval){ // timer for display
      SDL_Delay(interval - (actual_time - last_time));
    }
    last_time = actual_time;   
  }
  switch(choice){

  case MENU_GAME:
    cout<<"Quel est votre nom ?"<<endl;
    cin>>playername;
    play(playername);
    break;

  case MENU_SCORES:
    high_scores(cout);
    break;

  case MENU_QUIT:
    break;
  }
  quit();
  return 0;
}
