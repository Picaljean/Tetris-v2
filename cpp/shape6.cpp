#include "../hpp/shape6.hpp"

Shape6::Shape6(int x,int y,int s){
  c='o';
  size=s;
  num=6;
  first=3;
  last=6;
  shape.push_back(make_pair(x,y+s));
  shape.push_back(make_pair(x+s,y+s));
  shape.push_back(make_pair(x+2*s,y+s));
  shape.push_back(make_pair(x+2*s,y));
}

Shape6::Shape6(){}

Shape6::Shape6(const Shape6 & s){
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

Shape6::~Shape6(){
  while(!shape.empty()){
    shape.pop_back();
  }
}


AbstractShape * Shape6::Clone(int x,int y,int s)const{
  return new Shape6(x,y,s);
}
