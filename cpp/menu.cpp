#include "../hpp/menu.hpp"

SDL_Surface * Menu::Surfacefont(int size, string text, SDL_Color color){//print text of color in a surface, and return it (used in menu_element structure for hover/normal surface)

  TTF_Font* font = TTF_OpenFont(font_file.c_str(), size);

  SDL_Surface* surfaceText = TTF_RenderText_Blended(font, text.c_str(), color);
 
  TTF_CloseFont(font);

  return surfaceText;
}

void Menu::add_element(string text){//add element in menu
  menu_element e;

  e.Hover = Surfacefont(this->size, text, this->Hover_color);
 
  e.Normal = Surfacefont(this->size, text, this->Normal_color);

  elements.push_back(e);
}

Menu::Menu(int size,string font,string icone,string back_ground,SDL_Color hover,SDL_Color normal,int width,int height):size(size),font_file(font),Hover_color(hover),Normal_color(normal),posX(width/2-50),posY(height/2-50),currentIndex(0),width(width),height(height){

  SDL_WM_SetIcon(SDL_LoadBMP(icone.c_str()), NULL);//set icone of app, black is transparent

  scr = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);//set main surface in scr

  background = SDL_LoadBMP(back_ground.c_str());//load background

   if(!scr){//check if SDL_SetVideoMode worked
    cerr<<"Unable to load video mode : \n"<<SDL_GetError()<<endl;
    exit(EXIT_FAILURE);
  }
   SDL_WM_SetCaption("Tetris", "Tetris");
}

Menu::~Menu(){
  SDL_FreeSurface(background);
}

void Menu::flip(){SDL_Flip(scr);}

void Menu::reload(){//reload main surface in scr (used to go back to menu after a game or after seen highscores)
  scr = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);}

void Menu::blit_back(){//blit background on scr
  SDL_Rect pos;
  pos.x=0;
  pos.y=0;
  SDL_BlitSurface(background,NULL,scr,&pos);
}


void Menu::display_elem(SDL_Surface * e,int x,int y){//display a surface on scr
  SDL_Rect pos;
  pos.x=x;
  pos.y=y;
  SDL_BlitSurface(e,NULL,scr,&pos);
}

int Menu::getCurrentIndex(){return currentIndex;}

int Menu::getMenuSize(){return elements.size();}

void Menu::display(){
  int rowY;
  blit_back();
  for(int i = 0; i < getMenuSize(); i++) {

    rowY = this->posY + i * this->elements.at(i).Hover->h + 10;

    //if link is focused
    if(this->currentIndex == i) {
      //hover display
      display_elem(this->elements.at(i).Hover, this->posX, rowY);
    }
    else {
      //normal display
      display_elem(this->elements.at(i).Normal, this->posX, rowY);
    }
  }
}

void Menu::move_up(){// move the selection to the upper element
  if(currentIndex==0){
    currentIndex=getMenuSize()-1;
  }else{
    currentIndex--;
  }
}

void Menu::move_down(){//move the selection to the inferior element
  if(currentIndex==getMenuSize()-1){
    currentIndex=0;
  }else{
    currentIndex++;
  }
}


