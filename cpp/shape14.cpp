#include "../hpp/shape14.hpp"

Shape14::Shape14(int x,int y,int s){
  c='g';
  size=s;
  num=14;
  first=13;
  last=14;
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+2*s,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
}

Shape14::Shape14(){}

Shape14::Shape14(const Shape14 & s){
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

Shape14::~Shape14(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape14::Clone(int x,int y,int s)const{
  return new Shape14(x,y,s);
}
