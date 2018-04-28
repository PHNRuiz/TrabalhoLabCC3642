#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Neuronio{
	protected:
	   int entradas;
	   vector<double> w;
	   double taxaAprendizagem ; //numero BEM pequeno
	   
	public:
	  Neuronio(int ent, double ta=0.0000000001){
	  	entradas = ent;
	  	taxaAprendizagem = ta;
	  }
	  
		virtual double funcAtivacao(double x) = 0;
		virtual double derivadaParcialEmW(vector<double> x, double y) = 0;
		virtual double erro(vector<double> x);
		virtual void itera(vector<double> x);
		virtual ~Neuronio(){
			
		}
	
};


class Perceptron1 : public Neuronio{
	public:
	  Perceptron1(int entradas): Neuronio(entradas){
	  	
	  }
	  
		double esperado(vector<double> x){
			return 50*x[0]*x[0]; //input do neuronio, oq eu quero aprender
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
		
		double erro(vector<double> x){
			double e = esperado(x) - chute(x);
			e = e*e;
			return e;
		}
		
		void itera(vector<double> x){
			w[0] = w[0] - derivadaParcialEmW(x, esperado(x))*taxaAprendizagem;
			cout<<erro(x)<<endl;
		}
		
		virtual ~Perceptron1(){}
		
	private://fazer setters e getters
		
	
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
	
	for(int i=0;i<10000;i++){
		x[0] = i % 50;
		n->itera(x);
	}
	
	delete n;
  std::cout << "Hello World!\n";
}