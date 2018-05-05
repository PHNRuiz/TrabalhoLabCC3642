#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Neuronio{
	protected:
	   int entradas;
	   vector<double> w;
	   double taxaAprendizagem ; //numero BEM pequeno
	   
	public:
	  Neuronio(int ent, double ta=0.000000001){
	  	srand(time_t(NULL));
	  	entradas = ent;
	  	taxaAprendizagem = ta;
	  	for(int i=0; i< ent; i++)
	  		w.push_back((rand() % 1000)/1000.0);
	  }
	  
		virtual double funcAtivacao(double x) = 0;
		virtual double derivadaParcialEmW(vector<double> x, double y) = 0;
		virtual double erro(vector<double> x, double y) = 0;
		virtual void itera(vector<double> x, double y) = 0;
		virtual ~Neuronio(){
			
		}
	
};


class Perceptron1 : public Neuronio{
	public:
	  Perceptron1(int entradas): Neuronio(entradas){
	  }
	  
		double funcAtivacao(double xfa){
			return xfa*xfa; //funcao "dentro" do neuronio
		}
		
		double chute(vector<double> x){
			return funcAtivacao(w[0] * x[0]); //funcao ativaçao com peso
		}
		
		double derivadaParcialEmW(vector<double> x, double y){
			//2 w (w^2 x^4 - x^2 y); pra x^2 de ativaçao,
		 //temos essa derivada, ela muda conforma a ativaçao escolhida
			return 2*w[0]*(w[0]*w[0] * x[0]*x[0]*x[0]*x[0] - x[0]*x[0] * y);
		}
		
		double erro(vector<double> x, double y){
			double e = y - chute(x);
			e = e*e;
			return e;
		}
		
		void itera(vector<double> x, double y){
			w[0] = w[0] - derivadaParcialEmW(x, y)*taxaAprendizagem;
			cout << derivadaParcialEmW(x, y) << endl;
			cout<<erro(x, y)<<endl;
			cout << w[0] << endl;
			cout << "============" << endl;
		}
		
		virtual ~Perceptron1(){}
		
	
		
	
};
/*
class Perceptron2 : public Neuronio{
	public:
		double esperado(double x){
			return x*x*x;
		}
		
		double funcAtivacao(double x){
			return tanh(x);
		}
		
		double chute(double x){
			return funcAtivacao(w2 * x);
		}
		
		double derivadaParcialEmW(double y, double x){
			//1-(f(x))^2 ou x*(sech(w2*x))^2 ?
			return 1 - 
		}
		
		double erro(double x){
			double e = esperado(x) - chute(x);
			e = e * e;
			return e;
		}
		
		void itera(double x){
			w2 = w2 - derivadaParcialEmW(esperado(x), x)*taxaAprendizagem2;
			cout<< erro(x) <<endl;
		}
		
		
	private:
		double w2 = 
		double taxaAprendizagem2 = 
};


class Perceptron3{
	//ativaçao gaussiana e^(-x)^2
	//derivada -2xe^(-x)^2
	
	public:
		double esperado(double x){
			return 
		} 
		
		
		
	private:
		double w3 = 
		double taxaAprendizagem3 = 
};*/




int main() {
	
	Neuronio *n = new Perceptron1(1);
	vector<double> x(1);
	double y;
	
	for(int i=0;i<10000;i++){
		x[0] = i % 50;
		y = 50*x[0]*x[0]+x[0];
		cout << "x = " << x[0] << "  y  = " << y << endl;
		n->itera(x, y);
	}
	
	delete n;
  std::cout << "Hello World!\n";
}