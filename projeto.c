#include <stdlib.h>
#include <stdio.h>
#define MAX 100

struct Data{
    int dia;
    int mes;
    int ano;
}Data;

struct Receita{
    struct Data data;
    float valor;
    int tipo;
}Receita;

struct Data criaData(int dia, int mes, int ano){
    struct Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}



//Nelson eh um amigo q ajudou no projeto :3
struct Nelson{
    struct Receita receitas[MAX];
    int n;
};

int menu(){

    puts("=======================================");
    puts("1 - Insere   ");
    puts("2 - Insere valor com parcelas");
    puts("3 - Relatorio especifo ");
    puts("4 - Relatorio ultimos 12 meses ");
    puts("5 - Porcentagem dos gastos");
    puts("6 - Total de gastos em 1 ou 12 meses");
    puts("0 - Sai!    ");
    printf("opcao> ");
    int op;
    scanf("%d", &op);

    return op;

	
}
void cadastra(struct Nelson *j){
	printf("Valor: ");
	scanf("%f",&j->receitas[j->n].valor);
    printf("Tipo:(1-Moradia, 2-Estudos, 3-Transporte, 4-Alimentacao, 5-Trabalho) ");
    scanf("%d",&j->receitas[j->n].tipo);
    while(j->receitas[j->n].tipo>5){
    	printf("opacao invalida! Digite novamente ");
    	scanf("%d",&j->receitas[j->n].tipo);	
	}
    int d=0;
    int m=0;
    int a=0;
    int p=0;
    printf("apartir de que dia? ");
    scanf("%d",&d);
    while(d>31 ){
        printf("dia invalido ! insira novamente: ");
        scanf("%d",&d);
    }

	printf("apartir de que mes? ");
    scanf("%d",&m);
    while(m>12){printf("mes invalido ! insira novamente: ");
        scanf("%d",&m);
    }
	
	printf("apartir de que ano? ");	
    scanf("%d",&a);
    j->receitas[j->n].data=criaData(d,m,a);
    j->n++;	
}

int conferi(struct Nelson j,int d, int m , int a,int i,int op){
    int A = j.receitas[i].data.ano;
    int M = j.receitas[i].data.mes;
    int D = j.receitas[i].data.dia;
    if (op==0){
       if ((a-A==1 && (m<M ||(m==M && d<=D)) ) || (a-A==0 && (m>M ||(m==M && d>=D))) ){
            return 0;      
       }
       else{
            return 1;
       }
    }else{
        if ( (a-A==0 && ((m-M==0 && d-D>=0) || (m-M==1 && d-D<=0)) ) ){        
            return 0;       
        }else{
            return 1;
        }        
    } 
};

void imprime12(struct Nelson j){
    int d=0;
    int m=0;
    int a=0;
    printf("apartir de que dia? ");
    scanf("%d",&d);
    while(d>31 ){
        printf("dia invalido ! insira novamente: ");
        scanf("%d",&d);
    }

	printf("apartir de que mes? ");
    scanf("%d",&m);
    while(m>12){printf("mes invalido ! insira novamente: ");
        scanf("%d",&m);
    }
	
	printf("apartir de que ano? ");
	
    scanf("%d",&a);
    int i;
    int op=0;
	for (i = 0; i < j.n; i++){
        
        if(conferi(j,d,m,a,i,op)==0){
        	
        	puts("_________________________");
            if(j.receitas[i].tipo==1){            	
                printf(" Moradia: \n");
            }else if(j.receitas[i].tipo==2){            	
                printf(" Estudos: \n");
            }else if(j.receitas[i].tipo==3){
                printf(" Transporte: \n");
            }else if(j.receitas[i].tipo==4){
                printf(" Alimentacao: \n");
            }else if(j.receitas[i].tipo==5){
                printf(" Trabalho: \n");
            }
            
            printf(" Valor: %.2f \n",j.receitas[i].valor);
            
            printf(" Data: %d/%d/%d \n",j.receitas[i].data.dia,j.receitas[i].data.mes,j.receitas[i].data.ano);
            
        }        
    }    
}

void imprime1(struct Nelson j){
    int d=0;
    int m=0;
    int a=0;
	printf("apartir de que dia? ");
    scanf("%d",&d);
    while(d>31 ){
        printf("dia invalido ! insira novamente: ");
        scanf("%d",&d);
    }

	printf("apartir de que mes? ");
    scanf("%d",&m);
    while(m>12){printf("mes invalido ! insira novamente: ");
        scanf("%d",&m);
    }
	
	printf("apartir de que ano? ");
	
    scanf("%d",&a);
    int i;
    int op=1;
	for (i = 0; i < j.n; i++){
        puts("_________________________");
        if(conferi(j,d,m,a,i,op)==0){
            if(j.receitas[i].tipo==1){
                printf("Moradia:\n");
            }else if(j.receitas[i].tipo==2){
                printf("Estudos:\n");
            }else if(j.receitas[i].tipo==3){
                printf("Transporte:\n");
            }else if(j.receitas[i].tipo==4){
                printf("Alimentacao:\n");
            }else if(j.receitas[i].tipo==5){
                printf("Trabalho:\n");

            }
            
            printf(" Valor: %.2f\n",j.receitas[i].valor);
            
            printf(" Data: %d/%d/%d\n",j.receitas[i].data.dia,j.receitas[i].data.mes,j.receitas[i].data.ano);
            
        }        
    }
}

