#include "../hpp/screen.hpp"
#include <SDL/SDL_ttf.h>
using namespace std;

screen::screen(int w,int h,string icone,string back_ground):width(w),height(h){

  SDL_ShowCursor(SDL_DISABLE);//disable mouse cursor

  scr = SDL_SetVideoMode(width+width/2,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);//set the Main surface in scr

  background = SDL_LoadBMP(back_ground.c_str());//load background
  cursor = SDL_LoadBMP(icone.c_str());//load cursor picture
  game = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0);//create game surface
  piece = SDL_CreateRGBSurface(SDL_HWSURFACE, width/2, height/4, 32, 0, 0, 0, 0);//create next piece surface

  SDL_SetColorKey(piece,SDL_SRCCOLORKEY,SDL_MapRGB(piece->format, 255, 255, 255));//white become invisible in piece surface
  SDL_SetColorKey(cursor,SDL_SRCCOLORKEY,SDL_MapRGB(piece->format, 0, 0, 0));//black become invisible in cursor surface

  if(!scr){//check if SDL_SetVideoMode worked
    cerr<<"Unable to load video mode : \n"<<SDL_GetError()<<endl;
    exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption("Tetris", "Tetris");//set icone and window name
}

void screen::resize(){//call SDL_SetVideoMode again when a sdl_resize event is catched, to correct a mouse range bug when we go from menu scr to game scr
  scr = SDL_SetVideoMode(width+width/2,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
}

void screen::draw_rect(int x,int y,int w, int h,char c,SDL_Surface * s){// draw a rectangle of c color, on an SDL_Surface
  int r=0;
  int g=0;
  int b=0;
  SDL_Rect border;
  border.x = x;
  border.y = y;
  border.w = w;
  border.h = h;
  SDL_FillRect(s, &border, SDL_MapRGB(s->format, r, g, b));
  SDL_Rect rectangle;
  rectangle.x = x+1;
  rectangle.y = y+1;
  rectangle.w = w-2;
  rectangle.h = h-2;
  switch(c){
  case 'r':{
    r=255;
    g=0;
    b=0;
    break;}
  case 'g':{
    r=0;
    g=255;
    b=0;
    break;}
  case 'c':{
    r=0;
    g=255;
    b=255;
    break;}
  case 'b':{
    r=0;
    g=0;
    b=255;
    break;}
  case 'y':{
    r=255;
    g=255;
    b=0;
    break;}
  case 'p':{
    r=160;
    g=32;
    b=240;
    break;}
  case 'o':{
    r=255;
    g=69;
    b=0;
    break;}
  case 'n':{
    break;}
  }
  SDL_FillRect(s, &rectangle, SDL_MapRGB(s->format, r, g, b));
}

void screen::empty(){//clean piece and game surfaces
  SDL_FillRect(piece, NULL, SDL_MapRGB(piece->format, 255, 255, 255));
  SDL_FillRect(game, NULL, SDL_MapRGB(game->format,255,255,255));
}

SDL_Surface * screen::getGame()const{return game;}

SDL_Surface * screen::getPiece()const{return piece;}

SDL_Surface * screen::getScr()const{return scr;}

screen::~screen(){//release memory
  SDL_FreeSurface(piece);
  SDL_FreeSurface(game);
  SDL_FreeSurface(background);
  SDL_FreeSurface(cursor);
}

void screen::flip(){SDL_Flip(scr);}//flip main surface (double buffering)

void screen::write_text(string text,SDL_Color color,int x,int y,int font_size,string font_file){//write text with sdl on main surface
  TTF_Font *font = NULL;
  SDL_Rect pos;
  SDL_Surface * text_surface = NULL;
  font = TTF_OpenFont(font_file.c_str(), font_size);
  text_surface = TTF_RenderText_Blended(font, text.c_str(), color);
  pos.x=x;
  pos.y=y;
  SDL_BlitSurface(text_surface, NULL, scr, &pos);
  SDL_FreeSurface(text_surface);
  TTF_CloseFont(font);
}

void screen::blit(){// blit parts on main surface
  SDL_Rect pos;
  pos.x=width;
  pos.y=0;
  SDL_BlitSurface(background, NULL, scr, &pos);
  pos.x=width;
  pos.y=height/12;
  SDL_BlitSurface(piece, NULL, scr, &pos);
  pos.x=0;
  pos.y=0;
  SDL_BlitSurface(game, NULL,scr, &pos); 
  SDL_BlitSurface(cursor,NULL,scr, &pos_cursor);
}


int screen::getHeight(){return height;}

int screen::getWidth(){return width;}

void screen::setXcursor(int x){pos_cursor.x=x;}

void screen::setYcursor(int y){pos_cursor.y=y;}
