#include "../hpp/sound.hpp"

Sound::Sound(string m, string go,map<string,string> s){
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
    cerr<<Mix_GetError()<<endl;
  }
  volume = 64;
  music = Mix_LoadMUS(m.c_str());
  game_over = Mix_LoadMUS(go.c_str());
  Mix_VolumeMusic(volume);
  Mix_AllocateChannels(4);
  auto it = s.begin();
  for(it;it!=s.end();it++){
    if(sounds.find(it->first)==sounds.end()){
      Mix_Chunk * tmp=NULL;
      tmp = Mix_LoadWAV(it->second.c_str());
      sounds[it->first]=tmp;
    }
  }
}

Sound::~Sound(){
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  auto it = sounds.begin();
  for(it;it!=sounds.end();it++){
    Mix_FreeChunk(it->second);
  }
}

void Sound::play_music(int nb){
  Mix_PlayMusic(music,nb);
}

void Sound::stop_music(){
  Mix_HaltMusic();
}

void Sound::pause_music(){
  Mix_PauseMusic();
}

void Sound::play_game_over(){
  Mix_VolumeMusic(MIX_MAX_VOLUME/2);
  Mix_PlayMusic(game_over,1);
}

void Sound::down_Volume(){
  if(volume-10>0){
    volume-=10;
  }
  Mix_VolumeMusic(volume);
}

void Sound::up_Volume(){
  if(volume+10<MIX_MAX_VOLUME){
    volume+=10;
  }
  Mix_VolumeMusic(volume);
}

void Sound::resume_music(){
  Mix_ResumeMusic();
}

bool Sound::is_music_paused(){
  return Mix_PausedMusic();
}

void Sound::play_sound(string s){
  auto it = sounds.find(s);
  if(it!=sounds.end()){
    Mix_Volume(-1, (volume+10<MIX_MAX_VOLUME)?volume+10:volume);
    Mix_PlayChannel(-1, it->second, 0);
  }
}
