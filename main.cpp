#include <iostream>
#include <fstream>
#include<vector>


// TODO struct "object" with vectors for position, speed, doubles for Energy, friction force, gravity, mass
struct object{
  std::vector<double> position;
  std::vector<double> velocity;
  std::vector<double> acceleration;
  std::vector<double> gravity;
  double mass;
};


// input for variables of "ball" of type object from input.txt

int main(int argc, char** argv){

  std::ifstream in("input.txt"); 
  double e;
  double f;
  double h;   
  object ball;
  while (in>>e){
    in>>f;
    in>>h;
    in>>ball.mass;
    ball.position.push_back(e);
    ball.velocity.push_back(f);
    ball.gravity.push_back(h);
  }


  
  // TODO method for timesteps
  double tau = 0.01;
  while(ball.position[2]>0){
  for( int i; i<ball.acceleration.size(); i++){
    ball.acceleration[i] = ball.gravity[i]*ball.mass;
    ball.velocity[i] = ball.acceleration[i]*tau+ball.velocity[i];
    ball.position[i] = ball.velocity[i]*tau+ball.position[i];
  };
  };




  // TODO output of variables to output.txt
 
  std::ofstream out("output.txt");
  for( int i=0; i<ball.position.size(); i++){
    out << ball.position[i] << std::endl;
  }
  return(0);
}

