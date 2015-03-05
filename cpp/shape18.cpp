#include "../hpp/shape18.hpp"

Shape18::Shape18(int x,int y,int s){
  c='b';
  size=s;
  num=18;
  first=15;
  last=18;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+2*s,y));
  shape.push_back(make_pair(x+2*s,y+s));
}

Shape18::Shape18(){}

Shape18::Shape18(const Shape18 & s){
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

Shape18::~Shape18(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape18::Clone(int x,int y,int s)const{
  return new Shape18(x,y,s);
}
