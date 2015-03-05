#include "../hpp/shape2.hpp"

Shape2::Shape2(int x,int y,int s){
  c='c';
  size=s;
  num=2;
  first=1;
  last=2;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+2*s,y));
  shape.push_back(make_pair(x+3*s,y));
}

Shape2::Shape2(){}

Shape2::Shape2(const Shape2 & s){
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

Shape2::~Shape2(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape2::Clone(int x,int y,int s)const{
  return new Shape2(x,y,s);
}
