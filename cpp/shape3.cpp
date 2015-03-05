#include "../hpp/shape3.hpp"

Shape3::Shape3(int x,int y,int s){
  c='o';
  size=s;
  num=3;
  first=3;
  last=6;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x,y+2*s));
  shape.push_back(make_pair(x+s,y+2*s));
}

Shape3::Shape3(){}

Shape3::Shape3(const Shape3 & s){
  c=s.c;
  size=s.size;
  first=s.first;
  last=s.last;
  num=s.num;
  auto it=s.shape.begin();
  for(it;it!=s.shape.end();it++){
    shape.push_back(make_pair((*it).first,(*it).second));
  }
}

Shape3::~Shape3(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape3::Clone(int x,int y,int s)const{
  return new Shape3(x,y,s);
}
