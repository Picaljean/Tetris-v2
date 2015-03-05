#include "../hpp/shape13.hpp"

Shape13::Shape13(int x,int y,int s){
  c='g';
  size=s;
  num=13;
  first=13;
  last=14;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+s,y+2*s));
}

Shape13::Shape13(){}

Shape13::Shape13(const Shape13 & s){
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

Shape13::~Shape13(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape13::Clone(int x,int y,int s)const{
  return new Shape13(x,y,s);
}
