#include "../hpp/shape0.hpp"

Shape0::Shape0(int x,int y,int s){
  c='y';
  size=s;
  num=0;
  first=0;
  last=0;
  shape.push_back(make_pair(x,y));
  shape.push_back(make_pair(x+s,y));
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
}

Shape0::Shape0(){}

Shape0::~Shape0(){
  /*for(auto it=shape.begin();it!=shape.end();it++){
    delete (*it);
    }*/
  while(!shape.empty()){
    shape.pop_back();
  }
}

AbstractShape * Shape0::Clone(int x,int y,int s)const{
  return new Shape0(x,y,s);
}

Shape0::Shape0(const Shape0 & s){
  c=s.c;
  size=s.size;
  num=s.num;
  last=s.last;
  first=s.first;
  auto it=s.shape.begin();
  for(it;it!=s.shape.end();it++){
    shape.push_back(make_pair((*it).first,(*it).second));
  }
}
