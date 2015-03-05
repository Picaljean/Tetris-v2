#include "../hpp/shape9.hpp"

Shape9::Shape9(int x,int y,int s){
  c='p';
  size=s;
  num=9;
  first=7;
  last=10;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+2*s,y));
  shape.push_back(make_pair(x+s,y+s));
}

Shape9::Shape9(){}

Shape9::Shape9(const Shape9 & s){
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

Shape9::~Shape9(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape9::Clone(int x,int y,int s)const{
  return new Shape9(x,y,s);
}
