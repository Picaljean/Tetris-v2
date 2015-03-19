#include "../hpp/game.hpp"
#include <fstream>
#include <sstream>
#include <cstdio>
#include <SDL/SDL.h>
#include <vector>
#include <algorithm>
using namespace std;

Game::Game(string name,int level,int h, int w,int s):p(name),currentlevel(level),gridwidth(w),gridheight(h),sizecell(s),nbblocs(0),lines(0),pause(false){
  for(int i=0;i<gridwidth*gridheight;i++){
    grid.push_back('n');
  }
}

bool Game::is_paused(){return pause;}

void Game::setPause(){pause=!pause;}

void Game::add_line(){lines++;}

void Game::add_shape(AbstractShape * s){
  for(int cpt=0;cpt<4;cpt++){
    grid[s->get_location(cpt,gridwidth)]=s->getColor();
  }
  nbblocs++;
}

void Game::save_score(string fileoutput){
  ifstream file(fileoutput.c_str(),ios::in);
  ofstream tmp("tmp.txt",ios::app);
  bool done=false;
  string name;
  int score;
  int highscore=-1;
  if(file){
    while(true){
      file>>name;
      file>>score;
      if(file.eof()){
	break;
      }
      if(score>highscore){
	highscore=score;
      }
      if(name==p.getName() && score<p.getScore()){
	tmp<<p.getName()<<" "<<p.getScore()<<"\n";
	done=true;
      }else if(name==p.getName() && score>=p.getScore()){
	done=true;
	tmp<<name<<" "<<score<<"\n";
      }else{
	tmp<<name<<" "<<score<<"\n";
      }
    }
  }else{ // save file doesn't exist
    done=true;
    tmp<<p.getName()<<" "<<p.getScore()<<"\n";
  }
  if(!done){ // appends the new score to the file
    tmp<<p.getName()<<" "<<p.getScore()<<"\n";
  }
  file.close();
  tmp.close();
  rename("tmp.txt",fileoutput.c_str());
  if(highscore <= p.getScore()){
    cout<<"New Highscore !"<<endl;
  }
  cout<<p.getName()<<" score : "<<p.getScore()<<endl;
}

void Game::delete_line(int l){ // warning
  int cptl = l*gridwidth;
  int cptcol;
  char tmp;
  while(cptl<(l+1)*gridwidth){
    grid[cptl]='n';
    cptcol=cptl;
    while(cptcol-gridwidth>0){
      grid[cptcol]=grid[cptcol-gridwidth];
      cptcol-=gridwidth;
    }
    cptl++;
  }
}

bool Game::check_line(int l){
  int cpt = l*gridwidth;
  bool is_full_line=true;
  while(cpt<(l+1)*gridwidth){
    if(grid[cpt]=='n'){
      is_full_line=false;
      break;
    }
    cpt++;
  }
  return is_full_line;
}

int Game::getGridWidth(){return gridwidth;}

int Game::getGridHeight(){return gridheight;}

Player * Game::getPlayer(){return &p;}

screen & operator<<(screen & s,const Game & g){
  g.display(&s);
  return s;
}

void Game::setCurrentpiece(AbstractShape * s){
  currentpiece=s;
}

void Game::setNextpiece(AbstractShape * s){
  nextpiece=s;
}

Game::~Game(){
  delete currentpiece;
  save_score("save/save.txt");
}

AbstractShape * Game::getCurrentpiece(){return currentpiece;}

AbstractShape * Game::getNextpiece(){return nextpiece;}

int Game::getCurrentlevel(){return currentlevel;}

bool Game::colision(char c){
  bool colision = false;
  pair<int,int> tmp;
  for(int i=0;i<4;i++){
    tmp=currentpiece->near_bloc(c,i);
    if(!(c=='d' && tmp.second<0)){
      if(tmp.first>=0 && tmp.first<gridwidth*sizecell && tmp.second<gridheight*sizecell){
	if(grid[(tmp.second/sizecell)*gridwidth+tmp.first/sizecell]!='n'){
	  colision = true ;
	}
      }else{
	colision = true ; // end of line
      }
    }
  }
  return colision;
}

int Game::getNbblocs(){return nbblocs;}

void Game::resetNbblocs(){nbblocs=0;}

void Game::levelup(){currentlevel++;}

bool Game::rotation_colision(AbstractShape * a){
  bool colision=false;
  pair<int,int> tmp;
  for(int cpt=0;cpt<4;cpt++){
    tmp=a->getBloc(cpt);
    if(tmp.first>=0 && tmp.first<gridwidth*sizecell && tmp.second<gridheight*sizecell){
      if(grid[(tmp.second/sizecell)*gridwidth+tmp.first/sizecell]!='n'){
	colision = true ;
      }
    }else{
      colision = true ; // end of line
    }
  }
  return colision;
}

int Game::get_lines(){return lines;}

void Game::display(screen * s)const{
  int x=0;
  int y=0;
  
  for(auto it=grid.begin();it!=grid.end();it++){
    s->draw_rect(x,y,sizecell,sizecell,(*it),s->getGame());
    x+=sizecell;
    if(x==sizecell*gridwidth){
      x=0;
      y+=sizecell;
    }
  }
  currentpiece->display(s,0);
  nextpiece->display(s,1);
}
