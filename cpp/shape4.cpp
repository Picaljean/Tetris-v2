#include "../hpp/shape4.hpp"

Shape4::Shape4(int x,int y,int s){
  c='o';
  size=s;
  num=4;
  first=3;
  last=6;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+2*s,y));
  shape.push_back(make_pair(x,y+s));
}

Shape4::Shape4(){}

Shape4::Shape4(const Shape4 & s){
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

Shape4::~Shape4(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape4::Clone(int x,int y,int s)const{
  return new Shape4(x,y,s);
}
