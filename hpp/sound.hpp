#ifndef SOUND_HPP
#define SOUND_HPP
#include <string>
#include <SDL/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Sound{
private :
  Mix_Music * music;
  Mix_Music * game_over;
  map<string,Mix_Chunk *> sounds;
  int volume;
public :
  Sound(string,string,map<string,string>);
  void play_music(int);
  void pause_music();
  void stop_music();
  void down_Volume();
  void up_Volume();
  void resume_music();
  bool is_music_paused();
  void play_game_over();
  void play_sound(string);
  ~Sound();
};

#endif
