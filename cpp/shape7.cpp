#include "../hpp/shape7.hpp"

Shape7::Shape7(int x,int y,int s){
  c='p';
  size=s;
  num=7;
  first=7;
  last=10;
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+2*s,y+s));
}

Shape7::Shape7(){}

Shape7::Shape7(const Shape7 & s){
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

Shape7::~Shape7(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape7::Clone(int x,int y,int s)const{
  return new Shape7(x,y,s);
}