float calc(float valor, float v){
    return (v*100)/valor;
}

void porcent(struct Nelson j){
    float Vm=0;
    float Ve=0;
    float Vb=0;
    float Va=0;
    float Vt=0;
    float valor=0;
    int i;
    for ( i = 0; i < j.n ; i++){
        if(j.receitas[i].tipo==1){
            Vm+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==2){
            Ve+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==3){
            Vb+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==4){
            Va+=j.receitas[i].valor;
        }else if(j.receitas[i].tipo==5){
            Vt+=j.receitas[i].valor;
        }
        valor+=j.receitas[i].valor;

    }
    
    printf("Moradia: %f\n",calc(valor,Vm));
    printf("Estudos: %f\n",calc(valor,Ve));
    printf("Transport: %f\n",calc(valor,Vb));
    printf("Alimentacao: %f\n",calc(valor,Va));
    printf("Trabalho: %f\n",calc(valor,Vt));
};

void parcela(struct Nelson *j){
    int parc=0;
    int d=0;
    int m=0;
    int a=0;
    int i;
    
    float valor=0; 
    printf("Quantas parcelas? ");
    scanf("%d",&parc);
    printf("Valor Total: ");
	scanf("%f",&valor);
    printf("Tipo:(1-Moradia, 2-Estudos, 3-Transporte, 4-Alimentacao, 5-Trabalho) ");
    
    scanf("%d",&j->receitas[j->n].tipo);
    while(j->receitas[j->n].tipo > 5){
    	printf("opacao invalida! Digite novamente ");
    	scanf("%d",&j->receitas[j->n].tipo);	
	}
	int tipo=j->receitas[j->n].tipo;

    printf("apartir de que dia? ");
    scanf("%d",&d);
    while(d>31 ){
        printf("dia invalido ! insira novamente: ");
        scanf("%d",&d);
    }
	
	printf("apartir de que mes? ");
    scanf("%d",&m);
    while(m>12){printf("mes invalido ! insira novamente: ");
        scanf("%d",&m);
    }
	
	printf("apartir de que ano? ");
	
    scanf("%d",&a);
    float valorP=valor/parc;
    for (i = 0; i < parc; i++){
        j->receitas[j->n].valor=valorP;
        j->receitas[j->n].tipo=tipo;
        if (i==0){
            j->receitas[j->n].data=criaData(d,m,a);

        }else{
            if (m==12){
                j->receitas[j->n].data=criaData(d,1,a+1);
                m=1;
                a+=1;
            }else{
                j->receitas[j->n].data=criaData(d,m+1,a);
                m+=1;
            }  
        }
       j->n++; 
    }
}

void gastos(struct Nelson j){
    int d=0;
    int m=0;
    int a=0;
    int opp=0;
    printf("Quer ver 1 ou 12: ");
    scanf("%d",&opp);
	printf("apartir de que dia? ");
    scanf("%d",&d);
    while(d>31 ){
        printf("dia invalido ! insira novamente: ");
        scanf("%d",&d);
    }

	printf("apartir de que mes? ");
    scanf("%d",&m);
    while(m>12){printf("mes invalido ! insira novamente: ");
        scanf("%d",&m);
    }
	
	printf("apartir de que ano? ");
	
    scanf("%d",&a);
    int op;
    int i;
    if(opp==1){
    	op=1;
	}else{
		op=0;
	}
    
    float tot=0;
	for (i = 0; i < j.n; i++){
        if(conferi(j,d,m,a,i,op)==0){
            tot+=j.receitas[i].valor;
        }
            
    }
    if(op=1){
    	printf("No mes %d foi gasto um total de %.2f\n ",m,tot);
	}else{
		printf("Ate o mes %d foi gasto um total de %.2f nos ultimos 12 meses\n ",m,tot);
	}
    
};


int main()
{
	struct Nelson j;
	j.n = 0;
	
    while(1){
        int op = menu();
        if(op == 1){
            cadastra(&j);
        }else if(op == 4){
            imprime12(j);
        }else if(op == 3){
            imprime1(j);
        }else if(op == 5){
            porcent(j);
        }else if(op == 2){
            parcela(&j);            
        }else if(op == 6){
            gastos(j);            
        }else if(op == 0) {
        	
            break;
        }else{
        	puts("Opcao invalida! ");
		}
    }
   puts("Obrigado pela preferencia!");
 
  return 0;
}
 