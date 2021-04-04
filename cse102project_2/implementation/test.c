#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int main(){
	int a,b=0,result;

	node *root;
	root=malloc(sizeof(node));
	
	char **informations;
	informations=malloc(sizeof(char));
	informations[0]=malloc(sizeof(char*));	
	
	char **informations_defaults;
	informations_defaults=malloc(sizeof(char));
	informations_defaults[0]=malloc(sizeof(char*));
	
	informations=read_commands(informations);
	informations_defaults=read_defaults(informations_defaults);
	for(a=0;informations[a][0]!='\0';a++){

		result=control_error(informations[a]);
		if(result==2){
			
			root=realloc(root,sizeof(node)*(b+1));
			store_struct(root,informations[a],informations_defaults,b);
			if(root[b].archetype==4){
				print_square(root,b);
			}
			if(root[b].archetype==6){
				print_hexagon(root,b);
			}
			b++;
		}
		else{
			printf("	ERROR %d. ROW!!!!!\n",a);
		}
	}
	return 0;
}
