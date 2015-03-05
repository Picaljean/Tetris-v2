#include "../hpp/shape15.hpp"

Shape15::Shape15(int x,int y,int s){
  c='b';
  size=s;
  num=15;
  first=15;
  last=18;
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x,y+2*s));
  shape.push_back(make_pair(x+s,y+2*s));
}

Shape15::Shape15(){}

Shape15::Shape15(const Shape15 & s){
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

Shape15::~Shape15(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape15::Clone(int x,int y,int s)const{
  return new Shape15(x,y,s);
}
