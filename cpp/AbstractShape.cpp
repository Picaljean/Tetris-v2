#include "../hpp/AbstractShape.hpp"
#include <algorithm>

AbstractShape::~AbstractShape(){}//virtual destructor for inheritance

void AbstractShape::move_left(int x){// move all blocs to the left (called when left key is pressed)
  auto it=shape.begin(); 
  for(it;it!=shape.end();it++){
    (*it).first-=x;
  } 
}

  AbstractShape & AbstractShape::operator=(const AbstractShape & s){//operator = when we set a shape with another, in particular when currentshape or nextshape is changed
  if(this != &s){
    while(!shape.empty()){
      shape.pop_back();
    }
    auto it=s.shape.begin();
    for(it;it!=s.shape.end();it++){
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


void AbstractShape::move_right(int x){// move all to the blocs right (called when right key is pressed)
  auto it=shape.begin();
  for(it;it!=shape.end();it++){
    (*it).first+=x;
  }
}

void AbstractShape::move_down(int y){// move all blocs down (called in the game loop to move down the shape)
  auto it=shape.begin();
  for(it;it!=shape.end();it++){
    (*it).second+=y;
  }
}

char AbstractShape::getColor(){return c;}

int AbstractShape::match_line(){//match the lower bloc with the line number in the game vector
  return (y_down_bloc()+size)/size;
}

int AbstractShape::match_line_up(){//match the higher bloc with the line number in the game vector
  return y_up_bloc()/size;
}

int AbstractShape::get_location(int i,int col){//translate the coordinates of shape[i] in a index of the game vector
  return (shape[i].second/size)*col+(shape[i].first/size);
}

int AbstractShape::next(){//calculate the next shape in the factory of this shape
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

int AbstractShape::previous(){//calculate the previous shape in the factory of this shape
  int prev=num;;
  if(num==first){
    prev=last;
  }else{
    prev--;
  }
  return prev;
}

pair<int,int> AbstractShape::new_shape(){// coordinates of the new shape created when rotation is done (always left top corner whatever the shape is)
  return make_pair(x_left_bloc(),y_up_bloc());
}

pair<int,int> AbstractShape::near_bloc(char pos,int num){//get the coordinates of the near to the left/right/down bloc shape[num]
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
