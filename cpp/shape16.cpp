#include "../hpp/shape16.hpp"

Shape16::Shape16(int x,int y,int s){
  c='b';
  size=s;
  num=16;
  first=15;
  last=18;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+2*s,y+s));
}

Shape16::Shape16(){}

Shape16::Shape16(const Shape16 & s){
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

Shape16::~Shape16(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape16::Clone(int x,int y,int s)const{
  return new Shape16(x,y,s);
}
