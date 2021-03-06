#include "../hpp/factory.hpp"
#include <ctime>


void Factory::Register(const string objname, AbstractShape * obj){//add a shape in the factory
  if(factory.find(objname)==factory.end()){
    factory[objname]=obj;
  }
}

map<string,AbstractShape *> Factory::factory = std::map<string,AbstractShape*>();//static map, only one for the whole program

AbstractShape * Factory::create(const string key,int x,int y,int s){// create a precise shape
  AbstractShape * tmp = 0;
  auto it=factory.find(key);
  if(it!=factory.end()){
    tmp = ((*it).second)->Clone(x,y,s);
  }
  return tmp;
}

AbstractShape * Factory::create_random_shape(int x,int y,int s){//create random shape, by getting a random iterator on the map
  AbstractShape * tmp = 0;
  int random_shape=rand()%factory.size();
  auto it=factory.begin();
  advance(it,random_shape);
  tmp = ((*it).second)->Clone(x,y,s);
  return tmp;
}

Factory::Factory(){
  srand(time(NULL));
}

Factory::~Factory(){
  for(auto it=factory.begin();it!=factory.end();it++){//release factory memory
    delete (*it).second;
  }
  factory.clear();
}
