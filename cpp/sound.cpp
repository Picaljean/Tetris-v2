#include "../hpp/sound.hpp"

Sound::Sound(string m, string go,map<string,string> s){
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){// open sdl_mixer and check if it worked
    cerr<<Mix_GetError()<<endl;
  }
  volume = 64; // put the volume on half
  music = Mix_LoadMUS(m.c_str());//load game music
  game_over = Mix_LoadMUS(go.c_str());//load game over music
  Mix_VolumeMusic(volume);//set volume
  Mix_AllocateChannels(4);//set the number of different channel we could use
  auto it = s.begin();
  for(it;it!=s.end();it++){//fill sound map with chunks (sounds effect, different from mix_loadmus)
    if(sounds.find(it->first)==sounds.end()){
      Mix_Chunk * tmp=NULL;
      tmp = Mix_LoadWAV(it->second.c_str());//load the sound in a chunk
      sounds[it->first]=tmp;//register the sound in map [name,his chunk]
    }
  }
}

Sound::~Sound(){
  Mix_FreeMusic(music);
  Mix_FreeMusic(game_over);
  Mix_CloseAudio();//close library
  auto it = sounds.begin();
  for(it;it!=sounds.end();it++){//release chunks
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

void Sound::play_sound(string s){//play a sound effect
  auto it = sounds.find(s);
  if(it!=sounds.end()){
    Mix_Volume(-1, (volume+10<MIX_MAX_VOLUME)?volume+10:volume);
    Mix_PlayChannel(-1, it->second, 0);
  }
}
