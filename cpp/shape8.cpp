#include "../hpp/shape8.hpp"

Shape8::Shape8(int x,int y,int s){
  c='p';
  size=s;
  num=8;
  first=7;
  last=10;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x,y+2*s));
}

Shape8::Shape8(){}

Shape8::Shape8(const Shape8 & s){
  c=s.c;
  size=s.size;
  first=s.first;
  last=s.last;
  num=s.num;
  auto it=s.shape.begin();
  for(it;it!=s.shape.end();it++){
    shape.push_back(make_pair(it->first, it->second));
  }
}

Shape8::~Shape8(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape8::Clone(int x,int y,int s)const{
  return new Shape8(x,y,s);
}
