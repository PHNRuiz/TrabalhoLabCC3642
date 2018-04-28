#include <iostream>
#include <math.h>
using namespace std;

class Neuronio{
	public:
		virtual double funcAtivacao() = 0;
		virtual double derivadaParcialEmW() = 0;
		virtual ~Neuronio(){}
	
};


class Perceptron1 : public Neuronio{
	public:
		double esperado(double x){
			return 50*x*x; //input do neuronio, oq eu quero aprender
		}
		
		double funcAtivacao(double x){
			return x*x; //funcao "dentro" do neuronio
		}
		
		double chute(double x){
			return funcAtivacao(w1 * x); //funcao ativaçao com peso
		}
		
		double derivadaParcialEmW(double y, double x){
			//2 w (w^2 x^4 - x^2 y); pra x^2 de ativaçao,
		 //temos essa derivada, ela muda conforma a ativaçao escolhida
			return 2*w1(w1*w1 * x*x*x*x - x*x * y);
		}
		
		double erro(double x){
			double e = esperado(x) - chute(x);
			e = e*e;
			return e;
		}
		
		void itera(double x){
			w1 = w1 - derivadaParcialEmW(esperado(x), x)*taxaAprendizagem;
			cout<<erro(x)<<endl;
		}
		
		
		
	private://fazer setters e getters
		double w1 = 0.8;
		double taxaAprendizagem = 0.0000000001; //numero BEM pequeno
	
};

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
};




int main() {
	
	//Neuronio *n = new Perceptron1();
	//delete n;
  std::cout << "Hello World!\n";
}