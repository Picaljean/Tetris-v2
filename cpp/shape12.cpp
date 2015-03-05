#include "../hpp/shape12.hpp"

Shape12::Shape12(int x,int y,int s){
  c='r';
  size=s;
  num=12;
  first=11;
  last=12;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+2*s,y+s));
}

Shape12::Shape12(){}

Shape12::Shape12(const Shape12 & s){
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

Shape12::~Shape12(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape12::Clone(int x,int y,int s)const{
  return new Shape12(x,y,s);
}