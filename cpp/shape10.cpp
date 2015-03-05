#include "../hpp/shape10.hpp"

Shape10::Shape10(int x,int y,int s){
  c='p';
  size=s;
  num=10;
  first=7;
  last=10;
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+s,y+2*s));
}

Shape10::Shape10(){}

Shape10::Shape10(const Shape10 & s){
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

Shape10::~Shape10(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape10::Clone(int x,int y,int s)const{
  return new Shape10(x,y,s);
}
