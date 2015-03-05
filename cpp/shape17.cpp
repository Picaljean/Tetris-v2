#include "../hpp/shape17.hpp"

Shape17::Shape17(int x,int y,int s){
  c='b';
  size=s;
  num=17;
  first=15;
  last=18;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x,y+2*s));
}

Shape17::Shape17(){}

Shape17::Shape17(const Shape17 & s){
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

Shape17::~Shape17(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape17::Clone(int x,int y,int s)const{
  return new Shape17(x,y,s);
}
