#include "../hpp/shape5.hpp"

Shape5::Shape5(int x,int y,int s){
  c='o';
  size=s;
  num=5;
  first=3;
  last=6;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+s,y+2*s));
}

Shape5::Shape5(){}

Shape5::Shape5(const Shape5 & s){
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

Shape5::~Shape5(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape5::Clone(int x,int y,int s)const{
  return new Shape5(x,y,s);
}
