#include "../hpp/score.hpp"
#include <sstream>

score::score(string font,string file,string back_file,int size,int width,int height):font_file(font),size(size),width(width),height(height){
  scr=NULL;
  background=SDL_LoadBMP(back_file.c_str());
  c={255,255,255};
  fstream high_scores(file,ios::in);
  string name;
  int sco;
  if(high_scores){
    while(1){
      high_scores>>name;
      high_scores>>sco;
      if(high_scores.eof()){
	break;
      }
      s.push_back(make_pair(name,sco));
    }

    s.sort([](const pair<string,int> &left, const pair<string,int> &right){
    return left.second < right.second;
});
    high_scores.close();
  }else{
    cerr<<"Unable to open save file"<<endl;
  }
}

string score::concat(string text,int integer,int padding){
  stringstream tmp;
  string txt=text;
  for(int cpt=0;cpt<padding;cpt++){
    txt+=" ";
  }
  tmp.str( string() );
  tmp.clear();
  tmp<<integer;
  txt+=tmp.str();
  return txt;
}

int score::longest_score(){
  int size=0;
  int cpt=0;
  auto it = s.end();
  it--;
  while(it!=s.begin() && cpt<5){
    if(concat((*it).first+"   ",(*it).second,0).size()>size){
      size=concat((*it).first+"   ",(*it).second,0).size();
    }
    it--;
    cpt++;
  }
  return size;
}

void score::write_scores(){
  TTF_Font * font = NULL;
  SDL_Rect pos;
  int cpt=0;
  pos.x=width/2-100;
  SDL_Surface * score_surface=NULL;
  int y=height/3-20;
  font = TTF_OpenFont(font_file.c_str(), size);
  blit_back();

  auto it = s.end();
  it--;
  while(cpt<5){
    score_surface = TTF_RenderText_Blended(font,concat((*it).first+"   ",(*it).second,longest_score()-concat((*it).first+"   ",(*it).second,0).size()).c_str(),c);
    pos.y=y;
    SDL_BlitSurface(score_surface,NULL,scr,&pos);
    y+=size*2;
    if(it==s.begin()){
      break;
    }
    it--;
    cpt++;
  }

  SDL_FreeSurface(score_surface);
  TTF_CloseFont(font);
}

void score::blit_back(){
  SDL_Rect pos;
  pos.x=0;
  pos.y=0;
  SDL_BlitSurface(background,NULL,scr,&pos);
}

void score::clear(){
  SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
}

void score::resize(){scr=SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);}

score::~score(){
  SDL_FreeSurface(background);}

void score::flip(){SDL_Flip(scr);}
