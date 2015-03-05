#include "../hpp/shape11.hpp"

Shape11::Shape11(int x,int y,int s){
  c='r';
  size=s;
  num=11;
  first=11;
  last=12;
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x,y+2*s));
}

Shape11::Shape11(){}

Shape11::Shape11(const Shape11 & s){
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

Shape11::~Shape11(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape11::Clone(int x,int y,int s)const{
  return new Shape11(x,y,s);
}