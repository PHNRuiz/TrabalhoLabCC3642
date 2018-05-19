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

class Perceptron3 : public Neuronio{
	//ativaçao gaussiana e^(-x*w)^2
	//derivada 2w(x^2)e^((w)^2(x)^2)
	public:
		Perceptron3(int entradas):Neuronio(entradas){}
		double funcAtivacao(double xfa){
			return exp(-pow((xfa),2));
		}
		double chute(vector<double> x){
			return funcAtivacao(w[0] * x[0]);
		}
		double derivadaParcialEmW(vector<double> x, double y){
			return exp(pow(-x[0] * w[0], 2)) * 2 * (-x[0]*w[0]) * (-x[0]);
		}
		double erro(vector<double> x, double y){
			double e = y - chute(x);
			e = e*e;
			return e;
		}
		void itera(vector<double> x, double y){
			cout<<"Gaussiana"<<endl;
			w[0] = w[0] - derivadaParcialEmW(x,y)*taxaAprendizagem;
			cout<<derivadaParcialEmW(x,y)<<endl;
			cout<<erro(x,y)<<endl;
			cout<<w[0]<<endl;
			cout<<"---------------"<<endl;
		}
		
		virtual ~Perceptron3(){}
	
};


 //cúbica(mexer nessa)
class Perceptron2 : public Neuronio{
	public:

		Perceptron2(int entradas) : Neuronio(entradas){}
		
		
		double funcAtivacao(double xfa){
			return xfa*xfa*xfa;
		}
		
		double chute(vector<double> x){
			return funcAtivacao(w[0] * x[0]);
		}
		
		double derivadaParcialEmW( vector<double> x, double y){
			
			//return 3 * w[0] * w[0] * x[0] * x[0] * x[0];
			//return 3 * w[0] * w[0] * x[0] * x[0] * x[0];
			return 6 * pow(w[0],5) * pow(x[0],6) - 6 * pow(w[0],2) * pow(x[0],3) * y;
		}
		
		double erro(vector<double> x, double y){
			double e = y - chute(x);
			e = e * e;
			return e;
		}
		
		void itera(vector<double> x, double y){
			cout<<"Cúbica"<<endl;
			w[0] = w[0] - derivadaParcialEmW(x,y)*taxaAprendizagem;
			cout<<"Valor da derivada = "<<derivadaParcialEmW(x,y)<<endl;
			cout<<"Valor do erro = "<<erro(x,y)<<endl;
			cout<<"Peso = "<<w[0]<<endl;
			cout<<"---*---*---*---*---*---*---*---*"<<endl;
		}
		
		virtual ~Perceptron2(){}

};



void teste1(){//quadratico

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
	
}

void teste2(){//gaussiana(deu ruim)
	Neuronio *m = new Perceptron3(1);
	vector<double> x1(1);
	double y1;
	
		for(int i=0;i<10000;i++){
			x1[0] = (i/10000.0);
			y1 = exp((-pow(x1[0], 2)));
			cout<<"x = "<<x1[0]<<" y = "<< y1 <<endl;
			m->itera(x1,y1);
		}
	
	delete m;
	
}

void teste3(){//cubica
	Neuronio *p = new Perceptron2(1);
	vector<double> x2(1);
	double y2;
	for(int i=0;i<10000;i++){
		x2[0] = i % 50;
		y2 = x2[0] * x2[0] * x2[0];
		cout<<"x = "<<x2[0]<<" y = "<<y2<<endl;
		p->itera(x2,y2);

	}
	delete p;

}
	


int main() {
	
	//teste1();
	//teste2();
	teste3();

	
	
	

	

  std::cout << "Hello World!\n";
}