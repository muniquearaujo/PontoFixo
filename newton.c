#include<math.h>
#include<stdio.h>
#define N 3

FILE *fp;

//Cálculo das funções
double funcao1(double x[N])
{
	return(pow(x[1],2)-81*pow((x[2]+0.1),2)+sin(x[3])+1.06);
}

double funcao2(double x[N])
{
	return(M_E*(x[1]*x[2])+20*x[3]+((10*M_PI-3)/3));
}

double funcao3(double x[N])
{
	return(3*x[1]-cos(x[2]*x[3])-1/2);
}

//Cálculo da derivada
double deriv(double dx,int a)
{
	double x1[N],x2[N],df[N],xo[N]={0.1,0.1,-0.1};
	double (*F[N])()={funcao1,funcao2,funcao3};
	int i;

	for(i=0;i<N;i++)
	{
		x1[i]=xo[i]+dx/2;
		x2[i]=xo[i]-dx/2;
		df[i]=(F[a](x1[i]))-(F[a](x2[i]));		
	}
			return(df[i]);
}
main()
{
	double xo[N]={0.1,0.1,-0.1};
	double x[N],norma,raiz[N],dx=1E-6,d;
	int i,a,cont=0;
	double (*F[N])()={funcao1,funcao2,funcao3};
	fp=fopen("newton.dat","w");

	do{
		//calcular o valor de -Fo
		for(i=0;i<N;i++)
		{
			norma+=pow(xo[i],2);
			printf("\nValor da norma: %lf\n",norma);

			printf("Qual função você quer derivar? Função 1, 2 ou 3?\n\n");
			scanf("%d",&a);

			d=deriv(dx,a);
			printf("\nd=%lf",d);
			
			//calculando o valor da raíz	
			x[i]=(-1)*(F[a](xo));
						
			cont++;
			
			fprintf(fp,"%lf\t%lf\n",norma,x[i]);
		}
			printf("\n-F(xo): %lf\n\n",x[i]);

	}while(cont<15);	
	
}

