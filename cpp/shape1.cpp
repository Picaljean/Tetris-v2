#include "../hpp/shape1.hpp"

Shape1::Shape1(int x,int y,int s){
  c='c';
  size=s;
  num=1;
  first=1;
  last=2;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x,y+2*s));
  shape.push_back(make_pair(x,y+3*s));
}

Shape1::Shape1(){}

Shape1::~Shape1(){
  while(!shape.empty()){
    shape.pop_back();
  }
}

AbstractShape * Shape1::Clone(int x,int y,int s)const{
  return new Shape1(x,y,s);
}

Shape1::Shape1(const Shape1&s){
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
