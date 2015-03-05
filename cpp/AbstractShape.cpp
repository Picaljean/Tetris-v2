#include "../hpp/AbstractShape.hpp"
#include <algorithm>

AbstractShape::~AbstractShape(){}

void AbstractShape::move_left(int x){
  auto it=shape.begin(); 
  for(it;it!=shape.end();it++){
    //(*it)->setX((*it)->getX()-x);
    (*it).first-=x;
  } 
}

AbstractShape & AbstractShape::operator=(const AbstractShape & s){
  if(this != &s){
    while(!shape.empty()){
      shape.pop_back();
    }
    auto it=s.shape.begin();
    for(it;it!=s.shape.end();it++){
      //shape.push_back(new Bloc((*it)->getX(),(*it)->getY()));
      shape.push_back(make_pair((*it).first,(*it).second));
    }
    c=s.c;
    size=s.size;
    num=s.num;
    first=s.first;
    last=s.last;
  }
  return *this;
}


void AbstractShape::move_right(int x){
  auto it=shape.begin();
  for(it;it!=shape.end();it++){
    //(*it)->setX((*it)->getX()+x);
    (*it).first+=x;
  }
}

void AbstractShape::move_down(int y){
  auto it=shape.begin();
  for(it;it!=shape.end();it++){
    //(*it)->setY((*it)->getY()+y);
    (*it).second+=y;
  }
}

char AbstractShape::getColor(){return c;}

int AbstractShape::match_line(){
  return (y_down_bloc()+size)/size;
}

int AbstractShape::match_line_up(){
  return y_up_bloc()/size;
}

int AbstractShape::get_location(int i,int col){
  return (shape[i].second/size)*col+(shape[i].first/size);
}

int AbstractShape::next(){
  int next=num;
  if(num!=0){ // 0 % n don't exist, and bug in c++ (floating pointer exception, core dumped)
    if(next%last==0){
      next=first;
    }else{
      next++;
    }
  }else{
    next=0;
  }
  return next;
}

int AbstractShape::previous(){
  int prev=num;;
  if(num==first){
    prev=last;
  }else{
    num--;
  }
  return num;
}

pair<int,int> AbstractShape::new_shape(){
  return make_pair(x_left_bloc(),y_up_bloc());
}

pair<int,int> AbstractShape::near_bloc(char pos,int num){
  switch(pos){
  case 'l':{
    return make_pair(shape[num].first-size,shape[num].second);
    break;}
  case 'r':{
    return make_pair(shape[num].first+size,shape[num].second);
    break;}
  case 'd':{
    return make_pair(shape[num].first,shape[num].second+size);
    break;}
  }
}

int AbstractShape::x_left_bloc()const{
  auto it=shape.begin();
  int x=(*it).first;
  for(it;it!=shape.end();it++){
    if((*it).first<x){
      x=(*it).first;
    }
  }
  return x;
}

int AbstractShape::x_right_bloc()const{
  auto it=shape.begin();
  int x=(*it).first;
  for(it;it!=shape.end();it++){
    if((*it).first>x){
      x=(*it).first;
    }
  }
  return x;
}

int AbstractShape::y_down_bloc()const{
  auto it=shape.begin();
  int y=(*it).second;
  for(it;it!=shape.end();it++){
    if((*it).second>y){
      y=(*it).second;
    }
  }
  return y;
}

int AbstractShape::y_up_bloc()const{
  auto it=shape.begin();
  int y=(*it).second;
  for(it;it!=shape.end();it++){
    if((*it).second<y){
      y=(*it).second;
    }
  }
  return y;
}

pair<int,int> AbstractShape::getBloc(int n){
  return make_pair(shape[n].first,shape[n].second);
}

void AbstractShape::display(screen * s, int type)const{
  int lb = x_left_bloc();
  int up = y_up_bloc();
  switch(type){
  case 0:{ // case where the shape is displayed on game screen
    for(auto it=shape.begin();it!=shape.end();it++){
      s->draw_rect((*it).first,(*it).second,size,size,c,s->getGame());
    }
    break;}
  case 1:{ // case where the shape is displayed on piece screen (next piece)
    for(auto it=shape.begin();it!=shape.end();it++){
      s->draw_rect((*it).first-lb,(*it).second-up,size,size,c,s->getPiece());
    }
    break;}
  }
}
